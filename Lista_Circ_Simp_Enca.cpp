// Lista Circular Simplesmente Encadeada

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

class LCSE
{
     private:
     struct caixa
     {
            char txt[20];
            caixa *prox;
     } *inicio, *cx, *aux, *aux2;
     
     int conta;
     
     public:
     
     LCSE()
     {
          inicio = NULL;
          cx = NULL;
          aux = NULL;
          aux2 = NULL;
          conta=0; 
     } // Construtor
     
     void incluir()
     {
       char texto[20];
       
       while (true)
       {
             printf("\n Lista Circular");
             printf("\n Digite o Texto");
             printf("\n\n");
             gets(texto);
             if (strlen(texto) == 0) break;
             if (inicio == NULL)
             {
               cx=new caixa;
               inicio=cx;
               strcpy((*cx).txt,texto);
               (*cx).prox=inicio;
               aux=cx;
               
             }
             else
             {
                 aux=cx;
                 cx=new caixa;
                 strcpy((*cx).txt,texto);
                 (*cx).prox=inicio;
                 (*aux).prox=cx;
                 aux=cx;
             }
       }//fim while(tru)
       
     }//fim inserir
     
     //----------------------------------------------//
     
     void mostrar()
     {
          aux2=inicio;
          conta=0;
          
          do
          {
            conta++;          
            printf("\n [%d] = %s", conta, (*aux2).txt);
            aux2=(*aux2).prox;         
          }while(aux2!=inicio);//fim do do/while
          
     }//fim mostra
     
     //----------------------------------------------//
     
     void excluir()
     {
          mostrar();
          
          int pos;
          
          conta=1;
          aux2=inicio;
          
          printf("\n\nQual posi��o apagar?");
          scanf("%d",&pos);
          fflush(stdin);
          
          if(pos<=0) return;//testa se a posi��o nao � invalida
          
          
          if((*aux2).prox==inicio)//testa se � a primeira posi��o a ser apagada
          {
                                 inicio=NULL;
                                 free(aux2);                      
          }//fim do if
          
          
          if(pos==1)//se for primeira posi��o
          {
                    inicio=(*aux2).prox;//o inico passa a ser a segunda
                    free(aux2);//a primerira � limpa
                    aux=inicio;//e a ultima volta a apontar para o novo inicio
          }
          else//se nao, correr� todas a posi��es
          {
              cx=inicio;//aponta sempre para a posi��o anteriao ao aux2
              aux2=(*aux2).prox;//aponta, INICIALMENTE, para posi��o � frente do inicio
                  
              while(aux2!=inicio)
              {
                                conta++;
                                if(pos==conta)//se a posi��o for igual o contador, entao...
                                {
                                             (*cx).prox=(*aux2).prox;//o ponteiro cx apontara para posi��o al�m da que ser� apagada                
                                             free(aux2);//a posi��o selecionada ser� apagada
                                             break;//e o programa para                          
                                }
                                cx=aux2;//se nao for apagada as posi��es devem avan�ar
                                aux2=(*aux2).prox;
              }//fim while
          }//fim do excluir
          
          
     }//fim exclui
     
     //----------------------------------------------//
     
     void alterar()
     {
          aux2=inicio;
          
          int pos=0;
          char altera[20];
          
          
          mostrar();
          
          conta=0;
          
          printf("\n\nQual posi��o alterar?");
          scanf("\n%d",&pos);
          fflush(stdin);
          
          for(int i=0; i < pos; i++)
          {
                          conta++;
                          printf("\nconta = %d",conta);
                          if(pos==conta)
                          {
                                        printf("\n\nAltera�ao:");
                                        gets(altera);
                                        strcpy((*aux2).txt,altera);
                                        break;
                          }//fim if 
                          
                          aux2=(*aux2).prox;
                                     
          }//fim for
     }//fim alterar

     
}; //fim da Class


int main()
{
     LCSE Lista;
     Lista.incluir();
     system("cls");
     Lista.mostrar();
     system("cls");
     Lista.excluir();
     system("cls");
     Lista.alterar();
     Lista.mostrar();
     getchar();

} // Main



