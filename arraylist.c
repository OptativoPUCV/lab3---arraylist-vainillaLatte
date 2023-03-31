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
  if(i>l->size) return;
  
  if(l->capacity==l->size)
  {
    l->capacity*=2;
    l->data=(void*)realloc(l->data,l->size * sizeof(void*));
   
  }
  if(l->size>i)
  {
    for(int k = l->size; i < k; k--)
      {
        l->data[k]=l->data[k-1];
      }
  }
  l->data[i]=data;
  l->size++;
}

void* pop(ArrayList * l, int i)
{
  if (i < 0) {
    i = l->size + i;
  }
  
  if (i < 0 || i >= l->size) {
    return NULL;
  }
  
  void *data = l->data[i];
  
  for (int j = i; j < l->size - 1; j++) {
    l->data[j] = l->data[j+1];
  }
  
  l->size--;
  return data;

}

void* get(ArrayList * l, int i){
  if (i < 0) {
    i += l->size;
  }
  if (i < 0 || i >= l->size) {
    return NULL;
  }
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  l->capacity = 2;
  l->size = 0;
  l->data = (void **)realloc(l->data, sizeof(void *) * l->capacity);
  l->size = 0;
}