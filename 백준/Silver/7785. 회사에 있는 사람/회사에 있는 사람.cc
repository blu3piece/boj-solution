#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    unordered_map<string, bool> hmap;
    while(n--) {
        string m, s; cin>>m>>s;
        if(s == "enter") hmap[m] = true;
        else if(hmap[m]) {
            hmap[m] = false;
        }
    }
    vector<string> ans;
    for(auto k : hmap) {
        if(k.second) {
            ans.push_back(k.first);
        }
    }
    sort(ans.begin(), ans.end(), greater<string>());
    for(string t : ans) cout<<t<<'\n';
}