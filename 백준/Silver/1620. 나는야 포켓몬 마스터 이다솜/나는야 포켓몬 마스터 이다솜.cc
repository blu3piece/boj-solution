#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;

unordered_map<string, int> hashmap_int;
string hashmap_str[100001];

int main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; ++i) {
        string tmp; cin>>tmp;
        hashmap_int[tmp] = i;
        hashmap_str[i] = tmp;
    }
    for(int i=0; i<m; ++i) {
        string qr; cin>>qr;
        if('0' <= qr[0] && qr[0] <= '9') {
            int qnum = stoi(qr);
            cout<<hashmap_str[qnum]<<'\n';
        }
        else {
            cout<<hashmap_int[qr]<<'\n';
        }
    }
}