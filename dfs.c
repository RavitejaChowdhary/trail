#include<stdio.h>
#include<stdlib.h>
#define INF 999999
int graph[6][6]={{0,73,0,18,0,0},{73,0,22,0,21,0},{0,22,0,11,44,44},
{18,0,11,0,0,32},{0,21,44,0,0,45},{0,0,44,32,45,0}};
char dfs[10];int stack[10];int k,top=-1;int i=0;int visited[6]={0,0,0,0,0,0};int f=0;
void push(int item)
{  top++;stack[top]=item;}
int pop()
{int h=stack[top];top--;return h;}
void dfs_traversal(int start)
{push(start);
while(i!=6)
{k=pop();visited[k]=1;dfs[i]=k;i++;
    for(int l=0;l<6;l++)
    {if(graph[k][l]!=0 && visited[l]!=1)
        {
           for(int y=0;y<=top;y++)
           {  if(stack[y]==l)
                 f=1;
           }
           if(f!=1)
               push(l);
        }
    }
}
printf("the dfs traversal order is ");
for(int h=0;h<6;h++)
{
    printf(" %d ",dfs[h]);
}
}
void main()
{
dfs_traversal(2);
} 
