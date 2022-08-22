#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* top = NULL;

int isEmpty(){
	if(top==NULL){
		cout << "Stack empty";
		return 1;
	}
	return 0;
}

void push(int val){
	Node* newNode = new Node();
	newNode->data = val;
	newNode->link = top;
	top = newNode;
}

void pop(){
	if(isEmpty()) return;
	Node* temp = top;
	top = top->link;
	delete temp;
}

void topVal(){
	if(isEmpty()) return;
	cout << "Top: " << top->data << endl;
}

void printstack(){
	if(isEmpty()) return;
	cout << "Stack: ";
	Node* temp = top;
	while(temp){
		cout << temp->data << " ";
		temp = temp->link;
	}
}

int main(){
	push(23);
	push(12);
	printstack();
	pop();
	pop();
	printstack();
	push(33);
	push(34);
	topVal();
	printstack();
	return 0;
}