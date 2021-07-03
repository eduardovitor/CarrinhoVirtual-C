#include <stdio.h>
#include <stdlib.h>
#include "CarrinhoVirtual.h"
#include <string.h>
Carrinho* criarCarrinho(){
	return NULL;
}
int procurarProdutoCarrinho(Carrinho *carrinho, Produto *produto){
	Carrinho *aux=criarCarrinho(); //função para procurar um produto no carrinho
	aux=carrinho;
	while(aux!=NULL){
		if(strcmp(aux->produto->descricao,produto->descricao)==0){
			return 1;
		}
		aux=aux->prox;
	}
}
Carrinho* inserirProdutoCarrinho(Carrinho *carrinho, Produto *produto){
	Carrinho *c=(Carrinho*)malloc(sizeof(Carrinho)); //função para inserir um produto no carrinho
	c->produto=(Produto*)malloc(sizeof(Produto));
	c->qtditens=0;
	if(procurarProdutoCarrinho(carrinho,produto)==1){
			Carrinho *aux=criarCarrinho();
			aux=carrinho;
			int controle=0;
			while(aux!=NULL){
				if(strcmp(aux->produto->descricao,produto->descricao)==0){
					aux->qtditens++; //esse trecho de código aqui serve para atualizar a quantidade de itens de um produto já existente no carrinho e atualizar o estoque dele na Lista de produtos
					produto->qtd_estoque--;
				}
				aux=aux->prox;
			}
		}else{
			if(carrinho==NULL) {
				strcpy(c->produto->descricao,produto->descricao);
				c->produto->preco=produto->preco;
				c->produto->qtd_estoque=0; //coloquei dessa forma, pois no carrinho, essa informação não tem serventia, ela só é útil para o administrador da Lista de Produtos
				c->qtditens++;
				produto->qtd_estoque--;
				strcpy(c->produto->tipo,produto->tipo);
				c->ant=NULL;
				c->prox=NULL;
				return c;
     		}else{
				strcpy(c->produto->descricao,produto->descricao);
				c->produto->preco=produto->preco;
				c->produto->qtd_estoque=0;
				c->qtditens++;
				produto->qtd_estoque--;
				strcpy(c->produto->tipo,produto->tipo);
				c->prox=carrinho;
				c->ant=NULL;
				carrinho->ant=c;
				return c;
	       }
	   }
       return carrinho;
}

void visualizarProdutosCarrinho(Carrinho *carrinho){
	if(carrinho==NULL){	//Visualizar os produtos no carrinho
		printf("Nao existem produtos no carrinho! \n");
	}
	else{
		Carrinho *aux=criarCarrinho();
		aux=carrinho;
		while(aux!=NULL){
			printf("\n Descricao: %s \n Preco: $ %.2f \n Tipo: %s \n Quantidade de itens: %d \n --------- \n",aux->produto->descricao,aux->produto->preco,aux->produto->tipo,aux->qtditens);
			aux=aux->prox;
		}
	}	
}
void alterarQuantidadeItens(Carrinho *carrinho, Produto *produto, int qtditens){
	int controle=0; //Função para alterar a quantidade de itens de um produto no carrinho
	if(procurarProdutoCarrinho(carrinho,produto)==1){ //verificação básica
			Carrinho *aux=criarCarrinho();
			aux=carrinho;
			while(aux!=NULL){
				if(strcmp(aux->produto->descricao,produto->descricao)==0 && qtditens<=produto->qtd_estoque-1){
					produto->qtd_estoque+=aux->qtditens; // esse trecho de código atualiza a quantidade de itens e o estoque
					aux->qtditens=qtditens;
					produto->qtd_estoque-=aux->qtditens;
					controle=1;
				}
				aux=aux->prox;
			}
	}
	if(controle==0){
		printf("Nao e possivel colocar essa quantidade de itens \n");
	}
}
Carrinho* removerProdutoCarrinho(Carrinho *carrinho, Produto *produto){
	Carrinho *aux=criarCarrinho(); //função para remover um produto do carrinho
	aux=carrinho;
	if(procurarProdutoCarrinho(carrinho,produto)==1){
	while(aux!=NULL){
		if(strcmp(aux->produto->descricao,produto->descricao)==0){
			produto->qtd_estoque+=aux->qtditens; //atualização da quantidade de produtos em estoque devido à exclusão
			if(aux->ant==NULL && aux->prox==NULL){
				free(aux);
				carrinho=NULL;
				return carrinho;
			}
			else if(aux->ant==NULL){
				aux->prox->ant=NULL;
				carrinho=aux->prox;
				free(aux);
				return carrinho;
			}
			else if(aux->prox==NULL){
				aux->ant->prox=NULL;
				free(aux);
				return carrinho;
			}
			else{
				aux->ant->prox=aux->prox;
				aux->prox->ant=aux->ant;
				free(aux);
				return carrinho;
			}	
		}
		aux=aux->prox;
	}
   }
   else{
   	printf("Produto nao encontrado no carrinho \n");
   }
}
float CalcularValorTotal(Carrinho *carrinho){
	float soma=0.0;
	Carrinho *aux=criarCarrinho();
	aux=carrinho;
	while(aux!=NULL){ //calculando o valor total da compra
		soma=soma+(aux->produto->preco*aux->qtditens);
		aux=aux->prox;
	}
	return soma;
}
