#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

static int irq = 1;  // 中断号为 1
static int dev_id;   // 设备 ID

// 中断处理函数
static irqreturn_t my_interrupt(int irq, void *dev)
{
    printk(KERN_INFO "Interrupt %d occurred\n", irq);
    return IRQ_HANDLED;
}

static int __init my_init(void)
{
    int ret;

    printk(KERN_INFO "Registering interrupt handler\n");

    // 注册中断处理函数
    ret = request_irq(irq, my_interrupt, IRQF_SHARED, "my_interrupt", &dev_id);
    if (ret)
    {
        printk(KERN_ERR "Failed to register interrupt handler\n");
        return ret;
    }

    printk(KERN_INFO "Interrupt handler registered successfully\n");
    return 0;
}

static void __exit my_exit(void)
{
    // 卸载中断处理函数
    free_irq(irq, &dev_id);
    printk(KERN_INFO "Interrupt handler unregistered\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ChatGPT");
MODULE_DESCRIPTION("A simple interrupt example");