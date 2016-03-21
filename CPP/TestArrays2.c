#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStrings(char ** p_strings) {
	printf("getStrings has been started\n");

	char *strings[] = {"This is a test program", "I do not understand double pointers", "Let's learn this God's damn old C!"};
	
	char *c_alloc = malloc(sizeof(char) * 3 * 50);

	printf("\"c_alloc\" memory address is:\t\t\t%lu\n", (unsigned long)c_alloc);

	unsigned long address = (unsigned long)c_alloc;

	printf("\"address\" memory address is:\t\t\t%lu\n", address);
	printf("\"address\" points to:\t\t\t\t%lu\n", address);

	for(int i = 0; i < 3; i++) {
		printf("String lenght is:\t\t\t\t%lu\n", strlen(strings[i]));
		strcpy(c_alloc, strings[i]);
		printf("Current string is:\t\t\t\t\"%s\"\n", strings[i]);
		printf("On address: %lu is:\t\t\t\t\"%s\"\n", (unsigned long)c_alloc,  c_alloc);
		c_alloc += strlen(strings[i]);
		c_alloc++;
	}
	printf("\"c_alloc\" memory address is:\t\t\t%lu\n", (unsigned long)c_alloc);
	printf("\"address\" memory address is:\t\t\t%lu\n", address);
	printf("\"address\" points to:\t\t\t\t%lu\n", address);

	char *n_alloc = (char *)address;
	printf("\"n_alloc\" memory address is:\t\t\t%lu\n", (unsigned long)n_alloc);

	for(int i = 0; i < 3 * 50; i++) {
		if(n_alloc[i] >= 0x20 && n_alloc[i] <= 0x7F)
			putchar(n_alloc[i]);
		else
			printf("\'NaS:%d\'", n_alloc[i]);
	}
	printf("\n");

	*p_strings = address;

	printf("getStrings() has ended\n");
}

int main() {
	char * p_strings, * s_strings;
	
	getStrings(&p_strings);
	
	s_strings = p_strings;

	for(int i = 0; i < 3 * 50; i++) {
		if(s_strings[i] >= 0x20 && s_strings[i] <= 0x7F)
			putchar(s_strings[i]);
		else
			printf("\'NaS:%d\'", s_strings[i]);
	}
	printf("\n");

	char * u_strings = p_strings;

	for(int i = 0; i < 3; i++)
	{
		while(*u_strings)
			putchar(*u_strings++);
		u_strings++;
		putchar('\n');
	}

	printf("Trying to free memory...\n");
	free(p_strings);

	return 0;
}
