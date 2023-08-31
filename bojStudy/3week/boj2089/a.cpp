#include<iostream>
using namespace std;

string solve(int N){
    if(N == 0) return "0";
    string node = "1";
    if(N == 1) return node;
    if(N%-2 == 0) return solve(N/-2) + "0";
    if(N%-2 == -1) return solve(N/-2 + 1) + node;
    else return solve(N/-2) + node;
}

int main(){
    int N; cin>>N;
    cout<<solve(N);
}