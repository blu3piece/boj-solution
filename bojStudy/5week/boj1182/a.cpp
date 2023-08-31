#include<iostream>
using namespace std;

int arr[20];
int N, S, cnt;

void getSum(int prev, int idx){
    if(idx == N && prev == S){
        cnt++;
    }
    if(idx < N){
        getSum(prev + arr[idx], idx + 1);
        getSum(prev, idx + 1);
    }
}

int main(){
    cin>>N>>S;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N; ++i){
        getSum(arr[i], i + 1);
    }
    cout<<cnt;
}