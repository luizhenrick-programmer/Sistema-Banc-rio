#include "stdio.h" // BIBLIOTECA PADRÃO
#include "stdlib.h" // BIBLIOTECA AUXILIAR A PADRÃO
#include "string.h" // BIBLIOTECA DE STRINGS
#include "ctype.h" // BIBLIOTECA DE MANIPULAÇÃO
#include "time.h" // BIBLIOTECA DE TEMPO
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES


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


// VARIÁEVIS GLOBAIS
typedef enum { false, true } bool;
char buffer[CARACTERES];
char usuario[CARACTERES]; 
char senha[CARACTERES];
int pessoas = 0;
float saldo;
float saque;
float deposito;
int opcao;


void logomarca() { 
    printf("\n");
    usleep(500000);
    printf("                                                    ?????????????    ????????????   ???????    ????   ???????????    ??????????????\n");
    usleep(500000);
    printf("                                                    ????      ????   ????    ????   ????????   ????   ???????????    ??????????????\n");
    usleep(500000);
    printf("                                                    ????      ????   ????    ????   ???? ????  ????   ????           ????      ????\n");
    usleep(500000);
    printf("                                                    ?????????????    ????????????   ????  ???? ????   ????           ????      ????\n");
    usleep(500000);
    printf("                                                    ????      ????   ????    ????   ????   ????????   ????           ????      ????\n");
    usleep(500000);
    printf("                                                    ????      ????   ????    ????   ????    ???????   ???????????    ??????????????\n");
    usleep(500000);
    printf("                                                    ?????????????    ????    ????   ????     ??????   ???????????    ??????????????\n");
    usleep(500000);
    printf("\n\n");
    usleep(500000);
    printf("???????????             ????????????   ??????????   ???????????   ????    ????   ???????????     ??????????   ?????????????    ????????????   ???????    ????   ????    ????\n");
    usleep(500000);
    printf("???????????             ?????          ????         ???????????   ????    ????   ????    ????    ????         ????      ????   ????    ????   ????????   ????   ????   ????\n");
    usleep(500000);
    printf("????                    ?????          ????         ????          ????    ????   ????    ????    ????         ????      ????   ????    ????   ???? ????  ????   ????  ????\n");
    usleep(500000);
    printf("????          ??????    ??????????     ?????????    ????          ????    ????   ???????????     ?????????    ?????????????    ????????????   ????  ???? ????   ?????????\n");
    usleep(500000);
    printf("????          ??????         ?????     ????         ????          ????    ????   ???????????     ????         ????      ????   ????    ????   ????   ????????   ????  ????\n");
    usleep(500000);
    printf("???????????                  ?????     ????         ???????????   ????????????   ????    ????    ????         ????      ????   ????    ????   ????    ???????   ????   ????\n");
    usleep(500000);
    printf("???????????           ????????????     ??????????   ???????????   ????????????   ????    ?????   ??????????   ?????????????    ????    ????   ????     ??????   ????    ????\n");
    printf("\n\n");
    usleep(500000);
}


// FUNÇÃO PÁGINA INICIAL QUE SEMPRE RODARÁ NO LOOP
void cabecalho() {
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


// FUNÇÃO DA PÁGINA DE ENTRADA DO PROGRAMA
void menu_principal() {
    printf("\n");
    printf("Bem-vindo ao C-SECUREPAY: O melhor banco para você!");
    sleep(2);
    printf("\n");
    printf("----------------------------------------\n");
    printf("+  [ 1 ]  CRIAR CONTA NO C-SECUREPAY   +\n");
    printf("+  [ 2 ]  FAZER LOGIN NO C-SECUREPAY   +\n");
    printf("+  [ 3 ]  SAIR DO SISTEMA C-SECUREPAY  +\n");
    printf("----------------------------------------\n");
    printf("\n\n");
}

void animarTexto(const char* texto, int velocidade) {
    for (int i = 0; i < strlen(texto); i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        usleep(velocidade * 1000);
    }
}


void cadastro_titulo() {
    printf("\n");
    printf("CARREGANDO INFORMAÇÕES PARA CRIAÇÃO DE CONTA...\n");
    sleep(1);
    printf("\n");
    printf("------------------------------------------------\n");
    animarTexto("+               CADASTRANDO USUÁRIO           +\n", 50);
    printf("------------------------------------------------\n");
    printf("\n\n");
}


void cadastro_finalizado() {
    printf("\n");
    sleep(2);
    printf("\n");
    printf("-----------------------------------------------\n");
    animarTexto("+       CADASTRO FINALIZADO COM SUCESSO!      +\n", 50);
    printf("-----------------------------------------------\n");
    printf("\n\n");
}


void cadastro_error() {
    printf("\n");
    sleep(2);
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("+           ERRO AO FINALIZAR CADASTRO        +\n");
    printf("-----------------------------------------------\n");
    printf("\n\n");
    printf("Infelizmente ocorreu um erro ao finalizar o cadastro. Tente novamente e caso o problema insista converse diretamente com nosso suporte. Atenciosamente equipe C-SUCURE BANK");
}


void sistema_titulo() {
    printf("\n"); 
    sleep(1);
    printf("-----------------------------------------------\n");
    animarTexto("+              INICIANDO SISTEMA...           +\n", 50);
    printf("-----------------------------------------------\n");
    sleep(3);
}


void menu_banco() {
    printf("\n");
    animarTexto("Selecione o serviço que deseja utilizar:", 50);
    sleep(2);
    printf("\n");
    animarTexto("----------------------------------------\n", 50);
    animarTexto("+  [ 1 ]  VERIFICAR SALDO DA CONTA     +\n", 50);
    animarTexto("+  [ 2 ]  SACAR DINHEIRO DA CONTA      +\n", 50);
    animarTexto("+  [ 3 ]  DEPOSITAR DINHEIRO NA CONTA  +\n", 50);
    animarTexto("+  [ 4 ]  TRANSFERIR PARA OUTRA CONTA  +\n", 50);
    animarTexto("+  [ 5 ]  REALIZAR LOGOUT DA CONTA     +\n", 50);
    animarTexto("----------------------------------------\n", 50);
    printf("\n\n");
}


void imprimirSaldo() {
    printf("\n");
    animarTexto("Selecione o serviço que deseja utilizar:", 50);
    sleep(2);
    printf("\n");
    printf("----------------------------------------\n");
    animarTexto("+          VERIFICANDO SALDO...        +\n", 50);
    printf("----------------------------------------\n");
    printf("\n\n");
    printf("Seu saldo atual: R$ %f", saldo);
    printf("\n");
}


// CRIA O ARQUIVO PARA DATABASE CASO ELE NÃO EXISTA 
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


// FUNÇÃO PARA VALIDAÇÃO DE SENHA E USUÁRIO
int verificarUsuario(const char* usuario, const char* senha) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return 0;
    }
    char linha[CARACTERES];
    int encontrouUsuario = 0;
    int senhaCorreta = 0;
    while (fgets(linha, CARACTERES, arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        if (strstr(linha, "USERNAME: ") != NULL) {
            char* token = strtok(linha, " ");
            while (token != NULL) {
                if (strcmp(usuario, token) == 0) {
                    encontrouUsuario = 1;
                    break;
                }
                token = strtok(NULL, " ");
            }
        }
        if (encontrouUsuario && strstr(linha, "PASSWORD: ") != NULL) {
            char* token = strtok(linha, " ");
            token = strtok(NULL, " ");
            if (token != NULL) {
                if (senha != NULL && strcmp(senha, token) == 0) {
                    senhaCorreta = 1;
                }
                break;
            }
        }
    }
    fclose(arquivo);
    if (encontrouUsuario && senhaCorreta) {
        return 2;
    } else if (encontrouUsuario) {
        return 1;
    } else {
        return 0;
    }
}


// FUNÇÃO PARA VERIFICAÇÃO E VALIDAÇÃO DE CPF
bool validar_CPF(const char* cpf) {
    if (strlen(cpf) != 11) {
        return false;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }
    bool caracteres_iguais = true;
    for (int i = 0; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            caracteres_iguais = false;
            break;
        }
    }
    bool caracteres_negativos = true;
    for (int i = 0; i < 11; i++) {
        if (cpf[i] > 0) {
            caracteres_negativos = false;
            break;
        }
    }
    if (caracteres_iguais) {
        return false;
    }
    if (caracteres_negativos) {
        return false;
    }
    return true;
}


// FUNÇÃO PARA VERIFICAÇÃO E VALIDAÇÃO DE RG
bool validar_RG(const char* rg) {
    if (strlen(rg) != 7) {
        return false;
    }
    for (int i = 0; i < 7; i++) {
        if (!isdigit(rg[i])) {
            return false;
        }
    }
    bool caracteres_iguais = true;
    for (int i = 0; i < 7; i++) {
        if (rg[i] != rg[0]) {
            caracteres_iguais = false;
            break;
        }
    }
    bool caracteres_negativos = true;
    for (int i = 0; i < 11; i++) {
        if (rg[i] > 0) {
            caracteres_negativos = false;
            break;
        }
    }
    if (caracteres_iguais) {
        return false;
    }
    if (caracteres_negativos) {
        return false;
    }
    return true;
}


// FUNÇÃO PARA VERIFICAÇÃO E VALIDAÇÃO DE CEP
bool validar_CEP(const char* cep) {
    if (strlen(cep) != 8) {
        return false;
    }
    for (int i = 0; i < 7; i++) {
        if (!isdigit(cep[i])) {
            return false;
        }
    }
    bool caracteres_iguais = true;
    for (int i = 0; i < 7; i++) {
        if (cep[i] != cep[0]) {
            caracteres_iguais = false;
            break;
        }
    }
    bool caracteres_negativos = true;
    for (int i = 0; i < 11; i++) {
        if (cep[i] > 0) {
            caracteres_negativos = false;
            break;
        }
    }
    if (caracteres_iguais) {
        return false;
    }
    if (caracteres_negativos) {
        return false;
    }
    return true;
}


int obterSaldo(char* usuario, float* saldof) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return 0;
    }

    char linha[CARACTERES];
    int encontrouUsuario = 0;
    while (fgets(linha, CARACTERES, arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        if (strstr(linha, "USERNAME: ") != NULL) {
            char* token = strtok(linha, " ");
            while (token != NULL) {
                if (strcmp(usuario, token) == 0) {
                    encontrouUsuario = 1;
                    break;
                }
                token = strtok(NULL, " ");
            }
        }

        if (encontrouUsuario && strstr(linha, "SALDO: ") != NULL) {
            char* token = strtok(linha, " ");
            token = strtok(NULL, " ");
            if (token != NULL) {
                *saldof = atof(token);
                fclose(arquivo);
                return 1;
            }
            break;
        }
    }

    fclose(arquivo);

    return 0;
}


// FUNÇÃO DE CADASTRAMENTO DE USUÁRIOS
int cadastrar_usuario(usuarios *usuario) {
    system("cls");
    cadastro_titulo();
    printf("\n");
    animarTexto("Para que possamos lhe cadastrar por favor insira corretamente os dados requeridos abaixo:\n", 50);
    printf("\n");
    while (1) {
        fflush(stdin);
        animarTexto("Nome completo: ", 50);
        fgets(usuario->nome, sizeof(usuario->nome), stdin);
        usuario->nome[strcspn(usuario->nome, "\n")] = '\0';
        if (strcmp(usuario->nome, "") == 0 || strlen(usuario->nome) < 10) {
            printf("Nome Inválido. Digite seu Nome Completo novamente...\n");
            continue;
        } else {
            break;
        }
    }
    animarTexto("Para continuarmos digite sua data de nascimento [DD/MM/YYYY]\n", 50);
    while (1) {
        animarTexto("O dia referente ao seu nascimento: ", 50);
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
    while (1) {
        animarTexto("O Mês referente ao seu nascimento: ", 50);
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
    while (1) {
        animarTexto("O ano referente ao seu nascimento: ", 50);
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
    animarTexto("Informe os seguintes Dados Pessoais: [SOMENTE NÚMEROS]\n", 50);
    while (1) {
        animarTexto("CPF: ", 50);
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
    while (1) {
        animarTexto("RG: ", 50);
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
    animarTexto("Digite seu endereço abaixo:\n", 50);
    while (1) {
        animarTexto("Rua: ", 50);
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
        animarTexto("Número: ", 50);
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
    while (1) {
        animarTexto("Setor Residencial: ", 50);
        fgets(usuario->endereco.setor, sizeof(usuario->endereco.setor), stdin);
        usuario->endereco.setor[strcspn(usuario->endereco.setor, "\n")] = '\0';
        if (strcmp(usuario->endereco.setor, "") == 0) {
            printf("Setor Residencial Inválido. Digite o Setor Residencial em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    while (1) {
        animarTexto("Cidade: ", 50);
        fgets(usuario->endereco.cidade, sizeof(usuario->endereco.cidade), stdin);
        usuario->endereco.cidade[strcspn(usuario->endereco.cidade, "\n")] = '\0';
        if (strcmp(usuario->endereco.cidade, "") == 0) {
            printf("Cidade Inválido. Digite a Cidade em que vocÃª reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    while (1) {
        animarTexto("Estado: ", 50);
        fgets(usuario->endereco.estado, sizeof(usuario->endereco.estado), stdin);
        usuario->endereco.estado[strcspn(usuario->endereco.estado, "\n")] = '\0';
        if (strcmp(usuario->endereco.estado, "") == 0) {
            printf("Estado Inválido. Digite o Estado em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    while (1) {
        animarTexto("CEP: [APENAS NÚMEROS] ", 50);
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
    animarTexto("Após o cadastramento de dados pessoais, agora escolha um nome de usuário e senha para acesso a sua conta\n", 50);
    while (1) {
        animarTexto("Digite seu nome de usuario: ", 50);
        fgets(usuario->username, sizeof(usuario->username), stdin);
        usuario->username[strcspn(usuario->username, "\n")] = '\0';
        if (strcmp(usuario->username, "") == 0) {
            printf("Nome de usuário Inválido. Digite o nome de usuário em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    while (1) {
        animarTexto("Digite sua senha de acesso: ", 50);
        fgets(usuario->password, sizeof(usuario->password), stdin);
        usuario->password[strcspn(usuario->password, "\n")] = '\0';
        if (strcmp(usuario->password, "") == 0) {
            printf("Senha Inválido. Digite o Estado em que você reside corretamente...\n");
            continue;
        } else {
            break;
        }
    }
    animarTexto("Para finalizar informe o valor de depósito que deseja inserir em sua conta:\n", 50);
    while (1) {
        animarTexto("Depósito Inicial: R$ ", 50);
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
    cadastro = fopen("cadastro.txt", "a+");
    if (cadastro == NULL) {
        cadastro_error();
        return 1;
    }
    fprintf(cadastro, "NOME: %s\n", usuario->nome);
    fprintf(cadastro, "DIA: %.2d\n", usuario->nascimento.dia);
    fprintf(cadastro, "MÊS: %.2d\n", usuario->nascimento.ano);
    fprintf(cadastro, "ANO: %d\n", usuario->nascimento.mes);
    fprintf(cadastro, "CPF: %d\n", usuario->CPF);
    fprintf(cadastro, "RG: %d\n", usuario->RG);
    fprintf(cadastro, "RUA: %s\n", usuario->endereco.rua);
    fprintf(cadastro, "NÚMERO: %d\n", usuario->endereco.numero);
    fprintf(cadastro, "SETOR: %s\n", usuario->endereco.setor);
    fprintf(cadastro, "CIDADE: %s\n", usuario->endereco.cidade);
    fprintf(cadastro, "ESTADO: %s\n", usuario->endereco.estado);
    fprintf(cadastro, "CEP: %d\n", usuario->endereco.cep);
    fprintf(cadastro, "NUMEROCONTA: %d\n", usuario->numeroConta);
    fprintf(cadastro, "USERNAME: %s\n", usuario->username);
    fprintf(cadastro, "PASSWORD: %s\n", usuario->password);
    fprintf(cadastro, "SALDO: %.2f\n\n", usuario->saldo);
    fclose(cadastro);
    cadastro_finalizado();
}


// FUNÇÃO DE TELA DE LOGIN DO USUÁRIO
void acessar_sistema() {
    printf("Nome de Usuário: ");
    fflush(stdin);
    fgets(usuario, CARACTERES, stdin);
    usuario[strcspn(usuario, "\n")] = '\0';
    printf("Senha de Usuário: ");
    fflush(stdin);
    fgets(senha, CARACTERES, stdin);
    senha[strcspn(senha, "\n")] = '\0';
    int usuarioValido = verificarUsuario(usuario, senha);
    if (usuarioValido == 2) {
        sistema();
    } else if (usuarioValido == 1) {
        printf("Usuário válido, mas a senha está incorreta.\n");
        while (1) {
            printf("Digite a senha novamente: ");
            fflush(stdin);
            fgets(senha, CARACTERES, stdin);
            senha[strcspn(senha, "\n")] = '\0';

            int senhaValida = verificarUsuario(usuario, senha);

            if (senhaValida == 2) {
                sistema();
                break;
            } else {
                printf("Senha incorreta. Tente novamente...\n");
            }
        }
    } else {
        printf("Usuário não encontrado.\n");
        printf("Deseja se cadastrar para ter acesso ao sistema? [Caso digite NÃO o sistema se encerrará]\n");
        printf("-----------------------\n");
        printf("+      [ 1 ] SIM      +\n");
        printf("+      [ 2 ] NÃO      +\n");
        printf("-----------------------\n");

        while (1) {
            printf("\nSua opção: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "") == 0) {
                printf("Opção Inválida. Por favor digite uma opção válida...\n");
                continue;
            } else {
                int numerico = 1;
                for (int i = 0; i < strlen(buffer); i++) {
                    if (!isdigit(buffer[i])) {
                        numerico = 0;
                    }
                }
                if (!numerico) {
                    printf("Opção Inválida. Por favor digite uma opção válida...\n");
                    continue;
                }
                sscanf(buffer,"%d", &opcao);
                if (opcao < 1 || opcao > 2) {
                    printf("Opção Inválida. Por favor digite uma opção válida...\n");
                    continue;
                } else if (opcao == 1) {
                    usuarios Cliente[1];
                    cadastrar_usuario(Cliente);
                    break;
                } else if (opcao == 2) {
                    break;
                }
            }
        }
    }
    system("pause");
}


int sistema() {
    sistema_titulo();
    do {
        menu_banco();
        while (1) {
            animarTexto("Digite a opção requerida: ", 50);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "") == 0) {
                printf("Opção Inválida. Por favor digite uma opção válida...\n");
                continue;
            } else {
                int numerico = 1;
                for (int i = 0; i < strlen(buffer); i++) {
                    if (!isdigit(buffer[i])) {
                        numerico = 0;
                    }
                }
                if (!numerico) {
                    printf("Opção Inválida. Por favor digite uma opção válida...\n");
                    continue;
                }
                sscanf(buffer,"%d", &opcao);
                if (opcao < 1) {
                    printf("Opção Inválida. Por favor digite uma opção válida...\n");
                    continue;
                }
            }
        }
        switch (opcao) {
            case 1:
                imprimirSaldo();
                break;
            default:
                printf("\nOpção Inválida! Tente novamente...");
                continue;
        }
    
    } while (opcao != 5);
}


int main() {
    usuarios cliente[1];
    int opcao;
    system("cls");
    logomarca();
    system("pause");
    do {
        system("cls");
        cabecalho();
        menu_principal();
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
                printf("\nOpção Inválida! Tente novamente...");
                continue;
        }
    } while (opcao != 3);
    printf("\nSAINDO...");
    printf("\nObrigado por utilizar os serviços do C-Secure Bank! Até logo...");
    return 0;
}
