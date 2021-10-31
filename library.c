/*

	Realize a program that contains a library with a maximum
	of 100 books. The program asks how many books are there 
	going to be in the library and memorizes the value in a
	variable called N.
	Every book has all 6 information:

		. ISBN code (a sequence of 13 numbers)
		. Autor
		. Title
		. Year of publication
		. Shelf code (an integer number)
		. Cost 

	Then the program has these 4 functions:

		. A function that acquires information for a single book
		. A function that prints the book information
		. A function that prints the costs of a group of books
		  that are on the same shelf
		. A function that prints all of the autors (without duplicates)

*/

#include <stdio.h>
#include <string.h>

#define MAX_ISBN 13
#define MAX_LETTERS 50
#define MAX_BOOKS 100


typedef struct book_s {

	char ISBN[MAX_ISBN+1];
	char autor[MAX_LETTERS];
	char title[MAX_LETTERS];
	int year;
	float cost;
	int shelf_code;

} book_t;

typedef struct library_s {

	book_t books[MAX_BOOKS];
	int num_books;

} library_t;

book_t readbook();

void printbook(book_t);

void printcost(library_t, int shelf);

void printautors(library_t);

int main(int argc, char * argv[]){

	library_t library;
	int i, shelf;

	do{
		printf("How many books would you like to insert?\n");
		scanf("%d", &library.num_books);
		if(library.num_books <= 0 || library.num_books > 100){
			printf("The number that you have put is invalid. Try again!\n");
		}
	} while(library.num_books <= 0 || library.num_books > 100);

	for(i=0; i<library.num_books; i++)
		library.books[i] = readbook();
	
	for(i=0; i<library.num_books; i++)
		printbook(library.books[i]);

	printf("Shelf code?\n");
	scanf("%d", &shelf);
	printf("Cost of books that are on the same shelf:\n");
	printcost(library, shelf);
	printf("Autors:\n");
	printautors(library);


	return 0;
}


book_t readbook(){
	
	book_t result;

	printf("ISBN:\n");
	scanf("%s", result.ISBN);
	
	printf("Autor:\n");
	scanf("%s", result.autor);

	printf("Title:\n");
	scanf("%s", result.title);

	printf("Year:\n");
	scanf("%d", &result.year);

	printf("Cost:\n");
	scanf("%f", &result.cost);

	printf("Shelf code:\n");
	scanf("%d", &result.shelf_code);

	return result;
}

void printbook(book_t book){

	printf("ISBN: %s \n", book.ISBN);

	printf("Autor: %s \n", book.autor);

	printf("Title: %s \n", book.title);

	printf("Year: %d \n", book.year);

	printf("Cost: %f \n", book.cost);

	printf("Shelf code: %d \n", book.shelf_code);

}

void printcost(library_t l, int shelf){

	int i;

	i=0;
	while(i<l.num_books){
		if(l.books[i].shelf_code == shelf){
			printf("Cost: %f\n", l.books[i].cost);
		}
		i++;
	}

}

void printautors(library_t l){

	int i, j, isOK;

	for(i=0; i < l.num_books; i++){
		isOK = 0;
		for(j=0; j < i && isOK == 0; j++){
			if(strcmp(l.books[i].autor, l.books[j].autor) == 0){
				isOK = 1;
			}
		}
		if(isOK == 0)
			printf("Autor: %s\n", l.books[i].autor);
	}


}
