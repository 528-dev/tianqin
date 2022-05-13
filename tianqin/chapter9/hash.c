#include<stdio.h>
#include<stdlib.h>
#include"hash.h"

enum kindOfEntry {Legitimate, Empty, Deleted};
// Defining the 'deleted' because when we delete the element,
// we take lazy delete measures in case to corrupt the structure of the hash table.

typedef struct Cell{
    int element;
    enum kindOfEntry info;
}Cell;

struct HashTbl{
    int tableSize;
    Cell *cells;
};

HashTable initHashTable(int size){
    HashTable ret = (HashTable)malloc(sizeof(HashTbl));
    ret->tableSize = size;
    ret->cells = (Cell*)malloc(sizeof(Cell) * ret->tableSize);
    for (int i = 0; i < ret->tableSize; ++i){
        ret->cells[i].info = Empty;
    }
    return ret;
}

int detectFunc(int i, int size){
    return (i + 1) % size;
}

int findElem(int key, HashTable T){
    int index = key % T->tableSize;
    while (T->cells[index].element != key && T->cells[index].info != Empty){
        index = detectFunc(index, T->tableSize);
    }
    return index;
}

int insertElem(int key, HashTable T){
    int index = findElem(key, T);
    if (T->cells[index].info != Legitimate){
        T->cells[index].info = Legitimate;
        T->cells[index].element = key;
        return 1;
    }
    return 0;
}

