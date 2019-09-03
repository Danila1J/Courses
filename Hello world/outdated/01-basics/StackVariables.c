#include <stdio.h>

int main() {
	int a = 0;
	int b = 1;
	int c = 2;
	printf("%llu %llu %llu\n", (unsigned long long) & a, (unsigned long long) & b, (unsigned long long) & c);
	printf("%d %d %d\n", a, b, c);
	int* pb = &b;
	pb += 8;
	*pb = 4;
	printf("%d %d %d\n", a, b, c);
}