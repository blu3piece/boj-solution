#include<iostream>
using namespace std;

int main(){
    int N; cin>>N;
    int T = 2;
    while(N != 1){
        if(!(N%T)){
            cout<<T<<'\n';
            N = N/T;
        }
        else{
            T++;
        }
    }
}