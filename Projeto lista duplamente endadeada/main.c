#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"listdup.h"

int cmp(void *a, void *b){
    Indiv *pa=(Indiv *) a;
    int pb=(int)  b;
    if((int)pa-> cpf == pb){
        return TRUE;
    }
    return FALSE;
}

Dllist *list;

int main(){
    int opt,x;
    Indiv *pessoa;



    while(1){//menu
      
        system("cls");//limpa a tela no laço    
        printf("Escolha uma opcao: \n\n");
        printf("1 - Criar lista \n\n");
        printf("2 - Inserir no comeco da lista \n\n");
        printf("3 - imprimir \n\n");
        printf("4 - Contar lista \n\n");
        printf("5 - Inserir no final da fila \n\n");
        printf("6 - Remover primeiro\n\n");
        printf("7 - Remover ultimo\n\n");
      
        opt = getch();
        switch(opt){
            case '1'://criar lista
                system("cls");
                list =dllCreate();
                if(list !=NULL){
                    printf("A lista foi criada!\n");
                }
                else
                    printf("A lista nao pode ser criada!!\n");
                system("pause");   
            break;
            case '2'://inserir na frente da lista
                system("cls");
                pessoa=(Indiv *)malloc(sizeof(Indiv));
                printf("Digite o nome da pessoa: ");
                scanf("%s",pessoa-> nome);
                printf("Digite o CPF da pessoa: ");
                scanf("%d",&pessoa-> cpf);
                x =dllInserirFirst(list,(void *)pessoa);
                if(x)
                    printf("O Individuo foi adicionada na frente da lista!!\n");
                else
                    printf("O Individuo nao pode ser adicionado!!!\n");
                system("pause");
            break;
            case '3':
                 system("cls");
                 dllImprimeList(list);
                 system("pause");
            break;
            case '4':
                 system("cls");
                 x= dllContar(list);
                 if(x!= -1)
                     printf("A lista tem %d nos\n\n",x);
                 else
                     printf("A lista nao foi criada!!\n\n");
                 system("pause");
            break;
            case '5':
                 system("cls");
                 pessoa=(Indiv *)malloc(sizeof(Indiv));
                 printf("Digite o nome da pessoa: ");
                 scanf("%s",pessoa-> nome);
                 printf("Digite o CPF da pessoa: ");
                 scanf("%d",&pessoa-> cpf);
                 x =dllInserirLast(list,(void *)pessoa);
                 if(x)
                     printf("O Individuo foi adicionada no final da lista!!\n");
                 else
                     printf("O Individuo nao pode ser adicionado!!!\n");
                 system("pause");
            break;
            case '6':
                system("cls");
                pessoa= (Indiv *)RemoverFirst(list);
                if(pessoa!= NULL){
                    printf("nome: %s\n",pessoa-> nome);
                    printf("cpf: %d\n",pessoa-> cpf);
                }
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case '7':
                system("cls");
                pessoa= (Indiv *)RemoverEnd(list);
                if(pessoa!= NULL){
                    printf("nome: %s\n",pessoa-> nome);
                    printf("cpf: %d\n",pessoa-> cpf);
                }
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case '8':
                system("cls");
                pessoa=(Indiv *)malloc(sizeof(Indiv));
                printf("Digite o CPF da pessoa q deseja buscar: ");
                scanf("%d",&x);
                printf("Digite o nome da pessoa: ");
                scanf("%s",pessoa-> nome);
                printf("Digite o CPF da pessoa: ");
                scanf("%d",&pessoa-> cpf);
                x =dllInsertAfterEsp( list, (void *)pessoa, (void *)x, cmp);
                if(x)
                    printf("O Individuo foi adicionada na frente da lista!!\n");
                else
                    printf("O Individuo nao pode ser adicionado!!!\n");
                system("pause");
            break;
        }
    }
}



