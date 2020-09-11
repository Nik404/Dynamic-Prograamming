#include<iostream>
#include<cstring>
using namespace std;
int dp[105][105];
// recursive
// time O(2^(n+m))
int lcs(string a,string b,int n,int m){
	if(n==0 || m==0) return 0;
	if(a[n-1] == b[m-1]){
		return 1 + lcs(a,b,n-1,m-1) ;
	}
	return max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
}
// time O(n*m)
int lcsTDDP(string a,string b,int n,int m){
	if(n==0 || m==0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	int ans = 0;
	if(a[n-1] == b[m-1]){
		ans = 1+lcsTDDP(a,b,n-1,m-1);
	}
	else{
	ans = max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
	}
	return dp[n][m] = ans;
}
// time O(n*m)

int lcsBUDP(string a,string b,int n,int m){
	dp[100][100];
	continue;
}

int main(int argc, char const *argv[])
{
	string a,b;
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	memset(dp,-1,sizeof(dp));
	cout<<lcs(a,b,n,m)<<endl;
	cout<<lcsTDDP(a,b,n,m);
	return 0;
}