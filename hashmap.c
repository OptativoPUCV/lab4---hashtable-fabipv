#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) 
{
  int pos = hash(key, map->capacity);
  
  while(map->buckets[pos] != NULL)
  {
    pos = (pos + 1) % map->capacity;
  }

  if(map->buckets[pos] == NULL || map->buckets[pos]->key == NULL)
  {
    map->buckets[pos] = createPair(key,value);
    map->size++;
    map->current = pos;
  }


}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity)
{
  HashMap *newMap = (HashMap*) malloc(sizeof(HashMap));

  newMap->buckets = (Pair**) calloc(capacity,sizeof(Pair*));
  newMap->capacity = capacity;
  newMap->current = -1;
  newMap->size = 0;

  return newMap;
}

void eraseMap(HashMap * map,  char * key) 
{
  Pair* buscado = searchMap(map, key);

  if(buscado != NULL)
  {
    buscado->key = NULL;
    map->size--;
  }
}

Pair * searchMap(HashMap * map,  char * key) 
{   
  int pos = hash(key, map->capacity);

  while(map->buckets[pos] != NULL)
  {
    if(is_equal(map->buckets[pos]->key, key))
    {
      map->current = pos;
      return map->buckets[pos];
    }
    pos = (pos + 1) % map->capacity;
  }
  return NULL;
}

Pair * firstMap(HashMap * map) 
{
  int pos = 0;

  while(map == NULL)
  {
    pos++;
      
  }

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
