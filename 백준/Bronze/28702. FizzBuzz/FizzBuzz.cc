#include<iostream>
#include <string>
using namespace std;

int main() {
    string t;
    int next_num;
    bool finish = false;
    for(int i=0; i<3; ++i) {
        cin>>t;
        if(!finish && t != "Fizz" && t != "Buzz" && t != "FizzBuzz") {
            next_num = stoi(t) + (3 - i);
            finish = true;
        }
    }
    if(!(next_num%15)) cout<<"FizzBuzz";
    else if(!(next_num%3)) cout<<"Fizz";
    else if(!(next_num%5)) cout<<"Buzz";
    else cout<<next_num;   
}