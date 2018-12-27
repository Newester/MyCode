#include <string.h>
#include <semaphore.h>

#define MODULE_NAME_MAX_LEN    32       /* 定义模块名字最大长度 */

/*初始化优先级枚举*/
typedef enum
{
    INIT_RIGHT_START,

    INIT_TOP_RIGHT=1,
    INIT_HIGH_RIGHT,
    INIT_NORMAL_RIGHT,
    INIT_LOW_RIGHT,

    INIT_RIGHT_END,
}INIT_RIGHTS;

typedef void* (* PF_TASK_MAIN )(void* arg);
typedef unsigned long (* PF_INIT_FUNC )(unsigned long thread_id); 

typedef struct  ThreadCtl
{
    unsigned long thread_id; /* 线程ID   ,固定分配*/
    char thread_name[MODULE_NAME_MAX_LEN];          /* 模块名   */
    PF_INIT_FUNC init_func; /* 各个模块的初始化入口函数 */
    unsigned long task_id;   /* 模块任务ID，创建线程时，返回此值   */     
    unsigned long init_pri;/*模块的初始化优先级*/
    unsigned long task_pri; /* 各个模块的任务优先级 */
    int policy; /* 模块对应线程的调试策略*/
    PF_TASK_MAIN task_func;  /* 各个模块的任务入口函数 */
    unsigned long task_para; /* 各个模块的任务入口参数 */

} thread_ctrl_t;

typedef enum
{
    /*0模块ID预留*/
    THREAD_ZERO_ID, 
    /*特殊模块号，主线程模块ID*/
    THREAD_MAIN_ID,
    /*在此处罗列模块枚举*/
    THREAD_ONE_ID,
    THREAD_TWO_ID,

    /*模块结束ID*/ 
    THREAD_END_ID,
} MODULE_IDS;

void init_main_thread_info(void);
void init_thread_list(void);
void init_module_manager(void);
int mod_if_register_thread(int thread_id,int init_right,int task_right,char* thread_name,
                            PF_INIT_FUNC init_func,PF_TASK_MAIN func_entry, int policy);