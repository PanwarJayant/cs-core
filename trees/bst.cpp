#include<iostream>
using namespace std;

// another way to declare
// struct Node{
// 	int data;
// 	Node* left;
// 	Node* right;
// }; Rest of the syntax like creating a new node
// using NEW keyword remains the same

class Node{
public:
	int data;
	Node* left;
	Node* right;
};

Node* makeNewNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* findMin(Node* rootptr){
	while(rootptr->left!=NULL)	rootptr=rootptr->left;
	return rootptr;
}

Node* findMax(Node* rootptr){
	while(rootptr->right!=NULL)	rootptr=rootptr->right;
	return rootptr;
}

Node* insert(Node* rootptr, int data){
	if(rootptr==NULL){
		rootptr = makeNewNode(data);
	}

	else if(data<=rootptr->data){
		rootptr->left = insert(rootptr->left, data);
	}
	else {
		rootptr->right = insert(rootptr->right, data);
	}
	return rootptr;
}

Node* deletion(Node* rootptr, int data){
	if(rootptr==NULL) return rootptr;
	else if(data < rootptr->data){
		rootptr->left = deletion(rootptr->left, data);
	}
	else if(data > rootptr->data){
		rootptr->right = deletion(rootptr->right, data);
	}
	else{
		// node with no child
		if(rootptr->right==NULL && rootptr->left==NULL){
			delete rootptr;
			rootptr = NULL;
		}
		// node with 1 child
		else if(rootptr->left==NULL){
			Node* temp = rootptr;
			rootptr = rootptr->right;
			delete temp;
		}
		else if(rootptr->right==NULL){
			Node* temp = rootptr;
			rootptr = rootptr->left;
			delete temp;
		}
		// node with 2 children
		else{
			Node* inorder_predecessor = findMax(rootptr->left);
			rootptr->data = inorder_predecessor->data;
			rootptr->left = deletion(rootptr->left, inorder_predecessor->data);
			//Node* inorder_successor = findMin(rootptr->right);
			// rootptr->data = inorder_successor->data;
			// rootptr->right = deletion(rootptr->right, inorder_successor->data);
		}
	}
	return rootptr;
}

int search(Node* rootptr, int data){
	if(rootptr==NULL){
		return 0;
	}
	else if(rootptr->data==data){
		return 1;
	}
	else if(data<rootptr->data){
		return search(rootptr->left, data);
	}
	else{
		return search(rootptr->right, data);
	}
}

void preorder(Node* rootptr){
	if(rootptr==NULL)	return;
	cout << rootptr->data << ",";
	preorder(rootptr->left);
	preorder(rootptr->right);
}

void inorder(Node* rootptr){
	if(rootptr==NULL)	return;
	inorder(rootptr->left);
	cout << rootptr->data << ",";
	inorder(rootptr->right);
}

void postorder(Node* rootptr){
	if(rootptr==NULL)	return;
	postorder(rootptr->left);
	postorder(rootptr->right);
	cout << rootptr->data << ",";
}

int main(){
	Node* rootptr = NULL;
	rootptr = insert(rootptr, 123);
	rootptr = insert(rootptr, 44);
	rootptr = insert(rootptr, 55);
	rootptr = insert(rootptr, 150);
	rootptr = insert(rootptr, 130);
	rootptr = insert(rootptr, 160);
	inorder(rootptr);
	cout << endl;
	rootptr = deletion(rootptr, 150);
	inorder(rootptr);
	cout << endl;
	// preorder(rootptr);
	// cout << endl;
	// postorder(rootptr);
	//cout << "No presence: " << search(rootptr, 123);
	return 0;
}