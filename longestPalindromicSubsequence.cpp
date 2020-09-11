#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int dp[105][105];
// DP
int longestPanidromeSunsequenceBUDP(string s){
	int dp[100][100];
	for(int i = 0;i<s.length();i++){
		dp[i][i] = 1;
	}
	for(int len = 2;len<=s.length();len++){
		for(int i=0;i<=s.length()-len;i++){
			int j = i+len-1;
			if(s[i]==s[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}
			else{
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	// for printing the dp array
	// for(int i=0;i<s.size();i++){
	// 	for(int j=0;j<s.size();j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return dp[0][s.size()-1]; // hamara answer (0,n-1) par padaa hoga
}
int longestPanidromeSunsequenceTDDP(string s,int start,int end){
	if(start == end) return 1;
	if(start > end) return 0;
	int ans = 0;
	if(dp[start][end] != 0){
		return dp[start][end];
	}
	if(s[start] == s[end]){
	ans = longestPanidromeSunsequenceTDDP(s,start + 1,end - 1) + 2;
}
	else{
	ans = max(longestPanidromeSunsequenceTDDP(s,start+1,end),longestPanidromeSunsequenceTDDP(s,start,end-1));
}

	return dp[start][end] = ans;
}
// recursive
int longestPanidromeSunsequence(string s,int start,int end){
	if(start == end) return 1;
	if(start > end) return 0;
	int ans = 0;
	// if first and last  letter is same
	
	if(s[start] == s[end]){
	ans = longestPanidromeSunsequence(s,start + 1,end - 1) + 2;
}
	// if first and last  letter is different
	else{
	ans = max(longestPanidromeSunsequence(s,start+1,end),longestPanidromeSunsequence(s,start,end-1));
}


	return ans;
}
int main(){
	string s;
	cin>>s;
	memset(dp,0,sizeof(dp));
	int n = s.length();

	cout<<longestPanidromeSunsequence(s,0,n-1)<<endl;
	cout<<longestPanidromeSunsequenceTDDP(s,0,n-1)<<endl;
	cout<<longestPanidromeSunsequenceBUDP(s);
	return 0;
}