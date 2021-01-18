#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

class listaordenada
{
      private:
              struct caixa
              {
                     int num;
                     caixa *prox;
              }*cx, *inicio, *aux, *aux2;
              
      public:
             
             
             listaordenada()//construtot
             {                                
                       
                       inicio=NULL;
                       cx=NULL;
                       aux=NULL;
             }
             
             //----------------------------------------//
             
             
             void inserir()//inserir na lista
             {
                  int numero;
                  
                  while(true)
                  {
                             
                             
                             printf("\n Digite o numero");
                             scanf("%d",&numero);
                             if(numero==0)
                                          break;
                            
                                 if(inicio==NULL)//se nao tem nada cria uma caixa nova como primeira.
                                 {
                                                 cx=new caixa;
                                                 inicio=cx;
                                                 (*cx).num=numero;
                                                 (*cx).prox=NULL;
                                 }//if
                                 else
                                 {
                                     if(numero<=(*incio).num)//se ja tem, testa se é menor q o valor armazenado. se for por dps                                     
                                     {
                                                             aux=inicio;                                                                                                                        
                                                             cx=new caixa;
                                                             (*cx).num=numero;
                                                             (*cx).prox=aux;
                                                             inicio=cx;
                                     }                                                          
                                     else//senao ele irá procurar a posição correta para inserir
                                     {  
                                         aux=(*inicio).prox;
                                         aux2=inicio;
                                         
                                         while(aux!=NULL)
                                         {
                                                         if(numero>(*aux).num)
                                                         {
                                                                              aux2=aux;
                                                                              aux=(*aux).prox;
                                                         }//if
                                                         else
                                                             break;
                                                             
                                                         if(aux==NULL)
                                                         {
                                                                      cx=new caixa;
                                                                      (*cx).num=numero;
                                                                      (*cx).prox=NULL;
                                                                      (*aux2).prox=cx;
                                                         }//if
                                                         else
                                                         {
                                                             cx=new caixa;
                                                             (*cx).num=numero;
                                                             (*cx).prox=aux;
                                                             (*aux2).prox=cx;
                                                         }//else
                                                             
                                                                                                                                                                                                      
                                        }//while
                                     }//else
                  }//while
             }//fim inserir
             
             //----------------------------------------//

             
};
             
             
             
             
             
                  
                  
             
                                 
                                     
                                                 
                             
                             
                             
                             
                             
                             
                             
                  
