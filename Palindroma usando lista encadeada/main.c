#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h> 
#include"list.h" 
 
SLlist *list;
 
int main(){
    char frase[100];
    int i,x=0,y;
    scanf("%s",frase);
    list = sllCreate();
    
    for(i=0;i< strlen(frase) ;i++){
        sllInserFirst(list,(void *)frase[i]);
    }
    
    if(strlen(frase)% 2 == 0)
       y= strlen(frase)/2;
    else
       y= (strlen(frase)-1)/2;
  
    for(i=0;i< y ;i++){
        if( frase[i]==(char)sllRemoveFirst(list))
             ++x;
      
    }
    if(x==y)
        printf("A palavra eh um palindromo!");
    else
        printf("A palavra nao eh um palindromo!!");
    getch();
    
}
