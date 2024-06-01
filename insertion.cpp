#include <bits/stdc++.h>
using namespace std;
template <class t>
void insertion(t data[],int n){
    for(int i = 1 , j ; i<n ; i++){//n
        t tmp = data[i];
        for(j = i ; j>0 && tmp<data[j-1] ; j--){//n
            data[j] = data[j-1];
        }
        data[j]=tmp;
    }
    // 4 12 5 3 6
}
int main(){
    int k[1000] = {3,1,56,6};
    insertion(k,4);
    for(int i = 0 ; i<4 ; i++){
        cout<<k[i]<<" ";
    }
}