#include<iostream>
#include<bitset>
using namespace std;

int main(){
    string input;
    cin>>input;
    bool start = true;
    for(int i = 0; i<input.length(); ++i){
        int tmp = input[i] - 48;
        if(!(start && !(tmp >= 4 ? 1 : 0))){
            cout<<(tmp >= 4 ? 1 : 0);
            start = false;
        }
        if(!(start && !(tmp%4 >= 2 ? 1 : 0))){
            cout<<(tmp%4 >= 2 ? 1 : 0);
            start = false;
        }
        cout<<tmp%2;
        start = false;
    }
    return 0;
}