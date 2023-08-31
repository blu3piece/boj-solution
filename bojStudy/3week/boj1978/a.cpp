#include<iostream>
using namespace std;

int notPrime[1001] = {1, 1, };

int main(){
    int base = 2;
    while(base <= 500){
        for(int i = base + 1; i<= 1000; ++i){
            if(!(i%base)){
                notPrime[i] = 1;
            }
        }
        base++;
    }

    int N; cin>>N;
    int acc = 0;

    for(int i = 0; i<N; ++i) {
        int tmp; cin>>tmp;
        if(!notPrime[tmp]) ++acc;
    }

    cout<<acc;
}