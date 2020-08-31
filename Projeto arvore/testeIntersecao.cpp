#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct _Tnode_{
     void *data;
     struct _Tnode_ *l;
     struct _Tnode_ *r;
}Tnode;
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

int ABPComparar(Tnode *t1, Tnode *t2, int x){
    if(t2 != NULL){
          if(t1 == t2){
                ++x;
          }
          x = ABPComparar(t1, t2->l, x);
          x = ABPComparar(t1, t2->r, x);
    }   
    return x;
}
             
int ABPIntersecao(Tnode *t1, Tnode *t2, int x){
    if(t1!= NULL){
         x = ABPComparar(t1,t2,0);
         x = ABPIntersecao(t1-> l, t2, x);
         x = ABPIntersecao(t1-> r, t2, x);
    }
    return x;    
}                                                           


int main(){
    Tnode *t1, *t2;
    int x;
    
    t1 = (Tnode *)malloc(sizeof(Tnode));
    t1->data = (void *)'A';
    t2 = (Tnode *)malloc(sizeof(Tnode));
    t2->data = (void *)'Z';
    InsereL(t1,(void *)'C');
    InsereR(t1,(void *)'D');
    t2-> l = t1;
    t2-> r = t1->r;
    Simetrico(t1,visit);
    printf("\n");
    Simetrico(t2,visit);
    printf("\n");
    x = ABPIntersecao(t1,t2,0);
    printf("\n");
    printf("%d\n",x);
    
    system("pause");  
    
}
