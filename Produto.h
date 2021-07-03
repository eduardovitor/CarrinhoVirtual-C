
struct produto{
	char descricao[100];
	float preco;
	int qtd_estoque;
	char tipo[50];
	struct produto *prox;
};
typedef struct produto Produto;

Produto* criarProduto();
Produto* inserirProduto(Produto *produtos, char descricao[50], float preco, int qtd_estoque, char tipo[50]);
int procurarProdutoEstoque(Produto *produtos, char descricao[50]);
int procurarProduto(Produto *produtos, char descricao[50]);
void visualizarTodosProdutos(Produto *produtos);
void visualizarProdutoPorTipo(Produto *produtos, char tipo[50]);
void alterarProduto(Produto *produtos, char descricao[50]);
Produto* removerProduto(Produto *produtos, char descricao[50]);
Produto* retornarProdutoNome(Produto *produtos, char descricao[50]);
