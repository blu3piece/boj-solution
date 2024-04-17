#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[300001];

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n; cin>>n;
  double t = n*0.15;
  
  if(n == 0) {
    cout<<0;
    return 0;
  }
  for(int i=0; i<n; ++i) {
    cin>>arr[i];
  }
  sort(arr, arr + n);
  int s = round(t);
  double ans = 0;
  int cnt = n-2*s;
  for(int i=s; i<n-s; ++i) {
    ans += arr[i];
  }
  cout<<round(ans/cnt);
}