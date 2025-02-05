#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 5 // Espaço para indentação na exibição da árvore

// Função para criar um novo nó
Node *createNode(int id, const char *name) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Função para inserir um nó na árvore binária de busca
Node *insertNode(Node *root, int id, const char *name) {
  if (root == NULL) {
    return createNode(id, name);
  }
  if (id < root->id) {
    root->left = insertNode(root->left, id, name);
  } else if (id > root->id) {
    root->right = insertNode(root->right, id, name);
  }
  return root;
}

// Função para exibir a árvore em formato de árvore (visualização)
void printTree(Node *root, int space) {
  if (root == NULL) {
    return;
  }
  space += SPACE;
  printTree(root->right, space);
  printf("\n");
  for (int i = SPACE; i < space; i++) {
    printf(" ");
  }
  printf("%d (%s)\n", root->id, root->name);
  printTree(root->left, space);
}

// Função para buscar um nó na árvore por ID
Node *searchNode(Node *root, int id) {
  if (root == NULL || root->id == id) {
    return root;
  }
  if (id < root->id) {
    return searchNode(root->left, id);
  }
  return searchNode(root->right, id);
}

// Função para atualizar um nó na árvore
Node *updateNode(Node *root, int id, const char *newName) {
  Node *targetNode = searchNode(root, id);
  if (targetNode != NULL) {
    strcpy(targetNode->name, newName);
    printf("Pessoa atualizada com sucesso!\n");
  } else {
    printf("Pessoa com ID %d não encontrada.\n", id);
  }
  return root;
}

// Função para encontrar o nó mínimo na subárvore
Node *findMin(Node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

// Função para deletar um nó da árvore
Node *deleteNode(Node *root, int id) {
  if (root == NULL) {
    return root;
  }
  if (id < root->id) {
    root->left = deleteNode(root->left, id);
  } else if (id > root->id) {
    root->right = deleteNode(root->right, id);
  } else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = findMin(root->right);
    root->id = temp->id;
    strcpy(root->name, temp->name);
    root->right = deleteNode(root->right, temp->id);
  }
  return root;
}

// Função para salvar a árvore em um arquivo binário
void saveTreeToFile(FILE *file, Node *root) {
  if (root == NULL) {
    int nullId = -1;
    fwrite(&nullId, sizeof(int), 1, file);
    return;
  }
  fwrite(&root->id, sizeof(int), 1, file);
  fwrite(root->name, sizeof(char), 100, file);
  saveTreeToFile(file, root->left);
  saveTreeToFile(file, root->right);
}

