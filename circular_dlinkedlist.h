/* 
 * File:   circular_dlinkedlist.h
 * Author: Roshan
 *
 * Created on March 30, 2013, 11:20 AM
 */

#ifndef CIRCULAR_DLINKEDLIST_H
#define	CIRCULAR_DLINKEDLIST_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _node {
    void * payload;
    struct _node *prev;
    struct _node *next;
};

typedef struct _node node_dll_t;

/* Circular Double Linked List API */
node_dll_t *create_dlist(void * const payload);
int add_to_dlist(node_dll_t *d_list, void *payload);
void remove_from_dlist(node_dll_t * const node);
node_dll_t *next(node_dll_t **d_list);
/*node_dll_t *find(node_dll_t *d_lsit, node_dll_t *node);*/


#ifdef	__cplusplus
}
#endif

#endif	/* CIRCULAR_DLINKEDLIST_H */

