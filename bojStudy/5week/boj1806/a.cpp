#include<iostream>
using namespace std;

int arr[100000];

int main(){
    int N, S; cin>>N>>S;
    for(int i=0; i<N; ++i) cin>>arr[i];

    int start = 0, end = 0;

    int ans = -1; // 최소 길이
    int cnt = 1; // 현재 길이

    int sum = arr[0];

    while(start <= end){
        if(start == N - 1) break;
        if(sum < S){
            sum += arr[++end];
            cnt++;
        }
        if(sum >= S){
            if(ans == -1 || ans > cnt){
                ans = cnt;
            }
            sum -= arr[start++];
            cnt--;
        }
    }
    cout<<((ans == -1) ? 0 : ans);
}