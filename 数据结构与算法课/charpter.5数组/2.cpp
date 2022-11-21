#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
/**
左0，右1
左子树根节点 <  右 子树根节点 
节点  data, w , lchild, rchild
建立哈夫曼 （有序单链表）  
初始：循环输入字符与权值，创建节点，插入到链表中  形成一个包含8个节点的递增单链表
然后：将第一、二两个节点从单链表中删除，然后合并形成新的节点，新节点插入到有序表中，直至剩下一个节点。
可以通过递归遍历的方法得到每个字符的 哈夫曼编码
**/

//有序单链表
typedef struct Link{
  int  w;//存储整形权重
  char data;//存储char类型字符 
  struct Link *next;//指向直接后继元素的指针
  struct Link *lchild;
  struct Link *rchild;
}Link;


//初始化链表 
Link* InitLink(){
  Link* link = (Link*)malloc(sizeof(Link));//创建头结点 
  link->next = NULL;//头结点的next为空
  link->lchild = link->rchild = NULL;
  return link; 
}

//排序插入元素
void InsertLink(Link* link,Link* node){
  
  Link* p = link;
  Link* q = p->next;
  
  while(q && node->w>q->w)
  {
  	p=q;//记录位置 
  	q=q->next;
   }
   node->next = q;
   p->next = node;
  
}

//删除节点,返回被删除的节点 
Link* DelLink(Link* link,int index){
  Link *p, *s;
  int i = 0;
  p = link;
  while(i<index-1 && p->next != NULL)	//搜索指定位置前一个节点
  {
  	i++;
  	p = p->next;
  }
  if(i != index-1 || p->next == NULL)
  	printf("删除位置非法");
  s = p->next;
  p->next = s->next;

//	free(s);//释放节点 
  return s;

} 

//打印有序链表
void PrintLink(Link* link){
  Link* p = link->next;
  while(p){
  	printf("(%c,%d)",p->data,p->w);
  	p = p->next;
  }
  printf("\n");
}

//打印树
void PrintTree(Link* BT){
  if (BT != NULL)
  {
      printf("%d", BT->w); //输出根结点的值
      if (BT->lchild != NULL || BT->rchild != NULL)
      {
          printf("(");
          PrintTree(BT->lchild); //输出左子树
          if (BT->rchild != NULL)
              printf(",");
          PrintTree(BT->rchild); //输出右子树
          printf(")");
      }
  }
} 

//创建哈夫曼树 
Link* CreateHuffManTree(Link* link,int n){
  	Link *del1,*del2,*p;
  	Link* node ;
  	int w_sum,i;
  	p = link;		
  	for(i=0;i<n-1;i++){
  		
  	del1 = DelLink(p,1);//最小的元素 
  	del2 = DelLink(p,1);//第二小的元素
  	w_sum = del1->w + del2->w; //两个最小的数的和
  	
  	node = (Link*)malloc(sizeof(Link));
  	node->lchild= del1;
  	node->rchild= del2;
  	node->w = w_sum;
  	
  	InsertLink(link,node);
  				
  	}
  	return node; 
  	
}


//哈夫曼编码 
void getCoding(Link *tree,int len){
  if(!tree)
  return;
  static int a[20]; //定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
  int i;
  if(!tree->lchild && !tree->rchild){
  	printf(" %c的哈夫曼编码为：",tree->data);
  	for(i = 0; i < len; i++)
  	printf("%d",a[i]);
  	printf("\n");
  }
  else{//访问到非叶子结点时分别向左右子树递归调用，并把分支上的0、1编码保存到数组a ，的对应元素中，向下深入一层时len值增1 
  	a[len] = 0;
  	getCoding(tree->lchild, len + 1);
  	a[len] = 1;
  	getCoding(tree->rchild, len + 1);
  	
  }
}


int main(){
  Link* link = InitLink();//初始化链表
  Link* tree;
  int num,w,i;//长度
  char data;
  printf("输入元素个数:");
  scanf("%d",&num);getchar();
  for(i=0;i<num;i++){
  	printf("第%d个元素的字符:",i+1);
  	scanf("%c",&data);getchar();
  	printf("第%d个元素的权重:",i+1);
  	scanf("%d",&w);getchar();
  	Link* node = (Link*)malloc(sizeof(Link));;
  	node->data = data;node->w = w;
  	InsertLink(link,node);
  }
  printf("******************\n");
  tree = CreateHuffManTree(link,num);
  printf("哈夫曼树:"); 
  PrintTree(tree);printf("\n"); 
  getCoding(tree,0);
  return 0;
} 
