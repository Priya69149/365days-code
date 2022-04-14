//Implementation of Kruskal's Algorithm Dynamically
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define INFI 1000
int *parent;
int find(int);
int uni(int,int);
int main(){
 int i,j,a,b,u,v,n,ne=0;
 int min,mincost=0;
 int** cost;
 printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
 printf("\nEnter the no. of vertices\n");
 scanf("%d",&n);
 parent=(int *)malloc(sizeof(int)*n);
 cost=(int*)malloc(sizeof(int)*n);
 for(i=0;i<n;i++){
    cost[i]=(int *)malloc(n*sizeof(int));
 }
 printf("\nEnter the cost adjacency matrix\n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&cost[i][j]);
 if(cost[i][j]==0)
 cost[i][j]=INFI;
 }
 parent[i]=-1;
 }
 printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
 while(ne<(n-1))
 {
 for(i=0,min=INFI;i<n-1;i++) //Find current minimal weight edge
 {
 for(j=i+1;j<n;j++)
 {
 if(cost[i][j]<min)
 {
 min=cost[i][j];
 a=i;
 b=j;
 }
 }
 }
 u=find(a);
 v=find(b);
 if(uni(u,v))
 {
 printf("\n%d edge (%d,%d) =%d\n",++ne,a+1,b+1,min);
 mincost +=min;
 parent[b]=a;
 }
 //(cost+a+b)=(cost+b+a)=INFI;
 cost[a][b]=cost[b][a]=INFI;
 }
 printf("\n\tMinimum cost = %d\n",mincost);
 getch();
 return 0;
}
int find(int i)
{
 while(parent[i]!=-1)
 i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
 //parent[j]=i;
 return 1;
 }
 return 0;
}
