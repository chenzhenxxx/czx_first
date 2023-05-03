#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/slab.h>/* 定义内核模块参数 */
static int num_processes = 5;
module_param(num_processes, int, S_IRUGO); /* 进程控制块结构体 */
typedef struct
{
    int pid;      // 进程ID
    int priority; // 进程优先级（值越小表示优先级越高）
    struct list_head list;

} PCB;
/* 就绪队列和当前运行进程 */
struct list_head ready_queue;
PCB running_proc; /* 初始化函数 */
static int __init mymodule_init(void)
{
    printk(KERN_INFO "Module loaded\n"); /* 初始化就绪队列 */
    INIT_LIST_HEAD(&ready_queue);        /* 创建若干个进程并加入就绪队列 */
    for (int i = 0; i < num_processes; i++)
    { /* 分配进程控制块的内存 */
        PCB *proc = kmalloc(sizeof(PCB), GFP_KERNEL);
        proc->pid = i + 1;
        proc->priority = ((i % 3) + 1) * 10; // 设置不同的优先级(数值越小优先级越高)
        /* 将进程加入就绪队列尾部 */
        list_add_tail(&(proc->list), &ready_queue);
    }           /* 调度进程 */
    schedule(); // 应输出 "Switching to process 1"
    schedule(); // 应输出 "Switching to process 2"
    schedule(); // 应输出 "Switching to process 3"
    schedule(); // 应输出 "Switching to process 1"
    schedule(); // 应输出 "Switching to process 2"
    return 0;
} /* 退出函数 */
static void __exit mymodule_exit(void)
{ /* 释放就绪队列中所有进程的内存 */
    PCB *proc, *tmp;
    list_for_each_entry_safe(proc, tmp, &ready_queue, list)
    {
        list_del(&(proc->list));
        kfree(proc);
    }
    printk(KERN_INFO "Module unloaded\n");
} /* 选择下一个要执行的进程 */
PCB *select_next_proc(void)
{
    if (!list_empty(&ready_queue))
    { /* 找到优先级最高的进程 */
        PCB *next_proc = NULL;
        PCB *proc;
        list_for_each_entry(proc, &ready_queue, list)
        {
            if (next_proc == NULL || proc->priority < next_proc->priority)
            {
                next_proc = proc;
            }
        } /* 从就绪队列中删除该进程并返回其指针 */
        list_del(&(next_proc->list));
        return next_proc;
    }
    else
    { /* 就绪队列为空，返回 NULL */
        return NULL;
    }
} /* 进程调度函数 */
void schedule()
{ /* 选择下一个要执行的进程 */
    PCB *next_proc = select_next_proc();
    if (next_proc != NULL)
    { /* 切换到该进程 */
        running_proc = *next_proc;
        printk(KERN_INFO "Switching to process %d\n", running_proc.pid);
    }
    else
    {
        printk(KERN_INFO "No available process to run!\n");
    }
}
MODULE_LICENSE("GPL");
module_init(mymodule_init);
module_exit(mymodule_exit);
