#include<stdio.h>
#include<stdlib.h>


typedef struct _Tnode_{
    void *data;
    struct _Tnode_ *l;
    struct _Tnode_ *r;
}Tnode;

void PreOrdem(Tnode *t, void (*visit)(void *)){
     if(t!= NULL){
          visit(t-> data);
          PreOrdem(t-> l, visit);
          PreOrdem(t-> r, visit);
     }
}

void PosOrdem(Tnode *t, void (*visit)(void *)){
     if(t!= NULL){
          PosOrdem(t-> l, visit);
          PosOrdem(t-> r, visit);
          visit(t-> data);
     }
}

void Simetrico(Tnode *t, void (*visit)(void *)){
     if(t!= NULL){
          Simetrico(t-> l, visit);
          visit(t-> data);
          Simetrico(t-> r, visit);
     }
}

void visit(void *imprime){
     printf("%c",(char *)imprime);
}

void InsereL(Tnode *t,void *dados){
     Tnode *novono;
     if( t != NULL ){
          novono = (Tnode *)malloc(sizeof(Tnode));
          if( novono != NULL){
               novono-> data = dados;
               novono-> l = NULL;
               novono-> r =NULL;
               t-> l = novono;
               return;
          }
     }
}

void InsereR(Tnode *t,void *dados){
     Tnode *novono;
     if( t != NULL ){
          novono = (Tnode *)malloc(sizeof(Tnode));
          if( novono != NULL){
               novono-> data = dados;
               novono-> l = NULL;
               novono-> r =NULL;
               t-> r = novono;
               return;
          }
     }
}

int main(){
    
    Tnode *arvore;
    arvore = (Tnode *)malloc(sizeof(Tnode));
    arvore-> data = (void *)'A';
    InsereL(arvore,(void *)'B');
    InsereL(arvore-> l,(void *)'C');
    InsereR(arvore-> l,(void *)'D');
    InsereR(arvore,(void *)'E');
    InsereL(arvore-> r,(void *)'F');
    InsereR(arvore-> r,(void *)'G');
    printf("\n");
    PreOrdem(arvore, visit);
    printf("\n");
    PosOrdem(arvore, visit);
    printf("\n");
    Simetrico(arvore, visit);
    printf("\n");
    system("pause");  
    
}
