#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

// typedef enum BOOL { false, true } Boolean;

// // Linked list node definition
// typedef struct NODE Node;

// struct NODE
// {
  // char *string;
  // Node *next;
// };

static Node *top = NULL;
static int numNodes = 0;
 
// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

int size( )
{
	assert(numNodes>=0);
    return numNodes;
}
    
// add an element to the beginning of the linked list
Boolean insert( char const * const new_string )
{
	assert(new_string != NULL);
	assert(strcmp(new_string,""));
  Boolean rc = true;
  Node *newNode = NULL;
  
  newNode = (Node *)malloc( sizeof( Node ) );
  assert(newNode != NULL);
  newNode->next = top;
  top = newNode;
  
  // note that we need to have space for the string as well!
  newNode->string = (char *)malloc( strlen(new_string) + 1 );
  strcpy( newNode->string, new_string );
  numNodes++;
  
  return rc;
}


// remove an element with the given string
Boolean delete( char const * const target )
{
  Boolean deleted = false;
  Node *curr = top;
  Node *prev = NULL;
  assert(target!=NULL);
  assert(curr->string!=NULL);
  while ( curr != NULL && strcmp( target, curr->string ) != 0 )
  {
    prev = curr;
    curr = curr->next;
  }

  if ( curr != NULL )
  {
    if ( prev != NULL )
      prev->next = curr->next;
    else
      top = curr->next;
    
    free( curr->string );
    free( curr );
    deleted = true;
    numNodes--;
  }
  
  return deleted;
}

// tells us whether or not the given string is in the list
Boolean search( char const * const target )
{
  Boolean found = false;
  Node *curr = top;
  
  while ( curr != NULL && !found )
  {
    if ( strcmp( target, curr->string ) == 0 )
    {
      found = true;
    }
    
    else
    {
      curr = curr->next;
    }
  }
  
  return found;
}


// starts a list traversal by getting the data at top
char * firstItem()
{
	assert(top!=NULL);
  traverseNode = top->next;
  assert(top->string!=NULL);
  assert(strcmp(top->string,"")!=0);
  return top->string;
}


// gets the data at the current traversal node and increments the traversal
char * nextItem()
{
  char *item = NULL;
  
  // no need to go past the end of the list...
  if ( traverseNode != NULL )
  {
    item = traverseNode->string;
    traverseNode = traverseNode->next;
	assert(item!= NULL);
	assert(strcmp(item,"")!=0);
  }
 
  return item;
}
//ADDED! free's memory of table that is not deleted before at the end of the program to prevent memory leaks
void clearTable()
{
	Node *curr = top;
	while(top!=NULL)
	{
		top = top->next;
		free(curr);
		curr = top;
	}
	assert(top==NULL);
}