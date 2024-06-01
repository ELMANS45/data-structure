#include <bits/stdc++.h>
using namespace std ;
class AVL{
    protected:
    class Node{
        public:
        int key; // item
        Node *left;
        Node *right;
        Node () {left = right = 0;}
        Node (int el, Node* l = 0, Node* r = 0){
        key = el;
        left = l;
        right = r;
        }
        // Node* getLeft (){
        //     return left;
        // }
        // Node* getRight (){
        //     return right;
        // }
};
    Node *root;
     void inorder(Node *p){
        if(p!=NULL){
        inorder(p->left);
        cout<<p->key<<" ";
        inorder(p->right);
        }
    }
    void preorder(Node *p){
        if(p!=NULL){
        cout<<p->key<<" ";
        preorder(p->left);
        preorder(p->right);
        }
    }
    void postorder(Node *p){
        if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        cout<<p->key<<" ";
        }  
    }
    void breathFirst(){
          queue <Node*> q;
          Node *p = root;
          if(p!=0){
            q.push(p);
            while(!q.empty()){
                p = q.front();
                cout<<p<<" ";
                q.emplace(p);
                if(p->left!=0){
                    q.push(p->left);
                }
                if(p->right!=0){
                    q.push(p->right);
                }
            }
          } 
    }
    int height(Node *p){
	if(p == NULL){
		return 0;
    }
	else{
		return 1 + max(height(p->left), height(p->right));
    }
    }
    int max(int x , int y){
	if(x >= y){
		return x;
    }    
	else{
		return y;
    }    
    }
    int nodecount(Node* p){
        if(p == NULL){
		    return 0;
    }
	    else{
		return 1 + nodecount(p->left) + nodecount(p->right);
    }
    }
    int leavescount(Node *p){
        if(p==0){
            return 0 ;
        }
        else if(p->left==NULL && p->right ==NULL){
            return 1;
        }
        else{
            return leavescount(p->left) + leavescount(p->right);
        }
    }
    void leftRotation(){

    }
    void rightRotation(){
        
    }
    public:
    AVL (){
        root = 0;
    }
    bool isEmpty() {
        return root == 0;
    }
	void search(int k){

    };
	void searchRec(int k){

    };
	void insert(int k){

    };
	void remove(Node *p){

    };
	void inorderTraversal(){
        inorder(root);
    };
	void preorderTraversal(){
        preorder(root);
    };
	void postorderTraversal(){
        postorder(root);
    };
	int treeHeight(){
        return height(root);
    };
	int treeNodeCount(){
        return nodecount(root);
    };
	int treeLeavesCount(){
        return leavescount(root);
    };
    void clear(Node* p) {
    if(p != NULL)
	{
		clear(p->left);
		clear(p->right);
		delete p;
		p = NULL;
	}
    }

	~AVL(){
        clear(root);
    };
};

int main(){
    AVL b;
    b.preorderTraversal();
}