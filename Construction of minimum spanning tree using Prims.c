#include<stdio.h>
int visited[20]={0};
int n;
int cost[20][20]={0};
void prims(){
	int mincost=0,edges=1,i,j,a,b;
	visited[1]=1;
	printf("Enter the cost as matrix:\n");
	int cost[n+1][n+1];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if((cost[i][j]==0)||(i==j)){
				cost[i][j]=999;
			}
		}
	}
	while(edges<n){
		int min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					if(visited[i]==1){
					min=cost[i][j];
					a=i;
					b=j;
					}
				}	
			}
		}
		if(visited[b]==0){
			printf("Edge %d=(%d,%d)\tcost=%d\n",edges++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=999;
		cost[b][a]=999;
	}
	printf("%d\n",mincost);
}
int main(){
	int ver,i,j;
	printf("Enter no of Vertices: ");
	scanf("%d",&ver);
	n=ver;
	prims();
}

