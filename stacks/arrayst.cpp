#include<iostream>
using namespace std;

#define maxSize 100
int stack[maxSize];
int top = -1;

int isEmpty(){
	if (top==-1){
		cout << "Stack empty";
		return 1;
	}
	return 0;
}

void push(int val){
	if(top==maxSize-1){
		cout << "Stack full!";
		return;
	}
	stack[++top] = val;
}

void pop(){
	if(isEmpty()){
		return;
	}
	top--;
}

void topVal(){
	if(isEmpty()){
		return;
	}
	cout << "Top: " << stack[top] << endl;
}

void printstack(){
	if(isEmpty()){
		return;
	}
	int cp = 0;
	cout << "Stack: ";
	while(cp<=top){
		cout << stack[cp] << " ";
		cp++;
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