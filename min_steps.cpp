#include <iostream>
#include <climits>
using namespace std;

int minSteps2(int n,int *arr){
	if(n == 1){
		return 0;
	}

	if(arr[n] > 0){
		return arr[n];
	}

	int ans = 1 + minSteps2(n-1,arr);
	if(n % 2 == 0){
		ans = min(ans,1 + minSteps2(n/2,arr));
	}
	if(n %3 == 0){
		ans = min(ans,1 + minSteps2(n/3,arr));
	}
	arr[n] = ans;
	return ans;
}

int minSteps3(int n){
	int *arr = new int[n+1];
	arr[1] = 0;
	for(int i=2;i<=n;i++){
		int ans = 1 + arr[i-1];
		if(i%2 == 0){
			ans = min(ans,1 + arr[i/2]);
		}
		if(i%3 == 0){
			ans = min(ans,1 + arr[i/3]);
		}
		arr[i] = ans;
	}
	int output = arr[n];
	delete [] arr;
	return output;
}


int minSteps(int n){
	if(n == 1){
		return 0;
	}
	int ans = 1 + minSteps(n-1);
	if(n % 2 == 0){
		ans = min(ans,1 + minSteps(n/2));
	}
	if(n %3 == 0){
		ans = min(ans,1 + minSteps(n/3));
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	int *arr = new int[n+1];
	for(int i =0;i<=n;i++){
		arr[i] = 0;
	}
	cout<<minSteps(n)<<endl;//not optimized
	cout<<minSteps2(n,arr)<<endl;//optimized with extra work i.e. top down 
	cout<<minSteps3(n)<<endl;//optimized with bottom up
	return 0;
}