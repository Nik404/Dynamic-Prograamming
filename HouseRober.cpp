#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
// Recursive
int robHouse(int *arr,int n){
	if(n < 0 || n == 0) return 0;
	 int ans = max(arr[n-1] + robHouse(arr,n-2),robHouse(arr,n-1));


	return ans;
	

}
// TDDP
int rob2(int *arr,int n,int *dp){
    if(n < 0 || n == 0) return 0;

    if(dp[n] > 0) return dp[n];

    int ans = max(arr[n-1] + rob2(arr,n-2,dp),rob2(arr,n-1,dp));

     return dp[n] = ans;
}
// BUDP
int robbDP(int *arr,int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = max(arr[i-1] + dp[i-2], dp[i-1]);
    }
    memset(dp,-1,sizeof(dp));
    int ans = dp[n];
    delete [] dp;
    return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = 0;
    }
    cout<<robHouse(arr,n)<<endl;
    cout<<rob2(arr,n,dp)<<endl;
	cout<<robbDP(arr,n);
    delete [] dp;
	return 0;
}

// |---------------------------------------------------|-
// |     input1										   |
// |      5											   |
// |      2 7 9 3 1									   |
// |												   |
// |     input 2									   |
// |      4											   |
// |      1 2 3 1									   |
// |---------------------------------------------------|-

