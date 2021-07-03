#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"
Usuario* criarUsuario(Usuario *u, char nome_de_usuario[], char senha[]){
	Usuario *novousuario=(Usuario*)malloc(sizeof(Usuario));
	strcpy(novousuario->nome_de_usuario, nome_de_usuario);
	strcpy(novousuario->senha,senha);
	return novousuario;
}
