#include<stdlib.h>
#include "list.h"
#define TRUE 1          /* utilizado true com valor 1*/
#define FALSE 0         /* utilizado false com valor 0 */


SLlist *sllCreate(void)
{
       SLlist *l;
       l = (SLlist *)malloc(sizeof(SLlist));
       if(l!=NULL){
          l->first = NULL;
          return l;
       }
       return NULL;
}


int sllInserFirst(SLlist *l,void *elm){
    SLnode *neumode;
    if(l!=NULL){
       neumode = (SLnode *)malloc(sizeof(SLnode));
       if(neumode!=NULL){
          neumode->data = elm;
          neumode->next = l->first;
          l->first = neumode;
          return TRUE;
       }
    }
    return FALSE;
}


void *sllRemoveFirst(SLlist *l){
     SLnode *firstnode;
     void *elm;
     if(l!=NULL){
         if(l-> first!= NULL){
             firstnode = l->first;
             elm = firstnode->data;
             l->first = l->first->next;
             free(firstnode);
             return elm;
        }
     }
     return NULL;
} /* fim de sllRemoveFirst */
