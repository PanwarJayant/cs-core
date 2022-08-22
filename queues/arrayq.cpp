#include<iostream>
using namespace std;

#define sz 3
int q[sz];
int front=-1, rear=-1, n=sz;

int isfull(){
	if((rear+1)%n==front){
		cout << "Q is full";
		return 1;
	}
	return 0;
}

int isempty(){
	if(rear==-1 && front==-1){
		cout << "Q is empty";
		return 1;
	}
	return 0;
}

void enq(int val){
	if(isfull()) return;
	if(isempty()){
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear+1)%n;
	}
	q[rear] = val;
}

void deq(){
	if(isempty()) return;
	else if(front==rear){
		front = -1;
		rear = -1;
	}
	else{
		front = (front+1)%n;
	}
}

void peek(){
	if(isempty()) return;
	cout << "Front: " << q[front] << endl;
}

void last(){
	if(isempty()) return;
	cout << "Rear: " << q[rear] << endl;
}

void printq(){
	if(isempty()) return;
	cout << "The q is: ";
	int count = (rear+n-front)%n+1;
	for(int i=0; i<count; i++){
		int idx = (front+i)%n;
		cout << q[idx] << " ";
	}
	cout << endl;
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