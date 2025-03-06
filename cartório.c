#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);	
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string (c�pia, fonte de c�pia)
	
	FILE *file; //FILE seria considerado uma a��o de biblioteca, para selecionar arquivos do tipo *file
	file = fopen(arquivo, "w"); //fopen para abrir o arquivo, w de write pois � um arquivo novo
	fprintf(file,cpf); //salva no arquivo selecionado, a variavel selecionada
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar o arquivo selecionado
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	//adicionar virgula para separar informa��es
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //aparece a mensagem para o usuario at� o usuario n�o querer mais
	
}

int consulta() //fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	//in�cio cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim cria��o de vari�veis
	printf("Digitre o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" para Read
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto estiver escrevendo na variavel conteudo, at� 200 valores, que est�o dentro do arquivo, enquanto tiver diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //fun��o respons�vel por deletar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	else 
  	{
    	fclose(file); // Fecha o arquivo, pois ele existe

    	remove(cpf); // Agora voc� pode remover o arquivo

    	printf("Usu�rio deletado!\n");

    	system("pause");
  	}
	
}


int main() 
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1; laco=1;) //feito para resetar de um jeito simples a volta para o menu
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("��� Cart�rio da EBAC ���\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario (preciso colocar o & aparentemente nesse caso
	
		system("cls"); //comando para o sistema limpar a tela depois da escolha
		
		//inicio da sele��o do menu
		switch(opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf("Esta op��o est� invalida\n");
			system("pause");
			break;	
		}//fim da sele��o do menu
		
		
		printf("\n\nEsse Softare � da Mel\n");
		system("pause");
	}

}
