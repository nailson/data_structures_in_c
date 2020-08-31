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


int sllInsereLast(SLlist *l, void *data){
    SLnode *novono, *ultimo;
    if(l!= NULL){
        novono= (SLnode *)malloc(sizeof(SLnode));
        if(novono!= NULL){
            novono-> next= NULL;
            novono->data= data;
            if(l-> first != NULL){
                ultimo= l-> first;
                while(ultimo-> next!= NULL){
                    ultimo= ultimo-> next;
                }
                ultimo-> next= novono;
                return TRUE;
            }
            l-> first= novono;
            return TRUE;
        }
    }
    return FALSE;    
}


void *sllRemoveLast(SLlist *l){
    SLnode *ultimo, *penultimo;
    void *dados;
    if(l!= NULL){
        if(l-> first!= NULL){
            penultimo= NULL;
            ultimo= l-> first;
            while(ultimo-> next!= NULL){
                penultimo= ultimo;
                ultimo= ultimo-> next;
            }
            dados= ultimo-> data;
            if(penultimo!= NULL){
                penultimo-> next= NULL;
            }
            else
                l-> first= NULL;
            free(ultimo);
            return dados;
        }
    }
    return NULL;

}

int sllCountNode(SLlist *l){
    SLnode *aux;
    int count;
    if(l!= NULL){
        count= 0;
        if(l-> first!= NULL){
            aux= l-> first;
            count++;
            while(aux-> next!= NULL){
                aux= aux->next;
                count++;
            }
        }
        return count;
    }
    return -1;
}

SLnode *sllGetNode(SLlist* l, void *key, int (*cmp )(void *,void *)){
    SLnode *aux;
    if(l!= NULL){
        if(l-> first!= NULL){
            aux= l-> first;
            while(aux-> next!= NULL && !cmp(aux-> data, key)){
                aux= aux-> next;
            }
            if(cmp(aux-> data, key)){
                return aux;
            }    
        }
    }
    return NULL;
}

int sllInsertAfterEsp(SLlist *l,void *dados,void *key,int (*cmo)(void *,void *)){
    SLnode *novono, *aux;
    if(l!= NULL){
        if(l-> first!= NULL){
            aux= l-> first;
            while(aux-> next!= NULL && !cmp(aux-> data, key)){
                aux= aux-> next;
            }
            if(cmp(aux-> data, key)){
                novono= (SLnode *)malloc(sizeof(SLnode));
                if(novono!= NULL){
                    novono-> data= dados;
                    novono-> next= aux-> next;
                    aux-> next= novono;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;    
}


void *sllRemoveEsp(SLlist *l,void *key, int (*cmo)(void *,void *)){
    SLnode *antes, *cara;
    void *dados;
    if(l!= NULL){
        if(l-> first!= NULL){
            antes= NULL;
            cara= l-> first;
            while(cara-> next!= NULL && !cmp(cara-> data, key)){
                antes= cara;
                cara= cara-> next;
            }
            if(cmp(cara-> data, key)){
                dados= cara-> data;
                if(l-> first== cara){
                    l-> first= cara-> next;
                }
                else{
                    antes-> next= cara-> next;
                }
                free(cara);
                return dados;
            }
        }
    }
    return NULL;
}

int sllInsertBeforeEsp(SLlist *l,void *dados, void *key, int(*cmp)(void*, void*)){
    SLnode *antes, *cara, *novono;
    if(l!= NULL){
        if(l-> first!= NULL){
            antes= NULL;
            cara= l-> first;
            while(cara-> next!=NULL && !cmp(cara-> data, key)){
                antes= cara;
                cara= cara-> next;
            }
            if(cmp(cara-> data, key)){
                novono=(SLnode *)malloc(sizeof(SLnode));
                novono-> data= dados;
                novono-> next= cara;
                if(l-> first== cara){
                    l-> first= novono;
                }
                else{
                    antes-> next= novono;
                }
                return TRUE;
            }
        }
    }
    return FALSE;    
}

int sllRemoveAllNode(SLlist *l){
    SLnode *antes, *ultimo;
    if(l!= NULL){
        while(l-> first!= NULL){
            antes=NULL;
            ultimo= l-> first;
            while(ultimo-> next!= NULL){
                antes= ultimo;
                ultimo= ultimo-> next;
            }
            if(ultimo== l-> first){
                l-> first= NULL;
            }
            else{
                antes-> next= NULL;
            }
            free(ultimo);
        }
        return TRUE;
    }
    return FALSE;
}
