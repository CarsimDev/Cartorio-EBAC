 #include <stdio.h> //Biblioteca de comunica��o com o usu�rio
 #include <stdlib.h>//Biblioteca de aloca��o de espa�o em mem�ria
 #include <locale.h>//Biblioteca de aloca��es de texto por regi�o
 #include <string.h>//Biblioteca respons�vel para strings
 int registro()//Fun��o respons�vel por cadastrar usu�rios no sistema
 {
 	//�nicio cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //FInal cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: ");//Coletando info. do usu�rio
    scanf("%s", cpf); //%s refere-se a strings
    
    strcpy(arquivo, cpf);//Respons�vel por copiar valores de strings
    
    FILE *file;//Cria��o de arquivos
    file = fopen(arquivo, "w");//Cria o arquivo
    fprintf(file,cpf);//Salva o valor da vari�vel
    fclose(file);//Fecha o arquivo
    
    file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    file-fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);	
    
    system("pause");
    
 }
 
 int consulta()
 {
 	setlocale(LC_ALL, "Portuguese"); //Definindo a l�nguagem
 	
 	char cpf[40];
 	char conteudo[200];
 	
 	printf("Digite o CPF a ser consultado: ");
 	scanf("%s", cpf);
 	
 	FILE *file;
 	file = fopen(cpf, "r");
 	
 	if(file == NULL)
 	{
 	   	printf("Este ID n�o foi localizado.\n");
 		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	
	    system("pause");
    }
 }
 
 int deletar()//�nicio da exclus�o de usu�rio
 {
    char cpf[40];
    char cpf2[200];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado no sistema.\n");
		system("pause");
	}//Final da exclus�o de usu�rio
 }

 int main()
 {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
 	    setlocale(LC_ALL, "Portuguese"); //Definindo a l�nguagem
 	
 	    printf("### Cart�rio da EBAC ###\n\n"); //�nicio do menu
  	    printf("Escolha a op��o desejada do menu.\n\n");
 	    printf("\t1 - Registrar nomes\n");
 	    printf("\t2 - Consultar nomes\n");
 	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Op��o:"); //Fim do menu
 	
 	    scanf("%d",&opcao); //Armazenando info. do usu�rio
 	
 	    system("cls");//Limpeza de tela
 	    
 	    switch(opcao)//�nicio de sele��o do menu
		{
			case 1:
			registro();//Chamada de fun��es
 		    break;
 		    
 		    case 2:
 		    consulta();	
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        default:
	        printf("Esta op��o n�o est� disponivel.\n");
	 	    system("pause");
			break;	
 	    }
    }
}
