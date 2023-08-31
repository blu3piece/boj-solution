#include<iostream>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    for(int i = 0; i<input.length(); ++i){
        if('a' <= input[i] && input[i] <= 'z'){
            input[i] -= 'a';
            input[i] += 13;
            input[i] %= 26;
            input[i] += 'a';
        }
        if('A' <= input[i] && input[i] <= 'Z'){
            input[i] -= 'A';
            input[i] += 13;
            input[i] %= 26;
            input[i] += 'A';
        }
    }
    cout<<input;
    return 0;
}
