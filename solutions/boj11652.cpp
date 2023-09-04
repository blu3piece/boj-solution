#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100000];

int main(){
    int N; cin>>N;
    for(int i = 0; i<N; ++i) cin>>arr[i];
    sort(arr, arr + N);

    long long cursor = arr[0];
    int count = 0;
    int maxcount = 0;
    long long maxnum = 0;

    for(int i = 0; i<N; ++i) {
        if(cursor == arr[i]){
            count++;
            if(maxcount < count){
                maxnum = cursor;
                maxcount = count;
            }
        }
        else {
            cursor = arr[i];
            count = 1;
        }
    }
    cout<<maxnum;
}
