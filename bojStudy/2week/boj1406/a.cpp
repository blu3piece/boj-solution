#include<iostream>
#include<string>
using namespace std;

int main(){
    string edit; cin>>edit;
    int t, cursor; cin>>t;
    cursor = edit.length();
    while(t--){
        char cmd; cin>>cmd;
        if(cmd == 'P'){
            char tmp; cin>>tmp;
            edit.insert(cursor++, 1, tmp);
        }
        else if(cmd == 'B' && cursor > 0) edit.erase(--cursor, 1);
        else if(cmd == 'L' && cursor > 0) cursor--;
        else if(cmd == 'D' && cursor < edit.length()) cursor++;
    }
    cout<<edit;
}