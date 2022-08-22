#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* link;
};

void printList(Node* ref) {
	while(ref!=NULL){
		cout << "Value: " << ref->data << '\n';
		cout << "Next link: " << ref->link << '\n';
		ref = ref->link;
	} 
} 

int main() {
	Node* head = NULL;
	Node* one = new Node();
	Node* second = new Node();
	Node* third = new Node();

	
	head = one;
	(*one).data = 1;
	one->link = second;

	(*second).data = 13;
	(*second).link = third;

	third->data = 44;
	third->link = NULL;

	printList(head);

	return 0;
}