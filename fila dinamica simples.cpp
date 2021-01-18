#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

class filadina
{
      private:
              struct caixa
              {
                     char txt[20];
                     caixa *prox;
              }*cx, *inicio, *aux;
              
      public:
             
             
             filadina()//construtot
             {                                
                       
                       inicio=NULL;
                       cx=NULL;
                       aux=NULL;
             }
             
             //----------------------------------------//
             
             
             void inserir()//inserir na fila
             {
                  char texto[20];
                  while(true)
                  {
                             printf("\n Digite o texto");
                             gets(texto);
                             if(strlen(texto)==0)
                                                 break;
                             else
                                 if(inicio==NULL)
                                 {
                                                 cx=new caixa;
                                                 inicio=cx;
                                                 strcpy((*cx).txt,texto);
                                                 (*cx).prox=NULL;
                                 }//if
                                 else
                                 {
                                     aux=cx;
                                     cx=new caixa;
                                     (*aux).prox=cx;
                                     strcpy((*cx).txt,texto);
                                     (*cx).prox=NULL;
                                 }//else
                  }//while
             }//fim inserir
             
             
             //----------------------------------------//
             
             
             void mostrar()//mostrar fila
             {
                  int conta=0, opcao=0;
                  
                  aux=inicio;
                  
                  while(aux!=NULL)
                  {
                                   conta++;
                                   printf("[%d] - %s",conta,(*aux).txt);
                                   aux=(*aux).prox;
                  }//while
             }//fim mostrar
             
             
             //----------------------------------------//
             
             
             void excluir()
             {
                  char sn;
                  
                  printf("Quer exluir a primeira posicao?");
                  printf("\n%s",(*inicio).txt);
                  printf("\n\nSim ou Nao?");
                  scanf("%c",&sn);
                  if(sn=='s' || sn=='S')
                  {
                            aux=inicio;
                            inicio=(*aux).prox;
                            free(aux);
                  }//if
             }//exclir
             
             
             //----------------------------------------//
             
             
             void alterar()
             {
                  int opcao, i=0;
                  char texto[20];
                  
                  mostrar();
                  
                  printf("\n\n Qual posicao quer alterar");
                  scanf("%d",opcao);
                  
                  printf("\n\n Alteracao:");
                  gets(texto);
                  
                  aux=inicio;
                  
                  while(aux!=NULL)
                  { 
                                i++;             
                                if(opcao==i)
                                            strcpy((*aux).txt,texto);
                                            
                                aux=(*aux).prox;            
                  }//for
             }//fim alterar
             
             
};
             
             
             
             
             
                  
                  
             
                                 
                                     
                                                 
                             
                             
                             
                             
                             
                             
                             
                  
