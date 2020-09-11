#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
int dp[100];
int ways(int steps){
	// ground
	if(steps == 0) return 1;
	if(steps < 0) return 0;

	int ans = ways(steps-1) + ways(steps-2) + ways(steps-3);
	return ans;
}
int ways2(int n){
	if(n == 0) return 1;
	if(n < 0) return 0;

	if(dp[n] > 0){
		return dp[n];
	}
	int ans = ways2(n-1) + ways2(n-2) + ways2(n-3);
	return dp[n] = ans;
}
int ways3(int n){
	dp[1000];
	if(dp[n] < 0) return 0;
	dp[0] = 1;
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int steps;
	cin>>steps;
	memset(dp,0,sizeof(dp));
	cout<<ways(steps)<<endl;
	cout<<ways2(steps)<<endl;
	cout<<ways3(steps)<<endl;
	return 0;
}