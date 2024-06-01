#include <bits/stdc++.h>
using namespace std;

class Stack {
    struct Node {
        int info;
        Node *link;
    };

    Node *top;
    int count;

public:
    Stack() {
        top = NULL;
        count = 0;
    }

    bool isEmpty() {
        return (top == NULL);
    }
    void push(int in){
        Node *newNode;
        newNode= new Node;
        newNode->info=in;
        if(isEmpty()){
            newNode->link=NULL;
            top=newNode;
        }
        else{
            newNode->link=top;
            top=newNode;
        }
        count++;
    }
    void pop(){
        Node *current=top;
        top=current->link;
        delete current;
    }
    void display(){
        Node *cur = top;
        while (cur != NULL) {
            cout << cur->info << " ";
            cur = cur->link;
        }
        cout << endl;
    }
    void peek(){
        Node *cur=top;
        if(cur!=NULL){
            cout<<cur->info<<endl;
        }
    }
    string search(int in){
        Node *current=top;
        if(current->info==in){
            return "Found";
        }
        else{
            while(current!=NULL){
                if(current->info!=in){
                    current=current->link;
                }
                else{
                    return "Found";
                }
            }
            return "Not Found";
        }
    }
};
int main() {
    Stack List;
    List.push(30);
    List.push(40);
    List.push(35);
    List.push(32);
    List.push(92);
    List.pop();
    List.pop();
    List.pop();
    List.pop();
    List.push(40);
    List.push(41);                         
    cout<<List.search(40)<<endl;
    List.display();
    return 0;
}