#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#include"list.h" 

 
int cmp(void *a, void *b){
    if(a == b){
       return TRUE;
    }
    else return FALSE; 
}


SLlist *list;

 
int main(){
    char opt;
    int ano, x, *aux;
    SLnode *get;
    while(1){//menu
      
        system("cls");//limpa a tela no laço    
        printf("Escolha uma opcao: \n\n");
        printf("1 - Criar lista \n\n");
        printf("2 - Inserir no comeco da lista \n\n");
        printf("3 - retirar do comeco da lista \n\n");
        printf("4 - Inserir no final da lista \n\n");
        printf("5 - retirar do final da lista \n\n");
        printf("6 - Contar nos da lista \n\n");
        printf("7 - Procurar no da lista \n\n");
        printf("8 - Inserir no apos especifico da lista \n\n");
        printf("9 - Retirar especifico da lista \n\n");
        printf("0 - Inserir no antes especifico da lista \n\n");
        printf("d - Destruir lista \n\n");
        
        
      
        opt = getch();
        switch(opt){
            case '1'://criar lista
                system("cls");
                list= sllCreate();
                if(list!= NULL)
                    printf("A Lista foi criada!\n");
                else 
                    printf("A lista nao foi criada\n");
                system("pause");
            break;
            case'2'://inserir na primeira posicao
                system("cls");
                printf("Digite o numero q deseja adicionar a lista: ");
                scanf("%d",&ano);
                x= sllInserFirst(list,(void *)ano);
                if(x)
                    printf("o numero foi adicionada a lista!\n");
                else
                    printf("O numero nao pode ser adicionado a lista!!!\n");
                system("pause");
            break;
            case'3':
                system("cls");
                aux=(int*) sllRemoveFirst(list);
                if(aux!= NULL)
                    printf("O numero %d foi retirado da lista!\n",(int)aux);
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case'4'://inserir na ultima posicao
                system("cls");
                printf("Digite o numero q deseja adicionar a lista: ");
                scanf("%d",&ano);
                x= sllInsereLast(list,(void *)ano);
                if(x)
                    printf("o numero foi adicionada a lista!\n");
                else
                    printf("O numero nao pode ser adicionado a lista!!!\n");
                system("pause");
            break;
            case'5':
                system("cls");
                aux=(int*) sllRemoveLast(list);
                if(aux!= NULL)
                    printf("O numero %d foi retirado da lista!\n",(int)aux);
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case'6':
                system("cls");
                x= sllCountNode(list);
                if(x!= -1)
                    printf("A lista tem %d nos!\n",x);
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case'7':
                system("cls");
                printf("Digite o num q quer procurar na lista: ");
                scanf("%d",&x);
                get= sllGetNode(list,(void *)x, cmp);
                if(get!= NULL){
                    printf("\nFoi encontrado %d\n",(int)get->data);
                }
                else
                    printf("Nao foi possivel encontrar o no especifico\n");
                system("pause");
            break;
            case'8':
                system("cls");
                printf("Digite o numero q vc deseja buscar: ");
                scanf("%d",&x);
                printf("Digite o numero q deseja adicionar a lista: ");
                scanf("%d",&ano);
                x= sllInsertAfterEsp(list,(void *)ano, (void *)x, cmp);
                if(x)
                    printf("o numero foi adicionada a lista!\n");
                else
                    printf("O numero nao pode ser adicionado a lista!!!\n");
                system("pause");
            break;
            case'9':
                system("cls");
                printf("Digite o numero q vc deseja buscar: ");
                scanf("%d",&x);
                aux=(int*) sllRemoveEsp(list, x, cmp);
                if(aux!= NULL)
                    printf("O numero %d foi retirado da lista!\n",(int)aux);
                else
                    printf("Lista vazia!!\n");
                system("pause");
            break;
            case'0':
                system("cls");
                printf("Digite o numero q vc deseja buscar: ");
                scanf("%d",&x);
                printf("Digite o numero q deseja adicionar a lista: ");
                scanf("%d",&ano);
                x= sllInsertBeforeEsp(list,(void *)ano, (void *)x, cmp);
                if(x)
                    printf("o numero foi adicionada a lista!\n");
                else
                    printf("O numero nao pode ser adicionado a lista!!!\n");
                system("pause");
            break;
            case'd':
                system("cls");
                x= sllRemoveAllNode(list);
                if(x){
                    printf("A lista foi destruida!\n");
                }
                else
                    printf("Lista nao criada!!!\n");
                system("pause");
            break;
        }
    }
}
                
