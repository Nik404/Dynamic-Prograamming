#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
// recursive
int knapsack(int *wts,int *prices,int N,int W){
	if(N==0 || W==0) return 0;
	 int inc = 0 ,exc = 0;
	 // /if include
	 // sirf tab jabb hamare thale ki capacity <= ho wt se
	 if(wts[N-1]<=W){
	  inc = prices[N-1] + knapsack(wts,prices,N-1,W-wts[N-1]);
	 }
	 // agar exclude
	 exc = 0 + knapsack(wts,prices,N-1,W);

	 return max(inc,exc);
}

int knapsackDP(int *wts,int *prices,int N,int W){
	int dp[1000][1000];
	for(int i=0;i<=N;i++){
		for(int w=0;w<=W;w++){
			if(i==0 || w==0){
				dp[i][w] = 0;
			}
			else{
				int inc=0;int exc = 0;
				if(wts[i-1] <= w  ){
					inc = prices[i-1] + dp[i-1][w-wts[i-1]];
				}
				// excide price
				exc = dp[i-1][w];

				dp[i][w] = max(inc,exc);
			}

		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[N][W];
}
int main(){
	int wts[] = {2,7,3,4};
	int prices[] = {5,20,20,10};
	int N,W;
	cin>>N>>W;
	cout<<knapsack(wts,prices,N,W)<<endl;
	cout<<knapsackDP(wts,prices,N,W);
}