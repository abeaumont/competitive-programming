#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}
struct Node* FindMin(struct Node* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct Node* Getsuccessor(struct Node* root,int data) {
	struct Node* current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) { 
		return FindMin(current->right);
	}
	else {  
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
 
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);      
	printf("%d ",root->data);  
	Inorder(root->right);    
}
 
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";
 
	struct Node* successor = Getsuccessor(root,1);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";
}