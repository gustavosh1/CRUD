#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fun��o para criar um novo n� da lista
NodeList *createNodeList(int id, const char *name) {
  NodeList *newNode = (NodeList *)malloc(sizeof(NodeList));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->next = NULL;
  return newNode;
}

// Fun��o para inserir um n� na lista
void insertList(NodeList **head, int id, const char *name) {
  NodeList *newNode = createNodeList(id, name);
  newNode->next = *head;
  *head = newNode;
}

// Fun��o para imprimir a lista
void printList(NodeList *head) {
  NodeList *current = head;
  while (current != NULL) {
    printf("ID: %d, Nome: %s\n", current->id, current->name);
    current = current->next;
  }
}

// Fun��o para atualizar uma pessoa na lista
void updateList(NodeList *head, int id, const char *newName) {
  NodeList *current = head;
  while (current != NULL) {
    if (current->id == id) {
      strcpy(current->name, newName);
      printf("Pessoa atualizada com sucesso!\n");
      return;
    }
    current = current->next;
  }
  printf("Pessoa com ID %d n�o encontrada.\n", id);
}

// Fun��o para deletar uma pessoa da lista
void deleteList(NodeList **head, int id) {
  NodeList *current = *head;
  NodeList *previous = NULL;

  while (current != NULL && current->id != id) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Pessoa com ID %d n�o encontrada.\n", id);
    return;
  }

  if (previous == NULL) {
    *head = current->next; // Remove o primeiro n�
  } else {
    previous->next = current->next; // Remove n� do meio ou final
  }

  free(current);
  printf("Pessoa deletada com sucesso!\n");
}

