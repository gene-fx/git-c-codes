//Montar uma PILHA estatica com 30 elementos Inteiros,e com as seguintes Operações:
/*         
         1 - Inserir elemento PILHA
         2 - Mostrar elementos da PILHA
         3 - Excluir elemento da PILHA
         4 - Alterar elemento da PILHA
         5 - Gravar lista no disco <PILHA.txt>
         6 - Ler lista gravada <PILHA.txt>
         7 - Fim
*/

#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>
         
class pestatica
{
      private:
              struct PILHAestatica
              {
                     int qtde;
                     int elem[30];
                     int pos;
              }PILHAe;
      
      public:
             
             
     void lerdisco()
     {
      FILE *arq; 
      system("cls");
      arq = fopen("PILHAe.txt","rb");
      if (arq==NULL)
      {
         puts("arquivo <PILHAe.txt> não existe!");
         getchar();
         return;
      }//if
     
     int j=0;
     
     fread(&PILHAe.elem, sizeof(int),30,arq);
     fclose(arq);
     puts("lendo disco");
     getchar();
     for(j=0;j<30;j++)
             if(PILHAe.elem[j]==0)
             break;
     
     PILHAe.qtde=j;
     }//ler disco
             
             
             
             
            pestatica ()
             {
                       PILHAe.qtde = 0;
                       int i = 0;
                       
                       for (i=0; i<=29; i++)
                           PILHAe.elem[i] = 0;
                       puts ("constroi lista");
                       getchar();
                       lerdisco();
             }           
     
     void inserir ()
     {
          int i=0;
          system ("CLS");
          
          if (PILHAe.qtde == 30)
          { puts ("\nLista preenchida!");
            getch();
            return;
          }
          
          for (i = 29; i>=0; i--)
          {
              printf ("\nDigite valor[%d] = ", i);
              scanf ("%d", &PILHAe.elem[i]);
              fflush (stdin);
              if (PILHAe.elem[i] == 0)
              {
                PILHAe.pos=i;                  
                 break;
              }   
                 
              PILHAe.qtde++;   
          } // for
          
          PILHAe.qtde = i;
     }// inserir   
     
     void mostrar ()
     {
          system ("CLS");
          puts ("Lista estatica\n");
          
          for (int i=0; i<PILHAe.qtde; i++)
              printf ("\nLista[%d] = %d", i, PILHAe.elem[i]);
          puts ("\nFim");
          getchar();        
     }//mostrar
     
     void excluir ()
     {
          system("cls");
          char opcao;
          int contador=0, pos=0;
          
          puts ("\Que excluir a primeira posição da pilha?    s/n");
          scanf("%c",&opcao);
          if(opcao=='s')
          {
                        for(int i=29;i>=0;i--)
                        {
                                if(PILHAe.elem[i]=!0)  contador++;                                
                        }//fim for
                        
                        pos=29-contador+1;
                        PILHAe.elem[pos]=0;
                        PILHAe.qtde--;
                        PILHAe.pos=pos;
                        
                        
          }//fim if
          
                                                                             
                        
     }//excluir
     
     void alterar ()
     {
          int novo=0;
          int posicao=0;
          system ("CLS");
          mostrar ();
          puts ("Alterar qual posicao?: ");
          scanf ("%d", &posicao);
          fflush(stdin);
          
          if (posicao >= PILHAe.qtde)
          {
             puts ("Posicao invalida, essa posicao eh maior que os registros!");
             getchar();          
          }     
          else
              {
               puts("Digite o novo valor");
               scanf("%d",  &novo);
               fflush(stdin);
               PILHAe.elem[posicao]= novo;
              }//if
     }//alterar



     void gravardisco()
     {
          FILE *arq;
          system("cls");
          arq = fopen("PILHAe.txt", "wb");
          fwrite(&PILHAe.elem, sizeof(int),30,arq);
          fclose(arq); puts("gravando..."); 
          getchar();
     }//granvando


    

~pestatica()
{
            gravardisco();
}//destrutor


};

     






int main ()
{
    char opcao; pestatica objeto;
    
    while (1)
    {
          system ("CLS");
          printf ("\nMenu Opcoes");      
          printf ("\n1- Incluir Elementos");
          printf ("\n2- Mostrar Elementos");
          printf ("\n3- Excluir Elementos");
          printf ("\n4- Alterar Elementos");
          printf ("\n5- Gravar <lista.txt>");
          printf ("\n6- Ler <lista.txt");
          printf ("\n7- Fim");
          
          printf ("\n\nQual opcao?");
          opcao = getche ();
          
          if (opcao == '7') break;
          if (opcao == '1') objeto.inserir ();
          if (opcao == '2') objeto.mostrar ();
          if (opcao == '3') objeto.excluir ();
          if (opcao == '4') objeto.alterar ();
          if (opcao == '5') objeto.gravardisco ();
          if (opcao == '6') objeto.lerdisco();
    }
}
