#include <stdio.h>
#include <string.h>
#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "pthread_module.h"

/*******************线程1执行的入口函数******/
void *thread_one_main(void* arg) 
{
    while(true)
    {   
        sleep(3);       
        printf("MODULE ONE main func++++++++++++\n");
    }
}

/*******************线程2执行的入口函数******/
void *thread_two_main(void* arg) 
{
    while(true)
    {
        printf("MODULE TWO main func------------\n");
        sleep(3);
    }
}
/*******************主函数main******************/
int main(void)
{
    init_main_thread_info();
    init_thread_list();

    mod_if_register_thread(THREAD_ONE_ID,
                            INIT_TOP_RIGHT,
                            1,
                            const_cast<char *>("test thread1~~~"),
                            NULL,
                            thread_one_main,
                            SCHED_OTHER);
    mod_if_register_thread(THREAD_TWO_ID,
                            INIT_TOP_RIGHT,
                            3,
                            const_cast<char *>("test thread2~~~"),
                            NULL,
                            thread_two_main,
                            SCHED_OTHER);
    init_module_manager();
}