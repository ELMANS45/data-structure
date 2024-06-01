#include <bits/stdc++.h>
using namespace std;
template <class t>
void bubbleup(t data[], int n){
    for(int i = 0 ; i<n-1 ; i++){//n
        for(int j = n-1 ; j>i ; j--){//n
            if(data[j-1]>data[j]){//1
                swap(data[j],data[j-1]);//1
            }
        }
    }
}
template <class t>
void bubbledowm(t data[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        for(int j = 0 ; j=n-i-1 ; j++){
            if(data[j]>data[j+1]){
                swap(data[j+1],data[j]);
            }
        }
    }
}
int main(){
    int k[1000] = {3,1,56,6};
    bubbleup(k,4);
    for(int i = 0 ; i<4 ; i++){
        cout<<k[i]<<" ";
    }
}