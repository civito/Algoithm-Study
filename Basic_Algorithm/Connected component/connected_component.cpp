#include<stdio.h>
#include<stdlib.h>
#define white 3
#define gray 4
#define black 5
typedef struct hdnodes* Graph;
typedef struct node* nodePointer;
typedef nodePointer Vertex;
struct node{
   int vertex;
   nodePointer link;
   nodePointer pi;
   int present;
   int dt,ft;
   int color;
   int group;
};
struct hdnodes{
   int count;
   nodePointer link;
   
};
int gn=0;

void dfs(Graph G,int v)
{
   Vertex w;
   G[v].link->color=gray;
   G[v].link->group=gn;
   for(w=G[v].link;w;w=w->link)
   {
      if(G[w->vertex].link->color==white)
         dfs(G,w->vertex);
   }
}
void connected(Graph G,int n)
{
   int i;
   for(i=1;i<=n;i++)
   {
      if(G[i].link->color==white)
      {
         gn++;
         dfs(G,i);
      }
      
   }
}
void InsertGraph(Graph G,int X)
{   Vertex temp=(Vertex)malloc(sizeof(struct node));
   
      if(G[X].link==NULL)
      {
      
         temp->vertex=X;
         temp->link=(nodePointer)malloc(sizeof(nodePointer)*30);
         
         temp->link=NULL;
         temp->present=1;
         G[X].link=temp;
      }
}
void connect(Vertex A,Vertex B)//노드 그 자체가 아니라 노드의  
{
   Vertex new_nptr=(Vertex)malloc(sizeof(struct node));
   Vertex nptr2=(Vertex)malloc(sizeof(struct node));
   Vertex temp=A;
   new_nptr->dt=B->dt;
   new_nptr->ft=B->ft;
   new_nptr->vertex=B->vertex;nptr2->vertex=A->vertex;
   while(temp->link!=NULL)
   {
      temp=temp->link;
   }
   new_nptr->link=temp->link;
   temp->link=new_nptr;
   temp=B;
   while(temp->link!=NULL)
   {
      temp=temp->link;
   }
   nptr2->link=temp->link;
   temp->link=nptr2;
   
}


void initialization(Graph G,int n)
{
   
   int i;
   for(i=1;i<=n;i++)
   {
      Vertex temp=(Vertex)malloc(sizeof(struct node));
         temp->vertex=i;
         temp->link=(nodePointer)malloc(sizeof(nodePointer));
         temp->color=white;
         temp->link=NULL;
         temp->group=0;
         G[i].link=temp;
   }
      
 } 
int main()
{
   int i,n,max;
   int n1,n2;//node1, node2
   char fin;
   Vertex temp;
   scanf("%d",&n);
   Graph G=(Graph)malloc(sizeof(struct hdnodes)*(n+3));
   initialization(G, n);
   
   while(1)
   {
      fin=scanf("%d %d",&n1,&n2);

      connect(G[n1].link,G[n2].link);
               
      if(fin==EOF)break;
   
   }

   connected(G,n);
   printf("%d\n",gn);
   for(i=1;i<=n;i++)
      printf("%d\n",G[i].link->group);
   return 0;   
}
