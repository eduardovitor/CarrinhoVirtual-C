#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CarrinhoVirtual.h"
#include "Usuario.h"
int TelaBoasVindas(){
	printf("Bem vindo ao sistema de gerenciamento de produtos e de carrinho de compras \n");
}
void ImprimeMenuAdmin(){
	printf("Menu do Admin \n (1) Inserir produto \n (2) Alterar produto \n (3) Pesquisar produto \n (4) Filtrar produtos por tipo \n (5) Exibir todos os produtos \n (6) Remover produto \n (7) Ir ao menu de cliente \n (8) Parar programa \n ");
}
void ImprimeMenuCliente(){
	printf("Menu do Cliente \n (1) Inserir produto \n (2) Exibir produtos no carrinho \n (3) Exibir todos os produtos disponiveis \n (4) Alterar quantidade de itens de um produto no carrinho \n (5) Remover produto \n (6) Calcular valor total e finalizar compra \n (7) Voltar ao menu Admin \n ");
}
void OperacoesCliente(Produto *produtos, Carrinho *carrinho){
	while(1){
		ImprimeMenuCliente();
		int o=0;
		scanf("%d",&o);
		if(o==1){
			char descricao[100];
			printf("Digite a descricao: \n");
			scanf("%s",descricao);
			if(procurarProdutoEstoque(produtos,descricao)!=0){ //serve para saber se ainda é possível inserir um produto no carrinho
				carrinho=inserirProdutoCarrinho(carrinho,retornarProdutoNome(produtos,descricao));
			}
			else{
				printf("Produto nao disponivel \n");
			}
		}
		else if(o==2){
			visualizarProdutosCarrinho(carrinho);
		}
		else if(o==3){
			visualizarTodosProdutos(produtos);
		}
		else if(o==4){
			char descricao[100];
			int novaqtditens=0;
			printf("Digite a descricao: \n");
			scanf("%s",descricao);
			fflush(stdin);
			printf("Digite a nova quantidade de itens: \n");
			scanf("%d",&novaqtditens);
			alterarQuantidadeItens(carrinho,retornarProdutoNome(produtos,descricao),novaqtditens); 
		}
		else if(o==5){
			char descricao[100];
			printf("Digite a descricao: \n");
			scanf("%s",descricao);
			carrinho=removerProdutoCarrinho(carrinho,retornarProdutoNome(produtos,descricao));
		}
		else if(o==6){
			float valor=CalcularValorTotal(carrinho);
			printf("O valor total e $ %.2f \n",valor);
			printf("Realize o pagamento e sua compra estara finalizada \n");
			printf("Obrigado por comprar conosco! \n");
		}
		else if(o==7){
			break;
		}
		else{
			printf("Opcao incorreta \n");
		}
	}
}
void OperacoesAdmin(Produto *produtos, Carrinho *carrinho, Usuario *admin){
		char usuariodigitado[100];
		char senhadigitada[100], c;
		int a=0;
		printf("Digite o usuario: \n");
		scanf("%s",usuariodigitado);
		printf("Digite a senha: \n"); //esse trecho de código abaixo(máscara de senha) é da internet, foi só algo que eu achei que deixaria o negócio mais bonito
		do{
           	c=getch();
           	if(isprint(c)){       //Analisa se o valor da variável c é imprimivel
           	senhadigitada[a]=c;  //Se for, armazena o caractere
           	a++;
           	printf("*");          //imprime o * Anterisco
          }
           else if(c==8&&a){     //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           	senhadigitada[a]='\0';
           	a--;
           	printf("\b \b");       //Apagando o caractere digitado
           }
    	}  while(c!=13);             //13 é o valor de ENTER na tabela ASCII
    	senhadigitada[a]='\0';
		system("cls");
		if(strcmp(usuariodigitado,admin->nome_de_usuario)==0 && strcmp(senhadigitada,admin->senha)==0){
			while(1){
				ImprimeMenuAdmin();
				int o=0;
				scanf("%d",&o);
				if(o==1){
					char descricao[100];
					float preco;
					char tipo[50];
					int qtd_estoque;
					printf("Digite os dados do produto a seguir(sem espacos, por favor)\n");
					printf("Descricao: \n");
					scanf("%s",descricao);
					printf("Tipo: \n");
					scanf("%s",tipo);
					printf("Preco: \n");
					scanf("%f",&preco);
					printf("Quantidade em estoque: \n");
					scanf("%d",&qtd_estoque);
					produtos=inserirProduto(produtos,descricao,preco,qtd_estoque,tipo);
				}
				else if(o==2){
					char descr[100];
					printf("Digite a descricao do produto: \n");
					scanf("%s",descr);
					alterarProduto(produtos,descr);
				}
				else if(o==3){
					char descr[100];
					printf("Digite a descricao do produto: \n");
					scanf("%s",descr);
					int a=procurarProdutoEstoque(produtos,descr);
					if(a!=0){
						printf("Produto disponivel, %d unidades restantes \n",a);
					}
					else{
						printf("Produto indisponivel, apenas uma unidade de amostragem \n");
					}
				}
				else if(o==4){
					char tipo[100];
					printf("Digite o tipo: \n");
					scanf("%s",tipo);
					visualizarProdutoPorTipo(produtos,tipo);
		  		}
		  		else if(o==5){
		  		   visualizarTodosProdutos(produtos);
				}
				else if(o==6){
					char descr[100];
					printf("Digite a descricao do produto: \n");
					scanf("%s",descr);
					if(procurarProduto(produtos,descr)==1){
						produtos=removerProduto(produtos,descr);
					}
					else{
						printf("Produto inexistente \n");
					}
				}
				else if(o==7){
					system("cls");
					OperacoesCliente(produtos,carrinho); //achei conveniente os operações de cliente ficarem dentro do menu do administrador, pois assim um cliente só compra se tiver autorização
				}
				else if(o==8){
					break;
				}
				else{
					printf("Opcao incorreta \n");
				}
		    }
 	     }
		  else{
			printf("Acesso negado \n");
		  }
}

int main(){
	Produto *produtos=criarProduto();
	Carrinho *carrinho=criarCarrinho();
	Usuario *admin=criarUsuario(admin,"admin","admin");
	TelaBoasVindas();
	OperacoesAdmin(produtos,carrinho,admin);
	free(produtos);
	free(carrinho);
	free(admin);
	//pronto professora, foi esse o meu trabalho, espero que eu tenha conseguido cumprir todos os requisitos. Saudades das aulas de programação, a quarentena deixa a pessoa num tédio.
}
