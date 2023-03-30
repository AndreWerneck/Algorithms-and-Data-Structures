// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exerc�cios sobre listas encadeadas - fila.
//
// Quest�o 1.
// Implemente em queue.h e queue.c o TAD queue.
//
// Quest�o 2.
// Escreva uma fun��o "void Imprimir(queue p)" que recebe
// como par�metro uma fila q e imprime os elemento de q na tela.
// P�s-condi��o: a fila 'q' n�o � alterada.
//
// Quest�o 3.
// Escreva um programa que gerencia uma fila de banco. Ao entrar na fila,
// o cliente d� seu CPF e sua idade. Os clientes s�o atendidos por ordem de
// chegada. Entretanto, os clientes com 60 anos ou mais tem prioridade sobre
// os outros clientes, ou seja, um cliente com menos de 60 anos s� � atendido
// se n�o houver nenhum cliente com 60 anos ou mais esperando na fila. O sistema
// que voc� vai implementar deve apresentar duas op��es: "(1) Entrar na fila" e
// "(2) Pr�ximo da fila". Na Primeira, o sistema deve cadastrar o CPF e a
// idade do cliente. J� na segunda op��o, ele deve imprimir o CPF do
// pr�ximo cliente que est� esperando e retir�-lo da fila, ou se for o caso
// imprimir uma mensagem indicando que a fila est� vazia.
// DICA: Use duas filas: uma para armazenar os nomes dos clientes
// priorit�rios e outra para armazenar os nomes dos clientes n�o priorit�rios.

#include <stdio.h>
#include <stdlib.h>
#include "queue_with_linked_list.h"

// Quest�o 2.
////////////////////////////////////////////////////////////////////////////////

// Imprime os elementos da fila q na tela.
void Imprimir(queue q) {
  printf("[ ");
  for (int i = 0; i < size(q); i++) {
    printf("%d ", front(q));
    push(front(q), q);
    pop(q);
  }
  printf("]\n");
}

// Quest�o 3.
//////////////////////////////////////////////////////////////////////////////

// Insere um cliente na fila do banco.
void Enfileirar(int cpf,
                int idade,
                queue prioritarios,
                queue nao_prioritarios) {
  if (idade >= 60) {
    push(cpf, prioritarios);
  } else {
    push(cpf, nao_prioritarios);
  }
}

// Retira o pr�ximo cliente da fila do banco e retorna o seu cpf.
// Precondi��o: as duas filas n�o est�o vazias.
int Desenfileirar(queue prioritarios,
                  queue nao_prioritarios) {
  int proximo;
  if (!empty(prioritarios)) {
    proximo = front(prioritarios);
    pop(prioritarios);
    return proximo;
  } else {
    proximo = front(nao_prioritarios);
    pop(nao_prioritarios);
    return proximo;
  }
}

int main() {
  queue prioritarios = new_queue();
  queue nao_prioritarios = new_queue();
  int opcao;
  do {
    // Insiste at� que o usu�rio digite uma op��o correta.
    do {
      printf("(1) Entrar na fila\n");
      printf("(2) Proximo da fila\n");
      printf("(3) Imprimir Fila\n");
      printf("(0) Sair\n");
      printf(">> ");
      scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
    // Executa a solicita��o do usu�rio.
    if (opcao == 1) {
      int cpf;
      printf("CPF: ");
      scanf("%d", &cpf);
      int idade;
      printf("Idade: ");
      scanf("%d", &idade);
      Enfileirar(cpf, idade, prioritarios, nao_prioritarios);
    } else if (opcao == 2) {
      if (empty(prioritarios) && empty(nao_prioritarios)) {
        printf("\n\n\nNenhum cliente na fila.\n\n");
      } else {
	printf("\n\n\nProximo: %d\n\n", Desenfileirar(prioritarios, nao_prioritarios));
      }
    } else if (opcao == 3) {
	printf("\n\nLista de espera:\n");
	Imprimir(prioritarios);
	Imprimir(nao_prioritarios);
	printf("\n");
      }
  } while (opcao != 0);
  delete_queue(prioritarios);
  delete_queue(nao_prioritarios);
  return 0;
}
