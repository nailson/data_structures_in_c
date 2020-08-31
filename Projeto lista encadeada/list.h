#ifndef LIST_H
#define LIST_H

#define TRUE 1          /* utilizado true com valor 1*/
#define FALSE 0         /* utilizado false com valor 0 */


typedef struct _slnode_ {
       
    struct _slnode_ *next;	    /* Aponta para proximo elemento da lista */
	void *data;                 /* Contém os dados do elemento */
	
}SLnode;   

typedef struct _sllist_ {
    SLnode *first;              /* Aponta para primeiro elemento da lista */
}SLlist;



SLlist *sllCreate(void);

int sllInserFirst(SLlist *,void *);

void *sllRemoveFirst(SLlist *);

int sllInsereLast(SLlist *, void *);

void *sllRemoveLast(SLlist *);

int sllCountNode(SLlist *);

SLnode *sllGetNode(SLlist *,void *,int (*cmp)(void *,void *));

int sllInsertAfterEsp(SLlist *,void *, void *, int (*cmp)(void *,void *));

void *sllRemoveEsp(SLlist *,void *,int (*cmp)(void *,void *));

int sllInsertBeforeEsp(SLlist *,void *, void *, int (*cmp)(void *,void *));

int sllRemoveAllNode(SLlist *);

#endif
