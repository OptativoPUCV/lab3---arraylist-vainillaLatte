#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"



//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list;
  list = (ArrayList *)calloc(1,sizeof(ArrayList));
  list->capacity=2;
  list->size=0;
  list->data=(void**)calloc(list->capacity,sizeof(void));
    return list;
}

void append(ArrayList * l, void * data){
  if(l->capacity <=l->size)
  {
    l->data[l->size]=data;
    l->size=l->size*2;
    l->data=(void*)realloc(l->data,l->size * sizeof(void*));
    l->capacity=l->capacity*2;
  }
  else{
    //
    l->data[l->size]=data;
    l->size++;
    //l->capacity++;
  }
}

void push(ArrayList * l, void * data, int i){
  if(l->capacity<i)
  {
    l->data[i]=data;
    l->capacity=l->capacity*2;
    l->size=l->size*2;
    l->data=(void*)realloc(l->data,l->size * sizeof(void*));
  }

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
