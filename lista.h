#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// Estrutura do n� da lista encadeada
typedef struct NodeList {
  int id;
  char name[100];
  struct NodeList *next;
} NodeList;

// Fun��es CRUD para manipula��o da lista encadeada
NodeList *createNodeList(int id, const char *name);
void insertList(NodeList **head, int id, const char *name);
void printList(NodeList *head);
void updateList(NodeList *head, int id, const char *newName);
void deleteList(NodeList **head, int id);

#endif

