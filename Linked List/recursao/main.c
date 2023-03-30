#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main()
{
    Node x = new_list(0);

    int k, opcao;
    do {
        // Insiste at� que o usu�rio digite uma op��o correta.
        printf("\n(1) Inserir\n");
        printf("(2) Deletar\n");
        printf("(3) Size\n");
        printf("(4) Pertence\n");
        printf("(5) Ordenar\n");
        printf("(0) Imprimir\n");
        printf(">> ");
        scanf("%d", &opcao);

        // Executa a solicita��o do usu�rio.
        if (opcao == 1) {
            printf("\nValor a ser inserido: ");
            scanf("%d", &k);
            Inserir(x, k);
        }
        else if (opcao == 2) {
            printf("\nValor a ser removido: ");
            scanf("%d", &k);
            Remover(x,k);
        }
        else if (opcao == 3) {
            printf("%d", Size(x));
        }
        else if (opcao == 4) {
            printf("\nValor a ser conferido: ");
            scanf("%d", &k);
            if (Pertence(x, k) != NULL)
                printf("Pertence!");
            else
                printf("Nao!");
        }else if(opcao==5){
            int n = Size(x);
            int v[n];
            for(int i=0;i<n;i++){
            puts("\nValores a serem ordenados:\n");
            scanf("%d",&v[i]);}
                Ordenar(v);
        }else {
            Imprimir(x);
        }
    } while (1);

    return 0;
}


