#ifndef LISTDUP_H
#define LISTDUP_H

#define TRUE 1
#define FALSE 0


typedef struct _dlnode_{
    struct _dlnode_ *prev, *next;
    void *data;
}Dlnode;

typedef struct _dllist_{
    Dlnode *first;
}Dllist;


typedef struct _Cadastro_{
    char nome[50];
    int cpf;        
}Indiv;

Dllist *dllCreate(void);//funcao criar

int dllInserirFirst(Dllist *, void *);//funcao inserir na frente

int dllInserirLast(Dllist *,void *);//funcao inserir no final

int dllContar(Dllist *);//funcao contar nos

void dllImprimeList(Dllist *);//funcao imprimir list defeito!

void *RemoverFirst(Dllist *);//funcao remover primeiro

void *RemoverEnd(Dllist *);//funcao remover final

int dllInsertAfterEsp(Dllist *, void *, void *, int (*cmp)(void *, void *));

#endif
