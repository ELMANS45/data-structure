#include <bits/stdc++.h>
using namespace std;

class Queue {
    struct Node {
        int info;
        Node *link;
    };

    Node *first;
    Node *last;
    int count;

public:
    Queue() {
        first = last = NULL;
        count = 0;
    }
    bool isEmpty(){
        return (first==NULL);
    }
    void Enqueue(int in){
        Node* newNode;
        newNode =new Node;
        newNode->info=in;
        if(isEmpty()){
            newNode->link=NULL;
            first=last=newNode;
        }
        else{
            last->link=newNode;
            last=newNode;
        }
        count++;
    }
    void dequeue(){
        Node *current=first;
        first=current->link;
        delete current;
        count--;
    }
    void display(){
        Node *cur = first;
        while (cur != NULL) {
            cout << cur->info << " ";
            cur = cur->link;
        }
        cout << endl;
    }
};
int main(){
    Queue Q;
    Q.Enqueue(15);
    Q.Enqueue(10);
    Q.Enqueue(13);    
    Q.Enqueue(161);
    Q.Enqueue(164);
    Q.dequeue();
    Q.dequeue();
    Q.display();
}