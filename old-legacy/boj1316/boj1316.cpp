#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    int grpnum = 0;
    while(t--){
        string name;
        cin>>name;
        bool isGrp = true;
        char formal;
        vector<char> charset;
        for(int i = 0; i<name.length(); ++i){
            if(i > 0) formal = name[i-1];
            for(char t : charset){
                if(name[i] == t && name[i] != formal){
                    isGrp = false;
                    break;
                }
            }
            if(!isGrp) break;
            charset.push_back(name[i]);
        }
        if(isGrp) grpnum++;
    }
    cout<<grpnum;
    return 0;
}
