#include<iostream>
#include<cstring>
using namespace std;
int dp[105][105][2];
// DP
int adjBitCount(int n,int k,int first){
	if(n == 0) return 0;
	if(n == 1){
		if(k==0) return 1;
		else if(k < 0) return 0;
		else return 0;
	}

	if(dp[n][k][first] != -1){
		return dp[n][k][first];
	}
	int ans = -1;
	if(first == 1){
		ans = adjBitCount(n-1,k-1,1) + adjBitCount(n-1,k,0);
	}
	else{
		ans = adjBitCount(n-1,k,1) + adjBitCount(n-1,k,0);
	}

	return dp[n][k][first] = ans;
}
int main(){
	int n,k,first;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	int bits = adjBitCount(n,k,0);
	bits += adjBitCount(n,k,1);
	cout<<bits<<endl;
}