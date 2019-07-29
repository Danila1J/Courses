#include <stdio.h>

void print_memory(const void* ptr) {
	printf("Bytes from #%llu:\n", (unsigned long long) & ptr);
	for (size_t i = 0; i < 32; i++) {
		putchar(((const char*)ptr)[i]);
	}
	putchar('\n');
}

int main() {
	char str[8] = { 0 };
	int a = 65;
	printf("%llu %llu\n", (unsigned long long) str, (unsigned long long) & a);
	print_memory(str + sizeof(str));
	printf("'%s' %d\n", str, a);
	scanf("%s", str);
	printf("'%s' %d\n", str, a);
}