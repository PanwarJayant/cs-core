#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;
};

void deleteNode(Node** ref, Node* todel){
	if(*ref==NULL || todel==NULL){
		return;
	}

	if(*ref==todel){
		*ref = todel->next;
	}

	if(todel->next!=NULL){
		todel->next->prev = todel->prev;
	}

	if(todel->prev!=NULL){
		todel->prev->next = todel->next;
	}

	delete todel;
}

void deleteValue(Node** ref, int val){
	if(*ref==NULL){
		return;
	}

	Node* current = *ref;
	while(current!=NULL && current->data!=val){
		current = current->next;
	}

	deleteNode(ref, current);
}

void printList(Node* ref){
	Node* rev;
	cout << "List in normal direction" << endl;
	while(ref!=NULL){
		cout << "Value: " << ref->data << endl;
		//cout << " with next Address: " << ref->next << endl;
		//cout << " with prev Address " << ref->prev <<endl;
		rev = ref;
		ref = ref->next;
	}
	cout << "List in reverse direction" << endl;
	while(rev!=NULL){
		cout << "Value: " << rev->data << endl;
		//cout << " with next Address: " << rev->next << endl;
		//cout << " with prev Address: " << rev->prev << endl;
		rev = rev->prev;
	}
}

int main(){
	Node* head = NULL;
	Node* one = new Node();
	Node* two = new Node();
	Node* three = new Node();

	head = one;
	one->data = 88;
	one->prev = NULL;
	one->next = two;

	two->prev = one;
	two->data = 22;
	two->next = three;

	three->prev = two;
	three->data = 12;
	three->next = NULL;

	printList(head);
	deleteValue(&head, 223);
	cout << "list after deletion\n";
	printList(head);
}