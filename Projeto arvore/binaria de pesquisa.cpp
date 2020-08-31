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
     printf(" %d ",imprime);
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

void *ABPConsulta(Tnode *t, void *data, int (*cmp)(void *, void *)){
     if(t!= NULL){
          if(cmp(data, t-> data) == 0)
               return data;
          else if(cmp(data, t-> data) > 0)
               return ABPConsulta(t-> r, data, cmp);
          else
               return ABPConsulta(t-> l, data, cmp);
     }
     else
          return NULL;

}


Tnode *ABPMaior(Tnode *t){
     if(t!= NULL){
          if(t-> r!= NULL)
               return ABPMaior(t-> r);     
          else
               return t;
     }
     else 
          return NULL;     
}

Tnode *ABPMenor(Tnode *t){
     if(t!= NULL){
          if(t-> l!= NULL)
               return ABPMenor(t-> l);     
          else
               return t;
     }
     else 
          return NULL;     
}


int ABPContar(Tnode *t, int x){
     if(t!= NULL){
          ++x;
          x = ABPContar(t-> l, x);
          x = ABPContar(t-> r, x);
     }
     return x;
}

int ABPNumFolhas(Tnode *t, int x){
     if(t!= NULL){
          if(t-> l == NULL && t-> r == NULL){
               ++x;
          }
          x = ABPNumFolhas(t-> l, x);
          x = ABPNumFolhas(t-> r, x);
     }
     return x;    

}

int ABPGrau1(Tnode *t, int x){
     if(t != NULL){     
          if((t-> r == NULL || t-> l == NULL) ){
                if(!(t-> r == NULL && t-> l == NULL))
                     ++x;
          }
          visit(t->data);
          x = ABPGrau1(t-> l, x);
          x = ABPGrau1(t-> r, x);        
               
     }
     return x;    
}

int ABPSemL(Tnode *t, int x){
     if(t!= NULL){
          if(t-> l == NULL){
               ++x;
          }
          x = ABPSemL(t-> l, x);
          x = ABPSemL(t-> r, x);
     }
     return x;      
}

Tnode *ABPRemove(Tnode *t, void * key, int (*cmp)(void *, void *)){
     Tnode *noaux;
     void *aux;
     if(t != NULL){
          if(cmp(key, t-> data) == 0){
              if(t->r == NULL && t-> l == NULL){
                   free(t);
                   return NULL;
              }
              else if(t->r == NULL || t-> l == NULL){
                   if(t-> r == NULL){
                        noaux = t-> l;
                   }   
                   else{
                        noaux = t-> r;
                   }  
                   free(t);
                   return noaux;
              }
              else{
                   noaux = t-> l;
                   while(noaux->r != NULL){
                        noaux = noaux->r;
                   }
                   aux = noaux-> data;
                   t = ABPRemove(t, aux, cmp);
                   t-> data = aux;
                   return t;     
              }
          }
          else if(cmp(key, t-> data) <= 0){
              t-> l = ABPRemove(t-> l, key, cmp);
          }
          else{
              t-> r = ABPRemove(t-> r, key, cmp);
          }
          return t;
     }
     return NULL;     
}

int main(){
     Tnode *arvore, *galho;
     char opt; 
     int aux, *aux2;
     arvore = NULL;
     while(1){
      
        system("cls");
        printf("Escolha uma opcao: \n\n");
        printf("1 - Inserir na Arvore Binaria de Pesquisa \n\n");
        printf("2 - Consultar na Arvore Binaria de Pesquisa \n\n");
        printf("3 - Remover no da Arvore Binaria de Pesquisa \n\n");
        printf("4 - Imprimir Simetrico \n\n");
        printf("5 - Imprimir Pre Ordem \n\n");
        printf("6 - Imprimir Pos Ordem \n\n");
        printf("7 - Imprimir Maior da Arvore Binaria de Pesquisa\n\n");
        printf("8 - Imprimir Menor da Arvore Binaria de Pesquisa \n\n");
        printf("9 - Contar Nos da Arvore Binaria de Pesquisa \n\n");
        printf("0 - Contar Folhas da Arvore Binaria de Pesquisa \n\n");
        printf("q - Contar Nos com grau 1 da Arvore Binaria de Pesquisa \n\n");
        printf("w - Contar Nos sem filho esquerdo da Arvore Binaria de Pesquisa \n\n");
        
      
        opt = getch();
        switch(opt){
            case '1':
                system("cls");
                printf("Digite o numero ou caractere que deseja adicionar a ABP: ");
                scanf("%d",&aux);
                arvore = ABPInsere(arvore ,(void *)aux, cmp);
                system("pause");
                break;
            case '2':
                system("cls");
                printf("Digite o numero ou caractere que deseja Consultar na ABP: ");
                scanf("%d",&aux);
                aux2 = (int *)ABPConsulta(arvore ,(void *)aux, cmp);
                if(aux2 != NULL)
                     printf("\nFoi encontrado %d na arvore!\n", aux2);
                else
                     printf("\n O numero nao foi encontrado!\n");
                system("pause");
                break;
            case '3':
                system("cls");
                printf("Digite o numero ou caractere que deseja Consultar na ABP: ");
                scanf("%d",&aux);
                aux2 = (int *)ABPConsulta(arvore ,(void *)aux, cmp);
                if(aux2 != NULL)
                     printf("\n%d Foi encontrado  e retirado da arvore!\n", aux2);
                else
                     printf("\n O numero nao foi encontrado!\n");
                arvore = ABPRemove(arvore ,(void *)aux, cmp);
                
                system("pause");
                break;
            case '4':
                 system("cls");
                 if( arvore != NULL)
                      printf("Em ordem Simetrica: ");
                      Simetrico(arvore, visit);
                      printf("\n");
                 system("pause");
                 break;
            case '5':
                 system("cls");
                 if( arvore != NULL)
                      printf("Em ordem Pre Ordem: ");
                      PreOrdem(arvore, visit);
                      printf("\n");
                 system("pause");
                 break;
            case '6':
                 system("cls");
                 if( arvore != NULL)
                      printf("Em ordem Pos Ordem: ");
                      PosOrdem(arvore, visit);
                      printf("\n");
                 system("pause");
                 break;
            case '7':
                system("cls");
                galho = ABPMaior(arvore);
                if(galho != NULL)
                     printf("\nO Maior numero da arvore eh %d!\n", (int)galho-> data);
                else
                     printf("\n Nao ha numero na arvore!\n");
                system("pause");
                break;
            case '8':
                system("cls");
                galho = ABPMenor(arvore);
                if(galho != NULL)
                     printf("\nO Menor numero da arvore eh %d!\n", (int)galho-> data);
                else
                     printf("\n Nao ha numero na arvore!\n");
                system("pause");
                break;
            case '9':
                system("cls");
                aux = 0;
                aux = ABPContar(arvore,aux);
                     printf("\nO Numero de Nos eh %d!\n", aux);
                system("pause");
                break;
            case '0':
                system("cls");
                aux = 0;
                aux = ABPNumFolhas(arvore,aux);
                     printf("\nO Numero de Folhas eh %d!\n", aux);
                system("pause");
                break;
            case 'q':
                system("cls");
                aux = 0;
                aux = ABPGrau1(arvore,aux);
                     printf("\nO Numero de Nos com grau 1 eh %d!\n", aux);
                system("pause");
                break;
            case 'w':
                system("cls");
                aux = 0;
                aux = ABPSemL(arvore,aux);
                     printf("\nO Numero de Nos sem filho esquerdo eh %d!\n", aux);
                system("pause");
                break;
      
                 
        }    
    }
}
