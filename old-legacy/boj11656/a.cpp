#include<iostream>
#include<algorithm>
using namespace std;

string suffix[1000];

int main(){
    string input; cin>>input;
    int N = input.length();
    for(int i = 0; i<N; ++i){
        for(int j = N-1; j>=i; --j){
            suffix[i].insert(0, 1,input[j]);
        }
    }
    sort(suffix, suffix + N);
    for(int i = 0; i<N; ++i){
        cout<<suffix[i]<<'\n';
    }
    return 0;
}
