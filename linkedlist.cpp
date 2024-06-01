#include <bits/stdc++.h>
using namespace std;

class linkedListType {
    struct Node {
        int info;
        Node *link;
    };

    Node *first;
    Node *last;
    int count;

public:
    linkedListType() {
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
            last = newNode;
        }
        else{
        newNode->link=first;
        first=newNode;
        }
        count++;
    }

    void insertLast(int in) {
        Node *newNode = new Node;
        newNode->info = in;
        newNode->link = NULL;
        if (count == 0) {
            first = last = newNode;
        } else {
            last->link = newNode;
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
            current->link = newNode;
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
            first=first->link;
            delete current;
            count--;
        }
    }
    void removelast(){
        Node *current=first->link;
        Node *prev=first; 
        while(current!=last){
            prev=current;
            current=current->link;
        }
        delete current;
        prev->link=NULL;
        last=prev;
        count--;
    }
    void remove(int in){
        Node *current , *prev;
        if(isEmpty()){
            return;
        }
        else{
            if(first->info==in){
                current=first;
                first=first->link;
                delete current;
                count--;
                if(count==0){
                    last=NULL;
                }
            }
            else{
                prev=first;
                current=first->link;
                while(current!=NULL){
                    if(current->info!=in){
                        prev=current;
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
                prev->link=current->link;
                    if(last==current){
                        last=prev;
                    }
                delete current;
                count--;
                }
            }
        }
    }
    void reverse(){
        Node *current=first;
        Node *link;
        Node *prev=NULL;
        link=current->link;
        while(current!=NULL){
            link=current->link;
            current->link=prev;
            prev=current;
            current=link;
        }
        first=prev;
    }
    int search(int in){
        Node *current=first;
        int pos=0;
        while(current!=NULL){
            if(current->info==in){
                return pos;
            }
            current=current->link;
            pos+=1;
        }
        return -1;
    }
};
int main() {
    linkedListType List;
    List.insertFirst(30);
    List.insertLast(20);
    List.insertPos(1, 40);
    List.remove(30);
    List.reverse();
    cout<<List.search(60)<<endl;
    List.print();
    return 0;
}