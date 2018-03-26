//2013011703 Á¤Çö±³ 
#include<stdio.h>
#include<stdlib.h>
#define white 3
#define gray 4
#define black 5
typedef struct hdnodes* Graph;
typedef struct node* PtrToNode;
typedef PtrToNode Vertex;
struct node{
   int vertex;
   PtrToNode link;
   PtrToNode pi;
   int W;
   int done;
};
struct hdnodes{
   int count;
   PtrToNode link;
   
};




void connect(Vertex A,Vertex B,int W)
{
   Vertex new_nptr=(Vertex)malloc(sizeof(struct node));
   Vertex temp=A;
   new_nptr->W=W;
   new_nptr->vertex=B->vertex;
   while(temp->link!=NULL)
   {
      temp=temp->link;
   }
   new_nptr->link=temp->link;
   temp->link=new_nptr;
   
}

void initialization(Graph G,int n)
{
   
   int i;
   for(i=1;i<=n;i++)
   {
      Vertex temp=(Vertex)malloc(sizeof(struct node));

         temp->vertex=i;
         temp->link=(PtrToNode)malloc(sizeof(PtrToNode));
         temp->W=999;
         temp->done=0;
         temp->link=NULL;
         G[i].link=temp;
         
   }
      
 } 
 int extract_min(Graph G,int n)
 {
    int i,min,index=1;
    min=999;
    for(i=2;i<=n;i++)
    {
       if(G[i].link->W<min & G[i].link->done==0)
       {
          min=G[i].link->W;
          index=i;
       }
          
    }
    G[index].link->done=1;
    return index;
 }
 void Dijkstra(Graph G,int n)
 {
    int u,i;
    Vertex v;
    int* S=(int*)malloc(sizeof(int)*(n+1));
    v=G[1].link;
    while(v->link!=NULL)
      {
         v=v->link;
         if(G[v->vertex].link->W>v->W && G[v->vertex].link->done==0)
            G[v->vertex].link->W=v->W;
      }
    for(i=2;i<=n;i++)
    {
       u=extract_min(G,n);
       v=G[u].link;
       while(v->link!=NULL)
      {
         v=v->link;
         if(G[v->vertex].link->W > G[u].link->W+v->W && G[v->vertex].link->done==0)
            G[v->vertex].link->W=G[u].link->W+v->W;
      }
    }
 }

int main()
{
   int i,t, n,m,dest,w,max;
   int* nodes;
   Graph G;
   
   scanf("%d",&n);
   nodes=(int*)malloc(sizeof(int)*(n+2));
   
   G=(Graph)malloc(sizeof(struct hdnodes)*(n+3));
   initialization(G,n);
   
   for(i=1;i<=n;i++){
      scanf("%d %d",&nodes[i],&m);
      for(t=1;t<=m;t++){
         scanf("%d %d",&dest,&w);
         connect(G[i].link,G[dest].link,w);
      }
   }
   Dijkstra(G,n);
   max=G[2].link->W;
   for(i=2;i<=n;i++){
      if(max<G[i].link->W)
         max=G[i].link->W;
   }
   printf("%d",max);
   return 0;
      
}
