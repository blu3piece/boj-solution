#include<iostream>
#include<algorithm>
using namespace std;
long long arr[1000000];

long long getHeight(int N, long long M, long long start, long long end, long long answer){
    if(start >= end){
        return answer;
    }
    long long mid = (start + end)/2;
    long long value = 0;
    for(int i = 0; i<N; ++i){
        if(arr[i] > mid) value += arr[i] - mid;
    }
    answer = M < value ? mid : answer;
    if(M < value) return getHeight(N, M, mid + 1, end, answer);
    if(M > value) return getHeight(N, M, start, mid, answer);
    return mid;
}

int main(){
    int N; long long M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr, arr + N);
    cout<<getHeight(N, M, 0, arr[N - 1], -1);
}