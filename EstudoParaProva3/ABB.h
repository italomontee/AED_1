#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

//definir estrutura da ABB

typedef struct aux {
    int chave;
    struct aux * esquerda;
    struct aux * direita;
} NO;

typedef struct {
    NO * raiz;
} ARVORE ;

//protótipo das funções
void Inicializar(ARVORE * arvore);
NO * AlocarNo(int numero);
void Inserir(NO ** no, int numero);
void ImprimirInOrder(NO * no);
void ImprimirPreOrder(NO * no);
void ImprimirPosOrder(NO * no);
void Buscar(NO * no, int numero);
int Contar(NO * no);
int profundidade(NO* raiz, int codigo, int cont);
int percorrerEmLargura(NO * no);
#endif // ABB_H_INCLUDED
