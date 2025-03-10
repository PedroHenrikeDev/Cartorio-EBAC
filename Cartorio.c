#include <stdio.h> //biblioteca de comunicaï¿½ï¿½o com o usuï¿½rio
#include <stdlib.h> //biblioteca de alocaï¿½ï¿½o de espaï¿½o na memï¿½ria
#include <locale.h> //boblioteca de alocaï¿½ï¿½o de texto por regiï¿½o
#include <string.h> //biblioteca responsï¿½vel por cuidar das strings

int registro() // funï¿½ï¿½o responsï¿½vel por cadastrar os usuï¿½rios no sistema
{
	//inicio de criaï¿½ï¿½o das variï¿½veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaï¿½ï¿½o das variï¿½veis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informaï¿½ï¿½es do usuï¿½rio
	scanf("%s", cpf); //%s refere se a strings
	
	strcpy(arquivo, cpf); //responsï¿½vel por copiar os valores da string
	
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



int consultar() //funï¿½ï¿½o responsï¿½vel por consultar usuï¿½rios
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	//inicio a criaï¿½ï¿½o de variï¿½veis
	char cpf[40];
	char conteudo[200];
	//final da criaï¿½ï¿½o de variï¿½veis
	
	printf("Digite o CPF que deseja consultar:"); //coleta o dado necessï¿½rio para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // consulta o arquivo, "r" read(ler)

	if(file == NULL)
	{
		printf("lamento, este CPF nï¿½o foi localizado:\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //enquanto o fgets estiver escrevendo na variavel/sring o conteudo atï¿½ 200 dos valores dentro do arquivo
	{
		printf("\nEssas sï¿½o as informaï¿½ï¿½es do usuï¿½rio:/n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	


}

int deletar()
{
	setlocale(LC_ALL,"portuguese"); //definindo a linguagem
	
	//inicio das variï¿½veis
	char cpf[40];
	//fim das variï¿½veis
	
	printf("Digite o CPF do usuï¿½rio a ser deletado: "); //coleta o dado necessï¿½rio para deletar
	scanf("%s", cpf);	
	
	FILE*file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf("lamento, o usuï¿½rio nï¿½o foi encontrado no sistema.\n");
		system("pause");
	}
	
	else
	{
	fclose(file); // Fecha o arquivo, pois ele ï¿½ existente
    remove(cpf); // Agora vocï¿½ pode remover o arquivo
    printf("Usuï¿½rio deletado com sucesso!\n");
    system("pause");	
	}
	
	
}


int main()
{
	int opcao=0; //definindo variï¿½veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //responsï¿½vei por limpar a tela
	
	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
		printf("### Cartório de alunos da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu: \n\n"); 
		printf("\t1 - Registrar nomes:\n"); 
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n"); 
		printf("\t4 - Sair do sistema.\n");
		printf("opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuï¿½rio

		system("cls");
		
		switch(opcao) //inicio da seleï¿½ï¿½o do menu
		{
			case 1: 
			registro(); //chamada de funï¿½ï¿½es
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
			printf("Lamento, essa opção não está disponível :( , por favor retorne ao menu\n");
			system("pause"); //fim da seleï¿½ï¿½o
			
		}
		
	
	
	
	}
}
