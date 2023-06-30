
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define CARACTERES 250
#define MAX_TRANSACTIONS 100

void __init__() {
    printf("\n");
    usleep(500000);
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
    usleep(500000);
}

void slogan() {
    printf("\n\n");
    printf("\t++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t+                                            +\n");
    printf("\t+                    BANCO                   +\n");
    printf("\t+                 C-SECUREPAY                +\n");
    printf("\t+          Seu banco, sua segurança.         +\n");
    printf("\t+      Autenticidade em cada transação.      +\n");
    printf("\t+                                            +\n");
    printf("\t++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
}

void acess() {
    printf("\n");
    printf("Bem-vindo ao C-SECUREPAY: O melhor banco para você!");
    sleep(1);
    printf("\n");
    printf("----------------------------------------\n");
    printf("+  [ 1 ]  CRIAR CONTA NO C-SECUREPAY   +\n");
    printf("+  [ 2 ]  FAZER LOGIN NO C-SECUREPAY   +\n");
    printf("+  [ 3 ]  SAIR DO SISTEMA C-SECUREPAY  +\n");
    printf("----------------------------------------\n");
    printf("\n");
}

typedef struct admin{
    char name[CARACTERES];
    char username[CARACTERES];
    int numeroconta;
    char senha[CARACTERES]
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco{
    char rua[CARACTERES];
    int numero;
    char cidade[CARACTERES];
    char estado[CARACTERES];
    char cep[7];
};


typedef struct { 
    char nome[CARACTERES];
    char username[CARACTERES];
    char password[CARACTERES];
    struct Data nascimento;
    char CPF[11];
    char RG[8];
    struct Endereco endereco;
    int accountNumber;
    double saldo;
    double transactions[MAX_TRANSACTIONS];
    int transactionCount;
} usuarios;

void cadastrar_usuario(usuarios *usuario) {
    printf("CARREGANDO INFORMAÇÕES PARA CRIAÇÃO DE CONTA...\n");
    printf("\n");
    printf("Para que possamos lhe cadastrar por favor insira corretamente os dados requeridos abaixo:\n");
    printf("\n");
    while (1) {
        printf("Nome completo: "
        );
        fgets(usuario->nome, sizeof(usuario->nome), stdin);
        usuario->nome[strcspn(usuario->nome, "\n")] = '\0';
        if (strcmp(usuario->CPF, "") == 0 || strlen(usuario->nome) < 10 ) {
            printf("Nome Inválido. Digite seu Nome Completo novamente...\n");
            continue;
        } else {
            break;
        }
    }
    printf("Para continuarmos digite sua data de nascimento [DD/MM/YYYY]\n");
    while (1) {
        printf("O dia referente ao seu nascimento: ");
        if (scanf("%d", &usuario->nascimento.dia) != 1 || usuario->nascimento.dia > 31 || usuario->nascimento.dia < 1 ) {
            printf("Dia Inválido. Digite seu dia de nascimento corretamente...\n");
            int c;
            if ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        } else {
            break;
        }
    }
    while (1) {
        printf("O Mês referente ao seu nascimento: ");
        if (scanf("%d", &usuario->nascimento.mes) != 1 || usuario->nascimento.mes > 12 || usuario->nascimento.mes < 1) {
            printf("Mês Inválido. Digite seu mês de nascimento corretamente...\n");
            int c;
            if ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        } else {
            break;
        }
    }
    while (1) {
        printf("O ano referente ao seu nascimento: ");
        if (scanf("%d", &usuario->nascimento.ano) != 1 || usuario->nascimento.ano < 1900 || usuario->nascimento.ano > 2023 ) {
            printf("Ano Inválido. Digite seu ano de nascimento corretamente...\n");
            int c;
            if ((c = getchar()) != '\n' && c != EOF) {
                continue;
            }
        } else {
            break;
        }
    }
    printf("Informe os seguintes Dados Pessoais: [SOMENTE NÚMEROS]\n");
    while (1) {
        printf("CPF: ");
        fgets(usuario->CPF, sizeof(usuario->CPF), stdin);
        usuario->CPF[strcspn(usuario->CPF, "\n")] = '\0';
        if (strcmp(usuario->CPF, "") == 0 || strlen(usuario->CPF) != 10) {
            printf("CPF Inválido. Digite seu CPF corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    while (1) {
        printf("RG: ");
        fgets(usuario->RG, sizeof(usuario->RG), stdin);
        usuario->RG[strcspn(usuario->RG, "\n")] = '\0';
        if (strcmp(usuario->RG, "") == 0 || strlen(usuario->RG) != 7 ) {
            printf("RG Inválido. Digite RG corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    printf("Digite seu endreço abaixo:\n");
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
    while (1) {
        printf("Número: ");
        if (scanf("%d", &usuario->endereco.numero) != 1) {
            printf("Número Inválido. Digite o número da sua casa corretamente...\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        } else {
            break;
        }
    }
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
    scanf("%d", &usuario->saldo);
    while (1) {
        if (scanf("%d", usuario->saldo) != 1) {
            printf("Valor de saldo Inválido. Digite o valor correto que deseja depositar...\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        } else {
            break;
        }
    }
}

int main() {
    __init__();
    system("pause");
    system("cls");
    usuarios cliente[3];
    slogan();
    acess();
    cadastrar_usuario(cliente);
    return 0;
}

