#define __COLECAO_C_

#include <stdio.h>	    /* definicao da constante NULL */
#include <assert.h>	    /* afirmacoes de verificacao de pre condicao */
#include "Colecao.h"	/* inclui a especificacao do TAD */


#define TRUE    1
#define FALSE   0


//Criacao struct _colecao_
struct _colecao_ {
  
	int numItens;   /* numero de itens na colecao */
	int maxItens;	  /* tamanho máximo da colecao */
	void ** itens;     /*ponteiro vetor com os itens */

};


//Funcao Criar Colecao

Colecao *colCriar(int maxItens)// recebe o numero de itens, devolve um endereço de uma colecao
{
	Colecao * c; 
	if ( maxItens > 0 ){
	      c =(Colecao *) malloc( sizeof(Colecao));// aloca um espaco na memoria p/ a colecao
	
	     if(c!=NULL){
              c-> itens = (void**) calloc (maxItens, sizeof (void *));//aloca um espaço na memoria p/ os itens da colecao
              if(c->itens != NULL){
                   c-> maxItens = maxItens;//adiciona os elementos da colecao
                   c-> numItens = 0;
                   return c;
              }
          }
      }
     
    return NULL;
}   /* fim de colCriar */



//Funcao Inserir Item na Colecao

int colInserir( Colecao *c,void *item ){//recebe o o endereço da colecao, 
	
        if ( c != NULL ) {//se ja tiver sido criada a colecao
            if(c->numItens < c->maxItens){
                   c-> itens[c-> numItens] = item;
                   c-> numItens++;
                   return TRUE;
                 
            }
        }    
        return FALSE;
	
} /* fim de colInserir */





//Funcao Buscar


void* colBuscar(Colecao* c, void* Key, int cmp(void *, void *)){
      
      int i=0;

      if(c != NULL){
      if(c->numItens > 0){                          
         while((cmp(Key, c->itens[i]) != TRUE) && (i < (c->numItens))){
             i++;  
         }
         
         if((cmp(Key,c->itens[i])) == TRUE){
            return c->itens[i];
         }
         else return NULL;      
      }                  
   }
}// fim de colBuscar


//Funcao colRetirar

int colRetirar(Colecao* c, void *Key, int cmp(void *, void *)){
    void * al;
    int i=0;
    if(c != NULL){
            while((cmp(Key, c->itens[i]) != TRUE) && (i < (c->numItens))){
                 i++;  
            }
            if((cmp(Key,c->itens[i])) == TRUE)
                 
            c->numItens--;
            return TRUE;
    }
    
    return FALSE;
    

}

 
 //Funcao Destruir Colecao

int colDestruir(Colecao *c){ // recebe um ponteiro para colecao e devolve um int boolean
   
    if(c!= NULL){
           int i;
           
           for (i=0;i<c->maxItens;i++){
               free (c->itens[i]);
               }
              
           free(c-> itens);
           free(c);
           c=NULL;
           return TRUE; 
    }   
    return FALSE;
}// fim do colDestruir


 
