#include<iostream>
#include<algorithm>
using namespace std;

int arr[200000];

int solve(int N, int C, int start, int end, int answer){
    if(start > end) return answer;
    int spot = 0;
    int count = 1;
    int mid = (start+end)/2;
    for(int i = 1; i<N; ++i){
        if(arr[i] - arr[spot] >= mid){
            spot = i;
            count++;
        }
    }
    if(count >= C){
        answer = answer < mid ? mid : answer;
        return solve(N, C, mid + 1, end, answer);
    }
    return solve(N, C, start, mid - 1, answer);
}

int main(){
    int N, C; cin>>N>>C;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr, arr + N);
    cout<<solve(N, C, 1, arr[N-1] - arr[0], -1);
}