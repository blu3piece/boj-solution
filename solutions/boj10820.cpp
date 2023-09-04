#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    for(int i = 0; i<100; ++i){
        getline(cin, input); // Use Get Line in C++ std
        if(input.length() == 0) break;
        int Upper = 0, Lower = 0, Space = 0, Numeric = 0;
        for(int i = 0; i<input.length(); ++i){
            if(input[i] >= 'A' && input[i] <= 'Z') Upper++;
            if(input[i] >= 'a' && input[i] <= 'z') Lower++;
            if(input[i] == ' ') Space++;
            if(input[i] >= '0' && input[i] <= '9') Numeric++;
        }
        cout<<Lower<<' '<<Upper<<' '<<Numeric<<' '<<Space<<'\n';
    }
}