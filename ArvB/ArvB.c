#include "arvb.h"
#include <stdio.h>
#include <stdlib.h>

// Implementação das funções definidas em arvoreb.h

void inicializarArvore(Arvore *t){
    t->raiz = NULL;
}

No *criarNo(Arvore *t, int item, No *filho) { ///8, null
    No *novoNo;
    novoNo = malloc(sizeof(No));
    novoNo->item[1] = item;
    novoNo->cont = 1;
    novoNo->linker[0] = t->raiz;
    novoNo->linker[1] = filho;
    return novoNo;
}




//FUNÇÕES PARA INSERIR
void inserir(Arvore *t, int item) {
    int flag, i;
    No *filho;

    flag = definirValorNo(item, &i, t->raiz, &filho);
    if (flag)
        t->raiz = criarNo(t, i, filho);
}

int definirValorNo(int item, int *pval, No *no, No **filho) {
    int pos;
    if (no == NULL) {
        *pval = item;
        *filho = NULL;
        return 1;
    }

    if (item < no->item[1]) {
        pos = 0;
    } else {
        for (pos = no->cont; (item < no->item[pos] && pos > 1); pos--);
        if (item == no->item[pos]) {
            printf("Duplicates not allowed\n");
            return 0;
        }
    }
    if (definirValorNo(item, pval, no->linker[pos], filho) == 1) {
        if (no->cont < MAX) {
            addValorNo(*pval, pos, no, *filho);
        } else {
            split(*pval, pval, pos, no, *filho, filho);
            return 1;
        }
    }
    return 0;
}

void addValorNo(int item, int pos, No *no, No *filho) {
    int j = no->cont;
    while (j > pos) {
        no->item[j + 1] = no->item[j];
        no->linker[j + 1] = no->linker[j];
        j--;
    }
    no->item[j + 1] = item;
    no->linker[j + 1] = filho;
    no->cont++;
}

void split(int item, int *pval, int pos, No *no, No *filho, No **novoNo) {
    int median, j;

    if (pos > MIN){
        median = MIN + 1;
    }else{
        median = MIN;
    }

    *novoNo = (No *)malloc(sizeof(No));
    j = median + 1;
    while (j <= MAX) {
        (*novoNo)->item[j - median] = no->item[j];
        (*novoNo)->linker[j - median] = no->linker[j];
        j++;
    }
    no->cont = median;
    (*novoNo)->cont = MAX - median;
    if (pos <= MIN) {
        addValorNo(item, pos, no, filho);
    } else {
        addValorNo(item, pos - median, *novoNo, filho);
    }
    *pval = no->item[no->cont];
    (*novoNo)->linker[0] = no->linker[no->cont];
    no->cont--;
}



//FUNÇÃO DE BUSCA
int busca(Arvore *t, int item) {
    int i;
    return buscarNaAvore(item, &i, t->raiz);
}


int buscarNaAvore(int item, int *pos, No *no){
    if (!no) {
        return 0;
    }
    if (item < no->item[1]) {
        *pos = 0;
    } else {
    for (*pos = no->cont; (item < no->item[*pos] && *pos > 1); (*pos)--);
        if (item == no->item[*pos]) {
            return 1;
        }
    }
    return buscarNaAvore(item, pos, no->linker[*pos]);
}



//FUNÇÃO PARA IMPRIMIR
void imprimir( No *no) {
    int i;
    if (no) {
        for (i = 0; i < no->cont; i++) {
            imprimir(no->linker[i]);
            printf("%d ", no->item[i + 1]);
        }
        imprimir(no->linker[i]);
    }
}




// //FUNÇÕES PARA EXCLUIR
// void copySuccessor(No *no, int pos) {
//     No *dummy;
//     dummy = no->linker[pos];

//     for (; dummy->linker[0] != NULL;){
//         dummy = dummy->linker[0];
//         no->item[pos] = dummy->item[1];
//     }
// }

// void removeVal( No *no, int pos) {
//     int i = pos + 1;
//     while (i <= no->cont) {
//         no->item[i - 1] = no->item[i];
//         no->linker[i - 1] = no->linker[i];
//         i++;
//     }
//     no->cont--;
// }

// void rightShift( No *no, int pos) {
//     No *x = no->linker[pos];
//     int j = x->cont;

//     while (j > 0) {
//         x->item[j + 1] = x->item[j];
//         x->linker[j + 1] = x->linker[j];
//         j--;
//     }
//     x->item[1] = no->item[pos];
//     x->linker[1] = x->linker[0];
//     x->cont++;

//     x = no->linker[pos - 1];
//     no->item[pos] = x->item[x->cont];
//     no->linker[pos] = x->linker[x->cont];
//     x->cont--;
// }

// void leftShift( No *no, int pos) {
//     int j = 1;
//     No *x = no->linker[pos - 1];

//     x->cont++;
//     x->item[x->cont] = no->item[pos];
//     x->linker[x->cont] = no->linker[pos]->linker[0];

//     x = no->linker[pos];
//     no->item[pos] = x->item[1];
//     x->linker[0] = x->linker[1];
//     x->cont--;

//     while (j <= x->cont) {
//         x->item[j] = x->item[j + 1];
//         x->linker[j] = x->linker[j + 1];
//         j++;
//     }
// }

// void mergenos(No *no, int pos) {
//     int j = 1;
//     No *x1 = no->linker[pos], *x2 = no->linker[pos - 1];

//     x2->cont++;
//     x2->item[x2->cont] = no->item[pos];
//     x2->linker[x2->cont] = no->linker[0];

//     while (j <= x1->cont) {
//         x2->cont++;
//         x2->item[x2->cont] = x1->item[j];
//         x2->linker[x2->cont] = x1->linker[j];
//         j++;
//     }

//     j = pos;
//     while (j < no->cont) {
//         no->item[j] = no->item[j + 1];
//         no->linker[j] = no->linker[j + 1];
//         j++;
//     }
//     no->cont--;
//     free(x1);
// }

// void adjustno(No *no, int pos) {
//     if (!pos) {
//     if (no->linker[1]->cont > MIN) {
//         leftShift(no, 1);
//     } else {
//         mergenos(no, 1);
//     }
//     } else {
//     if (no->cont != pos) {
//         if (no->linker[pos - 1]->cont > MIN) {
//             rightShift(no, pos);
//         } else {
//             if (no->linker[pos + 1]->cont > MIN) {
//                 leftShift(no, pos + 1);
//             } else {
//                 mergenos(no, pos);
//             }
//         }
//     } else {
//         if (no->linker[pos - 1]->cont > MIN)
//             rightShift(no, pos);
//         else
//             mergenos(no, pos);
//     }
//     }
// }

// int delValFromno(int item, No *no) {
//     int pos, flag = 0;
//     if (no) {
//     if (item < no->item[1]) {
//         pos = 0;
//         flag = 0;
//     } else {
//         for (pos = no->cont; (item < no->item[pos] && pos > 1); pos--) {
//             if (item == no->item[pos]) {
//                 flag = 1;
//             } else {
//                 flag = 0;
//             }
//         }
//     }
//     if (flag) {
//         if (no->linker[pos - 1]) {
//             copySuccessor(no, pos);
//             flag = delValFromno(no->item[pos], no->linker[pos]);
//             if (flag == 0) {
//                 printf("Given data is not present in B-Arvore\n");
//             }
//             } else {
//                 removeVal(no, pos);
//             }
//     } else {
//         flag = delValFromno(item, no->linker[pos]);
//     }
//     if (no->linker[pos]) {
//         if (no->linker[pos]->cont < MIN)
//         adjustno(no, pos);
//     }
//     }
//     return flag;
// }

// void delete(int item, No *no, No *raiz) {
//     No *tmp;
//     if (!delValFromno(item, no)) {
//         printf("Not present\n");
//         return;
//     } else {
//     if (no->cont == 0) {
//         tmp = no;
//         no = no->linker[0];
//         free(tmp);
//     }
//     }
//     raiz = no;
//     return;
// }
