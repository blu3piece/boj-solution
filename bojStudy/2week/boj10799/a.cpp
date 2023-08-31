#include<iostream>
using namespace std;

int main(){
    string input; cin>>input;
    int cnt = 0, ans = 0;
    bool opened = false;
    for(int i = 0; i<input.length(); ++i){
        if(input[i] == '('){
            opened = true; // we don't know if this is the lazer input or not.
            cnt++;
        }
        if(input[i] == ')'){
            cnt--; // pop
            if(opened){ // if it's the lazer
                opened = false;
                ans += cnt;
            }
            else ans++; // the left steel stick
        }
    }
    cout<<ans + cnt;
}