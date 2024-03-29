#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
typedef struct ht
{
    int weight;
    char data;
    struct ht *next;
    struct ht *lchild;
    struct ht *rchild;
} HT;
HT *InitHT()  //初始化
{
    HT *huffman = (HT *)malloc(sizeof(HT));
    huffman->next = NULL;
    huffman->lchild = huffman->rchild = NULL;
    return huffman;
}
void InsertHuffman(HT *huffman, HT *node)  //插入元素
{
    HT *p = huffman;
    HT *q = p->next;
    while (q && node->weight > q->weight)   //保证有序
    {
        p = q;
        q = q->next;
    }
    node->next = q;
    p->next = node;
}
HT *DelLink(HT *huffman, int index)  //取出第index元素并从链表中删除
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
void PrintTree(HT *huffman)   //打印哈夫曼树用（）判别子树
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
HT *CreateHuffmanTree(HT *huffman, int n)  //创建哈夫曼树
{
    HT *min1, *min2, *p;
    HT *node;
    int w_sum, i;
    p = huffman;
    for (int i = 1; i < n; i++)
    {
        min1 = DelLink(p, 1);             //取出最小的两个元素进行运算
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
void Huffman_code(HT *tree, int len)    //哈夫曼编码
{
    if (!tree)
    {
        return;
    }
    static int a[20];
    int i;
    if (!tree->lchild && !tree->rchild)
    {
        printf("%c的哈夫曼编码为: ", tree->data);
        for (int i = 0; i < len; i++)
        {
            printf("%d", a[i]);
        }
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
    printf("输入元素个数:");
    scanf("%d", &num);
    if(num<=0)
    {
        printf("输入非法！");
        return 0;
    }
    getchar();
    for (i = 0; i < num; i++)
    {
        printf("第%d个元素的字符:", i + 1);
        scanf("%c", &data);   
        getchar();
        printf("第%d个元素的权重:", i + 1);
        scanf("%d", &w);
        getchar();
        HT *node = (HT *)malloc(sizeof(HT));
        ;
        node->data = data;
        node->weight = w;
        InsertHuffman(ht, node);
    }
    printf("******************\n");
    tree = CreateHuffmanTree(ht, num);
    printf("哈夫曼树:");
    PrintTree(tree);
    printf("\n");
    Huffman_code(tree, 0);

    HT *htt = InitHT();
    HT *treee;
    char buf[512];
    printf("请输入字符串！\n");
    scanf("%s", buf);
    int flag[128];
    int flag_len=0;
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
    printf("******************\n");
    treee = CreateHuffmanTree(htt,flag_len);
    printf("哈夫曼树:");
    PrintTree(treee);
    printf("\n");
    Huffman_code(treee, 0);

    return 0;
}
