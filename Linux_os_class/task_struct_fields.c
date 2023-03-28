#include <linux/bpf.h>
#include <linux/version.h>
#include <linux/kprobes.h>
#include <linux/sched.h>

#define MAX_FIELD_NAME_LEN 64
#define MAX_FIELD_SIZE 64

#define FIELD_OFFSET(type, field) ((unsigned long)(&((type *)0)->field))

struct field_desc {
    char name[MAX_FIELD_NAME_LEN];
    unsigned int size;
    unsigned int offset;
};

struct task_struct_fields {
    struct field_desc fields[10];
};

static struct task_struct_fields fields = {
    {
        {"pid", sizeof(pid_t), FIELD_OFFSET(struct task_struct, pid)},
        {"tgid", sizeof(pid_t), FIELD_OFFSET(struct task_struct, tgid)},
        {"comm", sizeof(char[MAX_COMM_LEN]), FIELD_OFFSET(struct task_struct, comm)},
        {"state", sizeof(long), FIELD_OFFSET(struct task_struct, state)},
        {"prio", sizeof(int), FIELD_OFFSET(struct task_struct, prio)},
        {"static_prio", sizeof(int), FIELD_OFFSET(struct task_struct, static_prio)},
        {"normal_prio", sizeof(int), FIELD_OFFSET(struct task_struct, normal_prio)},
        {"policy", sizeof(int), FIELD_OFFSET(struct task_struct, policy)},
        {"mm", sizeof(struct mm_struct *), FIELD_OFFSET(struct task_struct, mm)},
        {"stack", sizeof(struct thread_info *), FIELD_OFFSET(struct task_struct, stack)},
    }
};

static int kprobe__task_switch(struct pt_regs *ctx, struct task_struct *prev)
{
    char fmt[MAX_FIELD_NAME_LEN * 2 + 16];
    char buf[MAX_FIELD_SIZE];
    int i, ret;

    for (i = 0; i < 10; i++) {
        struct field_desc *field = &fields.fields[i];
        snprintf(fmt, sizeof(fmt), "%s: %%#lx\\n", field->name);
        ret = bpf_probe_read(buf, field->size, (void *)((unsigned long)prev + field->offset));
        if (ret == 0) {
            printk(fmt, *((unsigned long *)buf));
        }
    }

    return 0;
}

static int kprobe__task_exit(struct pt_regs *ctx, struct task_struct *prev)
{
    char fmt[MAX_FIELD_NAME_LEN * 2 + 16];
    char buf[MAX_FIELD_SIZE];
    int i, ret;

    for (i = 0; i < 10; i++) {
        struct field_desc *field = &fields.fields[i];
        snprintf(fmt, sizeof(fmt), "%s: %%#lx\\n", field->name);
        ret = bpf_probe_read(buf, field->size, (void *)((unsigned long)prev + field->offset));
        if (ret == 0) {
            printk(fmt, *((unsigned long *)buf));
        }
    }

    return 0;
}

static struct kprobe task_switch_kp = {
    .symbol_name = "finish_task_switch",
    .pre_handler = kprobe__task_switch,
};

static struct kprobe task_exit_kp = {
    .symbol_name = "do_exit",
    .pre_handler = kprobe__task_exit,
};

static int __init task_struct_fields_init(void)
{
    int ret;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 17, 0)
    task_switch_kp.flags |= KPROBE_FLAG_EXTENDED_REGS;
    task_exit_kp.flags |= KPROBE_FLAG_EXTENDED_REGS;
#endif

    ret = register_kprobe(&task_switch_kp);
    if (ret < 0) {
        printk("Error registering task_switch kprobe\n");
        return ret;
    }

    ret = register_kprobe(&task_exit_kp);
    if (ret < 0) {
        printk("Error registering task_exit kprobe\n");
        unregister_kprobe(&task_switch_kp);
        return ret;
    }

    printk("task_struct_fields module loaded\n");

    return 0;
}

static void __exit task_struct_fields_exit(void)
{
    unregister_kprobe(&task_switch_kp);
    unregister_kprobe(&task_exit_kp);
    printk("task_struct_fields module unloaded\n");
}

module_init(task_struct_fields_init);
module_exit(task_struct_fields_exit);
MODULE_LICENSE("GPL");