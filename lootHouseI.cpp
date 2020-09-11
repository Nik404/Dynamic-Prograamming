#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int lootHouse(int *arr,int n){
	if(n < 0) return 0;

	int ans = max(lootHouse(arr,n-1),lootHouse(arr,n-2) + arr[n]);

	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<lootHouse(arr,n);
	return 0;
}