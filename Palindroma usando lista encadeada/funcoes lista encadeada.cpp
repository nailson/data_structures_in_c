#define TRUE 1          /* utilizado true com valor 1*/
#define FALSE 0         /* utilizado false com valor 0 */
#include "Lista.h"      /* inclui a especificação do TAD */
#include <stdio.h>	    /* utilizado para funcões de entrada e saida */    

struct _slnode_ {
       
    struct _slnode_ *next;	    /* Aponta para proximo elemento da lista */
	void *data;                 /* Contém os dados do elemento */
	
};   

struct _sllist_ {
    SLnode *first;              /* Aponta para primeiro elemento da lista */
};


SLlist *sllCreate(void)
{
       SLlist *l;
       l = (SLlist *)malloc(sizeof(SLlist));
       if(l!=NULL){
          l->first = NULL;
          return l;
       }
       return NULL;
} /* fim de sllCreate */


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
}/* fim do sllInserFirst */


void *sllRemoveFirst(SLlist *l)
{
     SLnode *firstnode;
     void *elm;
     if(l!=NULL){
        elm = l->first->data;
        firstnode = l->first;
        l->first = l->first->next;
        free(firstnode);
        return elm;
     }
     return NULL;
} /* fim de sllRemoveFirst */


int sllDestroy(SLlist *l)
{
    if(l!=NULL){
       if(l->first!=NULL){
          free(l->first);
       }
       free(l);
       return TRUE;
    }
    return FALSE;
} /* fim de sllDestroy */
