#ifndef ABBCHAR_H_INCLUDED
#define ABBCHAR_H_INCLUDED

//definir estrutura da ABB

typedef struct aux {
    char chave;
    int h;
    struct aux * esquerda;
    struct aux * direita;
} NO;

typedef struct {
    NO * raiz;
} ARVORE ;

//protótipo das funções
void Inicializar(ARVORE * arvore);

//Medidas
int Altura(NO* raiz);
int Profundidade(NO* raiz, char codigo, int cont);
int Nivel(NO* raiz, char codigo, int cont);
int Contar(NO * no, int *count);
int maximo (int v1, int v2);

//Inserir
NO * AlocarNo(char codigo);
void InserirABB(NO ** no, char codigo);

//Imprimir
void ImprimirInOrder(NO * no);
void ImprimirPreOrder(NO * no);
void ImprimirPosOrder(NO * no);
int PercorrerEmLargura(NO * no);

//Buscar
void Buscar(NO * no, char codigo);


#endif // ABBCHAR_H_INCLUDED
