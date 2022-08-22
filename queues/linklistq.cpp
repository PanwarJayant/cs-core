#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* link;
};

Node* front = NULL;
Node* rear = NULL;

int isempty(){
	if(front==NULL){
		cout << "Q is empty." << endl;
		return 1;
	}
	return 0;
}

void enq(int val){
	Node* newNode = new Node();
	newNode->data = val;
	newNode->link = NULL;
	if(isempty() && rear==NULL){
		front = newNode;
		rear = newNode;
		return;
	}
	rear->link = newNode;
	rear = newNode; 
}

void deq(){
	if(isempty()) return;
	Node* temp = front;
	if(front==rear){
		front = rear = NULL;
	}
	else{
		front = front->link;
	}
	delete temp;
}

void peek(){
	if(isempty()) return;
	cout << "Front: " << front->data << endl;
}

void last(){
	if(isempty()) return;
	cout << "Rear: " << rear->data << endl;
}

void printq(){
	if(isempty()) return;
	Node* t = front;
	cout << "Q is: ";
	while(t){
		cout << t->data << " ";
		t = t->link;
	}
	cout <<  endl;
}

int main(){
	enq(33);
	enq(23);
	enq(454);
	printq();
	deq();
	peek();
	last();
	printq();
	deq();
	enq(232);
	printq();
	return 0;
}