#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int a, b;
int seg[(1 << 18)]; // N <= 100000

int init(int node, int start, int end){
    if(start == end) return seg[node] = 1;
    int mid = (start + end) / 2;
    return seg[node] = init(2*node, start, mid) + init(2*node + 1, mid + 1, end);
}

int update(int node, int start, int end, int deletenode){
    seg[node]--;
    if(start == end) return 0;
    else{
        int mid = (start + end) / 2;
        if(deletenode <= mid) return update(2*node, start, mid, deletenode);
        else return update(2*node + 1, mid + 1, end, deletenode);
    }
}

int query(int node, int start, int end, int order){
    if(start == end) return start; // found
    int mid = (start + end) / 2;

    if(order <= seg[2*node]) return query(2*node, start, mid, order); // found place at left child.
    else return query(2*node + 1, mid + 1, end, order - seg[2*node]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    init(1, 1, N);

    int index = 1;
    cout<<"<";

    for(int i = 0; i<N; ++i){
        int size = N - i; // total left numbers.
        index += K - 1; // apply initial value & apply deleted index

        if(index % size == 0) index = size; // if index is 0,
        else if(index > size) index %= size; // if out of bound.

        int order = query(1, 1, N, index); // what is real number.

        update(1, 1, N, order);
        cout<<order<<(i == N - 1 ? ">" : ", ");
    }
}