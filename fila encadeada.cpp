#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


class FILA_ENCADEADA
{
      private:
              struct caixa
              {
                    int valor;
                    caixa *prox;
              }cx[30],*ifila,*aux;
              int qtde,i;
              
      public:
             FILA_ENCADEADA()
             {
                             ifila=NULL;
                             qtde=0;
                             aux=NULL;
                             
                             for(i=0;i<=29;i++)
                             {
                                               cx[i].valor=0;
                                               cx[i].prox=NULL;
                             }//for
             }//construtor
             
             ///////////////////////////////////////////////////////////
             
             void incluir_fila()
             {
                  int xvalor;
                  i=qtde;
                  
                  while(true)//while só acaba no break
                  {
                                     if(i==30) 
                                     {
                                               puts("Fila cheia");                                      
                                               getchar(); 
                                               break;
                                     }
                                    
                             printf("\n digite um valor cx[%d]=",i);
                             scanf("%d",& xvalor);
                             fflush(stdin);
                             if(!xvalor) break;
                             
                             if(i==0)// cadastro 1°
                             {
                                     ifila=&cx[i];
                                     cx[i].valor=xvalor;
                                     cx[i].prox=NULL;
                                     qtde++;
                             }
                             else//cadastro 2°
                             {
                                 cx[i].valor=xvalor;
                                 cx[i].prox=NULL;
                                 cx[i-1].prox=&cx[i];
                                 qtde++;
                             }
                  }//while
             }//inclui fila
             
             
             
            //////////////////////////////////////////////////////////////////
            
            
            
             void mostra_fila()
             {
                  aux=ifila;
                  i=0;
                  
                  while(aux != NULL)
                  {
                            printf("\n Cx[%d]=%d",i,(*aux).valor);
                            i++;
                            aux=(*aux).prox;
                  }//while
             }//mostra fila
             
             ///////////////////////////////////////////////////////////////
             
             void alterar_fila()
             {
                  int xpos, xvalor;
                  
                  mostra_fila();
                  
                  printf("\n Qual posição alterar?");
                  scanf("%d",&xpos);
                  fflush(stdin);
                  if(xpos<0||xpos>+qtde);
                  {
                                         puts("Impossivel alterar");
                                         getchar();
                                         return;
                  }//if
                  
                  printf("\n digite o valor cx[%d]=",xpos);
                  scanf("%d",&xvalor);
                  fflush(stdin);                 
                  cx[xpos].valor=xvalor;
             }//aterar fila
             
             //////////////////////////////////////////////////////////////
             
             void excluir()
             {
                  char sn;
                  printf("Excluir primeira posiçao da fila? S/N");
                  scanf("%c",&sn);
                  if(sn=='S'||sn=='s')
                  {
                                      qtde--;
                                
                               if(qtde>=1)       
                                  {                                                 
                                          do
                                          {
                                               cx[i].valor=cx[i+1].valor;                                                                                      
                                          }while(i<qtde);
                                  }else
                                       ifila=NULL;
                                 
                                cx[qtde-1].prox=NULL;                                  
                  }
             }                         
                  
};//class

int main()
{
    int opcao=0;
    
    printf("Construindo Fila.");
    
    FILA_ENCADEADA fila;
    
    system("cls");
    
    printf("------MENU------");
    printf("\n\n\n\1 - Incluir na fila");
    printf("\n\n\2 - Ver fila");
    printf("\n\n\3 - Alterar posição");
    printf("\n\n\4 - Excluir");
    printf("\n\n\5 - Sair");
    scanf("%d",&opcao);
    
    
    switch(opcao)
    {
                 case 1:
                      fila.incluir_fila();
                      break;
                      
                 case 2:
                      fila.mostra_fila();
                      break;
                      
                 case 3:
                      fila.alterar_fila();
                      break;
                      
                 case 4:
                      fila.excluir();
                      break;
                      
                 case 5:
                      break;
    }
};
                      
    
    
                            
                            
                  
                  

                             
                  
                                                    
             
