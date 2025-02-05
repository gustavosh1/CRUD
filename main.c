#include "arvore_binaria.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// Função do menu para a árvore binária
void menuArvoreBinaria(Node **root) {
  int choice, id;
  char name[100];
  FILE *file;

  do {
    printf("\n-- MENU ARVORE BINARIA --\n\n");
    printf("1. Inserir nova pessoa\n");
    printf("2. Exibir arvore de pessoas\n");
    printf("3. Editar pessoa\n");
    printf("4. Salvar arvore em binario\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o ID: ");
      scanf("%d", &id);
      printf("Digite o nome: ");
      scanf("%s", name);
      *root = insertNode(*root, id, name);
      break;
    case 2:
      printf("\nExibindo arvore:\n");
      printTree(*root, 0);
      break;
    case 3:
      printf("Digite o ID da pessoa a ser editada: ");
      scanf("%d", &id);
      printf("Digite o novo nome: ");
      scanf("%s", name);
      *root = updateNode(*root, id, name);
      break;
    case 4:
      file = fopen("arvore.bin", "wb");
      if (file != NULL) {
        saveTreeToFile(file, *root);
        fclose(file);
        printf("Arvore salva com sucesso!\n");
      } else {
        printf("Erro ao abrir arquivo!\n");
      }
      break;
    case 5:
      printf("\nVoltando ao menu principal...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (choice != 5);
}

// Função do menu para a lista encadeada
void menuListaEncadeada(NodeList **head) {
  int choice, id;
  char name[100];

  do {
    printf("\n-- MENU LISTA ENCADEADA --\n\n");
    printf("1. Inserir nova pessoa\n");
    printf("2. Exibir lista de pessoas\n");
    printf("3. Editar pessoa\n");
    printf("4. Deletar pessoa\n");
    printf("5. Voltar ao menu principal\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Digite o ID: ");
      scanf("%d", &id);
      printf("Digite o nome: ");
      scanf("%s", name);
      insertList(head, id, name);
      break;
    case 2:
      printf("\nExibindo lista:\n");
      printList(*head);
      break;
    case 3:
      printf("Digite o ID da pessoa a ser editada: ");
      scanf("%d", &id);
      printf("Digite o novo nome: ");
      scanf("%s", name);
      updateList(*head, id, name);
      break;
    case 4:
      printf("Digite o ID da pessoa a ser deletada: ");
      scanf("%d", &id);
      deleteList(head, id);
      break;
    case 5:
      printf("\nVoltando ao menu principal...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (choice != 5);
}

int main() {
  Node *root = NULL;
  NodeList *head = NULL;
  int choice;

  do {
    printf("\n|| MENU PRINCIPAL ||\n\n");
    printf("1. Lista Encadeada\n");
    printf("2. Arvore Digital\n");
    printf("3. Sair\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      menuListaEncadeada(&head);
      break;
    case 2:
      menuArvoreBinaria(&root);
      break;
    case 3:
      printf("\nSaindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (choice != 3);

  return 0;
}
