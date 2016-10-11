//Jennifer Yu
//10-09-16

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node *nodeptr) {
//JOB DESCRIPTION
//Should take a pointer to a node struct and
//print out all of the data in the list

  printf("%d", nodeptr->i); //print first node
  nodeptr = nodeptr->next; //access next node using pointer

  while (nodeptr) { //nodeptr != 0, while there are still nodes
    printf(", %d", nodeptr->i); //print next node
    nodeptr = nodeptr->next; //access nextnext node
  }

  printf("\n"); //end list

}


struct node * insert_front(struct node *nodeptr, int data) {
//JOB DESCRIPTION
//Should take a pointer to the existing list and
//the data to be added, create a new node,
//put it at the beginning of the list and
//return a pointer to the beginning of the list.

  struct node * newnode = (struct node *) malloc(sizeof(struct node)); //create a new node

  newnode->i = data; //input data
  newnode->next = nodeptr; //input pointer

  return newnode; //return first pointer, which should be the new node

}

struct node * free_list(struct node *nodeptr) {
//JOB DESCRIPTION
//Should take a pointer to a list as a parameter and
//then go through the entire list freeing each node and
//return a pointer to the beginning of the list
//(which should be NULL by then).

  struct node * retptr = nodeptr; //create pointer to beginning of list

  while (nodeptr) { //nodeptr != 0, while there are still nodes
    struct node * nextnode = nodeptr->next; //move to next node
    free(nodeptr); //free the previous node
    nodeptr = nextnode; //set the return pointer to the new beginning
  }

  return retptr; //return the pointer to the beginning of the list, NULL

}

int main() {

  //setting up test sample
  struct node * humbleabode;
  struct node * guest = (struct node *) malloc(sizeof(struct node));
  guest->i = 123;
  guest->next = NULL;



  printf("\nMY LIST:\n");

  //printf("ONE NUM: ");
  //print_list(humbleabode);
  //can't print list with one element? memory problem maybe.

  humbleabode = insert_front(guest, 456);
  printf("TWO NUMS: ");
  print_list(humbleabode);

  humbleabode = insert_front(humbleabode, 789);
  printf("THREE NUMS: ");
  print_list(humbleabode);

  humbleabode = insert_front(humbleabode, 10000);
  printf("CUATRO NUMS: ");
  print_list(humbleabode);

  humbleabode = insert_front(humbleabode, -12);
  printf("CINCO NUMS: ");
  print_list(humbleabode);

  printf("\n");
  printf("Freed List:\n");
  free_list(humbleabode);
  print_list(humbleabode);
  //wonder why they aren't zero, addresses, or?


  return 0;

}