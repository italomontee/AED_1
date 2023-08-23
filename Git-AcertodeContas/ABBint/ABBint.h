#ifndef ABBINT_H_INCLUDED
#define ABBINT_H_INCLUDED

//definir estrutura da ABB

typedef struct aux {
    int chave;
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
int Profundidade(NO* raiz, int codigo, int cont);
int Nivel(NO* raiz, int codigo, int cont);
int Contar(NO * no, int *count);
int maximo (int v1, int v2);

//Inserir
NO * AlocarNo(int numero);
void InserirABB(NO ** no, int numero);

//Imprimir
void ImprimirInOrder(NO * no);
void ImprimirPreOrder(NO * no);
void ImprimirPosOrder(NO * no);
int PercorrerEmLargura(NO * no);

//Buscar
void Buscar(NO * no, int cod);



#endif // ABBINT_H_INCLUDED
