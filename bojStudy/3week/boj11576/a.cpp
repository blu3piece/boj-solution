#include<iostream>
#include<vector>
using namespace std;

int main(){
    int baseA, baseB; cin>> baseA>>baseB;
    int lenA; cin>>lenA;
    vector<int> A(lenA);
    vector<int> B;
    for(int i = 0; i<lenA; ++i){
        cin>>A[lenA - i - 1];
    }
    int decimal = 0;
    int carry = 1;
    for(int i = 0; i<lenA; ++i){
        decimal += A[i]*carry;
        carry *= baseA;
    }
    while(decimal){
        int tmp;
        tmp = decimal%baseB;
        decimal /= baseB;   
        B.push_back(tmp);
    }
    for(int i = B.size() - 1; i >= 0; --i){
        cout<<B[i]<<" ";
    }
    return 0;
}