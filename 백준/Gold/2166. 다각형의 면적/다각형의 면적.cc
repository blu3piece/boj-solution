#include<iostream>
#include<cmath>
using namespace std;

int n;

long double x[10001];
long double y[10001];

long double get_cp(int one, int two) {
    // 0번째 좌표와 one 번째와 two 번째 좌표로 하는 삼각형의 외적(넓이 X)
    long double result = 0.0;
    result += x[0]*y[one] + x[one]*y[two] + x[two]*y[0];
    result -= x[one]*y[0] + x[two]*y[one] + x[0]*y[two];
    result /= 2.0;

    return result;
}

int main(){ 
    cin.tie(0)->sync_with_stdio(0);
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%Lf %Lf", &x[i], &y[i]);
    }

    long double result = 0.0;
    for(int i=1; i<n-1; ++i) {
        result += get_cp(i, i+1);
    }

    printf("%.1Lf", abs(result));
}