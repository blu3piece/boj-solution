#include<iostream>
using namespace std;

int counts[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    int tmp;
    for(int i = 0; i<N; ++i){
        cin>>tmp;
        ++counts[tmp];
    }
    int i = 1;
    while(i <= 10000){
        if(counts[i] != 0){
            for(int j = 0; j<counts[i]; ++j) cout<<i<<'\n';
            counts[i] = 0;
        }
        ++i;
    }
    return 0;
}
