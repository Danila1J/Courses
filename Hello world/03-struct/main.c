#include "Person.h"
#include <stdlib.h>

int main() {
	struct Person* p1 = createPerson("Ivanov", "Danila", "Aleksandrovich", 30, 12, 1999);
	struct Person* p2 = createPerson("Alekseeva", "Liza", "Alekseevna", 26, 6, 1999);
	FILE* f = fopen("data", "w+");
	addPerson(f, p1);
	addPerson(f, p2);
	printPerson(p1);
    struct Person* p3=getPersonByID(f,p1->id);
    printPerson(p3);
	fclose(f);
	free(p1);
	free(p2);
	free(p3);
}
