#include<iostream>
using namespace std;

long long R = 31;
long long M = 1234567891;

int main() {
  int n; cin>>n;
  string buf; cin>>buf;
  long long s = 1;
  long long ans = 0;
  for(char t : buf) {
    long long cur = t - 'a' + 1;
    cur *= s;
    cur %= M;

    ans += cur;
    ans %= M;

    s *= R;
    s %= M;
  }
  cout<<ans;
}