#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf);	
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string (cópia, fonte de cópia)
	
	FILE *file; //FILE seria considerado uma ação de biblioteca, para selecionar arquivos do tipo *file
	file = fopen(arquivo, "w"); //fopen para abrir o arquivo, w de write pois é um arquivo novo
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
	
	//adicionar virgula para separar informações
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
	
	system("pause"); //aparece a mensagem para o usuario até o usuario não querer mais
	
}

int consulta() //função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	//início criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim criação de variáveis
	printf("Digitre o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" para Read
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto estiver escrevendo na variavel conteudo, até 200 valores, que estão dentro do arquivo, enquanto tiver diferente de nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //função responsável por deletar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	else 
  	{
    	fclose(file); // Fecha o arquivo, pois ele existe

    	remove(cpf); // Agora você pode remover o arquivo

    	printf("Usuário deletado!\n");

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
	
		printf("°°° Cartório da EBAC °°°\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario (preciso colocar o & aparentemente nesse caso
	
		system("cls"); //comando para o sistema limpar a tela depois da escolha
		
		//inicio da seleção do menu
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
				printf("Esta opção está invalida\n");
			system("pause");
			break;	
		}//fim da seleção do menu
		
		
		printf("\n\nEsse Softare é da Mel\n");
		system("pause");
	}

}
