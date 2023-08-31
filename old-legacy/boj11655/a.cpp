#include<iostream>
using namespace std;

int main(){
    string input;
    getline(cin, input);
    for(int i = 0; i<input.length(); ++i){
        if('a' <= input[i] && input[i] <= 'z'){
            input[i] += 13;
            if(input[i] > 'z'){
                input[i] %= 'z' + 1;
                input[i] += 'a';
            }
        }
        if('A' <= input[i] && input[i] <= 'Z'){
            input[i] += 13;
            if(input[i] > 'Z'){
                input[i] %= 'Z' + 1;
                input[i] += 'A';
            }
        }
    }
    cout<<input;
    return 0;
}
