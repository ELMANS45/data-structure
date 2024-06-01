#include <bits/stdc++.h>
using namespace std;
template <class t>
void selection(t data[],int n){
    for(int i = 0 , j ,least ; i<n-1 ; i++){ //n
        for(j=i+1 ,least = i ;j<n ; j++){ //n
            if(data[least] > data[j]){ //1
                least=j;
            }
        }
        swap(data[least] , data[i]);//1
    }
}


int main(){
    int k[1000] = {3,1,56,6};
    selection(k,4);
    for(int i = 0 ; i<4 ; i++){
        cout<<k[i]<<" ";
    }
}