//Author Sathvik Kumar
//TimeStamp 4-24-2022 14:26

#include <stdio.h>
#include<conio.h>
#include<time.h>									 // used to calculate the time

#define INFINITY 999


int prim(int cost[15][15], int source,int n)		 //cost[][] is the cost matrix which we are inputting mannually in the terminal
{
	int i,j,sum=0,visited[15],cmp[15],vertex[15];    //i and j are the loop variables used which represents row and column of a 2D matrix
	int min,u,v;									 
	for(i=1;i<=n;i++)
	{
		vertex[i]=source;							 //source is the starting node 
		visited[i]=0;
		cmp[i]=cost[source][i];
	}
	visited[source]=1;
	for (i=1;i<=n-1;i++)
	{
		min=INFINITY;								 // INFINITY is the value given to the nodes which are not directly connected
		for (j=1;j<=n;j++)
		if (!visited[j] && cmp[j]<min)
		{ 
			min=cmp[j];u=j;
		}
		visited[u]=1;
		sum=sum+cmp[u]; 
		printf("\n%d - > %d sum = %d",vertex[u],u,sum);
		for (v=1;v<=n;v++)
		if (!visited[v] && cost[u][v]<cmp[v])
		{
			cmp[v]=cost[u][v];
			vertex[v]=u;
		}
	} 
		return sum;									 //sum is the total cost of MST of the graph
}
	
int main()
{
	int a[15][15],n,i,j,m,source;
	//clrscr(); 
	printf("\nEnter the number of nodes");
	scanf("%d",&n); 
	printf("\nEnter the cost matrix:\n");
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	printf("\n Enter the source :");
	scanf("%d",&source); 
	
	double time_spent = 0.0;
 
    clock_t begin = clock();
    
    
	m=prim(a,source,n); 
	printf("\n\n Cost = %d",m);
	
	clock_t end = clock();
	
	
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf(" \n The elapsed time is %f seconds", time_spent);
 
	getch();
}

/*0 4 999 10 2 999 999 999
4 0 18 8 999 999 999 999
999 18 0 11 999 999 999 19
10 8 11 0 5 999 11 9
2 999 999 5 0 51 999 999
999 999 999 999 51 0 1 2
999 999 999 11 999 1 0 23
999 999 19 9 999 2 23 0 */

/*0 13 15 22 999 999 999 999 999 999 999 999
13 0 999 2 10 999 999 999 999 999 999 999
15 999 0 19 999 25 999 999 999 999 23 999 
22 2 19 0 15 16 999 999 999 999 999 999 
999 10 999 15 0 18 999 3 999 999 999 999
999 999 25 16 18 0 21 999 999 999 999 22
999 999 999 999 999 21 0 999 71 12 999 999
999 999 999 999 999 999 999 0 999 999 999 999
999 999 999 999 999 999 71 999 0 999 999 1
999 999 999 999 999 999 12 999 999 0 17 999
999 999 23 999 999 999 999 999 999 17 0 999
999 999 999 999 999 22 999 999 1 999 999 0 */