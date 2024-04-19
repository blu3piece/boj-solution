#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

// 시간을 보다 더 압축한 버전
// vector 등의 자료구조를 사용안했음

pair<int, int> arr[1000001];
int ans[1000001];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    int idx = 0;
    int prev = arr[0].first;

    for(int i = 0; i<n; ++i) {
        if(prev != arr[i].first) idx++;
        ans[arr[i].second] = idx;
        prev = arr[i].first;
    }
    for(int i=0; i<n; ++i) {
        cout<<ans[i]<<' ';
    }
}