#include<iostream>
#include<cmath>
using namespace std;

bool isnotPrime[1000001] = {true, true, };

void init(){
    int base = 2;
    for (int i = 2; i <= sqrt(1000000); i++) {
        for (int j = i + i; j <= 1000000; j += i) {
            if (isnotPrime[j] == false) isnotPrime[j] = true;
        }   
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int N = 1;
    while(N){
        cin>>N;
        if(N == 0) return 0;
        bool found = false;
        int i = 3;
        while(1){
            if(N - i < 3){
                cout<<"Goldbach's conjecture is wrong.\n";
                break;    
            }
            if(!isnotPrime[i] && !isnotPrime[N - i]){
                cout<<N<<" = "<<i<<" + "<<N - i<<'\n';
                break;
            }
            i++;
        }
    }
}