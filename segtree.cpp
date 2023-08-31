#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
long long segtree[4000005];
const long long MOD = 1000000007;

long long init(int s, int e, int idx) {
  if(s == e) return segtree[idx] = arr[s];
  int mid = (s+e)/2;
  return segtree[idx] = init(s, mid, idx*2)*init(mid+1, e, idx*2+1)%MOD;
}

long long getNode(int s, int e, int l, int r, int idx) {
  if(s > r || e < l) return 1;
  if(l <= s && e <= r) return segtree[idx];
  int mid = (s+e)/2;
  return (getNode(s, mid, l, r, idx*2)*getNode(mid+1, e, l, r, idx*2 + 1))%MOD;
}

long long update(int s, int e, int where, int to, int idx) {
  if(s > where || e < where) return 1;

  if(s == e) return segtree[idx] = to;
  
  int mid = (s+e)/2;
  
  return segtree[idx] = update(s, mid, where, to, idx*2)*update(mid+1, e, where, to, idx*2 + 1)%MOD;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  int n, m, k; cin>>n>>m>>k;
  for(int i=1; i<=n; ++i) {
    cin>>arr[i];
  }
  init(1, n, 1);
  for(int i=0; i<m+k; ++i) {
    int a,b,c; cin>>a>>b>>c;
    if(a == 1) {
      arr[b] = c;
      update(1, n, b, c, 1);
      cout<<"root:"<<segtree[1]<<'\n';
    }
    else cout<<getNode(1, n, b, c, 1)<<"\n";
  }
}