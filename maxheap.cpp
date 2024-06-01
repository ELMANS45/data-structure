#include <iostream>
#include <cassert>

using namespace std;
int heapify(int arr[] ,int sizeA , int i){
    int l = 2*i+1;
    int R = 2*i-1;
    int max=i;
    if(l<sizeA&&arr[l]>arr[max]){
        max=l;
    }
    if(R<sizeA&&arr[R]>arr[max]){
        max=R;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,sizeA,i);
    }
}
void builtheap(int arr[],int s){
    for(int i = ((s/2)-1) ; i>=0 ; i--){
        heapify(arr,s,i);
    }
}
int main(){

}