#include<iostream>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    
    if(b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    cout.tie(0); cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        int m,n,x,y; cin>>m>>n>>x>>y;
        int larger = m > n ? m : n;
        int larger_remain = m > n ? x : y;
        int max_num = m*n / gcd(m, n);
        bool found = false;
        
        for(int i=larger_remain; i<=max_num; i += larger) {

            if (i%m == x%m && i%n == y%n) {
                found = true;
                cout<<i<<'\n';
                break;
            }
        }
        if(!found) cout<<"-1\n";
    }
}