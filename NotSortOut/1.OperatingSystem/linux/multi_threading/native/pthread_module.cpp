#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <pthread.h>
#include "pthread_module.h"

using namespace std;
/*  在这里定义所有的应用模块，注意这里的数组需要和模块ID对应起来，方便管理*/
thread_ctrl_t  thread_info[THREAD_END_ID+1];

/******将主线程的信息与其他线程信息一同管
**理在此函数中完成主线程信息的特殊初始化流程**************************************************/
void init_main_thread_info(void)
{
    thread_info[THREAD_MAIN_ID].thread_id = THREAD_MAIN_ID;
    strcpy(thread_info[THREAD_MAIN_ID].thread_name, "Main Thread");
    thread_info[THREAD_MAIN_ID].init_func = NULL;
    thread_info[THREAD_MAIN_ID].task_id = pthread_self();//获取自身线程的ID值
    thread_info[THREAD_MAIN_ID].init_pri= INIT_TOP_RIGHT;
    thread_info[THREAD_MAIN_ID].task_pri= 0;
    thread_info[THREAD_MAIN_ID].task_func= NULL;
    thread_info[THREAD_MAIN_ID].task_para= 0;
}

/***********显式初始化模块注册数组***************/
void init_thread_list(void)
{
    int thread_id;
    for(thread_id = THREAD_ZERO_ID;thread_id < THREAD_END_ID+1;thread_id++)
    {
        thread_info[thread_id].thread_id= 0;
        strcpy(thread_info[thread_id].thread_name, "null");
        thread_info[thread_id].init_func= NULL;
        thread_info[thread_id].task_id= 0;
        thread_info[thread_id].init_pri= 0;
        thread_info[thread_id].task_pri= 0;
        thread_info[thread_id].task_func= NULL;
        thread_info[thread_id].task_para= 0;
    }
}

/**********获取对应模块的线程优先级**************/
int mod_if_get_thread_priority(int thread_id)
{
    int result;
    result = thread_info[thread_id].task_pri;

    return result;
}

/******************创建线程*********************/
int task_create(unsigned int thread_id, unsigned long* p_tidp, int policy, PF_TASK_MAIN func_entry,void * args)
{
    if (p_tidp == NULL)
    {
        return -1;
    }

    int result;
    pthread_attr_t pattr;
    struct sched_param param;
    pthread_attr_init(&pattr);
    param.sched_priority = mod_if_get_thread_priority(thread_id);   

    pthread_attr_setschedpolicy(&pattr,policy);
    pthread_attr_setschedparam(&pattr,&param);
    pthread_attr_setinheritsched(&pattr,PTHREAD_EXPLICIT_SCHED);
    result = pthread_create(p_tidp,
                            &pattr,
                            func_entry,
                            args);
    pthread_attr_destroy(&pattr);
    return result;
}

void startup_module(int thread_id)
{
task_create(thread_id, &thread_info[thread_id].task_id, thread_info[thread_id].policy, thread_info[thread_id].task_func, NULL);
}

/*按照模块注册时传入的初始化优先级进行模块初始化并创建线程*/
void startup_module_flowline(void)
{
    int init_right = 0;
    int moduleid = 0;
    int init_result = 0;

    for(init_right = INIT_TOP_RIGHT;init_right <  INIT_RIGHT_END;init_right++)
    {
        for(moduleid = THREAD_ZERO_ID+1;moduleid < THREAD_END_ID;moduleid++)
        {
            if((thread_info[moduleid].init_pri== init_right)&&(moduleid != THREAD_MAIN_ID))
            {
                if(thread_info[moduleid].init_func != NULL)
                {
                    init_result = thread_info[moduleid].init_func(moduleid);
                }
                startup_module(moduleid);
            }
            else
            {
                continue;
            }
        }
    }
}

/****按照与启动时相反的顺序以阻塞主线程的方式等待线程结束*****/
void block_module_queue(void)
{
    int init_right = 0;
    int moduleid = 0;

    for(init_right = INIT_RIGHT_END - 1; init_right > INIT_RIGHT_START; init_right--)
    {
        for(moduleid = THREAD_END_ID - 1; moduleid > THREAD_ZERO_ID; moduleid--)
        {
            if((thread_info[moduleid].init_pri== init_right)&&(moduleid != THREAD_MAIN_ID))
            {
                if(strcmp(thread_info[moduleid].thread_name,"null"))
                {
                pthread_join(thread_info[moduleid].task_id,NULL);
                }
            }
        }
    }
}

/***************模块管理的入口函数**********************/
void init_module_manager(void)
{
    startup_module_flowline();
    block_module_queue();
}

/******************************************************************
   *  函数名:          mod_if_register_module
   *  功能:           模块注册函数
       *  输入参数: thread_id:模块ID号
                    init_right:初始化优先级(模块启动顺序)
                    task_right:任务优先级(线程优先级 1~99)
                    thread_name:模块名
                    init_func:模块初始化入口(申请消息队列和信号量，初始化全局变量)
                    task_func:模块主函数入口
                    policy: 线程的调试策略(SCHED_FIFO, SCHED_OTHER, SCHED_RR)
******/
int mod_if_register_thread(int thread_id,int init_right,int task_right,char * thread_name,PF_INIT_FUNC init_func,PF_TASK_MAIN func_entry, int policy)
{
if(thread_id >= THREAD_END_ID)
    {
        printf("module error!!!\n");
        return -1;
    }
    if((task_right < 1) ||(task_right > 99))
    {
                printf("The value of task priority should between 1 and 99!\n");
        while(1);
    }

if((thread_info[thread_id].thread_id == 0)&&(thread_info[thread_id].init_pri ==0)
        &&(thread_info[thread_id].task_pri == 0)&&(strcmp(thread_info[thread_id].thread_name,"null") == 0)
        &&(thread_info[thread_id].init_func == NULL)&&(thread_info[thread_id].task_func == NULL))
    {
        thread_info[thread_id].thread_id= thread_id;
        thread_info[thread_id].init_pri= init_right;
        thread_info[thread_id].task_pri= task_right;
        strcpy(thread_info[thread_id].thread_name,thread_name);
        thread_info[thread_id].init_func= init_func;
        thread_info[thread_id].task_func= func_entry;
        thread_info[thread_id].policy = policy;
    }
    else
    {
        printf("Registered module ID!\n");
        while(1);
    }

}