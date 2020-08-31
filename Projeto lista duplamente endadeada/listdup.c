#include<stdlib.h>
#include<stdio.h>
#include"listdup.h"
#define TRUE 1
#define FALSE 0

//funcao Criar lista
Dllist *dllCreate(void){
    Dllist *l;
    l= (Dllist *)malloc(sizeof(Dllist));
    if(l!= NULL){
        l-> first =NULL;
        return l;     
    }
    return NULL;            
}

//funcao Inserir First
int dllInserirFirst(Dllist *l, void *newdata){
    Dlnode *novono;
    if(l!= NULL){
        novono= (Dlnode *)malloc(sizeof(Dlnode));
        if(novono!= NULL){
            novono-> data= newdata;
            novono-> next= l-> first;
            novono-> prev= NULL;
            if(l-> first!= NULL){
                l-> first-> prev= novono;
            }
            l-> first= novono;
            return TRUE;
        }
    }
    return FALSE;
}

//funcao Inserir no ultimo lugar
int dllInserirLast(Dllist *l,void *newdata){
    Dlnode *novono, *aux;
    if(l!= NULL){
        novono= (Dlnode *)malloc(sizeof(Dlnode));
        if(novono!= NULL){
            novono-> data= newdata;
            novono-> next= NULL;
            if(l-> first!= NULL){
                aux= l-> first;
                while(aux-> next!= NULL){
                    aux= aux-> next;
                }
                novono-> prev= aux;
                aux-> next= novono;
            }
            else{
                novono-> prev= NULL;
                l-> first= novono;
            }

            return TRUE;
        } 
    }
    return FALSE;
}

//Funcao contar nos
int dllContar(Dllist *l){
    Dlnode *aux;
    int i= 0;
    if(l!= NULL){
        if(l-> first!= NULL){
            aux= l->first;
            i++;
            while(aux-> next!= NULL){
                aux= aux->next;
                i++;
            } 
        }
        return i;       
    }    
    return -1;
}

//funcao imprime defeito
void dllImprimeList(Dllist *l){
    Dlnode *novo;
    Indiv *auxi;
    int i=0;
    if(l!= NULL){
        if(l-> first!= NULL){
            novo= l-> first;
            while(novo!= NULL){
                auxi=(Indiv *)novo-> data;
               // pessoa=(Indiv) novo-> data;
                //printf("%d\n\n",auxi-> cpf);
                printf("%d\n",i++);
                novo= novo-> next;
            }
        }
        else
            printf("Lista vazia!\n");  
    }     
    else
        printf("Lista nao criada!!!\n");
}

//funcao remove primeiro
void *RemoverFirst(Dllist *l){
    Dlnode *aux;
    void *data;
    if(l!= NULL){
        if(l->first!= NULL){
            aux= l-> first;
            l-> first= l-> first-> next;
            if(l-> first!= NULL){
                l-> first-> prev= NULL;
            }
            data= aux-> data;
            free(aux);
            return data;
        }
        
    }
    return NULL;
    
}

//funcao remover ultimo
void *RemoverEnd(Dllist *l){
    Dlnode *aux;
    void *data;
    if(l!= NULL){
        if(l-> first!= NULL){
            aux= l-> first;
            while(aux-> next!= NULL){
                aux= aux-> next;
            }
            data= aux-> data;
            if(aux-> prev!= NULL){
                aux-> prev-> next= NULL;
            }
            l-> first= NULL;
            free(aux);
            return data;
        }
    }
    return NULL;       
}

Dlnode *dllGetNode(Dllist* l, void *key, int (*cmp )(void *,void *)){
    Dlnode *aux;
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

int dllInsertAfterEsp(Dllist *l, void *dados, void *key, int (*cmp)(void *, void *)){
    Dlnode *novono, *cara;
    if(l!= NULL){
        if(l-> first!= NULL){
            /*cara= l-> first;
            while(cara-> next!= NULL && !cmp(cara-> data,key)){
                printf("estou no while %d",!cmp(cara-> data,key));
                cara= cara-> next;
            }
            printf("sai no while %d",cmp(cara-> data,key));
            if(cmp(cara-> data, key)){
                printf("estou no cmp");
                novono= (Dlnode *)malloc(sizeof(Dlnode));
                if(novono!= NULL){
                    novono-> data= dados;
                    novono-> prev= cara;
                    novono-> next= cara-> next;
                    cara-> next= novono;
                    return TRUE;
                }
            }*/
            cara= dllGetNode(l,key,cmp);
            if(cara!= NULL){
                novono= (Dlnode *)malloc(sizeof(Dlnode));
                if(novono!= NULL){
                    novono-> data= dados;
                    novono-> prev= cara;
                    novono-> next= cara-> next;
                    cara-> next= novono;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}


int dllRemoveAllNode(Dllist *l){
    Dlnode *antes, *ultimo;
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
