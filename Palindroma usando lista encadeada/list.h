//#ifndef LIST_H
//#define LIST_H


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

//#endif
