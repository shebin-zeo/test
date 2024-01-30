#include <stdio.h>
#include <conio.h>
	int n,i,j,front=0,rear=0,x=1,v,flag=0;
	int visited[10],queue[10],cost[10][10],newarr[10];
	void bfs(int);
void main()
{

	//clrscr();

	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	 for(i=1;i<=n;++i)
	 {
		queue[i]=0;
		visited[i]=0;
	 }

	printf("Enter cost adjacency matrix\n");
	for (i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			printf("Enter cost( %d,%d )\n",i,j);
			scanf("%d",&cost[i][j]);
			cost[j][i]=cost[i][j];
		}
	}
	for (i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	printf("Enter the starting vertex\n");
	scanf("%d",&v);
	visited[v]=1;
	front++;
	rear++;
	queue[rear]=v;
	newarr[x]=v;
	bfs(v);
	printf("\nVisited array\n");
	for(j=1;j<=n;++j)
	{
		if(visited[j]==1)
			printf("%d ",j);
		else
		{
			printf("\nNo Spanning tree\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nNew array\n");
		for(j=1;j<=n;++j)
		{
			printf("%d ",newarr[j]);
		}
	}
	getch();
}


void bfs(int v)
{
	for (i=1;i<=n;++i)
	{
		if( cost[v][i]!=0 && visited[i]==0)
		      {
			rear++;
			queue[rear]=i;
			visited[queue[rear]]=1;
			x++;
			newarr[x]=queue[rear];
		      }
		}
			if(front<=rear)
			{
			    bfs(queue[front++]);
			}
}