#include <stdlib.h>
#include <stdio.h>

void print(int* n, char* schar, char* dchar) {
	printf("%lu %d '%s'\n", (unsigned long)n, *n, (char*)n);
	printf("%lu %d '%s'\n", (unsigned long)schar, *(int*)schar, schar);
	printf("%lu %d '%s'\n", (unsigned long)dchar, *(int*)dchar, dchar);
}

int main() {
	int n = 0;
	char schar[4] = { 0 };
	char* dchar = calloc(4, 1);
	char* ptr = (char*)& n;
	int* sint = (int*)schar; // &schar[0];
	int* dint = (int*)dchar; //&dchar[0];
	if (dchar == NULL) return;
	print(&n, schar, dchar);
	//
	n = 0x656854;
	*sint = (48 << 16) + (48 << 8) + (49);
	*dint = 0x213F;
	print(&n, schar, dchar);

	ptr[0] = 100;
	ptr[1] = 0;
	ptr[2] = 0;
	ptr[3] = 0;
	schar[0] = 0xE3;
	schar[1] = 0x7;
	schar[2] = 0;
	schar[3] = 0;
	const int number = 987654321;
	dchar[0] = 0xFF & number;
	dchar[1] = (0xFF00 & number) >> 8;
	dchar[2] = (0xFF0000 & number) >> 16;
	dchar[3] = (0xFF000000 & number) >> 24;
	print(&n, schar, dchar);
}