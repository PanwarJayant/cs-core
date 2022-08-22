#include<iostream>
#include<vector>

using namespace std;

int recursiveBinarySearch(vector<int>&arr, int search, int start, int end){
	if (start>end){
		return -1;
	}
	int sol;
	int mid = (start+end)/2;
	if(arr[mid]==search){
		sol = mid;
	}
	else if(arr[mid]<search){
		sol = recursiveBinarySearch(arr, search, mid+1, end);
	}
	else {
		sol = recursiveBinarySearch(arr, search, start, mid-1);
	}
	
	return sol;
}

int binarySearch(vector<int>& arr, int search){
	int start=0, end=arr.size()-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid]==search){
			return mid;
		}
		else if(arr[mid]<search){
			start = mid+1;
		}
		else {
			end=mid-1;
		}
	}
	return -1;
}

int main(){
	cout << "Enter number of elements in array\n";
	int num;
	cin >> num;
	cout << "Please enter the SORTED array for searching!\n";
	vector<int> array;
	for(int i=0;i<num;i++){
		int val;
		cin >> val;
		array.push_back(val);
	}
	int search;
	cout << "Enter the number to be searched\n";
	cin >> search;
	int idx = recursiveBinarySearch(array, search, 0, array.size()-1);
	cout << "Number found at index: " << idx;
}