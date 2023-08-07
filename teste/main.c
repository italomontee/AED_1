#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura da Árvore Binária
struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó da Árvore Binária
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para construir a Árvore Binária a partir da notação infixa
struct TreeNode* constructExpressionTree(char* infixExpression, int start, int end) {
    if (start > end)
        return NULL;

    int i, bracketCount = 0;
    int minPrecedence = 9999;
    int minPrecedenceIndex = -1;

    for (i = start; i <= end; i++) {
        if (infixExpression[i] == '(') {
            bracketCount++;
        } else if (infixExpression[i] == ')') {
            bracketCount--;
        } else if (bracketCount == 0 && isOperator(infixExpression[i])) {
            int currentPrecedence = 0;
            if (infixExpression[i] == '+' || infixExpression[i] == '-') {
                currentPrecedence = 1;
            } else if (infixExpression[i] == '*' || infixExpression[i] == '/') {
                currentPrecedence = 2;
            }

            if (currentPrecedence <= minPrecedence) {
                minPrecedence = currentPrecedence;
                minPrecedenceIndex = i;
            }
        }
    }

    if (minPrecedenceIndex != -1) {
        struct TreeNode* newNode = createNode(infixExpression[minPrecedenceIndex]);

        newNode->left = constructExpressionTree(infixExpression, start, minPrecedenceIndex - 1);
        newNode->right = constructExpressionTree(infixExpression, minPrecedenceIndex + 1, end);

        return newNode;
    } else if (infixExpression[start] == '(' && infixExpression[end] == ')') {
        return constructExpressionTree(infixExpression, start + 1, end - 1);
    } else {
        char operand = infixExpression[start];
        if (operand == ' ') {
            return NULL;
        }
        return createNode(operand);
    }
}

// Função para imprimir a Árvore Binária de forma pré-ordem (raiz-esquerda-direita)
void printPreorder(struct TreeNode* root) {
    if (root) {
        printf("%c ", root->value);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Função para liberar a memória da Árvore Binária
void freeTree(struct TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char infixExpression[] = "(a*((b-c)/d))";
    struct TreeNode* root = constructExpressionTree(infixExpression, 0, strlen(infixExpression) - 1);

    printf("Árvore Binária na forma pré-ordem (raiz-esquerda-direita): ");
    printPreorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
