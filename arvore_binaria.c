#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 5 // Espa�o para indenta��o na exibi��o da �rvore

// Fun��o para criar um novo n�
Node *createNode(int id, const char *name) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->id = id;
  strcpy(newNode->name, name);
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Fun��o para inserir um n� na �rvore bin�ria de busca
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

// Fun��o para exibir a �rvore em formato de �rvore (visualiza��o)
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

// Fun��o para buscar um n� na �rvore por ID
Node *searchNode(Node *root, int id) {
  if (root == NULL || root->id == id) {
    return root;
  }
  if (id < root->id) {
    return searchNode(root->left, id);
  }
  return searchNode(root->right, id);
}

// Fun��o para atualizar um n� na �rvore
Node *updateNode(Node *root, int id, const char *newName) {
  Node *targetNode = searchNode(root, id);
  if (targetNode != NULL) {
    strcpy(targetNode->name, newName);
    printf("Pessoa atualizada com sucesso!\n");
  } else {
    printf("Pessoa com ID %d n�o encontrada.\n", id);
  }
  return root;
}

// Fun��o para encontrar o n� m�nimo na sub�rvore
Node *findMin(Node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

// Fun��o para deletar um n� da �rvore
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

// Fun��o para salvar a �rvore em um arquivo bin�rio
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

