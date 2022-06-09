void hidden_password(char password[])
{
    int i = 0, flag = 0;
    char input;
    while(1)//可以控制while循环次数，但这里写成了只能通过回车结束函数使用。
    {
        if((input = getch()) != '\r')//结束条件
        {
            if(input != '\b')
            {
                *(password + i++) = input;//通过指针给数组赋值
                printf("*");//回显*号
                fflush(stdin);
                flag++;
            }
            if(input == '\b' && flag != 0)//为了不让\b \b也删除掉输入密码前的提示文字即判断flag是否为0
            {
                flag--;//如果用户想要backspace，那么flag自减
                i--;//使指针向前移动一格
                printf("\b \b");
            }
        }
        else
        {
            *(password + i) = '\0';//\0不能忘记
            fflush(stdin);
            printf("\n");
            return;//函数调用结束

        }
    }
}

