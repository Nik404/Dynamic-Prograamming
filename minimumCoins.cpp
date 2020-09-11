#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
// Recursive
int coinsNeeded(int amount,int *d,int k){
	if(amount == 0) return 0;
	int ans = INT_MAX;
	for(int i=0;i<k;i++){
		if(amount >= d[i]){
		int smallerAns = coinsNeeded(amount-d[i],d,k);
		if(smallerAns != INT_MAX){
			ans = min(ans,smallerAns+1);
		}
		}
	}
	return ans;
}
// BUDP
int coinsNeededBUDP(int amount,int *d,int k){
	int *dp = new int[amount+1];
	for(int i=0;i<=amount;i++){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;

	for(int rokda = 1;rokda<=amount;rokda++){

		for(int i = 0;i<k;i++){
			if(rokda >= d[i]){
			int smallerAns = dp[rokda-d[i]];
			if(smallerAns != INT_MAX){
			dp[rokda] = min(dp[rokda],smallerAns+1);
				}
			}
		}
	}
return dp[amount];
}

int main()
{
	int amount,k;
	cin>>amount>>k;
	int d[k];
	for(int i = 0;i<k;i++){
		cin>>d[i];
	}
	// cout<<coinsNeeded(amount,d,k)<<endl;
	cout<<coinsNeededBUDP(amount,d,k);
	return 0;
}