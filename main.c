/* 
 * File:   main.c
 * Author: Roshan
 *
 * Created on March 30, 2013, 10:10 AM
 */

#include "circular_dlinkedlist.h"

/*#define DEBUG*/ /* If DEBUG is defined main function will be activated to test the functionality */

/* Circular Double Linked List Implementation */
node_dll_t *create_dlist(void * const payload)
{
    node_dll_t *node = malloc(sizeof(node_dll_t));
    
    if(!node) return NULL;
    
    node->payload = payload;
    node->next = node;
    node->prev = node;  
    
    return node;
}

node_dll_t *next(node_dll_t **d_list)
{
    (*d_list) = (*d_list)->next;
    return *d_list;
}

int add_to_dlist(node_dll_t *d_list, void * const payload)
{
    node_dll_t *tmp = create_dlist(payload);
    
    if(!tmp) return -1;
    
    node_dll_t *next_node = d_list->next;
    tmp->next = next_node;
    next_node->prev = tmp;
    
    d_list->next = tmp;
    tmp->prev = d_list;
    
    return 0; 
}

void remove_from_dlist(node_dll_t * const node)
{
    node_dll_t *next = node->next;
    node_dll_t *prev = node->prev;
    
    next->prev = prev;
    prev->next = next;
    
    free(node->payload);
    free(node);
}





#ifdef DEBUG

int main(int argc, char** argv) {
    node_dll_t *root = create_dlist((void*) "Hello how are you");
    add_to_dlist(root, (void*) "this is node tow");
    add_to_dlist(root, (void*) "this is three");
    
    while(1) {
        node_dll_t *next_node = next(&root);
        printf("paylod: %s\n", (char *) (next_node->payload));
        int ch = getchar();
        if((char)ch == 'd') remove_from_dlist(next_node);
    }

    return (EXIT_SUCCESS);
}

#endif

