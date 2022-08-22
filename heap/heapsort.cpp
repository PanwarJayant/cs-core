#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// descending sorting right now
void heapify(vector<int>&hp, int sz, int i){
	int largest = i;
	int lchild = 2*i+1;
	int rchild = 2*i+2;
	if(lchild<sz && hp[lchild]>hp[largest])	largest=lchild;
	if(rchild<sz && hp[rchild]>hp[largest])	largest=rchild;
	if(largest!=i){
		swap(&hp[i], &hp[largest]);
		heapify(hp, sz, largest);
	}
}

void displayHeap(vector<int> &hp){
	for(int i=0; i<hp.size(); i++){
		cout << hp[i] << " ";
	}
	cout << endl;
}

void heapSort(vector<int>&hp){
	int sz = hp.size();
	int i = sz/2-1;
	// BUILD HEAP
	while(i>=0){
		heapify(hp, sz, i);
		i--;
	}

	displayHeap(hp);

	i=sz-1;
	while(i>=0){
		// EXTRACT ROOT ELEMENT WHICH IS MAX
		swap(&hp[0], &hp[i]);
		// HEAPIFY THE REDUCED HEAP
		heapify(hp, i, 0);
		i--;
	}
}

int main(){
	vector<int> hp = {22, 19, 35, 4, 9, 10};
	heapSort(hp);
	displayHeap(hp);
	return 0;
}