section .data
    msg db 'my name is czxxx', 0
    buf resb 1; 分配1字节的空间，用于读取用户输入

section .text
    global _start

_start:
    ; 显示消息
    mov eax, 4 ; 系统调用号为 4 (write)
    mov ebx, 1 ; 文件描述符 1 是标准输出
    mov ecx, msg ; 消息字符串的地址
    mov edx, 28 ; 消息字符串的长度
    int 0x80 ; 调用系统调用

    ; 等待中断
    mov eax, 3 ; 系统调用号为 3 (read)
    mov ebx, 0 ; 文件描述符 0 是标准输入
    mov ecx, buf ; 输入缓冲区的地址
    mov edx, 1 ; 缓冲区的大小
    int 0x80 ; 调用系统调用

    ; 退出程序
    mov eax, 1 ; 系统调用号为 1 (exit)
    xor ebx, ebx ; 返回值为 0
    int 0x80 ; 调用系统调用