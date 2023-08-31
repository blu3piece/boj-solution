#include<iostream>
using namespace std;

int graph[10][10];
int answer = -1;
int N;
bool visit[10];

void traversal(int start, int left, int where, int cost){
    if(left == 1){
        if(graph[where][start]){
            cost += graph[where][start];
            answer = (answer == -1 || answer > cost) ? cost : answer;
        }
        return;
    }
    visit[where] = true;
    for(int i=0; i<N; ++i){
        if(!visit[i] && graph[where][i]){
            traversal(start, left-1, i, cost + graph[where][i]);
        }
    }
    visit[where] = false;
}

int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cin>>graph[i][j];
    }
    for(int i=0; i<N; ++i) traversal(i, N, i, 0);
    cout<<answer;
}