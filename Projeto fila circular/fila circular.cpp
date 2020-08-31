#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>

#define   TRUE     1
#define   FALSE    0



//fila circular
typedef struct _queue_{                  // estrutura fila--   maxsize - tamanho maximo, beg - comeco da fila
  int maxsize, beg, end, nelem;         // end - fim da fila, nelem - quantos elem tem na fila
  void **elem;                         // elementos da fila        
}Queue;                               //nome da extrutura Queue

Queue *fila;
int nome;

int qInsere(Queue *q, void *elem){              //insere elementos na fila
    if(q!= NULL){
         if(q-> nelem < q-> maxsize ){      //compara o tamanho com o tamanos max da fila
              q-> end = ( q-> end + 1 )% q-> maxsize;
			  q-> elem[q-> end] = elem;         // o vetor recebe o elem
			  q-> nelem++;                      // o num de elem eh incrementado
              return TRUE;
         }       
    }     
    return FALSE;
}

void *qRemove(Queue *q){
    
    void *aux;
    if(q!=NULL){
          if(q-> nelem > 0){
                aux= q-> elem[q->beg];
                q-> beg = ( q-> beg + 1 )% q-> maxsize;
                q-> nelem--;
				return aux;
                
          }
    }
    return NULL;
}

int cmp(void *str1,void *str2 ){
	int a,b;
	a=(int)str1;
	b=(int)str2;
	if(a==b)  
	     return TRUE;
	else return FALSE;
	
	
}


int qBuscar(Queue *q,void *str,int cmp(void*,void*) ){
     int i=0;
	 if(q!=NULL){
	     if(q->nelem > 0){
			  while(cmp(q-> elem[i],str) == FALSE && i< q-> nelem-1 )			
					 i++;
              if(cmp(q->elem[i],str))                      
					 return i;
              else   return -1;
			  
		 }
	 }	 

}

int qPune(Queue *q,int n){
	void *aux;
    int i,j;
	if(q!=NULL){
       	   if(n>0 && q->nelem > 1){
	       i=0;
	       aux=q->elem[q->beg];                     //aux recebe q formiga do começo da fila
	       j=q-> beg;                                       //j recebe a posicao do comeco da fila
	       while(i < n && j!= q -> end){                    //enquanto contador < numero de posicoes recebidas e j != final da fila
		          q->elem[j]= q->elem[(j+1) % q->maxsize];
		          printf("%d:  %d \n",j,(j+1) % q->maxsize);
				  j=(j+1)% q-> maxsize;
		          i++;
		   }
		   q->elem[j]= aux;
	       return TRUE;
	   }
	}
    else   return FALSE; 
}

int qPromove(Queue *q,int n){
	int j,i,z;
	void *aux;
	if(q!=NULL){
	     if(n>0 && q->nelem > 1){			
		     i=0;
 			aux=q-> elem[q-> end];
    		 j=q->end;
		     z=q->end;
	         while(i < n && j!= q->beg ){                 //enquanto contador < numero de posicoes recebidas e j != final da fila
		          if(z==0) z=q->maxsize -1;
		          else     --z;
				  printf("%d\n",z);
				  q-> elem[j] = q->elem[z];
				  j= z;
		          i++;
      		}
      		q->elem[j]= aux;
      	    return TRUE;
		 }
    return FALSE;
	}
	
}

void corrige(Queue *q)
{
     int i= -1,j;
     void ** aux;
     if(q!=NULL){
	     if(q-> beg != 0 && q->nelem > 1){
                aux = (void **)calloc(q-> maxsize, sizeof(void *));
                j = q-> beg;
                while(i< q-> nelem ){
                         i++;
                         aux[i] = q-> elem[j];
                         j = (j+1)%q-> maxsize;         
                }	   
                q-> beg = 0;
                q-> end = i;
                q-> elem = aux;
          }
     }
}

void limpar(Queue *q){
     if(q != NULL){
          if(q-> nelem > 0){
                 q-> beg = 0;
                 q-> end = -1;
                 q-> nelem = 0;       
          }     
     }     
}

int main(){
   

   int opt, qtd, x, i;
   while(1){                                                         //menu
      
        system("cls");                                               //limpa a tela no laço    
        printf("Escolha uma opcao: \n\n");
        printf("1 - Criar    fila\n\n");
        printf("2 - Inserir  numero na fila\n\n");
        printf("3 - imprimir fila \n\n");
        printf("4 - Retirar  da fila \n\n");
        printf("5 - Buscar numero\n\n");
        printf("6 - Punir numero\n\n");
        printf("7 - Promover numero\n\n");
        printf("8 - Corrigir fila\n\n");
        printf("9 - Limpar fila\n\n");
      
       opt = getch();
       switch(opt){
          case '1':                                                  //criar fila
              
               system("cls");    
               if(fila!=NULL)  printf ("Fila ja criada!!\n");
               else{
			       fila = (Queue *)malloc(sizeof(Queue));            //aloca espaço na memoria para a struct fila
                   printf("\nDigite a quantidade de formigas q deseja inserir na fila: ");
                   scanf("%d",&qtd);                                 // quantidade de formigas na fila
             
                   fila-> elem= (void**)calloc(qtd,sizeof(void *));
                   fila-> maxsize = qtd;
                   fila-> beg = 0;
                   fila-> end = -1;
                   fila-> nelem = 0;
                   printf("A fila foi criada com sucesso!\n");
			   }       
               system("pause");
               
          break;
          
          case '2':                                           //inserir formiga
               system("cls"); 
               if(fila-> maxsize > fila-> nelem){    
                   //nome = (int)calloc(qtd,sizeof(char *));
                   printf("\nDigite o numero na fila: ");
                   scanf("%d",&nome);
                   x= qInsere(fila,(void *)nome);
                   if(x)  printf("o numero %d foi inserido\n",fila->elem[fila->end]);
                   else   printf("o numero nao foi inserido\n");
               } 
               else  printf("A quantidade de numeros excedeu\n");
               //free(nome); 
              // nome=NULL;
			   system("pause");
              
               
          break;
          
          case '3'://imprimir fila
               system("cls");
			   if(fila!= NULL){
     			   x=fila->beg;
				   for(i=0;i < fila-> nelem; i++){
				       printf("posicao %d da fila : %d\n",x,fila-> elem[x]);
                       if(x == fila->maxsize -1)  x=0;
                       else      x++;
			       }
				   printf("\n\nnelem   %d\n",fila-> nelem);  
                   printf("maxsize %d\n",fila-> maxsize);  
                   printf("beg     %d\n",fila-> beg);
                   printf("end     %d\n\n",fila-> end);  
			  }
			  else printf("a fila nao foi criada!!\n");
			  system("pause");
          break; 
		  
		  case '4'://remover formiga
		  	   system("cls");
  	           if(fila!=NULL){
				 printf("beg fila eh %d\n",fila->elem[fila-> beg]);
			     nome = (int)qRemove(fila);
		  	     printf("%d retirado da fila\n",nome);
			   }
			   else  printf("a fila nao foi criada!!\n");
               system("pause");
	      break;
	      
	      case '5'://buscar formiga
  	          system("cls");
  	          if(fila!= NULL){
				//nome = (char *)calloc(qtd,sizeof(char *));
  	            printf("Digite o numero q deseja buscar: ");
  	            scanf("%d",&nome);
  	            x= qBuscar(fila,(void *)nome,cmp);
                if(x!= -1)
			           printf("\no numero %d foi encontrado na %d posicao na fila\n",nome,x);
  	            else   printf("o numero nao esta na fila!!\n");
			  }
			  else printf("a fila nao foi criada!!\n");
			  system("pause");
          break;
          
          case '6'://punir formiga
		  	   system("cls");
		  	   if(fila!= NULL){
			     printf("Em quantas posicoes deseja punir o numero: ");
			     scanf("%d",&i);
			     x=qPune(fila,i);
			     if(x) printf("A numero foi punida!\n");
			     else  printf("A numero nao foi punida!\n");
			   
			   }
               else  printf("A Fila nao foi criada!!\n");
               system("pause");
		  
		  
		  break;
		  
		  case '7'://promover formiga
	         system("cls");
	         if(fila!= NULL){
			    printf("Quantas posicoes deseja promover o numero: ");
			    scanf("%d",&i);
			    x=qPromove(fila,i);
			    if(x) printf("O numero foi punida!\n");
		        else  printf("O numero nao foi punida!\n");
			 }		  
		     else  printf("A Fila nao foi criada!!\n");
             system("pause");
		  break;
		  case '8'://promover formiga
	         system("cls");
	         if(fila!= NULL){
			    corrige(fila);
			 }		  
		     else  printf("A Fila nao foi criada!!\n");
             system("pause");
		  break;
		  case '9'://promover formiga
	         system("cls");
	         if(fila!= NULL){
			    limpar(fila);
			 }		  
		     else  printf("A Fila nao foi criada!!\n");
             system("pause");
		  break;
          
                 
      }
    }   
    
}

