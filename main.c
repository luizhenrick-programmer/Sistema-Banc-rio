#include <stdio.h> // BIBLIOTECA PADRÃO
#include <stdlib.h> // BIBLIOTECA AUXILIAR A PADRÃO
#include <string.h> // BIBLIOTECA DE STRINGS
#include <locale.h> // BIBLIOTECA PARA MUDAR O IDIOMA PARA PT_BR
#include <ctype.h> // BIBLIOTECA DE MANIPULAÇÃO
#include <time.h> // BIBLIOTECA DE TEMPO
#include <unistd.h> // BIBLIOTECA DE MILISEGUNDOS
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES


// VARIÁEVIS GLOBAIS
char buffer[CARACTERES];
typedef enum { false, true } bool;
int pessoas = 0;
float saque;


void logomarca() {
    printf("\n");
    usleep(500000); //PAUSA O PROGRAMA EM INTERVALOS DE MEIO SEGUNDO
    //DESIGNER E FRONT-END DA LOGO DO SISTEMA 
    printf("                                         ??????????    ????????????   ??????   ???     ???????????    ??????????????\n");
    usleep(500000);
    printf("                                         ???    ????   ????    ????   ??????   ???     ???????????    ??????????????\n");
    usleep(500000);
    printf("                                         ???    ????   ????    ????   ??? ???  ???     ????           ????      ????\n");
    usleep(500000);
    printf("                                         ??????????    ????????????   ???  ??? ???     ????           ????      ????\n");
    usleep(500000);
    printf("                                         ???    ????   ????    ????   ???   ??????     ????           ????      ????\n");
    usleep(500000);
    printf("                                         ???    ????   ????    ????   ???    ?????     ???????????    ??????????????\n");
    usleep(500000);
    printf("                                         ??????????    ????    ????   ???    ?????     ???????????    ??????????????\n");
    usleep(500000);
    printf("\n\n");
    usleep(500000);
    printf("???????????             ????????????   ??????????   ???????????   ????    ????   ????????????     ??????????   ????????????   ????????????   ????     ????\n");
    usleep(500000);
    printf("???????????             ?????          ????         ???????????   ????    ????   ?????    ????    ????         ????    ????   ????    ????   ????     ????\n");
    usleep(500000);
    printf("????                    ?????          ????         ????          ????    ????   ?????    ????    ????         ????    ????   ????    ????    ???????????\n");
    usleep(500000);
    printf("????          ??????    ??????????     ?????????    ????          ????    ????   ????????????     ?????????    ????????????   ????????????       ?????   \n");
    usleep(500000);
    printf("????          ??????         ?????     ????         ????          ????    ????   ????????????     ????         ????           ????    ????       ?????   \n");
    usleep(500000);
    printf("???????????                  ?????     ????         ???????????   ????????????   ?????    ????    ????         ????           ????    ????       ?????   \n");
    usleep(500000);
    printf("???????????           ????????????     ??????????   ???????????   ????????????   ?????    ?????   ??????????   ????           ????    ????       ?????   \n");
    printf("\n\n");
    usleep(500000);
}


void cabecalho() {
    // PÁGINA INICIAL QUE SEMPRE RODARÁ NO LOOP
    printf("\n\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+                                            +\n");
    printf("+                    BANCO                   +\n");
    printf("+                 C-SECUREPAY                +\n");
    printf("+          Seu banco, sua segurança.         +\n");
    printf("+      Autenticidade em cada transação.      +\n");
    printf("+                                            +\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n\n");
}


void menu_principal() {
    // PÁGINA DE ENTRADA DO PROGRAMA
    printf("\n");
    printf("Bem-vindo ao C-SECUREPAY: O melhor banco para você!");
    sleep(1);
    printf("\n");
    printf("----------------------------------------\n");
    printf("+  [ 1 ]  CRIAR CONTA NO C-SECUREPAY   +\n");
    printf("+  [ 2 ]  FAZER LOGIN NO C-SECUREPAY   +\n");
    printf("+  [ 3 ]  SAIR DO SISTEMA C-SECUREPAY  +\n");
    printf("----------------------------------------\n");
    printf("\n\n");
}


// STRUCT PARA DATA DE NASCIMENTO
struct Data {
    int dia;
    int mes;
    int ano;
};


// STRUCT PARA ENDEREÇO
struct Endereco {
    char rua[CARACTERES];
    int numero;
    char setor[CARACTERES];
    char cidade[CARACTERES];
    char estado[CARACTERES];
    int cep;
};


// STRUCT PARA CADASTRO DE USUÁRIOS
typedef struct { 
    char nome[CARACTERES];
    char username[CARACTERES];
    char password[CARACTERES];
    struct Data nascimento;
    int CPF;
    int RG;
    struct Endereco endereco;
    int numeroConta;
    float saldo;
    double transactions[MAX_TRANSACTIONS];
    int transactionCount;
} usuarios;


void criar_arquivo(char* nome_arquivo) {
    char nome_com_extensao[CARACTERES + 4];
    if (strlen(nome_arquivo) + 4 > CARACTERES) {
        printf("\nNome de arquivo muito grande\n");
        return;
    }
    strcpy(nome_com_extensao, nome_arquivo);
    strcat(nome_com_extensao, ".txt");
    FILE* arquivo = fopen(nome_com_extensao, "a");
    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo\n");
        return;
    }
    fclose(arquivo);
}


int verificarUsuario(char* usuario) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return 0;
    }

    char linha[CARACTERES];
    while (fgets(linha, CARACTERES, arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove a quebra de linha

        // Verifica se a linha atual contém o username
        if (strstr(linha, "USERNAME: ") != NULL) {
            char* username = linha + strlen("USERNAME: ");
            if (strcmp(usuario, username) == 0) {
                fclose(arquivo);
                return 1; // Indica que o usuário foi encontrado
            }
        }
    }

    fclose(arquivo);
    return 0; // Indica que o usuário não foi encontrado
}


bool validar_CPF(const char* cpf) {
    // Verifica se a string tem exatamente 11 caracteres
    if (strlen(cpf) != 11) {
        return false;
    }

    // Verifica se todos os caracteres são números
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }

    // Verifica se todos os caracteres são iguais
    bool caracteres_iguais = true;
    for (int i = 0; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            caracteres_iguais = false;
            break;
        }
    }

    // Se for verdade, ou seja, se todos forem igual returna falso
    if (caracteres_iguais) {
        return false;
    }

    return true;
}


bool validar_RG(const char* rg) {
    // Verifica se a string tem exatamente 7 caracteres
    if (strlen(rg) != 7) {
        return false;
    }

    // Verifica se todos os caracteres são números
    for (int i = 0; i < 7; i++) {
        if (!isdigit(rg[i])) {
            return false;
        }
    }

    // Verifica se todos os caracteres são iguais
    bool caracteres_iguais = true;
    for (int i = 0; i < 7; i++) {
        if (rg[i] != rg[0]) {
            caracteres_iguais = false;
            break;
        }
    }

    // Se for verdade, ou seja, se todos forem igual returna falso
    if (caracteres_iguais) {
        return false;
    }

    return true;
}


bool validar_CEP(const char* cep) {
    // Verifica se a string tem exatamente 8 caracteres
    if (strlen(cep) != 8) {
        return false;
    }

    // Verifica se todos os caracteres são números
    for (int i = 0; i < 7; i++) {
        if (!isdigit(cep[i])) {
            return false;
        }
    }

    // Verifica se todos os caracteres são iguais
    bool caracteres_iguais = true;
    for (int i = 0; i < 7; i++) {
        if (cep[i] != cep[0]) {
            caracteres_iguais = false;
            break;
        }
    }

    // Se for verdade, ou seja, se todos forem igual returna falso
    if (caracteres_iguais) {
        return false;
    }

    return true;
}


// FUNÇÃO DE CADASTRAMENTO DE USUÁRIOS
int cadastrar_usuario(usuarios *usuario) {
    system("cls");
    printf("CARREGANDO INFORMAÇÕES PARA CRIAÇÃO DE CONTA...\n");
    printf("\n");
    printf("Para que possamos lhe cadastrar por favor insira corretamente os dados requeridos abaixo:\n");
    printf("\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        fflush(stdin);
        printf("Nome completo: ");
        fgets(usuario->nome, sizeof(usuario->nome), stdin);
        usuario->nome[strcspn(usuario->nome, "\n")] = '\0';
        if (strcmp(usuario->nome, "") == 0 || strlen(usuario->nome) < 10) {
            printf("Nome Inválido. Digite seu Nome Completo novamente...\n");
            continue;
        } else {
            break;
        }
    }
    printf("Para continuarmos digite sua data de nascimento [DD/MM/YYYY]\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("O dia referente ao seu nascimento: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) {
            printf("Dia Inválido. Digite seu dia de nascimento corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->nascimento.dia);
            if (usuario->nascimento.dia > 31 || usuario->nascimento.dia < 1) {
                printf("Dia Inválido. Digite seu dia de nascimento corretamente...\n");
                continue;
            } else {
                break;
            }
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("O Mês referente ao seu nascimento: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) {
            printf("Mês Inválido. Digite seu Mês de nascimento corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->nascimento.mes);
            if (usuario->nascimento.mes > 31 || usuario->nascimento.mes < 1) {
                printf("Mês Inválido. Digite seu Mês de nascimento corretamente...\n");
                continue;
            } else{
                break;
            }
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("O ano referente ao seu nascimento: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) {
            printf("Ano Inválido. Digite seu ano de nascimento corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->nascimento.ano);
            if (usuario->nascimento.ano > 2023 || usuario->nascimento.ano < 1900) {
                printf("Ano Inválido. Digite seu ano de nascimento corretamente...\n");
                continue;
            } else{
                break;
            }
        }
    }
    printf("Informe os seguintes Dados Pessoais: [SOMENTE NÚMEROS]\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("CPF: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0 || !validar_CPF(buffer)) {
            printf("CPF Inválido. Digite seu CPF corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->CPF);
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("RG: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0 || !validar_RG(buffer)) {
            printf("RG Inválido. Digite seu RG corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->RG);
            break;
        }
    }
    printf("Digite seu endereço abaixo:\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Rua: ");
        fgets(usuario->endereco.rua, sizeof(usuario->endereco.rua), stdin);
        usuario->endereco.rua[strcspn(usuario->endereco.rua, "\n")] = '\0';
        if (strcmp(usuario->endereco.rua, "") == 0) {
            printf("Rua Inválida. Digite o endereço da sua rua corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Número: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) {
            printf("Número Inválido. Digite seu Número de endereço corretamente...\n");
            continue;
        } else {
            int todos_numeros = 1;
            for (int i = 0; i < strlen(buffer); i++) {
                if (!isdigit(buffer[i])) {
                    todos_numeros = 0;
                    break;
                }
            }

            if (!todos_numeros) {
                printf("Número Inválido. Digite seu Número de endereço corretamente...\n");
                continue;
            } else {
                sscanf(buffer, "%d", &usuario->endereco.numero);
                break;
            }
                
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Setor Residencial: ");
        fgets(usuario->endereco.setor, sizeof(usuario->endereco.setor), stdin);
        usuario->endereco.setor[strcspn(usuario->endereco.setor, "\n")] = '\0';
        if (strcmp(usuario->endereco.setor, "") == 0) {
            printf("Setor Residencial Inválido. Digite o Setor Residencial em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Cidade: ");
        fgets(usuario->endereco.cidade, sizeof(usuario->endereco.cidade), stdin);
        usuario->endereco.cidade[strcspn(usuario->endereco.cidade, "\n")] = '\0';
        if (strcmp(usuario->endereco.cidade, "") == 0) {
            printf("Cidade Inválido. Digite a Cidade em que vocÃª reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Estado: ");
        fgets(usuario->endereco.estado, sizeof(usuario->endereco.estado), stdin);
        usuario->endereco.estado[strcspn(usuario->endereco.estado, "\n")] = '\0';
        if (strcmp(usuario->endereco.estado, "") == 0) {
            printf("Estado Inválido. Digite o Estado em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("CEP: [APENAS NÚMEROS] ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0 || !validar_CEP(buffer)) {
            printf("CEP Inválido. Digite seu CEP corretamente...\n");
            continue;
        } else {
            sscanf(buffer, "%d", &usuario->endereco.cep);
            break;
        }
                
    }
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("   CADASTRAMENTO DE DADOS CONCLUÍDO COM SUCESSO!  \n");
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("Após o cadastramento de dados pessoais, agora escolha um nome de usuário e senha para acesso a sua conta\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Digite seu nome de usuario: ");
        fgets(usuario->username, sizeof(usuario->username), stdin);
        usuario->username[strcspn(usuario->username, "\n")] = '\0';
        if (strcmp(usuario->username, "") == 0) {
            printf("Nome de usuário Inválido. Digite o nome de usuário em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Digite sua senha de acesso: ");
        fgets(usuario->password, sizeof(usuario->password), stdin);
        usuario->password[strcspn(usuario->password, "\n")] = '\0';
        if (strcmp(usuario->password, "") == 0) {
            printf("Senha Inválido. Digite o Estado em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    printf("Para finalizar informe o valor de depósito que deseja inserir em sua conta: R$ ");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Depósito Inicial: R$ ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) {
            printf("Saldo Inválido. Por favor digite um valor válido para o depósito\n");
            continue;
        } else {
            sscanf(buffer,"%f", &usuario->saldo);
            if (usuario->saldo < 1) {
                printf("Saldo Inválido. Por favor digite um valor válido para o depósito\n");
                continue;
            } else if (usuario->saldo > 1000000000){
                printf("Saldo muito grande para um depósito inicial. Deposite um valor considerável para sua aprovação!");
            } else {
                break;
            }
        }
    }
    // CRIANDO ARQUIVO PARA ARMAZENAR DADOS CADASTRADOS
    FILE* cadastro;
    cadastro = fopen("cadastro.txt", "w+");
    // Verificar se a abertura do arquivo foi bem-sucedida
    if (cadastro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    // Escreve os dados do usuário no final do arquivo
    fseek(cadastro, 0, SEEK_END);
    fprintf(cadastro, "NOME: %s; ", usuario->nome);
    fprintf(cadastro, "DIA: %.2d; ", usuario->nascimento.dia);
    fprintf(cadastro, "MÊS: %.2d; ", usuario->nascimento.ano);
    fprintf(cadastro, "ANO: %.2d; ", usuario->nascimento.mes);
    fprintf(cadastro, "CPF: %d; ", usuario->CPF);
    fprintf(cadastro, "RG: %d; ", usuario->RG);
    fprintf(cadastro, "RUA: %s; ", usuario->endereco.rua);
    fprintf(cadastro, "NÚMERO: %d; ", usuario->endereco.numero);
    fprintf(cadastro, "SETOR: %s; ", usuario->endereco.setor);
    fprintf(cadastro, "CIDADE: %s; ", usuario->endereco.cidade);
    fprintf(cadastro, "ESTADO: %s; ", usuario->endereco.estado);
    fprintf(cadastro, "CEP: %d; ", usuario->endereco.cep);
    fprintf(cadastro, "NUMEROCONTA: %d; ", usuario->numeroConta);
    fprintf(cadastro, "USERNAME: %s; ", usuario->username);
    fprintf(cadastro, "PASSWORD: %s; ", usuario->password);
    fprintf(cadastro, "SALDO: %.2f\n", usuario->saldo);

    // Fechar o arquivo
    fclose(cadastro);
}


void acessar_sistema() {
    system("cls");
    criar_arquivo("cadastro");
    cabecalho();
    printf("Para iniciar o login informe: \n");
    fflush(stdin);
    printf("Nome de Usuário: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    if (verificarUsuario(buffer)) {
        printf("Usuário existe.\n");
        system("pause");
    } else {
        printf("Usuário não existe.\n");
        system("pause");
    }
}


int main() {
    usuarios cliente[1];
    int opcao;
    system("cls");
    logomarca();
    system("pause");
    system("cls");
    cabecalho();
    menu_principal();
    do {
        printf("\nDigite a opção requerida: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar_usuario(cliente);
                continue;
            case 2:
                acessar_sistema();
                continue;
            break;
            default:
                while (opcao > 3 || opcao < 1) {
                    printf("\nOpção Inválida! Tente novamente...");
                    printf("\nDigite a opção requerida: ");
                    scanf("%d", &opcao);
                }
        }
    } while (opcao != 3);
    printf("\nSAINDO...");
    printf("\nObrigado por utilizar os serviços do C-Secure Bank! Até logo...");
    return 0;
}
