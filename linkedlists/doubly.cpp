#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;
};

void appbeg(Node** ref, int data){
	Node* node = new Node();
	node->data = data;
	node->next = (*ref);
	node->prev = NULL;

	if((*ref)!=NULL){
		(*ref)->prev = node;
	}

	(*ref) = node;	
}

void appat(Node* node, int data){
	if(node==NULL){
		return;
	}
	Node* newnode = new Node();
	newnode->data = data;
	newnode->next = node->next;
	node->next = newnode;
	newnode->prev = node;
	if(newnode->next!=NULL){
		newnode->next->prev = newnode;
	}
}

void append(Node** ref, int data){
	Node* last = *ref;
	Node* node = new Node();
	node->data = data;
	node->next = NULL;

	if(*ref==NULL){
		node->prev = NULL;
		*ref = node;
		return;
	}

	while(last->next!=NULL){
		last = last->next;
	}
	node->prev = last;
	last->next = node;
}

void printList(Node* ref){
	Node* rev;
	cout << "List in normal direction" << endl;
	while(ref!=NULL){
		cout << "Value: " << ref->data;
		cout << "   with next Address: " << ref->next << endl;
		cout << "   with prev Address " << ref->prev <<endl;
		rev = ref;
		ref = ref->next;
	}
	cout << "List in reverse direction" << endl;
	while(rev!=NULL){
		cout << "Value: " << rev->data;
		cout << "   with next Address: " << rev->next << endl;
		cout << "   with prev Address: " << rev->prev << endl;
		rev = rev->prev;
	}
}

int main(){
	Node* head = NULL;

	append(&head, 8);
	appbeg(&head, 22);
	appbeg(&head, 44);
	appat(head->next, 90);

	printList(head);
	return 0;
}