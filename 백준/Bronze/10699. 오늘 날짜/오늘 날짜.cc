#define _CRT_SECURE_NO_WARNINGS

#include<ctime>
#include<cstdio>
using namespace std;

int main() {
	time_t timer = time(0);
	struct tm* t = localtime(&timer);
	t->tm_hour += 9;
	mktime(t);
	printf("%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}