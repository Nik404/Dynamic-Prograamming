#include<iostream>
using namespace std;
int num_change2(int n,int *d,int k,int **dp){
	if (n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	if(k == 0){
		return 0;
	}

	if(dp[n][k] >= 0){
		return dp[n][k];
	}
	int option1 = num_change2(n-d[0],d,k,dp);
	int option2 = num_change2(n,d + 1,k-1,dp);
	dp[n][k] = option1 + option2;
	return dp[n][k];	
}
// Recursive solution
int num_change(int n,int *d,int k){
	if (n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	if(k == 0){
		return 0;
	}
	int option1 = num_change(n-d[0],d,k);
	int option2 = num_change(n,d + 1,k-1);

	return option1 + option2;
}
int main(){

	int n,k; // 'n' denotes value for which we want change and 'k' denotes the number of denomination 
	cin>>n>>k;
	// int d[] = {1,2,3};	
	// int d[] = {2,3,5};
	// int d[] = {1,7,10};
	int **dp =  new int*[n+1];
	for(int i = 0;i<=n;i++){
		dp[i] = new int[n+1];
	}
	for(int i=0;i<=n;i++){
		for(int j = 0;j<=n;j++){
			dp[i][j] = -1;
		}
	}
	cout<<num_change(n,d,k)<<endl;
	cout<<num_change2(n,d,k,dp)<<endl;
}