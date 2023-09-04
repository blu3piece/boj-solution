#include<iostream>
using namespace std;

string arr;
int cache[5001];

int solve(int N){
    // return numbers of cases which arr is N length.
    if(cache[N]) return cache[N];
    cache[N] = solve(N-1);
    if(arr[N-1] - 48 == 1) cache[N] *= 2;
    if(arr[N-1] - 48 == 2 && arr[N] - 48 < 7) cache[N] += cache[N-1];
    return cache[N];
}

int main(){
    cache[1] = 1;
    cin >> arr;
    cout << solve(arr.length());
    return 0;
}