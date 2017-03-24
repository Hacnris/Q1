
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"
void addSuite();
int checkWord(const char * const string);
void printTable();
void searchTest();
void deleteSuite();

//constants for testing
const int MAX_WORD = 50;
const char * word1 = "bert";
const char * word2 = "alpha";
const char * word3 = "perfection";


int main(int argc, char *argv[])
{
	addSuite();
	searchTest();
	deleteSuite();
	clearTable();
	return EXIT_SUCCESS;
}

void addSuite()
{
	printf("Empty Insert\n");
	assert(word1 != NULL);
	insert(word1);
	assert(checkWord(word1));
	printTable();
	printf("first insert \n");
	assert(word2 != NULL);
	insert(word2);
	assert(checkWord(word2));
	printTable();
	printf("second insert \n");
	assert(word3 != NULL);
	insert(word3);
	assert(checkWord(word3));
	printTable();
	printf("end of last insert \n");
	
}

int checkWord(const char * const string )
{
	return(!strcmp(string, firstItem()));
}
void printTable()
{
	char *tableWord = firstItem();
	while(tableWord !=NULL)
	{
		assert(tableWord != NULL && strcmp(tableWord,"")!=0);
		printf("%s\t", tableWord);
		tableWord = nextItem();
	}
	printf("\n");
}

void deleteSuite()
{
	if(delete(word3))
		printf("passed deleting: %s\n", word3);
	if(delete(word1))
		printf("passed deleting: %s\n", word1);
	if(delete("dandy"))
		printf("SOMETHING WENT WRONG YOU DELETED A WORD THAT DIDN'T EXIST!\n");
	else
		printf("passed test! dandy wasn't deleted\n");
}
void searchTest()
{
	if(search(word1))
		printf("Search for %s Passed!\n", word1);
	if(search(word3))
		printf("Search for %s Passed!\n", word3);
	if(search("carp"))
		printf("SEARCH FOR CARP SHOULD HAVE FAILED, YOU FAILED!\n");
	else
		printf("Test worked like it should: CARP was not found\n");
	
}