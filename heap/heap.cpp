#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

// void heapifyUp(vector<int>&hp, int i){
// 	int sz = hp.size();
// 	int child = i;
// 	int parent = (i/2)-1;
// 	if(hp[parent]<hp[child] && parent>=0){
// 		swap(&hp[child], &hp[parent]);
// 		heapifyUp(hp, parent);
// 	}
// }

// below function is similar to heapifyDown but not exactly
void heapify(vector<int>&hp, int i){
	int sz = hp.size();
	int largest = i;
	int lchild = (2*i)+1;
	int rchild = (2*i)+2;
	if(lchild<sz && hp[lchild]>hp[largest])	largest = lchild;
	if(rchild<sz && hp[rchild]>hp[largest])	largest = rchild;
	if(largest!=i){
		swap(&hp[i], &hp[largest]);
		heapify(hp, largest);
	}
}

void insert(vector<int>&hp, int num){
	int sz = hp.size();
	if(!sz){
		hp.push_back(num);
		return;
	}
	hp.push_back(num);
	int i=sz/2-1;
	while(i>=0){
		heapify(hp, i);
		i--;
	}
}

void deleteNode(vector<int> &hp, int num){
	int sz = hp.size();
	int i=0;
	while(i<sz){
		if (num==hp[i])	break;
		i++;
	}
	swap(&hp[i], &hp[sz-1]);
	hp.pop_back();
	i=sz/2-1;
	while(i>=0){
		heapify(hp, i);
		i--;
	}
	// heapifyUp(hp, sz-2);
}

void displayHeap(vector<int> &hp){
	for(int i=0; i<hp.size(); i++){
		cout << hp[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int>hp;
	insert(hp, 12);
	insert(hp, 13);
	insert(hp, 22);
	insert(hp, 212);
	insert(hp, 90);
	insert(hp, 339);
	insert(hp, 798);

	displayHeap(hp);
	deleteNode(hp, 798);
	displayHeap(hp);
}