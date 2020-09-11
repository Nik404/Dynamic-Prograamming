#include<iostream>
using namespace std;

// Time : O(n)
int fib2(int n,int *arr){
	if(n ==0 || n==1){
		return 1;
	}
	if(arr[n] > 0){
		return arr[n];
	}
	int output = fib2(n-1,arr) + fib2(n-2,arr);
	arr[n] = output;
	return output;
}

// Time:O(n)
int fibi(int n){
	int *arr = new int[n+1];
	arr[0] = 1;
	arr[1] = 1;

	for(int i =2; i<= n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	int output = arr[n];
	delete [] arr;
	return output;
}

// Time: O(2^n)
int fibb(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	return fibb(n-1) + fibb(n-2);
}
int main(){

	int n;
	cin >> n;

	int *arr = new int[n+1];

	for(int i = 0;i<=n;i++){
		arr[i] = 0;
	}

	cout<<fib2(n,arr)<<endl; // optimized
	cout<<fibi(n)<<endl; //optimize with less work
	cout<<fibb(n)<<endl; // not optimized

	delete [] arr; 
}