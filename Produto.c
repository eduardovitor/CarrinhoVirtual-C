#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Produto* criarProduto(){
	return NULL;
}
Produto* inserirProduto(Produto *produtos, char descricao[], float preco, int qtd_estoque, char tipo[]){
		Produto *p=(Produto*)malloc(sizeof(Produto)); //Insere no início da lista e sempre retorna o início
		strcpy(p->descricao,descricao);
		p->preco=preco;
		p->qtd_estoque=qtd_estoque;
		strcpy(p->tipo,tipo);
		p->prox=produtos;
		printf("Produto inserido com sucesso! \n");
		return p;
}
int procurarProduto(Produto *produtos, char descricao[50]){
	Produto *aux=criarProduto(); //função para fins técnicos, para saber se um produto está na Lista de produtos
	aux=produtos;
	while(aux!=NULL){
		if(strcmp(aux->descricao,descricao)==0){
			return 1;
		}
		aux=aux->prox;
	}
}
int procurarProdutoEstoque(Produto *produtos, char descricao[]){
	Produto *aux=criarProduto(); //função geral para informar se um produto ainda está disponível em estoque, nesse caso, quando a quantidade é um, ele não está mais disponível
	aux=produtos;
	while(aux!=NULL){
		if(strcmp(aux->descricao,descricao)==0){
			if(aux->qtd_estoque>1){
				return aux->qtd_estoque;
			}
			else{
				return 0;
			}
		}
		aux=aux->prox;
	}
}
void visualizarTodosProdutos(Produto *produtos){ //visualizar todos os produtos da Lista
	if(produtos==NULL){
		printf("Nao tem produtos cadastrados! \n");
	}
	else{
		Produto *aux=criarProduto();
		aux=produtos;
		while(aux!=NULL){
			printf("\n Descricao: %s \n Preco: $ %.2f \n Quantidade em estoque: %d \n Tipo: %s \n ---------------- \n",aux->descricao,aux->preco,aux->qtd_estoque,aux->tipo);
			aux=aux->prox;
		}
	}	
}
void visualizarProdutoPorTipo(Produto *produtos, char tipo[]){
	if(produtos==NULL){		//Visualizar por tipo
		printf("Nao tem produtos cadastrados! \n");
	}
	else{
		Produto *aux=criarProduto();
		aux=produtos;
		while(aux!=NULL){
			if(strcmp(aux->tipo,tipo)==0){
				printf(" \n Descricao: %s \n Preco: $ %.2f \n Quantidade em estoque: %d \n ---------------- \n",aux->descricao,aux->preco,aux->qtd_estoque);
			}
			aux=aux->prox;
		}
	}	
}
void alterarProduto(Produto *produtos, char descricao[]){
	if(produtos==NULL){ //função para alterar um produto, com algumas condições básicas para saber se a lista está vazia ou não e se o produto existe
		printf("Nao tem produtos cadastrados! \n");
	}
	else if(procurarProduto(produtos,descricao)==1){
		Produto *aux=criarProduto();
		aux=produtos;
		while(aux!=NULL){
			if(strcmp(aux->descricao,descricao)==0){
				int op;
				printf("Digite o que deseja alterar(escolha um numero): Descricao(1) Preco(2) Quantidade(3) Tipo(4) \n");
				scanf("%d",&op);
				if(op==1){
					char novadescricao[50];
					printf("Digite a nova descricao: \n");
					scanf("%s",novadescricao);
					strcpy(aux->descricao,novadescricao);
					printf("Descricao alterado com sucesso! \n");
				}
				else if(op==2){
					float novopreco;
					printf("Digite o novo preco: \n");
					scanf("%f",&novopreco);
					aux->preco=novopreco;
					printf("Preco alterado com sucesso! \n");
				}
				else if(op==3){
					int novaqtd;
					printf("Digite a nova quantidade: \n");
					scanf("%d",&novaqtd);
					aux->qtd_estoque=novaqtd;
					printf("Quantidade alterada com sucesso! \n");
				}
				else if(op==4){
					char tipo[50];
					printf("Digite o tipo: \n");
					scanf("%s",tipo);
					strcpy(aux->tipo,tipo);
					printf("Tipo alterado com sucesso! \n");
				}
				else{
					printf("Opcao invalida \n");
				}
			}
			aux=aux->prox;
		}
	}
	else{
		printf("Produto nao encontrado \n");
	}
}
Produto* removerProduto(Produto *produtos, char descricao[]){
		Produto *aux=criarProduto();	//função para remover um produto
		Produto *aux2=criarProduto();
		aux=produtos;
		while(aux!=NULL){
			if(strcmp(aux->descricao,descricao)==0 && aux==produtos){
				produtos=aux->prox;
				free(aux);
				return produtos;
			}
			else if(strcmp(aux->descricao, descricao)==0 && aux->prox==NULL){
				aux2->prox=NULL;
				free(aux);
				return produtos; 
			}
			else if(strcmp(aux->descricao, descricao)==0 && aux!=produtos && aux->prox!=NULL){
				aux2->prox=aux->prox;
				free(aux);
				return produtos;
			}
			aux2=aux;
			aux=aux->prox;
		}
}
Produto* retornarProdutoNome(Produto *produtos, char descricao[]){
		Produto *aux=criarProduto(); //função para auxilios técnicos com o objetivo de retornar todas as informações de um produto da Lista de produtos
		aux=produtos;
		Produto produtodesejado;
		while(aux!=NULL){
			if(strcmp(aux->descricao,descricao)==0){
				return aux;
			}
			aux=aux->prox;
		}
}
