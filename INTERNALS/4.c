#include<stdio.h>
int a,b,u,n,i,j,ne=1,v;
int visited[10],min,mincost=0,cost[10][10];
int main()
{
printf("Enter the number of vertices and graph data\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
printf("(%d,%d):",i,j);
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
for(i=1;i<=n;i++)
visited[i]=0;
printf("The edges of spanning tree are\n");
visited[1]=1;
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
if(visited[i]==0)
continue;
else
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}
}
if(visited[u]==0||visited[v]==0)
{
printf("%d:edge(%d,%d)=%d\t",ne++,a,b,min);
mincost=mincost+min;
visited[b]=1;
} 
cost[a][b]=cost[b][a]=999;
}
printf("\nMinimum cost is %d\n",mincost);
return 0;
}
