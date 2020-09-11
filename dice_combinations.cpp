#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int diceCombTDDP(int n,int *dp){
	if (n == 0) return 1;
	if(n < 0) return 0;

	if(dp[n] > 0){
		return dp[n];
	}

	int ans = 1;
	for(int i=0; i <n ;i++){
		for(int k = 1;k<=6;k++){
			if(k > i) break;
		 ans += diceCombTDDP(i-k,dp);
		} 
	}
	return dp[n] = ans;
}

int diceCombBUDP(int n){
	int *dp = new int[n+1];
	dp[0] = 1;
	for(int i = 1;i<=n;i++){
		dp[i] = 0;
		for(int k=1;k<=6;k++){
			if(k > i) break;
			dp[i] +=  dp[i-k];
		}
	}
	int output = dp[n];
	delete [] dp;
	return output;
}
// recursive
int diceComb(int n){
	if (n == 0) return 1;
	if(n < 0) return 0;
	int ans = 1;
	for(int i=0; i <n ;i++){
		for(int k = 1;k<=6;k++){
			if(k > i) break;
		 ans += diceComb(i-k);
		} 
	}
	return ans;
}
// better recursive sol
int diceCombRec(int n){
	if (n == 0) return 1;
	if(n < 0) return 0;

	int res = 0;
	for(int i=1;i<=6;i++){
		res += diceCombRec(n-i);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int *dp = new int[n+1];
	for (int i = 0; i <= n; ++i)
	{
		dp[i] = 0;
	}
	cout<<diceComb(n)<<endl;
	cout<<diceCombTDDP(n,dp)<<endl;
	cout<<diceCombBUDP(n)<<endl;
	cout<<diceCombRec(n);


	delete [] dp;
}