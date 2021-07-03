#include "Produto.h"
struct carrinhovirtual{
	Produto *produto;
	int qtditens;
	struct carrinhovirtual *ant;
	struct carrinhovirtual *prox;
};
typedef struct carrinhovirtual Carrinho;

Carrinho* criarCarrinho();
Carrinho* inserirProdutoCarrinho(Carrinho *carrinho, Produto *produto);
int procurarProdutoCarrinho(Carrinho *carrinho, Produto *produto);
void alterarQuantidadeItens(Carrinho *carrinho, Produto *produto, int qtditens);
void visualizarProdutosCarrinho(Carrinho *carrinho);
Carrinho* removerProdutoCarrinho(Carrinho *carrinho, Produto *produto);
float CalcularValorTotal(Carrinho *carrinho);
