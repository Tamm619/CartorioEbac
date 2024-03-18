#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // strcpy = String Copy, copia valores das strings da direita para a esquerda.
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //Salvo o valor da variavel (CPF)
	fclose(file); //Fecha o arquivo
	
	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf (file,nome);
	fclose(file);
	
	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    
    if(file == NULL)
    {
    	printf("O CPF não está em nosso sistema.\n\n");
	}
	
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    
    printf("Digite o CPF do Usuário a ser deletado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) //Se não encontrar o arquivo com o nome digitado no %s, ativará a função abaixo.
    {
    	printf("Não foi possível localizar o CPF.\n\n");
    	system("pause");
	}    //Deixei else identado 1x a mais, para declarar que é sobre o if logo acima :)
		else //Se for encontrado, o comando acima não funcionará, e partirá para o else(Senão).
		{
			if(file != NULL)
		    fclose(file);
		    remove(cpf);
			printf("CPF Removido com sucesso!\n\n\n");
			system("pause");
		}
		
	

	
	
} 





int main()
{
    int opcao=0; //Definindo uma Variável, Variável OPCAO!
    int repet=1; //Variável para Looping do Menu
    
    for(repet=1;repet==1;)
    {
	
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	    printf("-== Cartório da EBAC ==-\n\n\n"); //Inicio do Menu
	    printf("Escolha a opção desejada do menu:\n\n"); 
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");  
	    printf("\t3 - Deletar Nomes\n");
	    printf("\t4 - Sair do Sistema\n\n\n");
	    printf("Opção:"); //Final do Menu //printf("Este Software é de livre uso de todos."); No Final!!!!
	    
	    scanf("%d", &opcao); //Gravando as Informações do Usuário
	    
	    system("cls"); //Comando para (Clear) na tela
	    
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
    		printf("Obrigado por acessar o Sistema!\n");
    		return 0;
    		break;
    		
    		default:
    		printf("Quer acessar as Backrooms é?\n");
        	system("pause");
        	break;
        	
		}
	        //Fim das Seleções

    }
}

