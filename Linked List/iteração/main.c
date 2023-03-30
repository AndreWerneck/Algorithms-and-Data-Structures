#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main()
{
    Node x = malloc(sizeof(struct Node_t));
    x->key = 0;
    x->next = NULL;

    int k, opcao;
    do {
        // Insiste até que o usuário digite uma opção correta.
        printf("\n(1) Inserir\n");
        printf("(2) Deletar\n");
        printf("(3) Size\n");
        printf("(4) Pertence\n");
        printf("(0) Imprimir\n");
        printf(">> ");
        scanf("%d", &opcao);

        // Executa a solicitação do usuário.
        if (opcao == 1) {
            printf("\nValor a ser inserido: ");
            scanf("%d", &k);
            Inserir(x, k);
        }
        else if (opcao == 2) {
            Deletar(x);
            Node x = malloc(sizeof(struct Node_t));
            x->key = 0;
            x->next = NULL;
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
        }
        else {
            Imprimir(x);
        }
    } while (1);

    return 0;
}


