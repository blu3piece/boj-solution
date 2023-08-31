#include<cstdio>
#include<cmath>
// 규칙을 찾아서 수학적으로 증명하는 문제..
// 관련 문제를 많이 풀어봐야 늘 것 같다.

int main(){
	int x, y;
	int k_n = 0;
	int t; scanf("%d", &t);
	while(t--){
		int x, y, N; scanf("%d %d", &x, &y);
		N = x - y > 0 ? x - y : y - x;
		double SqrtVal = sqrt(N);
		int IntVal = (int)SqrtVal;
		int overhead = 2*IntVal - 1;
		if(N == 1) printf("%d\n", 1);
		else if(SqrtVal - (double)IntVal > (double)0.5)
			printf("%d\n", overhead+2);
		else if(SqrtVal - (double)IntVal < (double)0.5 && (SqrtVal - (double)IntVal))
			printf("%d\n", overhead+1);
		else
			printf("%d\n", overhead);
	}
}
