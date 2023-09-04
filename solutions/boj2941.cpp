#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
    cin >> input;
    int cnt = 0;
    for(int i = 0; i<input.length(); i++){
        if(input[i] <= 'z' && input[i] >= 'a'){
            if(i > 0 && input[i] == 'j' && (input[i-1] == 'n' || input[i-1] == 'l')){
                cnt--;
            }
        }
        else{
            if(i > 0 && input[i] == '='){
                if(i > 1 && input[i-1] == 'z' && input[i-2] == 'd')
                    cnt -= 2;
                else if(input[i-1] == 's' || input[i-1] == 'z' || input[i-1] == 'c')
                    cnt--;
            }
            else if(i > 0 && input[i] == '-'){
                if(input[i-1] == 'd' || input[i-1] == 'c')
                    cnt--;
            }
        }
        cnt++;
    }
    cout<<cnt;
}