#include <stdio.h>


int main(int argc, char const *argv[])
{
	char *message = "Hello";
	char message1[] = "World";
	char *ptr = message1;

	printf("%s\n", "This is my first C programm");
	printf("%s\n", "I'm am embedded programmer");


	puts("Put string is working\n");

	printf("%s\n", message);

	puts(message);

	puts(ptr);

	return 0;
}