#include<iostream>
using namespace std;

bool isnotPrime[1000001] = {true, true, };

int main(){
    int base = 2;
    while(base<=1000000){
        for(int i = 2*base; i<=1000000 && !isnotPrime[base]; i += base){
            isnotPrime[i] = true;
        }
        base++;
    }
    int N, M; cin>>N>>M;
    for(int i = N; i<=M; ++i){
        if(!isnotPrime[i]) cout<<i<<'\n';
    }
    return 0;
}