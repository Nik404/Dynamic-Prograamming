#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;
int dp[105][105];
// Dp
int eggDropBUDP(int number_of_eggs,int total_floors){
	// for floors
	for(int i=0;i<=number_of_eggs;i++){
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
		// for eggs
		for(int j=0;j<=total_floors;j++){
			dp[0][j] = 0;
			dp[1][j] = j;
		}
		for(int egg = 2;egg<=number_of_eggs;egg++){
			for(int floor = 2;floor<=total_floors;floor++){
				int minimum = INT_MAX;
				int current;
				for(int x=1;x<=floor;x++){
					current = max(dp[egg-1][x-1],dp[egg][floor-x]) + 1;

					if(current < minimum){
						minimum = current;
					}
				}
				dp[egg][floor] = minimum;
			}
		}
	return dp[number_of_eggs][total_floors];
}

int eggDropTDDP(int number_of_eggs,int total_floors){
	if(number_of_eggs == 1) return total_floors;
	if(total_floors == 1) return 1;
	if(total_floors == 0)return 0;
	if(dp[number_of_eggs][total_floors] != -1){
		return dp[number_of_eggs][total_floors];
	}

	int minimum = INT_MAX;
	for(int kth_floor = 1;kth_floor<=total_floors;kth_floor++){
		int ans = max(eggDropTDDP(number_of_eggs-1,kth_floor-1),eggDropTDDP(number_of_eggs,total_floors - kth_floor));
		minimum = min(minimum,ans);
	}
	return dp[number_of_eggs][total_floors] = minimum + 1;
}
//Recursive 
int eggDrop(int number_of_eggs,int total_floors){
	if(number_of_eggs == 1) return total_floors;
	if(total_floors == 1) return 1;
	if(total_floors == 0)return 0;
	int minimum = INT_MAX;
	for(int kth_floor = 1;kth_floor<=total_floors;kth_floor++){
		int ans = max(eggDrop(number_of_eggs-1,kth_floor-1),eggDrop(number_of_eggs,total_floors - kth_floor));
		minimum = min(minimum,ans);
	}
	return minimum + 1;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cout<<eggDrop(10,10)<<endl;
	cout<<eggDrop(1,2)<<endl;
	cout<<eggDrop(2,6)<<endl;
	cout<<eggDropBUDP(3,14)<<endl;

	cout<<eggDropTDDP(2,36)<<endl;
}