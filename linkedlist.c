#include <stdio.h>
#include <stdlib.h>

struct node{
  int i;
  struct node *next;
};

void print_list(struct node *list){
  while(list){
    printf("%d -> ", list -> i);
    list = list -> next;
  }
  printf("NULL\n");
}

struct node *insert_front(struct node *old, int n){
  struct node *new = (struct node *)malloc(sizeof(struct node));
  new -> next = old;
  new -> i = n;
  return new;
}

struct node *free_list(struct node *list){
  struct node *start = list;
  while(list){
    struct node *temp = list -> next;
    free(list);
    list = temp;
  }
  return start;
}

void main(){
  int index;
  struct node *test = (struct node *)malloc(sizeof(struct node));
  struct node *pnt = test;
  index = 1;
  test -> i = index;
  print_list(pnt);
  for(index = 2; index < 10; index++){
    printf("Inserting %d\n", index);
    test = insert_front(test, index);
    print_list(test);
  }
  printf("Clearing list\n");
  test = free_list(pnt);
  print_list(pnt);
}
