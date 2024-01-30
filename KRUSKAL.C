#include<stdio.h>
#include<conio.h>
int cost[10][10],i,j,ne=1,n,a,b,u,v,parent[9],min,mincost=0;
int find(int);
int unio(int,int);
int main()
{
//clrscr();
printf("ENTER THE NO. OF VERTICES\n");
scanf("%d",&n);
printf("\nENTER THE ELEMENTS\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
		printf("\ncost of the position(%d,%d)",i,j);
		scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
printf("the adjacancy matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d \t",cost[i][j]);
		}
		printf("\n");
	}
while(ne<n)
{
	for(i=0,min=999;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cost[i][j]<min)
			{
				min=cost[i][j];
				a=u=i;
				b=v=j;
			}

		}
	}
 u=find(u);
 v=find(v);
	if(unio(u,v))
	{
		ne++;
		mincost+=min;
	}

	cost[a][b]=cost[b][a]=999;
}

printf("\nMINCOST=%d",mincost);

//getch();
}
int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}
int unio(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}