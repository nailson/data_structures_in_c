#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "colecao.h"

struct _aluno_{//Criacao da struct aluno
 char nome [50];
 int codigo;          
 int anoNasc;              
};    

typedef struct _aluno_ Aluno;


//criacao de variaveis globais p/ o uso na main
Aluno *al;
Colecao *col;
int num;
char opt;


int cmp(void *a, void *b){
    int *pa;
    Aluno *pb;
    pa = (int*)a;
    pb = (Aluno*)b;
    if(*pa == pb -> codigo){
       return 1;
    }
    else return 0;
}

int main()
{   int x;
    int s=1;
    char select;
    while (s) {
        
    	
        system("cls");//limpa a tela no laço    
        printf("Escolha uma opcao: \n\n");
        printf("1 - Criar    colecao\n\n");
        printf("2 - Inserir  aluno\n\n");
        printf("3 - Buscar   aluno\n\n");
        printf("4 - Retirar  aluno\n\n");
        printf("5 - Destruir colecao\n\n");
        printf("6 - Sair\n\n");
     
              
        
        select = getch();//guarda a opcao desejada 
        
        switch(select){
            case '1':    //criar
                 system("cls");
                 if(col!= NULL)       break;
                 printf("Digite a quantidade de itens: ");
                 scanf("%d",&num);
                 
                 if(num>0){
                 col= colCriar(num);
                 printf("\nColecao criada com sucesso\n\n");
                 }
                 
                 else printf("\nColecao invalida\n\n");
                 system("pause");
                
                 break;
            
            case '2':   //inserir              
                 system("cls");
                 al=(Aluno *)malloc (sizeof(Aluno));
                 if(col!= NULL){
                      printf("\n\nDigite o nome do aluno: ");
                      scanf("%s",al-> nome);
                      printf("\nDigite o codigo do aluno: ");
                      scanf("%d",&al-> codigo);
                      printf("\nDigite o ano de nascimento do aluno: ",num);
                      scanf("%d",&al-> anoNasc);
                      num = colInserir(col,(void *)al);
                      al=NULL;
                      free(al);
                      if(num) printf("\n\ncolecao inserida com sucesso!\n\n");
                      else    printf("\n\nColecao nao inserida!!!!!!\n\n");
                 }
                 else printf("\nColecao nao criada\n\n");
                 system("pause");
                 break;
            
            case '3':    //buscar
                 system("cls");
                 if(col!= NULL){
                       printf("Digite o codigo do aluno q deseja buscar: ");
                       scanf("%d",&num);
                       al=colBuscar (col,(void *)&num,cmp);
                       if(al!= NULL){
                              printf("\nNome : %s\n",al-> nome);
                              printf("\nCodigo: %d\n",al-> codigo);
                              printf("\nAno Nascimento: %d\n\n\n", al-> anoNasc);
                       }
                       else   printf("\nCodigo nao identificado\n\n");
                 }
                 else  printf("\nColecao nao criada\n\n");
                 system("pause");
                 break;
            
            case '4':    //retirar
                 system("cls");
                 if(col!= NULL){
                            printf("Digite o codigo do aluno q deseja retirar: ");
                            scanf("%d",&num);
                            x= colRetirar(col,(void *)&num,cmp);
                            if(x) printf("\nO aluno foi retirado com sucesso da colecao\n\n");
                            else    printf("\nO aluno nao foi retirado com sucesso\n\n");
                 }
                 else     printf("Colecao nao criada");
                 system("pause");
                 break;
            
            case '5':      //destruir
                 system("cls");
                 if(col!= NULL){
                          printf("Vc realmente deseja destruir a colecao? (s,n)\n\n");
                         opt = getch();
                         if(opt== 's'){  
                                  num=colDestruir(col);
                                  col=NULL;
                                  if(num) printf("\ncolecao destruida com sucesso!\n\n");
                                  else    printf("\na colecao nao pode ser destruida!!!!!\n\n");
                         }
                         else if(opt== 'n')  printf("\nColecao nao destruida\n\n");
                         else printf("\n Opcao invalida\n\n");
                         
                 }
                 else  printf("\nColecao nao criada\n\n");
                 system ("pause");
                 
                 break;

                 
            case '6':    //sair
                 s=0;
                 break;
        
        } 
    }        
}
        
