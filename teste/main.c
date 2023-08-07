#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defini��o da estrutura da �rvore Bin�ria
struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Fun��o para criar um novo n� da �rvore Bin�ria
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fun��o para verificar se um caractere � um operador
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Fun��o para construir a �rvore Bin�ria a partir da nota��o infixa
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

// Fun��o para imprimir a �rvore Bin�ria de forma pr�-ordem (raiz-esquerda-direita)
void printPreorder(struct TreeNode* root) {
    if (root) {
        printf("%c ", root->value);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Fun��o para liberar a mem�ria da �rvore Bin�ria
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

    printf("�rvore Bin�ria na forma pr�-ordem (raiz-esquerda-direita): ");
    printPreorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}
