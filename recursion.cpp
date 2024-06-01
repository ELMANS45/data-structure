#include <iostream>
using namespace std;
int r = 1 ;
int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else if(n<0){
        return -999;
    }
    else{
        return n*fact(n-1);
    }
}
int fabi(int n){
    if(n==0||n==1){
        return n;
    }
    else{
        return fabi(n-1)+fabi(n-2);
    }
}
int sum(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return n+sum(n-1);
    }
}
int main(){
    cout<<fact(5)<<endl;
    cout<<fabi(6)<<endl;
    cout<<sum(5)<<endl;
}