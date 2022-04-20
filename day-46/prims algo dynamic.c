//Implementation of Prims Algorithm Dynamically
#include<stdio.h>
#include<stdlib.h>
int main(){
int a,b,u,v,n,i,j,ne=1,min,mincost=0;
int **cost;
int* visited;
printf("\n\nImplementation of Prims Algorithm:\n");
printf("Enter the number of vertices:\n");
scanf("%d",&n);
//printf("Enter the adjancency matrix:\n");
visited=(int*)malloc(sizeof(int)*n);
cost=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
cost[i]=(int *)malloc(n*sizeof(int));
}
for(i=0;i<n;i++){
    visited[i]=0;
}
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 visited[0]=1;
 printf("\n");
 while(ne<n)
 {
  for(i=0,min=999;i<n;i++)
  {
     if(visited[i])
     {
        for(j=0;j<n;j++)
        {
           if(visited[j])
               continue;
           if(cost[i][j]<min)
           {
             min=cost[i][j];
             a=u=i;
             b=v=j;
           }
        }
     }
  }
  if(visited[u]==0 || visited[v]==0)
  {
            printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
  }
     //cost[a][b]=cost[b][a]=999;
 }
 printf("\n Minimun cost=%d",mincost);
 getch();
return 0;
}
