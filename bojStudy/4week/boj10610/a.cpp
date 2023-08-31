#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000];

int main(){
    string input; cin>>input;
    int N = input.length();
    int sum = 0;
    for(int i=0; i<N; ++i){
        arr[i] = input[i] - 48;
        sum += arr[i];
    }
    sort(arr, arr + N);
    if(arr[0] != 0 || sum%3){
        cout<<-1;
        return 0;
    }
    for(int i=N-1; i>=0; --i)
        cout<<arr[i];
}