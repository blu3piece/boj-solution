/**
 * @file kmp.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 * 아직 이해가 안되는 부분?
 * 
 * 1. for 문 : i는 최대 1번만 봐도 되기 때문에 i에 관한 증감 연산이 for문 내에 있을 필요가 없다.
 * 2. while 문 : while 문을 적어둔 이유는 W = "abaabaaba" 같은 경우는 W 길이의 절반 이상으로 접두사/접미사값이 되기때문이다.
 * 이런 경우 한번만 해당 while문(실패함수 위치로 돌아가기) 수행하게 된다면, 모든 일치가 있을 경우의 수를 계산하지 않고 건너뛰게 된다.
 * 
 * 
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n, m;
string t, p;
vector<int> ans_list;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, t); getline(cin, p);
	vector<int> fail(p.size(), 0);
	int ans = 0;
	for (int i = 1, j = 0; i < p.size(); ++i) {
		// i = 1인 이유 : 접두사 와 접두사를 비교하지 않게 하기 위해서.
		while (j > 0 && p[i] != p[j]) {
			// p[i] == p[j] 가 된다면 그때가 바로 일치하는 때이고,
			// 접미사와 접두사 비교중에 이미 틀렸으니 다음 단계로 넘어가는 과정이다.
			// i를 옮길 필요없이 비교표 기준으로 j를 뒤로 땡기면 되니까
			j = fail[j - 1];
		}
		if (p[i] == p[j]) {
			fail[i] = ++j;
		}
	}

	for (int i = 0, j = 0; i < t.size(); ++i) {
		while (j > 0 && t[i] != p[j]) {
			j = fail[j - 1];
			
		}
		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				ans_list.push_back(i - p.size() + 2);
				j = fail[j];
			}
			else ++j;
		}
	}

	cout << ans_list.size() << "\n";
	for (int t : ans_list) {
		cout << t << ' ';
	}
}