#include<iostream>
#include<stdlib.h>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void insertionSort(vector<int>& array){
	for(int i=1; i<array.size();i++){
		int key = array[i];
		int j = i-1;
		while(j>=0 && array[j]>key){
			array[j+1]=array[j];
			j--;
		}
		array[j+1] = key;
	}
}

void merge(vector<int>& array, int start, int mid, int end){
	vector<int> temp(end-start+1);
	int i=start, j=mid+1, k=0;
	while(i<=mid && j<=end){
		if(array[i]<=array[j]){
			temp[k] = array[i];
			k++;
			i++;
		}
		else {
			temp[k] = array[j];
			k++;
			j++;
		}
	}

	while(i<=mid){
		temp[k] = array[i];
		k++; i++;
	}

	while(j<=end){
		temp[k] = array[j];
		k++; j++;
	}

	for(int x=start; x<=end; x++){
		array[x] = temp[x-start];
	}
}

void mergeSort(vector<int>& array, int start, int end){
	if (start < end){
		int mid = (start+end)/2;
		mergeSort(array, start, mid);
		mergeSort(array, mid+1, end);
		merge(array, start, mid, end);
	}
}

void iterativeMergeSort(vector<int>& array, int n){
	int curr_size, left_start;
	for(curr_size=1; curr_size<n; curr_size*=2){
		for(left_start=0; left_start<n-1; left_start+=2*curr_size){
			int mid = min(left_start+curr_size-1, n-1);
			int right_end = min(left_start+2*curr_size-1, n-1);
			merge(array, left_start, mid, right_end);
		}
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<int>&array, int low, int high){
	int pivotElement = array[high];
	int pivotIndex = low-1;
	for(int i=low; i<high; i++){
		if(array[i]<=pivotElement){
			pivotIndex++;
			swap(&array[i], &array[pivotIndex]);
		}
	}
	swap(&array[pivotIndex+1], &array[high]);
	return pivotIndex+1;
}

int randomizedQuickSortPartition(vector<int>& array, int low, int high){
	int pivotElementindex = int(low+(rand()%(high-low+1)));
	swap(&array[high], &array[pivotElementindex]);
	// Rest is same as above partition function
	int pivotElement = array[high];
	int pivotIndex = low-1;
	for(int i=low; i<high; i++){
		if(array[i]<=pivotElement){
			pivotIndex++;
			swap(&array[i], &array[pivotIndex]);
		}
	}
	swap(&array[pivotIndex+1], &array[high]);
	return pivotIndex+1;
}

void quickSort(vector<int>& array, int low, int high){
	if(low<high){
		int pi = partition(array, low, high);
		quickSort(array, low, pi-1);
		quickSort(array, pi+1, high);
	}
}

void selectionSort(vector<int>& array, int size){
	for(int step=0; step<size-1;step++){
		int min_index = step;
		for(int m=step+1; m<size; m++){
			if(array[m]<array[min_index]){
				min_index = m;
			}
		}
		swap(&array[step], &array[min_index]);
	}
}

void recursiveBubbleSort(vector<int>& array, int size){
	int swapped = 0;
	if (size==1)
		return;
	for(int iter=0; iter<size-1; iter++){
		if(array[iter]>array[iter+1]){
			swap(&array[iter], &array[iter+1]);
			swapped = 1;
		}
	}
	if(!swapped){
		return;
	}
	recursiveBubbleSort(array, size-1);
}

void bubbleSort(vector<int>& array, int size){
	for(int step=0; step<size-1; step++){
		int swapped = 0;
		for(int iter=0; iter<size-step-1; iter++){
			if(array[iter]>array[iter+1]){
				swap(&array[iter], &array[iter+1]);
				swapped = 1;
			}
		}
		if(!swapped){
			break;
		}
	}
}

void printArray(vector<int>& array){
	for(int i=0; i<array.size(); i++){
		cout << array[i] << " ";
	}
}

int main(){
	cout << "Enter number of elements in array\n";
	int num;
	cin >> num;
	cout << "Please enter the array for sorting!\n";
	vector<int> array;
	for(int i=0;i<num;i++){
		int val;
		cin >> val;
		array.push_back(val);
	}
	//insertionSort(array);
	//quickSort(array, 0, array.size()-1);
	//sort(array.begin(), array.end());
	recursiveBubbleSort(array, array.size());
	printArray(array);
}