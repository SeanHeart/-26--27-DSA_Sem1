//Open Hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

/* insert: add f to the dictionary.
 * If an item with the same name already exists, do nothing (no duplicates).
 * Bucket index is hash(f.type). Increment D->total on a successful insert.
 * returns 1 on successful insertion, 0 otherwise
 * TODO: implement.
 */
int insert(Dictionary *D, Furniture f) {
    /* TODO */
    if(D == NULL){
        return 0;
    }
    if(search(D, f.name) != NULL){
        return 0;
    }

    Node *n = (Node*)malloc(sizeof(Node));
    if(n == NULL){
        return 0;
    }
    n->elem = f;
    int idx = hash(f.type);

    n->next = D->buckets[idx];
    D->buckets[idx] = n;
    D->total++;
    return 1;
}

/* search: return a pointer to the stored item whose name matches,
 * or NULL if not present. Because the bucket is chosen by type but the
 * lookup key is the name, scan all buckets.
 *
 * TODO: implement.
 */
Furniture *search(Dictionary *D, const char *name) {
    /* TODO */
    if(D == NULL || name == NULL || D->total == 0){
        return NULL;
    }

    for(int i=0; i<TABLE_SIZE; i++){
        for(Node *cur = D->buckets[i]; cur != NULL; cur = cur->next){
            if(strcmp(cur->elem.name, name) == 0){
                return &cur->elem;
            }
        }
    }
    return NULL;
}

/* delete: remove the item whose name matches.
 * Return 1 if found and removed, otherwise 0.
 * free() the removed node and decrement D->total.
 *
 * TODO: implement.
 */
int delete(Dictionary *D, const char *name) {
    /* TODO */
    if(D==NULL || name==NULL || D->total == 0){
        return 0;
    }

    for(int i=0; i<TABLE_SIZE; i++){
        Node *prev = NULL;
        Node *cur = D->buckets[i];
        while(cur != NULL && strcmp(cur->elem.name, name) != 0){
            prev = cur;
            cur = cur->next;
        }

        if(cur == NULL){
            continue;
        }

        if(prev == NULL){
        D->buckets[i] = cur->next;
        }else{
            prev->next = cur->next;
        }

        free(cur);
        D->total--;
        return 1;
    }

    return 0;
}

/* freeDictionary: free every node in every bucket, set all buckets to NULL,
 * and reset D->total to 0.
 *
 * TODO: implement.
 */
void freeDictionary(Dictionary *D) {
    /* TODO */
    if(D == NULL){
        return;
    }

    for(int i=0; i<TABLE_SIZE; i++){
        Node *cur = D->buckets[i];
        while(cur != NULL){
            Node *next = cur->next;
            free(cur);
            cur = next;
        }

        D->buckets[i] = NULL;
    }
    D->total = 0;
}