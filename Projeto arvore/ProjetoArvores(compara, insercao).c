#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct _Tnode_{
     void *data;
     struct _Tnode_ *l;
     struct _Tnode_ *r;
}Tnode;

int cmp(void *a1, void *b1){
    if((int)a1 == (int)b1 )
         return 0;
    else if((int)a1 > (int)b1)
         return 1;
    else 
         return -1;      
}

Tnode *ABPInsere(Tnode *t,void *data, int(*cmp)(void *, void *)){
     Tnode *novono;
     if(t != NULL){
          if(cmp(data, t-> data) > 0){
               t-> r = ABPInsere(t-> r, data, cmp);
          }
          else if(cmp(data, t-> data) <= 0){
               t-> l = ABPInsere(t-> l, data, cmp);     
          }
          return t;
     }      
     else{
          novono = (Tnode *)malloc(sizeof(Tnode));
          if( novono != NULL){
               novono-> data = data;
               novono-> l = NULL;
               novono-> r = NULL;
               return novono;
          }     
     } 
}
void visit(void *imprime){
     printf("%d ",imprime);
}

void Simetrico(Tnode *t, void (*visit)(void *)){
     if(t!= NULL){
          Simetrico(t-> l, visit);
          visit(t-> data);
          Simetrico(t-> r, visit);
     }
}

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

int ABPComparaArv(Tnode *t1,Tnode *t2,int (*cmp)(void *, void *), int x){

    if(t1 != NULL && t2!= NULL){
          if(cmp(t1->data, t2->data) == 0){
                x = ABPComparaArv(t1-> l, t2->l, cmp, x);
                x = ABPComparaArv(t1-> r, t2-> r, cmp, x);
                return x;           
          }
          return x*0;      
    }
    else if(t1 == NULL && t2 == NULL){
          return x;
    }
    return x*0;    
}
                                                     

int main(){
     Tnode *arvore1, *arvore2, *galho;
     char opt; 
     int aux, *aux2;
     arvore1 = NULL;
     arvore2 = NULL;
     while(1){
      
        system("cls");
        printf("Escolha uma opcao: \n\n");
        printf("1 - Inserir na Arvore1  \n\n");
        printf("2 - Inserir na Arvore2 \n\n");
        printf("3 - Comparar as duas Arvores \n\n");
        printf("4 - Imprimir Simetrico \n\n");
        printf("5 - Imprimir Pre Ordem \n\n");
        printf("6 - Imprimir Pos Ordem \n\n");
        
         opt = getch();
        switch(opt){
            case '1':
                system("cls");
                printf("Digite o numero ou caractere que deseja adicionar a ABP: ");
                scanf("%d",&aux);
                arvore1 = ABPInsere(arvore1 ,(void *)aux, cmp);
                system("pause");
                break;
            case '2':
                system("cls");
                printf("Digite o numero ou caractere que deseja adicionar a ABP: ");
                scanf("%d",&aux);
                arvore2 = ABPInsere(arvore2 ,(void *)aux, cmp);
                system("pause");
                break;
            case '3':
                 system("cls");
                 if(ABPComparaArv( arvore1, arvore2, cmp, 1)){
                      printf("As arvores sao iguais!!\n");
                 }
                 else{
                      printf("As arvores nao sao iguais!!!!\n");     
                 }
                 system("pause");
                 break;
            case '4':
                 system("cls");
                 if( arvore1 != NULL){
                      printf("Arvore1 em ordem  Simetrica: ");
                      Simetrico(arvore1, visit);
                      printf("\n");
                 }
                 if( arvore2 != NULL){
                      printf("Arvore2 em ordem Simetrica: ");
                      Simetrico(arvore2, visit);
                      printf("\n");
                 }
                 system("pause");
                 break;
            case '5':
                 system("cls");
                 if( arvore1 != NULL){
                      printf("Arvore1 em ordem Pre Ordem: ");
                      PreOrdem(arvore1, visit);
                      printf("\n");
                 }
                 if( arvore2 != NULL){
                      printf("Arvore2 em ordem Pre Ordem: ");
                      PreOrdem(arvore2, visit);
                      printf("\n");
                 }
                 system("pause");
                 break;
            case '6':
                 system("cls");
                 if( arvore1 != NULL){
                      printf("Arvore1 em ordem Pos Ordem: ");
                      PosOrdem(arvore1, visit);
                      printf("\n");
                 }
                  if( arvore2 != NULL){
                      printf("Arvore2 em ordem Pos Ordem: ");
                      PosOrdem(arvore2, visit);
                      printf("\n");
                 }
                 
                 system("pause");
                 break;
        }
      }
      
}
