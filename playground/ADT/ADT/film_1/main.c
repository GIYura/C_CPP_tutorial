#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TITLE_SIZE	45

typedef struct{
	char title[TITLE_SIZE];
	int rating;
}film_t;

char* s_gets(char* st, int n);

//
int main(int argc, char **argv)
{
	film_t* movies;
	int film_number = 0;
	int film_cntr = 0;
	puts("Please, enter a number of movies\r\n");
	scanf("%d", &film_cntr);
	getchar();
	movies = (film_t*)malloc(sizeof(film_t) * film_cntr);
	if(movies == NULL){
		printf("Can't allocate memory\r\n");
		return -1;
	}
	
	puts("Input the title of the first movie\r\n");
	
	while(film_number < film_cntr && s_gets(movies[film_number].title, TITLE_SIZE) != NULL && movies[film_number].title[0] != '\0'){
		puts("Input film rating <0 - 10>:");
		scanf("%d", &movies[film_number].rating);
		if(movies[film_number].rating < 0 || movies[film_number].rating > 10){
			puts("Error ! You've entered the wrong number");
		}
		while(getchar() != '\n'){
			continue;
		}
		film_number++;
		puts("Input the title of the next movie or empty string to stop input:");
	}
	
	if(film_number == 0){
		printf("There is no data\r\n");
	} else {
		printf("The list of films:\r\n");
		for(int j = 0; j < film_number; j++){
			printf("Movie: %s\t\tRating: %d\r\n", movies[j].title, movies[j].rating);
		}
	}
	printf("Game over\r\n");
	return 0;
}

char* s_gets(char* st, int n){
	char* ret_val;
	char* find;
	
	ret_val = fgets(st, n, stdin);
	
	if(ret_val){
		find = strchr(st, '\n');
		if(find){
			*find = '\0';
		} else {
			while(getchar() != '\n'){
				continue;
			}
		}
	}
	return ret_val;
}
