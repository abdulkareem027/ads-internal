#include<stdio.h>
int knapsack(int weights[],int values[],int capacity,int n){
	int dp[n+1][capacity+1];
	for(int i=0;i<=n;i++){
		for(int w=0;w<=capacity;w++){
			if(i==0 || w==0){
				dp[i][w]=0;
			}else if(weights[i-1]<=w){
				dp[i][w] = (dp[i-1][w]>dp[i-1][w-weights[i-1]]+values[i-1])?dp[i-1][w]:(dp[i-1][w-weights[i-1]]+values[i-1]);
			}else{
				dp[i][w] = dp[i-1][w];
			}
		}
	}
	return dp[n][capacity];
}
int main(){
	int n,capacity;
	printf("Enter the no. of items: ");
	scanf("%d",&n);
	int weights[n],values[n];
	printf("Enter the weight and price of all items\n");
	for(int i=0;i<n;i++){
		scanf("%d %d",&weights[i],&values[i]);
	}
	printf("enter the capacity of knapsack: ");
	scanf("%d",&capacity);
	int max_value = knapsack(weights,values,capacity,n);
	printf("The maximum value of items that can be put into knapsack is: %d \n",max_value);
	return 0;
}
