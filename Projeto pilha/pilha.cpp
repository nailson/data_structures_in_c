#include <stdio.h>
#include <conio.h>
#include<stdlib.h>


#define TRUE  1
#define FALSE 0

typedef struct _pilha_{
    int maxElems;
    int topo;
    void **elms;
}PILHA;

PILHA *pilha;

PILHA *pilCria(PILHA *p,int max){
    
    p = (PILHA*)malloc(sizeof(PILHA));
    
    if (p!=NULL){
        p->elms = (void**)calloc(max,sizeof(void*));
    }
    
    if (p->elms != NULL){
        p->maxElems = max;
        p->topo = -1;
        return p;
    }
    free(p);
    return NULL;    
}


int pilEmpilhar(PILHA *p, void *elms){
    if (p != NULL){
        if ( p->topo < p->maxElems - 1 ){
            p->topo++;
            p->elms[p->topo]=elms;
            return TRUE;
		}
    }
    return FALSE; 
}

void Imprimir(PILHA *p){
     int i= 0;
     if(p!= NULL){
            if(p-> topo >= 0){
                   i = p-> topo;
                   while(i >= 0){
                           printf(" %d \n",p-> elms[i]);
                           i--;
                   }       
            }       
     }
     return;
}

void *pilDesempilha(PILHA *p){
    void* aux;
    if (p != NULL){
        if (p-> topo >= 0){
            aux = p->elms[p->topo];
            p-> topo--;
            return aux;
        }
    }
    return NULL;
}

int cmp(void *x, void *y){
    int x1 = (int)x, y2 = (int)y;
    if(x1 ==  y2)
              return 0;
    else if(x1 > y2)
               return 1;
    else       
               return -1;     
}

void retiraMenor(PILHA *p, void *key){
     if(p != NULL){
          if(p-> topo >= 0){
                 while(cmp(key, p-> elms[p-> topo]) >= 0){
                                p-> topo--;               
                 }       
          }     
     }     
     return;
}
void Impar(PILHA *p){
     int i = 0, j = -1;
     void ** aux;
     if(p!= NULL){
            if(p->topo > 0){
                 aux = (void **)calloc((p-> topo + 1 )/2, sizeof(void *));
                 while(i<=p-> topo){
                       j++;
                       aux[j] = p-> elms[i];
                       i+=2;             
                 } 
                 p-> topo = j;
                 free(p-> elms);
                 p-> elms = aux;          
            }       
     }     
     return;
}

void Inverte(PILHA *p){
     int i, x;
     void *aux;
     if(p!= NULL){
            if(p->topo > 0){
                 if(p-> topo %2 == 0)
                        x = p-> topo / 2;
                 else
                        x = (p-> topo + 1)/ 2;
                 for( i=0; i < x; i++){
                      aux = p-> elms[i];
                      p-> elms[i] = p-> elms[p-> topo - i];
                      p-> elms[p-> topo - i] = aux;                 
                 }       
            }       
     }     
     return;
}


int main(){
    int x,y;
    int num;
    char select;
    while (1) {
        
    	
        system("cls");//limpa a tela no laço    
        printf("Escolha uma opcao: \n\n");
        printf("1 - Criar   PILHA\n\n");
        printf("2 - PUSH numero\n\n");
        printf("3 - POP numero\n\n");
        printf("4 - Imprimir Pilha\n\n");
        printf("5 - Retirar menor que key\n\n");
        printf("6 - Retirar os com indice impar\n\n");
        printf("7 - Inverter Pilha\n\n");
     
              
        
        select = getch();//guarda a opcao desejada 
        
        switch(select){
            case '1':  //criar PILHA
				   system("cls");
				   if(pilha!= NULL)  printf("PILHA ja criada!!");
				   else{
			  	      printf("Quantos elementos: ");
		  		      scanf("%d",&x);
				      pilha= pilCria(pilha,x);
		      	      if(y)   printf("pilha criada com sucesso!\n");
	  			      else    printf("A pilha nao pode ser criada!!\n");
 				      system("pause");
				   }
			       break;
			 
			 case '2':// empilhar PILHA
			       system("cls");
			       if(pilha!=NULL){
                       if(pilha->topo <= pilha->maxElems - 1){

					       printf("Digite o numero: ");
					       scanf("%d",&num);
					       x= pilEmpilhar(pilha,(void *)num);
			    		   if(x) printf("Numero empilhado com sucesso!\n");
				    	   else  printf("O numero nao pode ser empilhado!!\n");
				    	   Imprimir(pilha);
					   }
				   
				   }
			 	   else  printf("A PILHA nao foi criada!!\n");
			 	   system("pause");
                   break;
             
			 
			 case '3':// desempilhar PILHA
			       system("cls");        
                   if(pilha != NULL){
				   	  if(pilha->topo >= 0){
						 num =(int)pilDesempilha(pilha);
						 printf("o numero %d foi retirado da pilha\n",num);   
					  }				 
                      else printf("Nenhum numero foi adicionado!!\n");
                      Imprimir(pilha);
                   }
			       else   printf("A PILHA nao foi criada!!\n");
			       system("pause");
			       break;
			 
		     case '4':
			       system("cls");        
                   Imprimir(pilha);
			       system("pause");
			       break;
 	         case '5':
			       system("cls");        
                   printf("Digite o numero: ");
                   scanf("%d",&num);
                   retiraMenor(pilha, (void *)num);
                   Imprimir(pilha);
			       system("pause");
			       break;
             case '6':
			       system("cls");        
                   Impar(pilha);
                   Imprimir(pilha);
			       system("pause");
			       break;
             case '7':
			       system("cls");        
                   Inverte(pilha);
                   Imprimir(pilha);
			       system("pause");
			       break;
		}
    }	 
	
}
