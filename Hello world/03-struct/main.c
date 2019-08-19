#include "Person.h"
#include <stdlib.h>

int main() {
    struct Database* d=openDatabase("data");
	struct Person* p1 = createPerson("Ivanov", "Danila", "Aleksandrovich", 30, 12, 1999);
	struct Person* p2 = createPerson("Alekseeva", "Liza", "Alekseevna", 26, 6, 1999);
	addPerson(d, p1);
	addPerson(d, p2);
	printPerson(p1);
	printPerson(p2);
	removePerson(d,1);
	printPerson(p1);
	printPerson(p2);
	closeDatabase(d);
	free(p1);
	free(p2);
}
