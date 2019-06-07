//horipyr.c------------------------------------
include <stdio.h>
#include <stdlib.h>


int main (){
	unsigned int xDim,yDim,zDim;
	scanf("%u %u %u",&xDim,&yDim,&zDim);	
	for (int i=0;i<yDim;i++)
	{
		if (i==0 || i == yDim-1)
		{	
			for (int j=0;j<xDim;j++)
			{ 		
				printf("#");
			}
		}
		else if (i!=0 |i!=yDim-1)
		{
		//print first hash then zDim hash then the last hash
			for (int j=0;j<xDim;j++){
				if ((j!=0) && (j!=xDim-1)){				
					printf(".");
				}else{
					printf("#");
				}
			}
		}
		printf("\n");
		
	} 

}

//horipyr2.c--------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    int xDim,yDim,zDim,i,j;
	// find x-coordinates of pyramid edges on the j'th row
	// where x is the pyramid width, z is the pyramid height,
	
	//unsigned int xDim,yDim,zDim;
	scanf("%d %d %d",&xDim,&yDim,&zDim);
	//create for loop for zdim	
	for(i = zDim-1; i >= 0; i--)
	{
		for (j= 0; j <= xDim-1; j++)
		{
			int left = floor(i * (xDim/(2.0*zDim)) );
			int right = ceil( (xDim-1)-i * (xDim/(2.0*zDim)) );
			if (i<=0 || (j == left || j==right))
			{
				printf("#");
			}
			else 
			{
				if (j < left)
				{
					printf(" ");
				}
				else
				{
					if (i == zDim-1 && (j<right))
					{
						printf("#");
					}
					else
					{
						if ((j>left) && (j<right))
						{
							printf(".");
						}
					}
				}
			}
		}
		printf("\n");
	}			
	return 0; 
}

//LL-node.h--------------------------------------

typedef struct _node {
	int data;
	struct _node * next;
} node_t;
//LL.c
#include "LL.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/*
typedef struct {
    node_t * head;
    node_t * tail;
} LL_t;
*/

void LLappendNode(LL_t * intlist, node_t * newNode);

#include "LL-node.h"


typedef struct {
	node_t * head;
	node_t * tail;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();


// Adds a new element to the tail end of a list
void LLappend(LL_t * intlist, int value);


// Outputs the list elements in sequence from head to tail
void LLprint(LL_t * intlist);


// Return 1 iff target is in intlist; 0 otherwise.
int LLsearch(LL_t * intlist, int target);


// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(LL_t * L1, LL_t * L2);


// Pre/Post:  L's data are in sorted orde
void LLquickSort(LL_t * intlist);

// Pre/Post:  intlist is sorted; newNode contains data already
void LLinsertNode(LL_t * intlist, node_t * newNode);

// Pre: intlist not sorted
// Post:  values in intlist are in sorted order
void LLinsertionSort(LL_t * intlist);
// Creates and returns a new, empty list
LL_t * LLcreate() {
    LL_t * ret = malloc(sizeof(LL_t));
    if (ret != NULL) {
        ret->head = NULL;
        ret->tail = NULL;
    }
    return ret;
}


// Adds a new element to the tail end of a list
void LLappend(LL_t * intlist, int value) {
    node_t * newNode = malloc(sizeof(node_t));
    if (newNode != NULL) {
        newNode->data = value;
        LLappendNode(intlist, newNode);
    }
}


// Adds a new node_t to the tail end of a list
// Pre:  newNode != NULL
void LLappendNode(LL_t * intlist, node_t * newNode) {
    if (newNode != NULL) {
        newNode->next = NULL;
        if (intlist->tail == NULL) {
            // empty list
            assert(intlist->head == NULL);
            intlist->head = newNode;
            intlist->tail = newNode;
        } else {
            // non empty list
            intlist->tail->next = newNode; // seg fault
            intlist->tail = newNode;
        }
    }
}


// Outputs the list elements in order from head to tail
void LLprint(LL_t * intlist) {
    // for ( init ; entry ; increment ) {
    for ( node_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->data);
    }
    putchar('\n');

    /*
    node_t * current = intlist->head;
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    putchar('\n');
    */
}


// Return 1 iff target in intlist; 0 otherwise
int LLsearch(LL_t * intlist, int target) {
    // for ( init ; entry ; increment ) {
    /*
    for ( node_t * current = intlist->head; current != NULL ; current = current->next ) {
        printf(" %d", current->data);
    }
    putchar('\n');
    */

    /*
    node_t * current = intlist->head;
    while (current != NULL) {
        if (current->data == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
    */

    if (intlist->head == NULL) {
        assert(intlist->tail == NULL);
        return 0;
    }
    if (intlist->head->data == target) {
        return 1;
    }
    LL_t rest; rest.head = intlist->head->next; rest.tail = (rest.head == NULL) ? NULL : intlist->tail;
    return LLsearch(&rest, target);
}


// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(LL_t * L1, LL_t * L2) {
    if (L2->head == NULL) {
        assert(L2->tail == NULL);
    } else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        //L1->head = L2->head;
        //L1->tail = L2->tail;
        *L1 = *L2;
    } else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}





void LLquickSort(LL_t * intlist) {
    // base case:  0 or 1 node
    if (intlist->head == intlist->tail) {
        return;
    }

    // remove the head from intlist (pivot)
    int pivot = intlist->head->data;
    node_t * pivot_node = intlist->head;
    intlist->head = intlist->head->next;

    // partition
    LL_t * first = LLcreate();
    LL_t * second = LLcreate();
    node_t * curr = intlist->head;
    node_t * next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->data <= pivot) {
            LLappendNode(first, curr);
        } else {
            LLappendNode(second, curr);
        }
        curr = next;
    }
    intlist->head = NULL;
    intlist->tail = NULL;

    //LLprint(first);
    //LLprint(second);

    LLquickSort(first);
    LLquickSort(second);

    // join
    LLcatenate(intlist, first);
    LLappendNode(intlist, pivot_node);
    LLcatenate(intlist, second);
}

// Pre/Post:  intlist is sorted; newNode contains data already
void LLinsertNode(LL_t * intlist, node_t * newNode) {
    // list empty
    if (intlist->head == NULL) {
        assert(intlist->tail == NULL);
        intlist->head = newNode;
        intlist->tail = newNode;
        newNode->next = NULL;
    } else if (intlist->head->data >= newNode->data) {
        // new head
        newNode->next = intlist->head;
        intlist->head = newNode;
    } else {
        // typical case
        node_t * prev = intlist->head;
        node_t * curr = intlist->head->next;
        while (curr != NULL && curr->data < newNode->data) { // insertion pt found while is False
            curr = curr->next;
            prev = prev->next;
        }
        newNode->next = curr;
        prev->next = newNode;
        if (curr == NULL) {
            // new tail
            intlist->tail = newNode;
        }
    }
}


// Pre: intlist not sorted
// Post:  values in intlist are in sorted order
void LLinsertionSort(LL_t * intlist) {
    // create a new [empty] list
    LL_t * newlist = LLcreate();

    // scan through all items and insert 'em
    node_t * curr = intlist->head;
    while (curr != NULL) {
        node_t * next = curr->next;
        LLinsertNode(newlist, curr);
        curr = next;
    }

    // recycle old list
    // swap
    LL_t tmp; 
    tmp = *intlist;
    *intlist = *newlist;
    *newlist = tmp;
    free(newlist);
    //LLdestroy(newlist);


}
//LL.h------------------------------------------------------------
#include "LL-node.h"


typedef struct {
	node_t * head;
	node_t * tail;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();


// Adds a new element to the tail end of a list
void LLappend(LL_t * intlist, int value);


// Outputs the list elements in sequence from head to tail
void LLprint(LL_t * intlist);


// Return 1 iff target is in intlist; 0 otherwise.
int LLsearch(LL_t * intlist, int target);


// joins different L1, L2 such that L1 <- L1 + L2, frees L2
void LLcatenate(LL_t * L1, LL_t * L2);


// Pre/Post:  L's data are in sorted orde
void LLquickSort(LL_t * intlist);

// Pre/Post:  intlist is sorted; newNode contains data already
void LLinsertNode(LL_t * intlist, node_t * newNode);

// Pre: intlist not sorted
// Post:  values in intlist are in sorted order
void LLinsertionSort(LL_t * intlist);

//LinkedListA.c-------------------------------------

LIST IMPLEMENTATION USING ARRAY 
#include<stdio.h> 
#include<conio.h>
#define MAX 20 //maximum no of elements in the list

//user defined datatypes

struct 
{
	int list[MAX];
	int element;//new element to be inserted 
	int pos; //position of the element to be inserted or deleted 
	int length; //total no of elements
}l;

enum boolean { true, false };
typedef enum boolean boolean;

//function prototypes 

int menu(void); //function to display the list of operations 
void create(void); //function to create initial set of elements
void insert(int, int); //function to insert the given element at specified position
void delet(int);//function to delete the element at given position 
void find(int); //function to find the position of the given element, if exists
void display(void); //function to display the elements in the list
boolean islistfull(void);//function to check whether the list is full or not 
boolean islistempty(void); //function to check whether the list is empty or not 

void main() 
{
	int ch;
	int element;
	int pos;
	l.length = 0; 
	while(1) 
	{
		ch = menu();
		switch (ch)
		{
			case 1:
				l.length = 0;
				create();
				break;
			case 2:
				if (islistfull() != true)
				{

					printf("\tEnter the New element : ");
					scanf("%d", &element);
					printf("\tEnter the Position : ");
					scanf("%d", &pos);
					insert(element, pos);
				}
				else 
				{
					printf("\tList if Full. Cannot insert");
					printf("\nPress any key to continue...");
					getch();
				}
				break; 
			case 3: 
				if (islistempty() != true) 
				{
					printf("Enter the position of element to be deleted : 					");
					scanf("%d", &pos);
					delet(pos);
				}
				else 
				{
					printf("List is Empty.");
					printf("\nPress any key to continue...");
					getch();
				}
				break;
			case 4:
				printf("No of elements in the list is %d", l.length);
				printf("\nPress any key to continue...");
				getch();
				break;
			case 5:
				printf("Enter the element to be searched : ");
				scanf("%d", &element);
				find(element);
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Invalid Choice"); 
				printf("\nPress any key to continue..."); 
				getch(); 
		} 
	} 
} 

//function to display the list of elements 

int menu() 
{
	int ch;
	clrscr();
	printf("\n\t\t********************************************\n");
	printf("\t\t******LIST Implementation Using Arrays******\n"); 
	printf("\t\t********************************************\n\n"); 
	printf("\t1. Create\n\t2. Insert\n\t3. Delete\n\t4. Count\n\t5. Find\n\t6. Display\n		\t7. Exit\n\n\tEnter your choice : ");
	scanf("%d", &ch);
	printf("\n\n");
	return ch;
}

//function to create initial set of elements 

void create(void) 
{
	int element;
	int flag=1;
	while(flag==1)
	{
		printf("Enter an element : ");
		scanf("%d", &element);
		l.list[l.length] = element;
		l.length++;
		printf("To insert another element press '1' : ");
		scanf("%d", &flag);
	} 
}

//function to display the elements in the list 

void display(void) 
{
	int i;
	for (i=0; i<l.length; i++)
        	printf("Element %d : %d \n", i+1, l.list[i]);
	printf("Press any key to continue...");
	getch();
}

//function to insert the given element at specified position 

void insert(int element, int pos) 
{
	int i;
	if (pos == 0)
	{
		printf("\n\nCannot insert at zeroth position"); 
		getch(); 
		return; 
	}
	if (pos-1 > l.length) 
	{ 
		printf("\n\nOnly %d elements exit. Cannot insert at %d postion", l.length, 		pos);
		printf("\nPress any key to continue...");
		getch();
	}
	else 
	{
		for (i=l.length; i>=pos-1; i--)
		{
			l.list[i+1] = l.list[i]; 
		}
		l.list[pos-1] = element; 
		l.length++; 
	} 
}

//function to delete the element at given position 

void delet(int pos) 
{
	int i;
	if(pos == 0)
	{
		printf("\n\nCannot delete at zeroth position");
		getch();
		return;
	}
	if (pos > l.length) 
	{
		printf("\n\nOnly %d elements exit. Cannot delete", l.length, pos);
		printf("\nPress any key to continue...");
		getch();
		return;
	}
	for (i=pos-1; i<l.length; i++) 
	{ 
		l.list[i] = l.list[i+1]; 
	}
	l.length--; 
}

//function to find the position of the given element, if exists 

void find(int element) 
{
	int i;
	int flag = 1;
	for (i=0; i<l.length; i++)
	{ 
		if(l.list[i] == element) 
		{
			printf ("%d exists at %d position",element, i+1);
			flag = 0;
			printf("\nPress any key to continue...");
			getch();
			break;
		} 
	}
	if(flag == 1) 
	{
	printf("Element not found.\nPress any key to continue...");
	getch();
	} 
}

//function to check whether the list is full or not 

boolean islistfull(void) 
{ 
	if (l.length == MAX) 
		return true; 
	else 
		return false; 
}

//function to check whether the list is empty or not 

boolean islistempty(void) 
{ 
	if (l.length == 0)
		return true; 
	else 
		return false; 
}

//QueueA.c---------------------------------------------------

CIRCULAR QUEUE IMPLEMENTATION USING ARRAYS
/*Program of queue using array*/
# include
# define MAX 5

int queue_arr[MAX];
int rear = -1;
int front = -1;
int count = 0;

int main()
{
	int choice;
	while(1)
	{
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				enqueue();
				break;
			case 2 :
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
	return 0;
}/*End of main()*/

enqueue()
{
	int added_item;
	if (count==MAX)
		printf("Queue Overflow\n");
	else
	{
	if (front==-1) /*If queue is initially empty */
		front=0;
		printf("Input the element for adding in queue : ");
		scanf("%d", &added_item);
		rear=rear+1;
		if (rear==MAX)
			rear=0;
		queue_arr[rear] = added_item ;
		count++;
	}
}/*End of insert()*/

dequeue()
{
	if (front == -1 || count==0)
	{
	printf("Queue Underflow\n");
	return ;
	}
	else
	{
	printf("Element deleted from queue is : %d\n", queue_arr[front]);
	front=front+1;
	if (front==MAX)
		front=0;
	count--;
	}
}/*End of del() */

display()
{
	int i;
	if (front == -1)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		for(i=front;i<= rear;i++)
			printf("%d ",queue_arr[i]);
		printf("\n");
	}
}/*End of display() */





LINEAR QUEUE IMPLEMENTATION USING ARRAYS
/*Program of queue using array*/
# include
# define MAX 5

int queue_arr[MAX];
int rear = -1;
int front = -1;
int count = 0;

int main()
{
	int choice;
	while(1)
	{
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				enqueue();
				break;
			case 2 :
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
	return 0;
}/*End of main()*/

enqueue()
{
	int added_item;
	if (count==MAX)
		printf("Queue Overflow\n");
	else
	{
	if (front==-1) /*If queue is initially empty */
		front=0;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	rear=rear+1;
	queue_arr[rear] = added_item ;
	count++;
	}
}/*End of insert()*/

dequeue()
{
	if (count == 0)
	{
	printf("Queue Underflow\n");
	return ;
	}
	else
	{
	printf("Element deleted from queue is : %d\n", queue_arr[front]);
	count--;
	if (count == 0)
		front = -1;
	else
		for(i=0; i<rear; i++)
			queue_arr[i] = queue_arr[i+1]
		rear=rear-1;
	}
}/*End of del() */

display()
{
	int i;
	if (front == -1)
		printf("Queue is empty\n");
	else
	{
		printf("Queue is :\n");
		for(i=front;i<= rear;i++)
			printf("%d ",queue_arr[i]);
		printf("\n");
	}
}/*End of display() */

//StackA.c-------------------------------------------------------------

STACK IMPLEMENTATION USING ARRAYS
/* Program of stack using array*/
#include
#define MAX 5

int top = -1;
int stack_arr[MAX];

main()
{
	int choice;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

push()
{
	int pushed_item;
	if(top == (MAX-1))
		printf("Stack Overflow\n");
	else
	{
		printf("Enter the item to be pushed in stack : ");
		scanf("%d",&pushed_item);
		top=top+1;
		stack_arr[top] = pushed_item;
	}
}/*End of push()*/

pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
	{
		printf("Popped element is : %d\n",stack_arr[top]);
		top=top-1;
	}
}/*End of pop()*/

display()
{
	int i;
	if(top == -1)
		printf("Stack is empty\n");
	else
	{
		printf("Stack elements :\n");
		for(i = top; i >=0; i--)
			printf("%d\n", stack_arr[i] );
	}
}/*End of display()*/

//



