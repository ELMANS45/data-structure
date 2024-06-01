#include <bits/stdc++.h>
using namespace std ;
class BST{
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
    public:
    BST (){
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
        Node *p=root;
        Node *prev=NULL;
        while(p!=NULL){
            prev=p;
            if(k>p->key){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        if(root==NULL){
            root = new Node(k);
        }
        else if(prev->key<k){
            prev->right = new Node(k);
        }
        else{
            prev->left = new Node(k);
        }
    };
	void remove(Node *p){
        Node *current;
        Node *currentrail;
        Node *tmp;
        if(p->left==NULL && p->right==NULL){
            delete p;
            p=NULL;
        }
        else if(p->left==NULL){
            tmp=p;
            p=p->right;
            delete tmp;
        } 
        else if(p->right==NULL){
            tmp=p;
            p=p->left;
            delete tmp;
        } 
        else{
            current=p->left;
            while(current->right!=NULL){
                currentrail=current;
                current=current->right;
            }
            if(currentrail==NULL){
                p->left=current->left;
            }
            else{
                currentrail->right=current->left;
            }
            delete current;
        }
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

	~BST(){
        clear(root);
    };
};

int main(){
    BST b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.preorderTraversal();
}