#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<bits/stdc++.h>
using namespace std;
map<char,string> password;

typedef struct ht
{
    int weight;
    char data;
    struct ht *next;
    struct ht *lchild;
    struct ht *rchild;
} HT;
HT *InitHT() //初始化
{
    HT *huffman = (HT *)malloc(sizeof(HT));
    huffman->next = NULL;
    huffman->lchild = huffman->rchild = NULL;
    return huffman;
}
void InsertHuffman(HT *huffman, HT *node) //插入元素
{
    HT *p = huffman;
    HT *q = p->next;
    while (q && node->weight > q->weight) //保证有序
    {
        p = q;
        q = q->next;
    }
    node->next = q;
    p->next = node;
}
HT *DelLink(HT *huffman, int index) //取出第index元素并从链表中删除
{
    HT *p, *s;
    int i = 0;
    p = huffman;
    while (i < index - 1 && p->next != NULL)
    {
        i++;
        p = p->next;
    }
    if (i != index - 1 || p->next == NULL)
    {
        printf("删除位置非法");
    }
    s = p->next;
    p->next = s->next;
    // free(s);
    return s;
}
void PrintTree(HT *huffman) //打印哈夫曼树用（）判别子树
{
    if (huffman != NULL)
    {
        printf("%d", huffman->weight);
        if (huffman->lchild != NULL || huffman->rchild != NULL)
        {
            printf("(");
            PrintTree(huffman->lchild);
            if (huffman->rchild != NULL)
                printf(",");
            PrintTree(huffman->rchild);
            printf(")");
        }
    }
}
HT *CreateHuffmanTree(HT *huffman, int n) //创建哈夫曼树
{
    HT *min1, *min2, *p;
    HT *node;
    int w_sum, i;
    p = huffman;
    for (int i = 1; i < n; i++)
    {
        min1 = DelLink(p, 1); //取出最小的两个元素进行运算
        min2 = DelLink(p, 1);
        w_sum = min1->weight + min2->weight;
        node = (HT *)malloc(sizeof(HT));
        node->lchild = min1;
        node->rchild = min2;
        node->weight = w_sum;

        InsertHuffman(huffman, node);
    }
    return node;
}
void Huffman_code(HT *tree, int len) //哈夫曼编码
{ 
    if (!tree)
    {
        return;
    }
    static int a[20];
    int i;
    if (!tree->lchild && !tree->rchild)
    {   string s;
        printf("%c的哈夫曼编码为: ", tree->data);
        for (int i = 0; i < len; i++)
        {   s+=a[i];
            printf("%d", a[i]);
        }
        password[tree->data]=s;
        printf("\n");
    }
    else
    {
        a[len] = 0;
        Huffman_code(tree->lchild, len + 1);
        a[len] = 1;
        Huffman_code(tree->rchild, len + 1);
    }
}

int main()
{
    HT *ht = InitHT(); //初始化链表
    HT *tree;
    int num, w, i; //长度
    char data;
    HT *htt = InitHT();
    HT *treee;

    printf("请输入读取文件地址!");
    char path[128];
    char buf[512];
    int flag[128];
    int flag_len = 0;
    FILE *fp,*fq;
    scanf("%s", path);
    if ((fp=fopen(path, "r"))==NULL)
    {
        printf("open file error！\n");
    }
    while ((fread(buf, sizeof(char),512,fp))!=0)
    {
        memset(flag, 0, sizeof(flag));
       
        for (int i = 0; i < strlen(buf); i++)
        {
            if (flag[buf[i]] == 0)
            {
                flag_len++;
            }
            flag[buf[i]]++;
        }

        for (int i = 0; i < 128; i++)
        {
            if (flag[i] != 0)
            {
                HT *node = (HT *)malloc(sizeof(HT));
                node->data = (char)i;
                node->weight = flag[i];
                printf("%c %d\n", node->data, node->weight);
                InsertHuffman(htt, node);
            }
        }
        memset(buf, 0, sizeof(buf));
    }
    printf("******************\n");
    treee = CreateHuffmanTree(htt, flag_len);
    printf("哈夫曼树:");
    PrintTree(treee);
    printf("\n");
    Huffman_code(treee, 0);
    fclose(fp);
    if ((fp=fopen(path, "r"))==NULL)
    {
        printf("open file error！\n");
    }
    if((fq=fopen("./2.txt","a+"))==0)
    while ((fread(buf, sizeof(char),512,fp))!=0)
     {
         for (i=0;i<strlen(buf);i++)
          {
            fwrite(password[buf[i]].c_str(),)
          }
     }
    return 0;
}
