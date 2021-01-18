//Montar uma fila estatica com 30 elementos Inteiros,e com as seguintes Operações:
/*         
         1 - Inserir elemento fila
         2 - Mostrar elementos da fila
         3 - Excluir elemento da fila
         4 - Alterar elemento da fila
         5 - Gravar lista no disco <fila.txt>
         6 - Ler lista gravada <fila.txt>
         7 - Fim
*/

#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>
         
class festatica
{
      private:
              struct filaestatica
              {
                     int qtde;
                     int elem[30];
              }filae;
      
      public:
             
             
     void lerdisco()
     {
      FILE *arq; 
      system("cls");
      arq = fopen("filae.txt","rb");
      if (arq==NULL)
      {
         puts("arquivo <filae.txt> não existe!");
         getchar();
         return;
      }//if
     
     int j=0;
     
     fread(&filae.elem, sizeof(int),30,arq);
     fclose(arq);
     puts("lendo disco");
     getchar();
     for(j=0;j<30;j++)
             if(filae.elem[j]==0)
             break;
     
     filae.qtde=j;
     }//ler disco
             
             
             
             
             festatica ()
             {
                       filae.qtde = 0;
                       int i = 0;
                       
                       for (i=0; i<=29; i++)
                           filae.elem[i] = 0;
                       puts ("constroi lista");
                       getchar();
                       lerdisco();
             }           
     
     void inserir ()
     {
          int i=0;
          system ("CLS");
          
          if (filae.qtde == 30)
          { puts ("\nLista preenchida!");
            getch();
            return;
          }
          
          for (i = filae.qtde; i<=29; i++)
          {
              printf ("\nDigite valor[%d] = ", i);
              scanf ("%d", &filae.elem[i]);
              fflush (stdin);
              if (filae.elem[i] == 0) break;
          } // for
          
          filae.qtde = i;
     }// inserir   
     
     void mostrar ()
     {
          system ("CLS");
          puts ("Lista estatica\n");
          
          for (int i=0; i<filae.qtde; i++)
              printf ("\nLista[%d] = %d", i, filae.elem[i]);
          puts ("\nFim");
          getchar();        
     }//mostrar
     
     void excluir ()
     {
        char opcao;
          puts ("Deseja excluir a posição 0?  s/n ");
               scanf("%c", &opcao);
               if(opcao=='s')
               {
                             filae.elem[0]=0;
                             
                             for(int i=0; i<filae.qtde; i++)
                                     filae.elem[i]=filae.elem[i]+1;
                                     filae.qtde--;              
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
          
          if (posicao >= filae.qtde)
          {
             puts ("Posicao invalida, essa posicao eh maior que os registros!");
             getchar();          
          }     
          else
              {
               puts("Digite o novo valor");
               scanf("%d",  &novo);
               fflush(stdin);
               filae.elem[posicao]= novo;
              }//if
     }//alterar



     void gravardisco()
     {
          FILE *arq;
          system("cls");
          arq = fopen("filae.txt", "wb");
          fwrite(&filae.elem, sizeof(int),30,arq);
          fclose(arq); puts("gravando..."); 
          getchar();
     }//granvando


    

~festatica()
{
            gravardisco();
}//destrutor


};

     






int main ()
{
    char opcao; festatica objeto;
    
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
