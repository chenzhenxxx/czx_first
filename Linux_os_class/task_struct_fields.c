#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>   //task结构体
#include <linux/fdtable.h>      //files
#include <linux/fs_struct.h>   //fs
#include <linux/mm_types.h>   //打印内存信息
#include <linux/init_task.h>   
#include <linux/types.h>
#include <linux/atomic.h>
 
MODULE_LICENSE("GPL");  //许可证
 
//入口函数
static int __init print_pcb(void)    //init宏是由init.h文件所支持
{
        struct task_struct *task,*p;
        struct list_head *pos;   //双向链表
        int count=0;          //统计当前系统进程一共有多少个
 
        printk("begin...\n");
 
        //对链表遍历时，希望从第一个开始
        task=&init_task;  //指向0号进程pcb
 
        list_for_each(pos,&task->tasks) //遍历操作，使用pos指向，传入的参数task指向tasks字段.0号进程的tasks进行遍历。tasks将所有的进程连在一块。
        {
                p=list_entry(pos,struct task_struct,tasks);    //找到一个节点，就可以用这个节点的tasks字段，找到这个结构体的地址.对应的字段tasks
                //此时的p指针已经指向task_struct结构体的首部，后面就可以通过p指针进行操作
                count++;  //找到一个进程，自加
                printk("\n\n");
                printk("pid: %d; state: %d; prior: %d; static_pri: %d; parent_pid: %d; count: %d; umask: %d; utime: %llu; stime: %llu;mm: %p\n",p->pid,p->__state,p->prio,p->static_prio,(p->parent)->pid,atomic_read(&(p->files)->count),(p->fs)->umask,p->utime,p->stime,p->mm);
        //linux中内核线程的mm是空的，要对它进行打印，就会出错，指针错误
        if((p->mm)!=NULL)
                printk("Total_vm: %ld",(p->mm)->total_vm);      //线性区总的页数
 
        }
 
        printk("进程的个数:%d\n",count);
 
        return 0;
}
 
static void __exit exit_pcb(void)    //出口函数
{
        printk("Exiting...\n");
}
 
// 指明入口点与出口点，入口/出口点是由module.h支持的
 
module_init(print_pcb);
module_exit(exit_pcb);

