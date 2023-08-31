#include<iostream>
using namespace std;

int solve(int N){
    if(N <= 1) return 1;
    return solve(N-1)*N;
}

int main(){
    int N; cin>>N;
    cout<<solve(N);
}