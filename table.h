#ifndef _table_h_
#define _table_h_

typedef enum BOOL { false, true } Boolean;
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};
//PROTOTYPE DECLARATIONS
int size();
Boolean insert(char const * new_string);
Boolean delete(char const*const target);
Boolean search(char const * const target);
char * firstItem();
char * nextItem();
void clearTable();
#endif