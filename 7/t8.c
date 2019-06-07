#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"




void list_sort(list_t * list) 
{
	if (list->head == list->tail) 
	{
		return;
	}
	int pivot = list->head->val;
	element_t * pivot_node = list->head;
	list->head = list->head->next;
	list_t * first = list_create();
	list_t * second = list_create();
	element_t * curr = list->head;
	element_t * next;
	while (curr != NULL) 
	{
		next = curr->next;
		curr->next = NULL;
		if (curr->val <= pivot) 
		{
			list_append(first, curr);
		} 
		else 
		{
			list_append(second, curr);
		}
		curr = next;
	}
	list->head = NULL;
	list->tail = NULL;

}

/*void list_sort(list_t *list)
{
	list_t * newlist = list_create();
	element_t * curr = list->head;
	while (curr != NULL) {
        element_t * next = curr->next;
        list_append(list, curr);
        curr = next;
    }
	list_t tmp;
	
    	tmp = *list;
    	*list = *newlist;
   	*newlist = tmp;
    	free(newlist);
}*/

/*void list_sort(list_t *list)
{
	if (list->head == list->tail)
	 {
       		 return;
	 }
	int pivot = list->head->val;
    	element_t * pivot_node = list->head;
    	list->head = list->head->next;
	// partition
	list_t * first = list_create();
    	list_t  *second = list_create();
    	element_t * curr = list->head;
    	element_t * next;
	
	while (curr != NULL) 
	{
	        next = curr->next;
	        curr->next = NULL;
	        if (curr->val <= pivot) 
		{
	            list_append(first, curr);
	        } 
		else 
		{
      		    list_append(second, curr);
       		 }
        	curr = next;
   	 }
    	list->head = NULL;
    	list->tail = NULL;
	
	list_sort(first);
   	list_sort(second);

    	// join
   list_prepend(list, first);
   list_append(list, pivot_node);
   list_prepend(list, second);
}*/




