#ifndef __COLECAO_H
#define __COLECAO_H

typedef struct _colecao_ Colecao;



Colecao *colCriar(int);//funçao criar

int colInserir( Colecao *,void * );//funcao inserir

void *colBuscar(Colecao *, void *, int cmp(void*,void*));//funcao buscar

int colRetirar(Colecao *, void *, int cmp(void*,void*));//funcao retirar

int colDestruir(Colecao *);//funcao destruir







#endif  /* __Colecao_INT_H */
