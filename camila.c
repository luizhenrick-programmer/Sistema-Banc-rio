#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[100];
    int quantidade;
    float preco;
};

struct Produto produtos[100];
int numProdutos = 0;

	//cadastrar o produto 
	
void cadastrarProduto() {
    if (numProdutos > 100) {
        printf("Limite máximo de produtos atingido.\n");
        return;
    }

    printf("Nome do produto: ");
    fgets(produtos[numProdutos].nome, 100, stdin);
    printf("Preco: ");
    scanf("%f", &produtos[numProdutos].preco);
    printf("Quantidade: ");
    scanf("%d", &produtos[numProdutos].quantidade);
    getchar(); // limpar char

    numProdutos++;
    printf("Produto cadastrado com sucesso.\n");
}

	// alterar dados de produtos: nome,preço e quantidade
	
void alterarDadosProduto() {
    char nomeProduto[100];
    int pos=-1;
    printf("Nome do produto: ");
    fgets(nomeProduto, 100, stdin);
    nomeProduto[strcspn(nomeProduto,"\n")]= '\0';

    for (int i = 0; i < numProdutos; i++) { 
       
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
           pos =i;
        }
    }
    if(pos!=-1)
	{
		    printf("Novo nome: ");
            fgets(produtos[pos].nome, 100, stdin);
            fflush(stdin);
            printf("Novo preco: ");
            scanf("%f", &produtos[pos].preco);

            printf("Dados do produto alterados com sucesso.\n");
            pos=-1;
            system("pause");
	}
	else
	{
		printf("Produto nao encontrado.\n");
	}

    
}

//mostrar o produto e preço e salvar no arquivo

void listarProdutos() {
	 for (int i = 0; i < numProdutos; i++) {
         printf("Nome: %s\n",produtos[i].nome);
         printf("Quantidade: %d\n",produtos[i].quantidade);
         printf("Preco: %.2f\n", produtos[i].preco);
         printf("================\n\n");

            
        }
        system("pause");
   
}

//salvar no arquivo 

void salvarDadosArquivo() {
    FILE* arquivo = fopen("dados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
  
    
	// Cabeçalho
	fprintf(arquivo,"Nome,Quantidade,Preco\n");
    char resp[50];
    for (int i = 0; i < numProdutos; i++) {
       
        produtos[i].nome[strcspn( produtos[i].nome,"\n")]= '\0';
        fprintf(arquivo,"%s,",produtos[i].nome);
        fprintf(arquivo,"%d,",produtos[i].quantidade);
        fprintf(arquivo,"%.2f\n", produtos[i].preco);
        
    }
    printf("Dados salvos no arquivo.\n");
    fclose(arquivo);
}

//recuperar arquivo

void lerCSV(struct Produto produtos[], int* tamanho) {
    FILE* arquivo = fopen("dados.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    *tamanho = 0;

    fgets(linha, 200, arquivo);

    while (fgets(linha, 200, arquivo) != NULL) {
        char* token = strtok(linha, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(produtos[*tamanho].nome, token);
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        produtos[*tamanho].quantidade = atoi(token);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        produtos[*tamanho].preco = atof(token);

        (*tamanho)++;
    }

    fclose(arquivo);
}


struct Cliente {
    char nome[50];
    char email[50];
    char telefone[50];
};
struct Cliente clientes[100];
int numClientes = 0;

void cadastrarCliente() {
    if (numClientes > 100) {
        printf("Limite máximo de clientes atingido.\n");
        return;
    }

    printf("Nome do cliente: ");
    fgets(clientes[numClientes].nome, 50, stdin);
    printf("Telefone:");
    fgets(clientes[numClientes].telefone, 50, stdin);
    printf("Email: ");
    fgets(clientes[numClientes].email, 50, stdin);
    

    numClientes++;
    printf("Cliente cadastrado com sucesso.\n");
}
void alterarCliente() {
    char nomeCliente[50];
    printf("Nome do cliente: ");
    fgets(nomeCliente, 50, stdin);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nomeCliente) == 0) {
            printf("Novo nome: ");
            fgets(clientes[i].nome, 50, stdin);
            printf("Novo telefone:");
            fgets(clientes[i].telefone,50,stdin);
            printf("Novo email: ");
            fgets(clientes[i].email, 50, stdin);
            printf("Dados do cliente alterados com sucesso.\n");
            return;
        }
    }

    printf("Cliente não encontrado.\n");
}
void listarClientes() {
    FILE *arquivo;
    char linha[100];
printf("=======Lista de Cliente=======\n");

    // Abrir o arquivo em modo de leitura
    
    arquivo = fopen("arquivo.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ler cada linha do arquivo e imprimir na tela
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
 
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void salvarDadosArquivoCliente() {
    FILE* arquivo = fopen("arquivo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

 		 
   // Verificar se o arquivo está vazio
   
    fseek(arquivo, 0, SEEK_END);
    if (ftell(arquivo) == 0) {
      fprintf(arquivo, "Nome,Email,Telefone\n");
  }
  
  	// Cabeçalho
    for (int i = 0; i < numClientes; i++) {
    	
    fprintf(arquivo,"Nome:%s\n",clientes[i].nome);
	fprintf(arquivo,"email:%s\n" ,clientes[i].email);
	fprintf(arquivo,"telefone:%s\n",clientes[i].telefone);
	fprintf(arquivo,"===============\n\n");
     
    }
    printf("Dados salvos no arquivo.\n");
    fclose(arquivo);
}

void recuperarCSV(struct Cliente clientes[], int* tamanho) {
    FILE* arquivo = fopen("arquivo.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    *tamanho = 0;

    fgets(linha, 200, arquivo); // Descartar o cabeçalho

    while (fgets(linha, 200, arquivo) != NULL) {
        char* token = strtok(linha, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(clientes[*tamanho].nome, token);
        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(clientes[*tamanho].email, token);

        token = strtok(NULL, ",");

        if (token == NULL) {
            continue;
        }

        strcpy(clientes[*tamanho].telefone, token);

        (*tamanho)++;
    }

    fclose(arquivo);
}


void realizarVenda() {
    float valor_total = 0;
    int opcaopagamento = 0, opcaoparcelar = 0;
    int quantidade, pos=-1;
    float preco;
    char nomeproduto[100];
    listarProdutos();
    printf("Digite o produto: ");
    fgets(nomeproduto, 100, stdin);
    nomeproduto[strcspn(nomeproduto,"\n")]= '\0';

    
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeproduto) == 0) {
            pos=i;
            
            break;
        }    
    }
    if(pos!=-1){
    	    printf("Nome: %s,",produtos[pos].nome);
            printf("Preco:%2.f\n",produtos[pos].preco);
            printf("Quantidade:%d\n\n",produtos[pos].quantidade);
            
            do{
			
              printf("Digite a quantidade: ");
              scanf("%d", &quantidade);
              
              
              
			  }while(quantidade>produtos[pos].quantidade);
               
               
               	valor_total += produtos[pos].preco * quantidade;
                produtos[pos].quantidade -= quantidade;
            //função para valor total e diminui a quantidade
            
            
	}
    

//formas de pagamento 

    printf("\nCompra adicionada ao carrinho com sucesso!\n");
    printf("Quantidade: %d\n", quantidade);
    printf("Valor adicionado ao carrinho: R$ %.2f\n", valor_total);

    printf("\nValor total da compra: R$ %.2f\n", valor_total);
    printf("Selecione a forma de pagamento:\n");
    printf("1. PIX ou dinheiro \n");
    printf("2. Cartao de Debito\n");
    printf("3. Cartao de Credito\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcaopagamento);

    switch (opcaopagamento) {
        case 1:
            printf("\nForma de pagamento escolhida: PIX ou dinheiro.\n");
            printf("Valor total da compra: R$ %.2f\n", valor_total);
            break;
        case 2:
            printf("\nForma de pagamento escolhida: Cartão de Debito.\n");
            printf("Valor total da compra: R$ %.2f\n", valor_total);
            break;
        case 3:
            printf("\nForma de pagamento escolhida: Cartao de Credito.\n");
            printf("Valor total da compra: R$%.2f\n", valor_total);

            if (valor_total >= 20) {
                printf("\nPara compras com valores acima de R$ 20,00 parcelamos em ate 4 vezes.\n");
                printf("Escolha o numero de parcelas: \n");
                printf("1 vez de R$ %.2f\n", valor_total);
                printf("2 vezes de R$ %.2f\n", ((valor_total * 0.05) + valor_total) / 2);
                printf("3 vezes de R$ %.2f\n", ((valor_total * 0.10) + valor_total) / 3);
                printf("4 vezes de R$ %.2f\n", ((valor_total * 0.15) + valor_total) / 4);
                printf("Digite a opcao desejada: ");
                scanf("%d", &opcaoparcelar);
            }

            if (opcaoparcelar == 1) {
                printf("\nValor total da compra: 1 vez de R$ %.2f\n", valor_total);
            } else if (opcaoparcelar == 2) {
                printf("\nValor total da compra: 2 vezes de R$ %.2f\n", ((valor_total * 0.05) + valor_total) / 2);
            } else if (opcaoparcelar == 3) {
                printf("\nValor total da compra: 3 vezes de R$ %.2f\n", ((valor_total * 0.10) + valor_total) / 3);
            } else if (opcaoparcelar == 4) {
                printf("\nValor total da compra: 4 vezes de R$ %.2f\n", ((valor_total * 0.15) + valor_total) / 4);
            }
    }
}

void exibirMenu() {
    int opcao;

    do {
    	
printf("\n\n\t\t\t\t\t  __  __ __ ___ \n");
printf("\t\t\t\t\t |  _ \| _|   |_  /\n");
printf("\t\t\t\t\t | |_) |  _|   | |   / / \n");
printf("\t\t\t\t\t |  _/| |_  | |  / / \n");
printf("\t\t\t\t\t ||   |_| || /__|\n");
                         

  printf(" ______________  \n");
 printf("((   _ 			   		)) \n");                
 printf(" )) |)  _  . _   \\  / o ._   _|  _   ((  \n");
 printf("((  |) (/ | | |   \\/  | | | (| ()   )) \n");
  printf("---------------------------------------- \n");
 

        printf("\n\n");

        printf("[1]. Cadastrar produto\n");
        printf("[2]. Cadastrar cliente\n");
        printf("[3]. Alterar produtos\n");
        printf("[4]. Alterar cliente\n");
        printf("[5]. Listar produtos\n");
        printf("[6]. Lista clientes\n");
        printf("[7]. Realizar Venda\n");
        printf("[8]. Salvar dados em arquivo\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o char

        switch (opcao) {
            case 1:
                system("cls");
                
                cadastrarProduto();
                salvarDadosArquivo();
                break;
                
            case 2:
                system("cls");
                
                cadastrarCliente();
                salvarDadosArquivoCliente();
                break;
                
                
            case 3:
                system("cls");
                
                alterarDadosProduto();
                break;
            case 4:
                system("cls");
                
                alterarCliente();
                break;
                
            case 5:
                system("cls");
                
                listarProdutos();
                break;
                
        	case 6:
                system("cls");
                
                listarClientes();
                break;
                
            case 7:
                system("cls");
                
                realizarVenda();
                break;
                
            case 8:
                system("cls");
                
                salvarDadosArquivoCliente();
                salvarDadosArquivo();
                break;
                
            case 0:
                system("cls");
                
                printf("Saindo...\n");
                break;
                
            default:
                system("cls");
                
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);
}

int main() {
    lerCSV(produtos, &numProdutos);
    recuperarCSV(clientes,&numClientes);
    exibirMenu();
    return 0;
}
