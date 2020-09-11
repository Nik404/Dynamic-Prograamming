#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
int dp[1000];
// recursive
// Time:O(k^n)
int ways(int n,int k){
	if(n == 0) return 1;
	if(n < 0) return 0;

	int ans = 0;
	for(int j=1;j<=k;j++){
		ans += ways(n-j,k);
	}
	return ans;
}
// TDDP
// time O(n*k)
int ways2(int *dp,int n,int k){
	if(n == 0) return 1;
	if(n < 0) return 0;

	if(dp[n] > 0) return dp[n];

	int output = 0;
	for(int j=1;j<=k;j++){
		output += ways(n-j,k);
	}
	return dp[n] = output;
}
// BUDP
// time : O(n*k)
int ways3(int n,int k){
	int *dp = new int[n+1];
	dp[0] = 1;
	for(int step=1;step<=n;step++){
		dp[step] = 0;
		for(int j = 1;j<=k;j++){
			if(step-j >= 0){
			dp[step] += dp[step-j];
		}
	}

  }
  return dp[n];
}
// can be done in O(n)
int waysBUDPOptimized(int n,int k){
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;

	for(int step=1;step<=n;step++){
		// dp[step] = 0;
		if(dp[step-k] >= 0){
		dp[step+1] = 2*dp[step-1] - dp[step-k];
		}
		else{
			dp[step+1] = 2*dp[step-1];
		}
    }
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int *dp = new int[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = 0;
	}
	cout<<ways(n,k)<<endl;
	cout<<ways2(dp,n,k)<<endl;
	cout<<ways3(n,k)<<endl;
	cout<<waysBUDPOptimized(n,k)<<endl;
	return 0;
}