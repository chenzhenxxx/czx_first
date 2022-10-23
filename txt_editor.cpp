#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 100
#define NOT_FOUND -1
//定义行结构体：
struct line
{
	char text[MAX_LEN]; //本行文本
	int num;			//行号
	struct line *next;	//指向下一个行的指针
	struct line *prior; //指向前一个行的指针
};
int lnum;
char filename[512];
struct line *start;									  //指向线性表中第一行的指针
struct line *last;									  //指向线性表中最后一行的指针
struct line *find(int);								  //查找指定行是否存在
void patchup(int, int);								  //对当前行以后的每行的行号加1或
void delete_text(int);								  //删除一行文字
void List();										  //显示文件的全部内容
void save();										  //保存文件
void load();										  //打开文件，初始化线性表
void insert(char str[], int linenum, int position);	  //插入文字到一行的中间
void printline(int linenum);						  //打印一行文字
void deletestr(int linenum, int position, int lenth); //删除一个字符串
int findstr(char *to_find);							  //查找字符串
int findstr_pos(char *to_find,int row,int col);       
int menu_select();									  //显示主菜单
int menu_select_insert();							  //显示插入功能子菜单
int menu_select_delete();							  //显示删除功能子菜单
int menu_select_print();							  //显示打印功能子菜单
int menu_select_move();								  //显示移动功能子菜单
void enter(int linenum);							  //插入一行文字
void enter_empty(int linenum);						  //插入一个空白行

//下列函数是系统主函数，提供系统主界面，通过选择项转入执行插入、删除、查存盘、读人文件等功能的界面。
int main(void)
{
	char str[MAX_LEN];
	int choice;
	int linenum = 1;
	int number = 0;
	start = NULL;
	last = NULL;
	printf("请输入要操作的文件完全路径!\n");
	cin>>filename;
	load(); //打开文件，初始化线性表
	do
	{
		choice = menu_select();
		switch (choice)
		{
		case 1:							   //插入
			choice = menu_select_insert(); //显示插入子菜单
			switch (choice)
			{
			case 1: //插入一行
				printf("\t行号:");
				scanf("%d", &linenum);
				enter(linenum);
				break;
			case 2: //插入到指定行的指定列
				printf("输入插入位置一行号：");
				scanf("%d", &linenum);
				printf("输入插入位置-列号：");
				scanf("%d", &number);
				printf("要插入的字符串：");
				scanf("%s", str);
				insert(str, linenum, number);
				break;

			case 3: //退出插入
				break;
			}
			break;
		case 2:							   //删除
			choice = menu_select_delete(); // 删除子菜单
			switch (choice)
			{
			case 1: //删除指定行
				printf("\t行号:");
				scanf("%d", &linenum);
				delete_text(linenum);
				break;
			case 2: //删除指定的字符串
				printf("要删除的字符串：");
				scanf("%s", str);
				number = findstr(str);
				if (number == NOT_FOUND) //没找到
				{
					printf("没有找到");
				}
				else //循环删
				{
					deletestr(lnum, number, strlen(str));
					while ((number = findstr(str)) != -1)
					{
						deletestr(lnum, number, strlen(str));
					}
				}

				break;
			case 3: //退出删除
				break;
			}
			break;
		case 3:							  //执行打印功能
			choice = menu_select_print(); //显示子菜单
			switch (choice)
			{
			case 1: //打印某一行
				printf("\t行号:");
				scanf("%d", &linenum);
				printline(linenum);
				break;
			case 2: //显示全部
				List();
				break;
			case 3: //退出显示
				break;
			}
			break;
		case 4: //执行查找功能
			printf("输入想要查找的字符串：");
			scanf("%s", str);
			number = findstr_pos(str,1,1);
			if (number == NOT_FOUND)
				printf("没有找到");
			else
                {  int tmp_lnum=lnum;
		           int tmp=number+strlen(str);
				printf("要查找的字符串所在行号:%d，列号:%d\n", lnum, number);
				 while((number=findstr_pos(str,lnum,tmp))!=-1) //循环查找
				 {   
					 if(tmp_lnum!=lnum) //这次与上次行数不同
					 { 
					 number-=(tmp-1);
					 tmp=number+strlen(str);
					 }
					 else
					 tmp=number+strlen(str);
                     printf("要查找的字符串所在行号:%d，列号:%d\n", lnum, number);
					 tmp_lnum=lnum; 
					 
				 }
				}
			break;
		case 5: //执行替换功能
			printf("输入被替换的字符串：");
			scanf("%s", str);
			number = findstr(str);
			if (number == NOT_FOUND)
				printf("没有找到");
			else
			{    char tmp[MAX_LEN];
				deletestr(lnum, number, strlen(str));
				printf("要替换的字符串：");
				scanf("%s",&tmp);
				insert(tmp, lnum, number + 1);
				while ((number = findstr(str) )!= -1)
				{
					deletestr(lnum, number, strlen(str));
					insert(tmp, lnum, number + 1);
				}
			}
			break;

		case 6:							 //执行移动功能
			choice = menu_select_move(); //移动子菜单
			switch (choice)
			{
			case 1: // 向下移动一行
				printf("输人要移动的字符串所在行号：");
				scanf("%d", &linenum);
				enter_empty(linenum);
				break;
			case 2: //向上移动一行
				printf("输入要移动的字符串所在行号：");
				scanf("%d", &linenum);
				delete_text(linenum - 1);
				break;
			case 3: //向右移动一列
				printf("输人要移动的字符串所在行号：");
				scanf("%d", &linenum);
				printf("输入要移动的字符串所在列号：");
				scanf("%d", &number);
				str[0] = ' ';
				str[1] = '\0';
				insert(str, linenum, number);
				break;
			case 4: //向左移动
				printf("输入要移动的字符串所在行号：");
				scanf("%d", &linenum);
				printf("输入要移动的字符串所在列号：");
				scanf("%d", &number);
				if (number <= 0)
					printf("该列不存在");
				else
					deletestr(linenum, number - 2, 1);
				break;
			case 5: //退出移动
				break;
			}
			break;
		case 7: //保存
			save(); //保存
			load(); //重新刷新打开文本
			break;
		case 8: //执行退出功能
			exit(0);
			break;
		default:
		    printf("输入非法,请重新输入!\n");
			break;
		}
	} while (1);
	return 0;
}
//下列函数是主菜单功能的提示界面，其功能是说明主菜单中选项
int menu_select()
{
	int c;
	printf("\n1.插入字符串\n");
	printf("2.删除字符串\n");
	printf("3.显示\n");
	printf("4.查找字符串\n");
	printf("5.替换字符串\n");
	printf("6.移动行\n");
	printf("7.保存修改\n");
	printf("8.退出\n");
	do
	{
		printf("\n\n请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 9));
	return (c);
}

//下列函数是插入子菜单功能的提示界面，其功能是说明在插入菜单下选项的含义。
int menu_select_insert()
{
	int c;
	printf("\n1.插入一行文字\n");
	printf("2.插入一段文字\n");
	printf("3.返回上级菜单\n");
	do
	{
		printf("\n\n请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return (c);
}
//下列函数是删除子菜单功能的提示界面，其功能是说明在删除子菜单下选项的含义。
int menu_select_delete()
{
	int c;
	printf("\n1.删除一行文字\n");
	printf("2.删除一段文字\n");
	printf("3.返回上级菜单\n");
	do
	{
		printf("\n\n请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return (c);
}
//下列函数是显示子菜单功能的提示界面，其功能是说明在显示子菜单下选项的含义
int menu_select_print()
{
	int c;
	printf("\n1.显示一行\n");
	printf("2.全部显示\n");
	printf("3.返回上级菜单\n");
	do
	{
		printf("\n\n请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 3));
	return (c);
}
//下列函数是移动子菜单功能的提示界面，其功能是说明在移动子菜单下选项的含义
int menu_select_move()
{
	int c;
	printf("\n1.向下移动一行\n");
	printf("2.向上移动一行\n");
	printf("3.向右移动一列\n");
	printf("4.向左移动一列\n");
	printf("5.返回上级菜单\n");
	do
	{
		printf("\n\n请按数字选择：");
		scanf("%d", &c);
	} while (!(c >= 1 && c <= 5));
	return (c);
}
//下列函数的功能是在指定的行号 linenum处插入一行文字。
void enter(int linenum)
{
	struct line *info, *q, *p;
	p = start;
	q = NULL;
	while (p && p->num != linenum) //遍历找到对应行
	{
		q = p;
		p = p->next;
	}
	if (p == NULL && (q->num + 1) != linenum) //行不存在
	{
		printf("输入的行号不存在");
	}
	else //进行插入
	{
		info = (struct line *)malloc(sizeof(struct line));
		printf("输入要输入的字符串");
		scanf("%s", info->text);
		info->text[strlen(info->text)] = '\0';
		info->num = linenum;
		if (linenum == 1) //插入在第一行
		{
			info->next = p;
			p->prior = info;
			info->prior = NULL;
			start = info;
		}
		else if (q->num != linenum) //插入在最后一行
		{
			q->next = info;
			info->next = p;
			info->prior = q;
		}
		else //插入在其他行
		{
			q->next = info;
			info->next = p;
			p->prior = info;
			info->prior = q;
		}
		while (p) //如果不是插入在最后一行，插入行后面的行号都加1
		{
			p->num = p->num + 1;
			p = p->next;
		}
	}
}

//下列函数是为其他功能提供的一个辅助函数，它的功能是当文本内容插在文件中间时
//其下面的内容的行号必须增加1，而删除时，被删除的文本后面的行号必减1.
void patchup(int n, int incr)
{
	struct line *i;
	i = find(n);
	i = i->next;
	while (i)
	{
		i->num = i->num + incr;
		i = i->next;
	}
}
//下列函数的功能是在指定行处插入一个空白行。
void enter_empty(int linenum)
{
	struct line *info, *p;
	info = (struct line *)malloc(sizeof(struct line));
	if (!info)
	{
		printf("\t！内存不够！\n");
		exit(0);
	}
	info->text[0] = ' ';
	info->text[1] = '\0';
	info->num = linenum;
	if (find(linenum)) //如果要插人的行号存在，则进行插入
	{
		p = start;
		if (linenum == 1) //插入在首行
		{
			info->next = p;
			start = info;
			info->prior = NULL;
			p->prior = info;
		}
		else //插入在其他行
		{
			while (p->next->num != linenum)
				p = p->next;
			info->next = p->next;
			p->next->prior = info;
			p->next = info;
			info->prior = p;
		}
		patchup(linenum, 1);
	}
	else
		printf("该行不存在");
}

//插入到任意位置，要是插入位置和现有位置中间有间隔，会补全空格
void insert(char str[], int linenum, int position)
{
	struct line *info;
	int len, i;
	int lenth;
	char rest_str[MAX_LEN], nostr[2] = {" "};
	info = start;
	while (info && info->num != linenum) //查询要插入的行
	{
		info = info->next;
	}
	if (info == NULL)
		printf("不存在该行！\n");
	else if (position < 0)
		printf("不存在该列！\n");
	else //如果行和列都存在，则进行插入
	{
		lenth = strlen(info->text);
		if (lenth < position) //插入列大于本行文件列数
		{
			len = position - lenth - 1;
			for (i = 0; i < len; i++)
				strcat(info->text, nostr); //将空余的部分插入空格符
			strcat(info->text, str);	   //插入字符到列的未尾
		}
		else //插入列在本行文字的中间
		{
			strcpy(rest_str, &info->text[position - 1]);
			strcpy(&info->text[position - 1], str);
			strcat(info->text, rest_str);
		}
	}
}

//下列函数的功能是删除指定行、指定位置、长度为 lenth的一段文字。
void deletestr(int linenum, int position, int lenth)
{
	struct line *info;
	char rest_str[MAX_LEN];
	info = find(linenum);
	if (info == NULL)
		printf("该行没有字符！n");
	else
	{
		if (strlen(info->text) <= (position + lenth)) //本行的字符长度<=待删除的列号+删除长度，直接在当前位置插入'\0'
			info->text[position] = '\0';
		else
		{
			strcpy(rest_str, &info->text[position + lenth]);
			strcpy(&info->text[position], rest_str);
		}
	}
}
//下列函数的功能是删除指定行号 lineup的文字。
void delete_text(int linenum)
{
	struct line *info, *p;
	info = start;
	while ((info->num < linenum) && info)
		info = info->next;
	if (info->next == NULL)
		printf("该行不存在");
	else
	{
		p = info->next;
		if (start == info) //如果删除的是第一行
		{
			start = info->next;
			if (start) //如果删除后，不为空
				start->prior = NULL;
			else //删除后为空
				last = NULL;
		}
		else
		{
			info->prior->next = info->next;		 //指定行的上一行指向指定行的下一行
			if (info != last)					 //如果不是最后一行
				info->next->prior = info->prior; //修改其下一行的指向头的指针
			else								 //如果是最后一行，修改尾指针
				last = info->prior;
		}
		free(info);
		while (p)
		{
			p->num = p->num - 1;
			p = p->next;
		}
	}
}

int findstr(char *to_find) //查找文本中第一次出现的字符串位置
{
	struct line *info;
	int i = 0, find_len, found = 0, position;
	char substring[MAX_LEN];
	info = start;
	lnum = 0; //匹配到的行号
	find_len = strlen(to_find);
	while (info && !found) //查询
	{
		i = 0; //行间循环
		string s1 = info->text;
		if ((i = s1.find(to_find)) != -1)
		{
			found = 1;
			lnum = info->num;
		}
		info = info->next;
	}
	if (found) //查找成功
		position = i;
	else //查找不成功
		position = NOT_FOUND;
	return (position);
}

int findstr_pos(char *to_find,int row,int col) //查找文本中第一次出现的字符串位置
{
	struct line *info;
	int i = 0, find_len, found = 0, position;
	char substring[MAX_LEN];
	info = start;
	while(info)
	{
		if(info->num==row)
		{
           break;
		}
		info=info->next;
	}
	lnum = 0; //匹配到的行号
	find_len = strlen(to_find);
	string s1=&info->text[col-1];
	while (info && !found) //查询
	{
		i = 0; //行间循环
		if ((i = s1.find(to_find)) != -1)
		{
			found = 1;
			lnum = info->num;
		}

		info = info->next;
		if(!info)
		{
			break;
		}
		s1=info->text;
	}
	if (found) //查找成功
		position = col+i;
	else //查找不成功
		position = NOT_FOUND;
	return (position);
}

//下列函数的功能是查找指定行，如果查找成功返回结点所在的行指针。
struct line *find(int linenum)
{
	struct line *info;
	info = start;
	while (info)
	{
		if (linenum != info->num)
			info = info->next;
		else
			break;
	}
	return (info);
}

//下列函数的功能是显示指定行
void printline(int linenum)
{
	struct line *info;
	info = find(linenum);
	if (info)
		printf("%d:%s\n", info->num, info->text);
	else
		printf("该行不存在");
}
//下列函数的功能是显示线性表中的所有文本
void List()
{
	struct line *info;
	info = start;
	while (info)
	{
		printf("%d:%s\n", info->num, info->text);
		info = info->next;
	}
	printf("\n\n");
}
//下列函数的功能是把线性表中的所有文字保存到文件中
void save()
{
	struct line *info;
	char *p;
	FILE *fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t文件打不开！n");
		exit(0);
	}
	printf("正在存入文件！\n");
	info = start;
	while (info)
	{
		p = info->text;
		while (*p)
			putc(*p++, fp);
		putc('\n', fp);
		info = info->next;
	}
	fclose(fp);
}

//下列函数的功能是把文本文件中的内容读入到线性表中。
void load()
{   int choice=0;
	struct line *info, *temp; // info指向当前行，temp指向info的前驱行
	char c;
	FILE *fp;	 //文件指针
	int inct, i; //行计数器
	temp = NULL;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("文件打不开！\n");
		int choice=0;
		printf("是否创建文件(1:yes,2:no)!\n");
		cin>>choice;
		if(choice==1)
		{
			fp=fopen(filename, "wr");
			char t[10]=" ";
			fwrite(t,sizeof(char),strlen(t),fp);
			fclose(fp);
			fp=fopen(filename,"r");
		}
		else
		exit(0);
	}
	printf("正加载文件！\n");
	start = (struct line *)malloc(sizeof(struct line)); //动态生成一行的结点空间
	info = start;
	inct = 1;
	while ((c = fgetc(fp)) != EOF)
	{
		i = 0;
		info->text[i] = c;
		i++;
		while ((c = fgetc(fp)) != '\n'&&c!=EOF && info->prior == NULL) //从文件中读取一行字符到线性表中，文件中每一行以\n为结束标
		{
			info->text[i] = c;
			i++;
		}
		info->text[i] = '\0'; //线性表中每行末尾的结束标志,不然会乱码
		info->num = inct++;	  //行号和计数器都加1
		info->next = (struct line *)malloc(sizeof(struct line));
		if (!info->next)
		{
			printf("\n\t内存已经用完！");
			exit(0);
		}
		info->prior = temp;
		temp = info;
		info = info->next;
	}
	temp->next = NULL;
	last = temp;
	free(info);
	start->prior = NULL;
	fclose(fp);
	printf("加载文件成功！\n");
}