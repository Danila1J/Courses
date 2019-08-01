#include <stdarg.h>
#include <stdio.h>
#include <math.h>

void printInt(int n) {
	if (n < 0) {
		putchar(45);
		n = -n;
	}
	int count = 0;
	{
		int nc = n;
		if (n == 0) {
			putchar(n);
			return;
		}
		while (nc != 0) {
			nc = nc / 10;
			count++;
		}
	}
	int num = n;
	int div = pow(10, count - 1);
	for (int i = 0; i < count; ++i, div /= 10) {
		int digit = num / div;
		putchar(48 + digit);
		num %= div;
	}
}

void printF(const char* format, ...) {
	va_list args;
	va_start(args, format);
	for (int i = 0; format[i] != 0; ++i) {
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
			printInt(va_arg(args, int));
			++i;
		}
		else {
			putchar(format[i]);
		}
	}
	va_end(args);
}

int main() {
	printF("%d %i pen",456,12);
}