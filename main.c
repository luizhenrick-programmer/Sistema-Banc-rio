
#include <stdio.h> // BIBLIOTECA PADRÃO
#include <stdlib.h> // BIBLIOTECA AUXILIAR A PADRÃO
#include <string.h> // BIBLIOTECA DE STRINGS
#include <locale.h> // BIBLIOTECA PARA MUDAR O IDIOMA PARA PT_BR
#include <ctype.h> // BIBLIOTECA DE MANIPULAÇÃO
#include <time.h> // BIBLIOTECA DE TEMPO
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES


// VARIÁVEIS GLOBAIS
char buffer[CARACTERES];
typedef enum { false, true } bool;


void __init__() {
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


void slogan() {
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


void acess() {
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


// STRUCT PARA ACESSO DO ADMINISTRADOR
typedef struct {
    char name[CARACTERES];
    char username[CARACTERES];
    int numeroconta;
    char senha[CARACTERES]
}admin;


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
    char cidade[CARACTERES];
    char estado[CARACTERES];
    char cep[7];
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
    int accountNumber;
    float saldo;
    double transactions[MAX_TRANSACTIONS];
    int transactionCount;
} usuarios;


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


// FUNÇÃO DE CADASTRAMENTO DE USUÁRIOS
int cadastrar_usuario(usuarios *usuario) {
    printf("CARREGANDO INFORMAÇÕES PARA CRIAÇÃO DE CONTA...\n");
    printf("\n");
    printf("Para que possamos lhe cadastrar por favor insira corretamente os dados requeridos abaixo:\n");
    printf("\n");
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
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
            printf("Mês Inválido. Digite seu mês de nascimento corretamente...\n");
            continue;
        } else {
            sscanf(buffer,"%d", &usuario->nascimento.mes);
            if (usuario->nascimento.mes > 31 || usuario->nascimento.mes < 1) {
                printf("Mês Inválido. Digite seu mês de nascimento corretamente...\n");
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
    printf("Digite seu endreço abaixo:\n");
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
            printf("Número Inválido. Digite seu número de endereço corretamente...\n");
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
                printf("Número Inválido. Digite seu número de endereço corretamente...\n");
                continue;
            } else {
                sscanf(buffer, "%d", &usuario->endereco.numero);
                break;
            }
                
        }
    }
    // INICIA O LOOP DE VERIFICAÇÃO DE DADOS
    while (1) {
        printf("Cidade: ");
        fgets(usuario->endereco.cidade, sizeof(usuario->endereco.cidade), stdin);
        usuario->endereco.cidade[strcspn(usuario->endereco.cidade, "\n")] = '\0';
        if (strcmp(usuario->endereco.cidade, "") == 0) {
            printf("Cidade Inválida. Digite a Cidade em que você reside corretamente...\n");
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
            printf("Estado Inválido. Digite o Estado em que você reside corretamente...\n");
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
            printf("Estado Inválido. Digite o Estado em que você reside corretamente...\n");
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
    char* dados = "PESSOA%d{\n\t\"NOME\": \"%s\",\n\t\"NASCIMENTO\": \"%d/%d/%d\",\n\t\"Dados Pessoais\":[\n\t\t{\"CPF\": \"%d\"},\n\t\t\{"RG\": \"%d\"},\n\t\t{\"RUA\": \"%s\"},\n\t\t{\"NÚMERO\": \"%d\"},\n\t\t{\"CIDADE\":\"%s\"},\n\t\t{\"ESTADO\":\"%s\"}\n\t]\n}";
    cadastro = fopen("cadastro.json", "w");
    // Verificar se a abertura do arquivo foi bem-sucedida
    if (cadastro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Escrever no arquivo
    fprintf(cadastro, dados, usuario->nome, usuario->nascimento.dia, usuario->nascimento.mes, usuario->nascimento.ano, usuario->CPF, usuario->RG, usuario->endereco.rua, usuario->endereco.numero, usuario->endereco.cidade, usuario->endereco.estado);

    // Fechar o arquivo
    fclose(cadastro);
}

int main() {
    usuarios cliente[1];
    cadastrar_usuario(cliente);
    return 0;
}

