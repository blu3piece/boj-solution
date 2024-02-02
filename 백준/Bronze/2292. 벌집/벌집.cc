#include<iostream>
using namespace std;

int main() {
	int t; cin >> t;
	int ans = 0;
	int six = 1;
	while (t > 0) {
		t -= six;
		if (ans == 0) six--; // 처음 경우의 예외 수 제외
		ans++;
		six += 6;
	}
	cout << ans;
}