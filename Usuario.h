struct usuario{
	char nome_de_usuario[100];
	char senha[100];
};
typedef struct usuario Usuario;

Usuario* criarUsuario(Usuario *u, char nome_de_usuario[], char senha[]);

