#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //boblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio de cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
}



int consultar() //fun��o respons�vel por consultar usu�rios
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio a cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF que deseja consultar:"); //coleta o dado necess�rio para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // consulta o arquivo, "r" read(ler)

	if(file == NULL)
	{
		printf("lamento, este CPF n�o foi localizado:\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //enquanto o fgets estiver escrevendo na variavel/sring o conteudo at� 200 dos valores dentro do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio:/n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	


}

int deletar()
{
	setlocale(LC_ALL,"portuguese"); //definindo a linguagem
	
	//inicio das vari�veis
	char cpf[40];
	//fim das vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta o dado necess�rio para deletar
	scanf("%s", cpf);	
	
	FILE*file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("lamento, o usu�rio n�o foi encontrado no sistema.\n");
		system("pause");
	}
	
	else
	{
	fclose(file); // Fecha o arquivo, pois ele j� existente
    remove(cpf); // Agora voc� pode remover o arquivo
    printf("Usu�rio deletado com sucesso!\n");
    system("pause");	
	}
	
	
}


int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //respons�vei por limpar a tela
	
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio de alunos da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada no menu: \n\n"); 
		printf("\t1 - Registrar nomes:\n"); 
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n"); 
		printf("\t4 - Sair do sistema.\n");
		printf("op��o:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio

		system("cls");
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: 
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema! :)\n");
			return 0;
			break;
			
			
			default: 
			printf("Lamento, essa op��o n�o est� dispon�vel :( , por favor retorne ao menu\n");
			system("pause"); //fim da sele��o
			
		}
		
	
	}
}
