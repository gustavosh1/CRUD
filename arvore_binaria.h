#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h> // Adicionada para resolver o erro "unknown type name 'FILE'"

// Estrutura do nó para a árvore binária
typedef struct Node {
  int id;
  char name[100];
  struct Node *left;
  struct Node *right;
} Node;

// Funções CRUD para manipulação da árvore
Node *createNode(int id, const char *name);
Node *insertNode(Node *root, int id, const char *name);
void printTree(Node *root, int space);
Node *searchNode(Node *root, int id);
Node *updateNode(Node *root, int id, const char *newName);
Node *deleteNode(Node *root, int id);
void saveTreeToFile(FILE *file, Node *root);
#endif

