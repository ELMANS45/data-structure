#include <bits/stdc++.h>
using namespace std;

class doublyLinkedListType {
    struct Node {
        int info;
        Node *link;
        Node *prev;
    };

    Node *first;
    Node *last;
    int count;

public:
    doublyLinkedListType() {
        first = last = NULL;
        count = 0;
    }

    bool isEmpty() {
        return (first == NULL);
    }

    void insertFirst(int in) {
        Node *newNode = new Node;
        newNode->info = in;
        if (count == 0) {
            first=newNode;
            newNode->link=NULL;
            newNode->prev=NULL;
            last = newNode;
        }
        else{
            newNode->link=first;
            newNode->prev=NULL;
            first->prev=newNode;
            first=newNode;
        }
        count++;
    }

    void insertLast(int in) {
        Node *newNode = new Node;
        newNode->info = in;
        newNode->link = NULL;
        newNode->prev = NULL;
        if (count == 0) {
            first = last = newNode;
        } else {
            newNode->prev=last;
            last->link=newNode;
            last = newNode;
        }
        count++;
    }

    void insertPos(int pos, int in) {
        if (pos < 0 || pos > count) {
            throw out_of_range("Position out of range");
        }

        if (pos == 0) {
            insertFirst(in);
        } else if (pos == count) {
            insertLast(in);
        } else {
            Node *newNode = new Node;
            newNode->info = in;
            Node *current = first;
            for (int i = 0; i < pos - 1; i++) {
                current = current->link;
            }
            newNode->link = current->link;
            current->link->prev=newNode;
            current->link = newNode;
            newNode->prev=current;
            count++;
        }
    }

    void print() {
        Node *cur = first;
        while (cur != NULL) {
            cout << cur->info << " ";
            cur = cur->link;
        }
        cout << endl;
    }
    void removefirst(){
        if(count==0){
            cout<<"NOT";
        }
        else if(count==1){
            delete first;
            last=first=NULL;
            count--;
        }
        else{
            Node *current=first;
            first->link->prev=NULL;
            first=first->link;
            delete current;
            count--;
        }
    }
    void removelast(){
        Node *current=first->link;
        Node *previ=first; 
        while(current!=last){
            previ=current;
            current=current->link;
        }
        delete current;
        previ->link=NULL;
        last=previ;
        count--;
    }
    void remove(int in){
        Node *current , *previ;
        if(isEmpty()){
            return;
        }
        else{
            if(first->info==in){
                current=first;
                first->link->prev=NULL;
                first=first->link;
                delete current;
                count--;
                if(count==0){
                    last=NULL;
                }
            }
            else{
                previ=first;
                current=first->link;
                while(current!=NULL){
                    if(current->info!=in){
                        previ=current;
                        current=current->link;
                    }
                    else{
                        break;
                    }
                }
                if(current==NULL){
                    cout<<"not found";
                }
                else{
                previ->link=current->link;
                current->link->prev=previ;
                    if(last==current){
                        last=previ;
                    }
                delete current;
                count--;
                }
            }
        }
    }
    // void reverse(){
    //     Node *current=first;
    //     Node *link;
    //     Node *previ=NULL;
    //     link=current->link;
    //     while(current!=NULL){
    //         link=current->link;
    //         current->link=previ;
    //         previ=current;
    //         current=link;
    //     }
    //     first=previ;
    // }
    // int search(int in){
    //     Node *current=first;
    //     int pos=0;
    //     while(current!=NULL){
    //         if(current->info==in){
    //             return pos;
    //         }
    //         current=current->link;
    //         pos+=1;
    //     }
    //     return -1;
    // }
};
int main(){
    doublyLinkedListType List;
    List.insertFirst(30);
    List.insertFirst(60);
    List.insertLast(20);
    List.insertPos(1, 40);
    List.remove(40);
    List.print();
}