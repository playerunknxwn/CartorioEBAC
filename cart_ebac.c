#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro(){ //fun��o que cria os usu�rio na base de dados do sistema
	printf("Registro de nomes\n\n");

	//cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //coletando info do use

	strcpy(arquivo, cpf);

	FILE *file;
	file = fopen(arquivo, "w");  //cria o arquivo "w" escreve no arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");


}

int consulta(){

	setlocale(LC_ALL, "Portuguese"); //define a linguagem

	printf("Consulta de nomes\n\n");
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r");


	if(file==NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}

	while(fgets(conteudo, 200, file)!=NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");


}

int deletar(){
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);

	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);

	if(file==NULL){
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}


int main(){
    setlocale(LC_ALL, "Portuguese"); //define a linguagem
	int opcao=5; //definindo vari�veis
	int x=1;
	char senhadigitada[]="a";
	int compara;

	printf("_xX Cart�rio da EBAC Xx_ \n\n");
	printf("Login de administrador.\n\nDigite a senha: ");
	scanf("%s",senhadigitada);

	compara=strcmp(senhadigitada,"admin");
	//'compara' recebe 'strcmp' que vai ser a compara��o de senhadigitada e admin se � true que s�o iguais

	if(compara == 0){ //0 significa que os valores s�o iguais

        for(x=1;x=1;){

            system("cls");

            printf("_xX Cart�rio da EBAC Xx_ \n\n"); //menu ...
            printf("Escolha a op��o desejada:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n\n");
            printf("\t0 - Sair\n\n");
            printf("Op��o: ");

            scanf("%d", &opcao); //armazena a escolha do user "%d"==inteiro, &variavel referida

            system("cls");

            switch(opcao){
                case 1:
                registro(); //chama as tais fun��es
                break;

                case 2:
                consulta();
                break;

                case 3:
                deletar();
                break;

                case 0:
                printf("Saindo...\n");
                return 0;
                break;

                default:
                printf("Essa op��o n�o est� dispon�vel.\n\nEscolha uma das 3 op��es:\n\n");
                system("pause");
                break;
            }
		}
	}
	else
        printf("Senha incorreta!");
}
