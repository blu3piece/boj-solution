#include<iostream>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;

typedef pair<pair<int, int>, string> vsc; // vowel, consonant, string.

const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
char chars[15];
int L, C;
stack<string> ans;

bool isVowel(char c){
    for(int i=0; i<5; ++i){
        if(vowel[i] == c) return true;
    }
    return false;
}

int getIdx(char c){
    for(int i=0; i<C; ++i){
        if(c == chars[i]) return i;
    }
    return -1;
}

void push(stack<vsc>& st, vsc node, int i){
    if(isVowel(chars[i])){
        st.push(make_pair(make_pair(node.first.first + 1, node.first.second), node.second + chars[i]));
    }
    else{
        st.push(make_pair(make_pair(node.first.first, node.first.second + 1), node.second + chars[i]));
    }
}

void solve(){
    stack<vsc> st;
    st.push(make_pair(make_pair(0, 0), ""));
    while(!st.empty()){
        vsc node = st.top(); st.pop();
        
        if(node.second.length() == L && 
            node.first.first > 0 && node.first.second > 1){
                ans.push(node.second);
        }
        if(node.second.empty()){
            for(int i=0; i<C; ++i) push(st, node, i);
        }
        else{
            int idx = getIdx(node.second[node.second.length() - 1]);
            for(int i=idx + 1; i<C; ++i) push(st, node, i);
        }
    }
}

int main(){
    cin>>L>>C;
    for(int i=0 ; i<C; ++i) cin>>chars[i];
    sort(chars, chars + C);
    solve();
    while(!ans.empty()){
        cout<<ans.top()<<'\n'; ans.pop();
    }
}