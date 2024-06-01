#include <bits/stdc++.h>
using namespace std;
class linkedListType{
struct Node {
    int info ;
    Node *link;
};
    Node *first;
    Node *last;
    int count;
public:
    linkedListType(){
        first=last=NULL;
        count=0;
    }
bool isEmpty(){
    return (first==NULL);
}
void insertFirst(int in){
    Node *newNode;
    newNode = new Node;
    newNode->info=in;
    if(count==0){
        first=newNode;
        newNode->link=NULL;
    }
    else{
        newNode->link=first;
        first=newNode;
    }
    count+=1;
}
void insertLast(int in){
    Node *newNode;
    newNode = new Node;
    newNode->info=in;
    if(count==0){
        first=last=newNode;
        newNode->link=NULL;
    }
    else{
        last->link=newNode;
        newNode->link=NULL;
        last=newNode;
    }
    count+=1;
}
void insertPos(int pos , int in){
    Node *newNode;
    newNode = new Node;
    Node *current;
    if(pos==0){
        insertFirst(in);
    }
    else if(pos==count){
        insertLast(in);
    }
    else{
    current=first;
    for(int i = 0 ; i<pos-1 ; i++){
        current=current->link;
    }
    newNode->link=current->link;
    current->link=newNode;
    }
}
void print(){
    Node *cur =first;
    while(cur!=NULL){
        cout<<cur->info<<" ";
        cur=cur->link;
    }
}
};
int main (){
    linkedListType List;
    List.insertFirst(30);
    List.insertLast(20);
    List.insertPos(1,40);
    List.print();
}