#include<iostream>
using namespace std;

int A[1000000];
int B[1000000];
int C[2000000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int lenA, lenB; cin>>lenA>>lenB;
    int cursorA = 0, cursorB = 0;
    int cursorC = 0;
    for(int i=0; i<lenA; ++i) cin>>A[i];
    for(int i=0; i<lenB; ++i) cin>>B[i];
    while((cursorA < lenA) && (cursorB < lenB)){
        if(A[cursorA] < B[cursorB]){
            C[cursorC++] = A[cursorA++];
        }
        else C[cursorC++] = B[cursorB++];
    }
    while(cursorA < lenA) C[cursorC++] = A[cursorA++];
    while(cursorB < lenB) C[cursorC++] = B[cursorB++];
    for(int i=0; i<cursorC; ++i) cout<<C[i]<<' ';
}