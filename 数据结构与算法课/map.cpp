#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
#define MAXVEX 20
#define INFINITY 32767
int visited[MAXVEX] = {0};
int simple_path;
typedef struct AdjMartix
{
  int arcs[MAXVEX][MAXVEX]; // 关系
  char vex[MAXVEX];         // 顶点
  int vexnum;               // 顶点个数
  int arcnum;               // 边个数
} AdjMartix;

typedef struct ArcNode
{
  int adjvex;
  int weight;
  struct ArcNode *next;
}ArcNode;
typedef struct VertexNode
{
  char vexdata;
  ArcNode *head;
}VertexNode;
typedef struct AGraph
{
  VertexNode adjlist[MAXVEX]; //邻接表
  int vernum;  //顶点数
  int arcnum;  //边数
}AGraph;

int LocateVex(AdjMartix *G, char v) // 定位点在vex数组里的位置
{
  for (int i = 1; i <= G->vexnum; i++)
  {
    if (v == G->vex[i])
    {
      return i;
    }
  }
  return 0;
}
void CreatebyMartix(AdjMartix *G) // 创建邻接矩阵
{
  int i, j, k, weight = 0;
  char vex1, vex2;
  printf("请输入无向网的点数及无向网的边数!\n");
  scanf("%d %d", &G->vexnum, &G->arcnum);
  getchar();
  for (int i = 1; i <= G->vexnum; i++)
    for (int j = 1; j <= G->vexnum; j++)
    {
      G->arcs[i][j] = INFINITY;
    }
  printf("请输入无向网的%d个顶点", G->vexnum);
  for (i = 1; i <= G->vexnum; i++)
  {
    scanf("%c", &G->vex[i]);
  }
  getchar();
  printf("请输入无向网%d条边\n", G->arcnum);
  for (k = 1; k <= G->arcnum; k++)
  {
    printf("No.%d条边顶点V:", k);
    scanf("%c", &vex1);

    getchar();
    printf("<--->顶点V:");
    scanf("%c", &vex2);

    getchar();
    printf("两条边的距离:");
    scanf("%d", &weight);
    getchar();
    i = LocateVex(G, vex1);
    j = LocateVex(G, vex2);
    G->arcs[i][j] = weight;
    G->arcs[j][i] = weight;
  }
}
int FirstAdjVex(AdjMartix *G, int v0) // 图g中v0的第一个邻接点
{
  for (int i = 1; i <= G->vexnum; i++)
  {
    if (G->arcs[v0][i] != INFINITY)
      return i;
  }
  return -1;
}
int NextAdjVex(AdjMartix *G, int v0, int begin) // 图g中顶点v0的下一个邻接点
{
  for (int i = begin + 1; i <= G->vexnum; i++)
  {
    if (G->arcs[v0][i] != INFINITY)
      return i;
  }
  return -1;
}
void DFS(AdjMartix *G, int v0) // 深搜 （递归版)
{
  int w;
  printf("%c", G->vex[v0]);
  visited[v0] = 1;
  w = FirstAdjVex(G, v0);
  while (w != -1)
  {
    if (!visited[w])
    {
      DFS(G, w);
    }
    w = NextAdjVex(G, v0, w);
  }
}
void DFS_notraverseG(AdjMartix *G, int v0)
{
  int w;
  stack<int> s;
  s.push(v0);
  while (!s.empty())
  {
    int v = s.top();
    s.pop();
    if (!visited[v])
    {
      printf("%c ", G->vex[v]);
      visited[v] = 1;
    }
    w = FirstAdjVex(G, v);
    while (w != -1)
    {
      if (!visited[w])
        s.push(w);
      w = NextAdjVex(G, v, w);
    }
  }
}
void TraverseG_DFS(AdjMartix *G) //(对每个点进行深搜，可判断是否为连通图)
{
  int cnt = 0;
  for (int v = 0; v <= G->vexnum; v++)
  {
    visited[v] = 0;
  }
  for (int i = 1; i <= G->vexnum; i++)
  {
    if (!visited[i])
    {
      printf("begin from :%c  :", G->vex[i]);
      // DFS(G,i);
      DFS_notraverseG(G, i);
      printf("\n");
      cnt++;
    }
  }
  if (cnt == 1)
  {
    printf("此图为连通图\n");
  }
  else
  {
    printf("此图有%d个联通子图\n", cnt);
  }
}

void BFS(AdjMartix *G, int v0)
{
  queue<int> q;

  printf("%c", G->vex[v0]);
  visited[v0] = 1;
  q.push(v0);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    int w = FirstAdjVex(G, v);
    while (w != -1)
    {
      if (!visited[w])
      {
        printf("%c", G->vex[w]);
        visited[w] = 1;
        q.push(w);
      }
      w = NextAdjVex(G, v, w);
    }
  }
}
void TraverseG_BFS(AdjMartix *G)
{
  for (int i = 1; i <= G->vexnum; i++)
    visited[i] = 0;
  for (int v = 1; v <= G->vexnum; v++)
    if (!visited[v])
    {
      printf("begin from :%c  :", G->vex[v]);
      BFS(G, v);
      printf("\n");
    }
}

void judge_single_path(AdjMartix *G,int begin,int end,int visit[],char path[],int index)
{
     visit[begin]=1;
     path[index++]=begin;
     if(begin==end)
     { simple_path++;
       printf("%c -> %c 的第%d条路:",G->vex[0],end,simple_path);
      for(int i=0;i<index;i++)
      {
        cout<<G->vex[path[i]]<<" ";
      }
      cout<<endl;
      return ;
     }
     int w=FirstAdjVex(G,begin);
     while(w!=-1)
     {
       if(!visit[w])
       {
        judge_single_path(G,w,end,visit,path,index);
        visit[w]=0;
       }
       w=NextAdjVex(G,begin,w);
     }


}
void Judge_single_path(AdjMartix *G)
{ 
  char begin,end;
  int visit[MAXVEX]={0};
  char path[MAXVEX]={'\0'};
  printf("请输入起点v1:");
  scanf("%c",&begin);
  getchar();
  printf("\n");
  printf("请输入终点:v2");
  scanf("%c",&end);
  getchar();
  begin=LocateVex(G,begin);
  end=LocateVex(G,end);
  if(begin==end)
  {  
    cout<<G->vex[begin]<<endl;
    return;
  }
  else
  {
  judge_single_path(G,begin,end,visit,path,0);
  if(simple_path==0)
  {
    printf("从%c -》 %c没有简单路径",G->vex[begin],G->vex[end]);
  }
  }
}


//邻接表
AGraph * Create_Graph()
{ int m,n,k;
  AGraph*G;
  ArcNode*s;
  G=(AGraph *)malloc(sizeof(AGraph));
  int i;
  printf("请输入顶点数和边数(例如3 4\n");
  scanf("%d %d",&G->vernum,&G->arcnum);
  printf("请输入%d个顶点的信息",G->vernum);
  for(int i=1;i<=G->vernum;i++)
   {
    cin>>G->adjlist[i].vexdata;
    G->adjlist[i].head=NULL;
   }
  printf("请输入%d条边的信息 i j weight",G->arcnum);
  for(int j=1;j<=G->arcnum;j++)
   {
    cin>>m>>n>>k;
    s=(ArcNode *)malloc(sizeof(ArcNode));
    s->adjvex=n;
    s->next=G->adjlist[m].head;     //头插法
    s->weight=k;
    G->adjlist[m].head=s;

    s=(ArcNode *)malloc(sizeof(ArcNode));
    s->adjvex=m;
    s->next=G->adjlist[n].head;
    s->weight=k;
    G->adjlist[n].head=s;
    }
    // cout<<"邻接表如下:"<<endl;
    // for(int i=1;i<=G->vernum;i++)
    // {
    //   ArcNode *p=G->adjlist[i].head;
    //   while (p!=NULL)
    //   {
    //     cout<<"<"<<G->adjlist[i].vexdata<<","<<G->adjlist[p->adjvex].vexdata<<">";
    //     p=p->next;
    //   }
    //   cout<<endl;
    // }
  return G;
}

void DFS_bygraph(AGraph*G,int v)
{
   ArcNode* p;
   visited[v]=1;
   printf("%c",G->adjlist[v].vexdata);
   ArcNode * w=G->adjlist[v].head;
   while(w!=NULL)  
   {
     if(!visited[w->adjvex])
     {
      visited[w->adjvex]=1;
      DFS_bygraph(G,w->adjvex);
     }
     w=w->next;
   } 
}
void TraverseG_DFS_bygraph(AGraph *G) //(对每个点进行深搜，可判断是否为连通图)
{
  int cnt = 0;
  for (int v = 0; v <= G->vernum; v++)
  {
    visited[v] = 0;
  }
  for (int i = 1; i <= G->vernum; i++)
  {
    if (!visited[i])
    {
      printf("begin from :%c  :", G->adjlist[i].vexdata);
      // DFS(G,i);
      DFS_bygraph(G, i);
      printf("\n");
      cnt++;
    }
  }
  if (cnt == 1)
  {
    printf("此图为连通图\n");
  }
  else
  {
    printf("此图有%d个联通子图\n", cnt);
  }
}
void BFS_byGraph(AGraph *G,int v)
{ 
  queue <int> q;
  printf("%c",G->adjlist[v].vexdata);
  visited[v]=1;
  q.push(v);
  while(!q.empty())
   {
    int tmp=q.front();
    q.pop();
    ArcNode *p=G->adjlist[tmp].head;
    while(p!=NULL)
    {
      if(visited[p->adjvex]==0)
      {
        printf("%c",G->adjlist[p->adjvex].vexdata);
        visited[p->adjvex]=1;
        q.push(p->adjvex);
      }
      p=p->next;

    }
   }
}
void TraverseG_BFS_byGraph(AGraph *G)
{
  for (int i = 1; i <= G->vernum; i++)
    visited[i] = 0;
  for (int v = 1; v <= G->vernum; v++)
    if (!visited[v])
    {
      printf("begin from :%c  :", G->adjlist[v].vexdata);
      BFS_byGraph(G, v);
      printf("\n");
    }
}



void judge_single_path_Graph(AGraph*G,int begin,int end,int visit[],char path[],int index)
{
     visit[begin]=1;
     path[index++]=begin;
     if(begin==end)
     { simple_path++;
       printf("%c -> %c 的第%d条路:",G->adjlist[0].vexdata,end,simple_path);
      for(int i=0;i<index;i++)
      {
        cout<<G->adjlist[path[i]].vexdata<<" ";
      }
      cout<<endl;
      return ;
     }
     ArcNode *w=G->adjlist[begin].head;
     while(w!=NULL)
     {
       if(!visit[w->adjvex])
       {
        judge_single_path_Graph(G,w->adjvex,end,visit,path,index);
        visit[w->adjvex]=0;
       }
       w=w->next;
     }


}
void Judge_single_path_Graph(AGraph *G)
{ 
  int begin,end;
  int visit[MAXVEX]={0};
  char path[MAXVEX]={'\0'};
  printf("请输入起点v1:");
  scanf("%d",&begin);
  printf("\n");
  printf("请输入终点:v2");
  scanf("%d",&end);
  if(begin==end)
  {  
    cout<<G->adjlist[begin].vexdata<<endl;
    return;
  }
  else
  {
  judge_single_path_Graph(G,begin,end,visit,path,0);
  if(simple_path==0)
  {
    printf("从%c -》 %c没有简单路径",G->adjlist[begin].vexdata,G->adjlist[end].vexdata);
  }
  }
}
int main()
 {
// printf("邻接矩阵:\n");
//    AdjMartix G;
//    CreatebyMartix(&G);
//    printf("DFS:");
//    TraverseG_DFS(&G);
//    printf("BFS");
//    TraverseG_BFS(&G);
//    Judge_single_path(&G);
//   printf("邻接表:\n");
  AGraph *Gp;
  Gp=Create_Graph();
  memset(visited,0,sizeof(visited));
  printf("DFS:");
  TraverseG_DFS_bygraph(Gp);
  printf("\n");
  memset(visited,0,sizeof(visited));
  printf("BFS:");
  TraverseG_BFS_byGraph(Gp);
  Judge_single_path_Graph(Gp);


}
