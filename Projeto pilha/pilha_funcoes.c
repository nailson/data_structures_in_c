#include <stdio.h>
#include <conio.h>

typedef struct _pilha_{
    int maxElems;
    int topo;
    void* *elms;
}PILHA;

int pilCria(int max){
    PILHA *p;
    p = (PILHA*)malloc(sizeof(PILHA));
    
    if (p!=NULL){
        p->elms = (void**)calloc(max,sizeof(void*));
    }
    
    if (p->elms != NULL){
        p->maxElems = max;
        p->topo = -1;
        return TRUE;
    }
    free(p);
    return FALSE;    
}

int pilDestroi(PILHA *p){
    if (p != NULL){
        if (p->topo <= 0){
            return FALSE;
        }
        else{
            free(p->elms);
            free(p);
            return TRUE;
    } 
}

int pilEmpilhar(PILHA *p, void *elms){
    if (p != NULL){
        if (p->topo < p->maxElems-1){
            p->topo++;
            p->elms[p->topo]=elms;
        }
    }
    return NULL; 
}

int pilDesempilha (PILHA *p){
    void* aux;
    if (p != NULL){
        if (p->top >= 0){
            aux=p->elms[p->topo];
            p->topo--;
            return aux;
        }
    }
    return NULL;
}

int pilVazia (PILHA *p){
    if (p != NULL){
        if (p->topo < 0){
            return TRUE;
        }
    }
    return FALSE;
}

void *pilPegatopo (PILHA *p){
    if (p != NULL){
        if (p->top >= 0){
            return p->elms[p->topo];
        }
    }
    return NULL;
}
