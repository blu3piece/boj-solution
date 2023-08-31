#include<iostream>
#include<algorithm>
using namespace std;

int arr[500001];

int hasCard(int index, int start, int end){
    if(start == end){
        if(index == arr[start]) return 1;
        return 0;
    }
    int mid = (start + end)/2;
    if(arr[mid] > index) return hasCard(index, start, mid);
    if(arr[mid] < index) return hasCard(index, mid + 1, end);
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;cin>>N;
    for(int i=0; i<N; ++i) cin>>arr[i];
    sort(arr, arr + N);
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int tmp; cin>>tmp;
        cout<<hasCard(tmp, 0, N-1)<<' ';
    }
}