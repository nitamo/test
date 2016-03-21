#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5


void newArray(char ** p) {
	char a[] = {'f','g','h','i','j','\0'};

	char * v = malloc((SIZE + 1) * sizeof(char));
	strcpy(v, a);
	
	printf("\n");

	char * t = v;
	for(; *v != '\0'; v++) {
		printf("%c", *v);
	}
	v = t;

	*p = v;
}

int main() {

	char a[] = {'a','b','c','d','e','\0'};

	printf("Array size is: %lu\n", strlen(a));
	printf("Array's first element address is: %lu\n", a);

	char * p = a;

	printf("Pointer address is: %lu\n", p);

		
	for(int i = 0; i <= strlen(a); i++) {
		printf("%c", a[i]);
	}

	printf("\n");

	for(p = a; *p != '\0'; p++) {
		printf("%c", *p);
	}

	printf("\n");

	for(p = a; *p != '\0'; p++) {
		printf("%lu\n", p);
	}

	newArray(&p);
	
	char * t = p;
		
	printf("\n");

	for(p = t; *p != '\0'; p++) {
		printf("%c", *p);
	}

	printf("\n");

	for(p = t; *p != '\0'; p++) {
		printf("%lu\n", p);
	}

	free(t);

	return 0;
}

