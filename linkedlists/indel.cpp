#include<iostream>

using namespace std;

class Node{
public:
	int data;
	Node* link;
};

void appbeg(Node** ref, int data){
	Node* node = new Node();
	node->data = data;
	node->link = (*ref);
	(*ref) = node;	
}

void appat(Node* node, int data){
	if(node==NULL){
		return;
	}
	Node* newnode = new Node();
	newnode->data = data;
	newnode->link = node->link;
	node->link = newnode;
}

void append(Node** ref, int data){
	Node* last = *ref;
	Node* node = new Node();
	node->data = data;
	node->link = NULL;

	if(*ref==NULL){
		*ref = node;
		return;
	}

	while(last->link!=NULL){
		last = last->link;
	}

	last->link = node;
}

void delet(Node** ref, int keydata){
	Node* temp = *ref;
	Node* prev = NULL;

	if(temp!=NULL && temp->data==keydata){
		*ref = temp->link;
		delete temp;
		return;
	}

	while(temp!=NULL && temp->data!=keydata){
		prev = temp;
		temp = temp->link;
	}

	if(temp==NULL){
		return;
	}

	prev->link = temp->link;
	delete temp;
}

void printList(Node* ref){
	while(ref!=NULL){
		cout << "Value: " << ref->data;
		cout << " at Address: " << ref->link << endl;
		ref = ref->link;
	}
}

int main(){
	Node* head = NULL;
	appbeg(&head,11);
	appbeg(&head,22);
	appbeg(&head,23);

	append(&head,6);

	appat(head->link,8);

	delet(&head, 23);
	delet(&head, 11);

	cout << "***Final LINKED LIST***"<< endl;
	printList(head);
}