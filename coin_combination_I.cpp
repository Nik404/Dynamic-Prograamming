// Consider a money system consisting of n coins. Each coin has a positive integer value. 
// Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

// BUDP
int change(int n,int k,int *d){
	int *dp = new int[n+1];
	dp[0] = 1;
	for(int i = 1;i<=n;i++){
		dp[i] = 0;
		for(int value=0;value<k;value++){
			if(d[value] <= i)
				dp[i] = dp[i] + dp[i-d[value]];
		}
	}
	return dp[n];
}

int main(){
	int n,k;
	cin>>n>>k;  //'n' denotes value for which we want change and 'k' denotes the number of denomination .
	int d[] = {2,3,5};
	cout<<change(n,k,d);

}