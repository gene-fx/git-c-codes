//Montar uma lista estatica com 30 elementos Inteiros,e com as seguintes Operações:
/*         
         1 - Inserir elemento lista
         2 - Mostrar elementos da lista
         3 - Excluir elemento da lista
         4 - Alterar elemento da lista
         5 - Gravar lista no disco <lista.txt>
         6 - Ler lista gravada <lista.txt>
         7 - Fim
*/

#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>
         
class lestatica
{
      private:
              struct listaestatica
              {
                     int qtde;
                     int elem[30];
              }listae;
      
      public:
             
             
     void lerdisco()
     {
      FILE *arq; 
      system("cls");
      arq = fopen("listae.txt","rb");
      if (arq==NULL)
      {
         puts("arquivo <listae.txt> não existe!");
         getchar();
         return;
      }//if
     
     int j=0;
     
     fread(&listae.elem, sizeof(int),30,arq);
     fclose(arq);
     puts("lendo disco");
     getchar();
     for(j=0;j<30;j++)
             if(listae.elem[j]==0)
             break;
     
     listae.qtde=j;
     }//ler disco
             
             
             
             
             lestatica ()
             {
                       listae.qtde = 0;
                       int i = 0;
                       
                       for (i=0; i<=29; i++)
                           listae.elem[i] = 0;
                       puts ("constroi lista");
                       getchar();
                       lerdisco();
             }           
     
     void inserir ()
     {
          int i=0;
          system ("CLS");
          
          if (listae.qtde == 30)
          { puts ("\nLista preenchida!");
            getch();
            return;
          }
          
          for (i = listae.qtde; i<=29; i++)
          {
              printf ("\nDigite valor[%d] = ", i);
              scanf ("%d", &listae.elem[i]);
              fflush (stdin);
              if (listae.elem[i] == 0) break;
          } // for
          
          listae.qtde = i;
     }// inserir   
     
     void mostrar ()
     {
          system ("CLS");
          puts ("Lista estatica\n");
          
          for (int i=0; i<listae.qtde; i++)
              printf ("\nLista[%d] = %d", i, listae.elem[i]);
          puts ("\nFim");
          getchar();        
     }//mostrar
     
     void excluir ()
     {
          int posicao=0;
          system ("CLS");
          mostrar ();
          puts ("Excluir qual posicao?: ");
          scanf ("%d", &posicao);
          fflush(stdin);
          
          if (posicao >= listae.qtde)
          {
             puts ("Posicao invalida, essa posicao eh maior que os registros!");
             getchar();          
          }     
          else
              {
               for (int i=posicao; i<listae.qtde; i++)
                   listae.elem[i] = listae.elem[i + 1];
                   
                listae.qtde--;               
              }//if
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
          
          if (posicao >= listae.qtde)
          {
             puts ("Posicao invalida, essa posicao eh maior que os registros!");
             getchar();          
          }     
          else
              {
               puts("Digite o novo valor");
               scanf("%d",  &novo);
               fflush(stdin);
               listae.elem[posicao]= novo;
              }//if
     }//alterar



     void gravardisco()
     {
          FILE *arq;
          system("cls");
          arq = fopen("listae.txt", "wb");
          fwrite(&listae.elem, sizeof(int),30,arq);
          fclose(arq); 
          puts("gravando..."); 
          getchar();
     }//granvando


    

~lestatica()
{
            gravardisco();
}//destrutor


};

     






int main ()
{
    char opcao; lestatica objeto;
    
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
