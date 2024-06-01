#include <bits/stdc++.h>
using namespace std;
template <class t>
void quick(t data[],int left,int right){
    int i = left ;
    int j = right;
    t tmp;
    t pivot = data[(left+right)/2];
    while(i<=j){
        while(data[i]<pivot){
            i++;
        }
        while(data[j]>pivot){
            j--;
        }
        if(i<=j){
            tmp=data[i];
            data[i]=data[j];
            data[j]=tmp;
            i++;
            j--;
        }
    }
    if(i<right){
        quick(data,i,right);
    }
    if(j>left){
        quick(data,left,j);
    }
}
int main(){
    int k[1000] = {3,1,56,6};
    quick(k,0,3);
    for(int i = 0 ; i<4 ; i++){
        cout<<k[i]<<" ";
    }
}