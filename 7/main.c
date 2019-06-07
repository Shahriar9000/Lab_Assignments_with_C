#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*int main( int argc, char* argv[] )
{
  list_t* list = list_create();
	if (list == NULL)
		{ return 1;}
	if (head->next != NULL)
		{ return 1;}
	if (tail->next != NULL)
		{ return 1;}

  for( int i=0; i<5; i++ )
    {
	list_append( list, i );
	
    }
  
  for( int i=-1; i>-5; i-- )
    list_prepend( list, i );
  
  list_print( list );

  
  int index = 2;
  element_t* el = list_index( list, index );
  
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  
  printf( "value at index %d is %d\n", index, el->val );
  
  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list );

  return 0; // tests pass
}*/

int main(int argc, char* argv[]) {
	list_t* list = list_create();
	for(int i = 0; i < 5; i++)
		list_append(list, i);
	for(int i = -1; i > -5; i--)
		list_prepend(list, i);
	printf("Array: ");
	list_print(list);
	int index = 2;
	element_t* el_1 = list_index(list, index);
	if(el_1 == NULL) {
		printf("FAIL index %d is not in array\n", index);
		return 1; 
	}
	printf("value at index %d is %d\n", index, el_1->val);
	printf("Next Task\n");
	printf("Testing tasks 2 to 6\n");
	if(el_1->val != -2) 
		return 1;
 
 
 
 
	//Task 2
	printf("Testing Task 2\n");
	element_t* el_2 = element_create(9);
	if(el_2->val != 9) {
		printf("el_2->val is supposed to be 9 but isn't\n");
		return 1;
	}
 
	if(el_2 == NULL) {
		printf("MEM ALLOC FAIL");
		return 1;
	}
 
	element_t* el_3 = element_create(99);
	list_t* list_2 = list_create();
	for(int i = 0; i < 5; i++)
		list_append( list_2, i);
	for(int i = -1; i > -5; i--)
		list_prepend(list_2, i);
	if (list->tail->val != 4){
		printf("TAIL ERROR\n");
		return 1;
	}
 
	el_3->next = list_index(list_2, 3);
	free(el_3->next);
	el_3 = element_create(100);
	if(el_3->next != NULL){
		printf("el_3->next is supposed to be NULL but isn't\n");
		return 1;
	}
	printf("Task 2 Passed\n");
 
 
 
 
	//Task 3
	printf("Testing Task 3\n");
	list_t* list_3 = list_create();
	element_t* el_4 = list_index(list_3, 5);
	if(el_4 != NULL) {
		printf("el_4 is supposed to be NULL but isn't\n");
		return 1;
	}
	printf("Task 3 Passed\n");
 
 
 
 
	//Task 4
	printf("Testing Task 4\n");
	list_t* list_4 = list_create();
	list_prepend(list_4, 800);
	if(list_4->tail->val != 800) {
		printf("list_4->tail is supposed to be 800 but isn't\n");
		return 1;
	}
	printf("Task 4 Passed\n");
 
 
 
 
	//Task 5
	printf("testing list_create(t5)...\n");
	list_t* list_5 = list_create();
	list_5->head = element_create(666);
	list_5->head->next = element_create(333);
	list_5->tail = list_5->head->next;
	free(list_5);
	list_5 = list_create();
 
	if(list_5->tail != NULL) {
		printf("list_5->head is supposed to be NULL\n but isn't");
		return 1;
	}
	printf("Task 5 Passed\n");
 
 
	//Task 6
	printf("Testing Task 6\n");
	list_t* list_6 = list_create();
	list_print(list_6);
	printf("Task 6 Passed\n");
 
	//get rid of arrays
	list_destroy(list);
	list_destroy(list_2);
	list_destroy(list_3);
	list_destroy(list_4);
	list_destroy(list_5);
	list_destroy(list_6);
 
	printf("Tasks 2 to 6 have all passed\n");
	return 0; 
}
