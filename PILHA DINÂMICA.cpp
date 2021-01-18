#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//montar uma PILHA DINÂMICA (encadeada) na memória

class pilhadinamica
{
      private:
              struct caixa
              {
                     char letra;
                     caixa *prox;
              } *ipilha, *aux, *cx;
              
      public:
             
                         
            //_________________________________________//
             pilhadinamica()
             {
                            //construtor
                  ipilha = NULL;
                  aux = NULL;
                  cx = NULL;
                  printf("CONSTRUTOR");
                  getchar();
             }//contrutor
             
             
             //_________________________________________//
             void inserirpilha(char xl)
             {
                  if(ipilha==NULL)
                  {
                                  cx=new caixa;
                                  (*cx).letra=xl;
                                  (*cx).prox=NULL;
                                  ipilha=cx;
                  }//if
                  else
                  {
                                  cx=new caixa;
                                  (*cx).letra=xl;
                                  (*cx).prox=ipilha;
                                  ipilha=cx;
                  }//else
                                  
             }//inserir pilha
             
             
             //_________________________________________//
             void mostrarpilha()
             {
                  int i=0;
                  aux=ipilha;
                  while(aux!=NULL)
                  {
                                  printf("\nCx %d = %c",i,(*aux).letra);
                                  aux=(*aux).prox;
                                  i++;
                  }//while
                  getchar();
                                  
             }//mostrar pilha
             
             
            //_________________________________________// 
             void alterarpilha()
             {
                  mostrarpilha();
                  
                  char pos, nova;
                  
                  printf("\nQual letra deseja alterar?");
                  scanf("%c",&pos);
                  fflush(stdin);
                  printf("\nQual a nova letra?");
                  scanf("%c",&nova);
                  fflush(stdin);
                  
                  aux=ipilha;
                  while(aux!=NULL)
                  {
                                  if(pos==(*aux).letra)
                                  (*aux).letra=nova;
                                  aux=(*aux).prox;                                                        
                  }//while                                                                   
             }//alterar pilha
             
             
             //_________________________________________// 
             void excluirpilha()
             {
                  if(ipilha==NULL)
                  {
                      puts("Pilha Vazia!");
                      getchar();
                      return;
                  }//if
                  
                  char sn;
     
                  printf("Quer excluir a ultima posição (Letra '%c')? s/n",(*ipilha).letra);
                  scanf("%c",&sn);
                  fflush(stdin);
                  
                  if(sn=='s'||sn=='S');
                  {
                                       aux=ipilha;                                       
                                       ipilha=(*aux).prox;
                                       free(aux);                  
                  }//if             
                  system("cls");
                  mostrarpilha();
                                                                                          
             }//excluipilha
             
             
             //_________________________________________// 
             void gravarpilha()
             {
                  FILE *arq;
                  
                  arq=fopen("pilha.txt","wt");
                  aux=ipilha;
                  while(aux!=NULL)
                  {
                                  fprintf(arq,"%c\n",(*aux).letra);//gravando no disco
                                  aux=(*aux).prox;                 //- \n serve para gravar um item e pular a linha para gravar o proximo           
                  }
                  fclose(arq);
             }//gravarpilha
             
             
             //_________________________________________// 
             void lerpilha()
             {
                  FILE *arq;
                  char letra;
                  caixa *iaux=NULL;
                  
                  arq=fopen("pilha.txt","rt");
                  if(arq==NULL)
                               return;
                  
                  while(!feof(arq))
                  {
                                   fscanf(arq,"%c",&letra);//lendo disco
                                   cx=new caixa;
                                   (*cx).letra=letra;
                                   (*cx).prox=iaux;
                                   iaux=cx;
                  }
                  fclose(arq);//copiou o conteudo do arquivo para o *cx mas ainda nao criou a pilha
                  //ao ler o arquivo o conteudo é lido em ordem inversa, ou seja, a ultima posição é 'a' e vai até 'u'
                  
                  aux=ipilha;
                  while(aux!=NULL)
                  {
                                  inserirpilha((*aux).letra);
                                  aux=(*aux).prox;
                  }//passaou o conteudo do arquivo para dentro da pilha em posição correta
                  //a pilha e montada de 'u' até 'a'
                  
             }//lerpilha
                               
                               
                  
             
             

             
};

int main ()
{
    pilhadinamica p;
    p.inserirpilha('a');
    p.mostrarpilha();
    p.inserirpilha('e');
    p.mostrarpilha();
    p.inserirpilha('i');
    p.inserirpilha('o');
    p.inserirpilha('u');
    p.mostrarpilha();
    system("cls");
    p.alterarpilha();
    p.mostrarpilha();
    system("cls");
    p.excluirpilha();
    p.gravarpilha();
} 
