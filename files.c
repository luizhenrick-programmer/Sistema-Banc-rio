#include "stdio.h" // BIBLIOTECA PADRÃO
#include "stdlib.h" // BIBLIOTECA AUXILIAR A PADRÃO
#include "string.h" // BIBLIOTECA DE STRINGS
#include "ctype.h" // BIBLIOTECA DE MANIPULAÇÃO
#include "time.h" // BIBLIOTECA DE TEMPO
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES
#define NUM_CONTAS 10000000

// STRUCT PARA ACESSO DO ADMINISTRADOR
typedef struct {
    char username[CARACTERES];
    char senha[CARACTERES];
    int numeroConta;
} admin;


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
    float saldo;
    int numeroConta;
    double transactions[MAX_TRANSACTIONS];
    int transactionCount;
} usuarios;


// VARIÁEVIS GLOBAIS
typedef enum { false, true } bool;
char buffer[CARACTERES];
char usuario[CARACTERES];
char senha[CARACTERES];
usuarios cliente[100];
int numerosUtilizados[NUM_CONTAS];
float saldo;
float saque;
float deposito;
int opcao;


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
        printf("\nErro ao abrir o arquivo\n");
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


bool validar_Usuario(char* usuario) {
    FILE* arquivo = fopen("cadastro.txt", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return false;
    }

    char linha[CARACTERES];
    int usuarioJaExiste = true;
    while (fgets(linha, CARACTERES, arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';

        if (strstr(linha, "USERNAME: ") != NULL) {
            char* token = strtok(linha, " ");
            while (token != NULL) {
                if (strcmp(usuario, token) == 0) {
                    usuarioJaExiste = false;
                    break;
                }
                token = strtok(NULL, " ");
            }
        }
    }

    if (usuarioJaExiste) {
        return false;
    }

    fclose(arquivo);

    return true;
}


int Gerador_Contas(int min, int max, int *numerosUtilizados, int numNumerosUtilizados) {
    int numero;
    int validacao;
    do {
        numero = min + rand() % (max - min + 1);
        validacao = 0;
        for (int i = 0; i < numNumerosUtilizados; i++) {
            if (numerosUtilizados[i] == numero) {
                validacao = 1;
                break;
            }
        }
    } while (validacao);
    return numero;
}


int obterSaldo(const char* usuario, float* saldof) {
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


void modificarSaldo(const char* arquivo, const char* usuario, float novoSaldo) {
    FILE* fpOriginal = fopen(arquivo, "r");
    if (fpOriginal == NULL) {
        printf("Erro ao abrir o arquivo original.\n");
        return;
    }

    FILE* fpTemporario = fopen("temporario.txt", "w");
    if (fpTemporario == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(fpOriginal);
        return;
    }

    char linha[256];
    int usuarioEncontrado = 0;

    while (fgets(linha, sizeof(linha), fpOriginal)) {
        if (strstr(linha, "USERNAME: ") != NULL && strstr(linha, usuario) != NULL) {
            fputs(linha, fpTemporario);
            usuarioEncontrado = 1;
        } else if (usuarioEncontrado && strstr(linha, "SALDO: ") != NULL) {
            fputs("SALDO: ", fpTemporario);
            fprintf(fpTemporario, "%.2f\n", novoSaldo);
            printf("Saldo atualizado com sucesso!\n");
            usuarioEncontrado = 0;
        } else {
            fputs(linha, fpTemporario);
        }
    }

    fclose(fpOriginal);
    fclose(fpTemporario);

    if (remove(arquivo) != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    if (rename("temporario.txt", arquivo) != 0) {
        printf("Erro ao renomear o arquivo temporário.\n");
        return;
    }
}


int sacarSaldo(const char* usuario) {
    system("cls");
    analise_saque();
    while (1) {
        animarTexto("\n\nDigite o valor que deseja retirar: R$ ", 50);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        obterSaldo(usuario, &saldo);
        if (strcmp(buffer, "") == 0) {
            printf("\n\n");
            sleep(2);
            erro_saque();
            animarTexto("\nImpossível realizar saque! O valor não pode ficar vazio...", 50);
            continue;
        } else {
            sscanf(buffer,"%f", &saque);
            if (saque > saldo) {
                saldo_insuficiente();
                animarTexto("\nImpossível realizar saque! Solicitação de saque acima do saldo atual...", 50);
                continue;
            } else if (saque <= 0){
                printf("\n\n");
                sleep(2);
                erro_saque();
                animarTexto("\nImpossível realizar saque! Solicitação de saque não pode ser igual ou inferior a R$ 00,00...", 50);
                continue;
            } else {
                sleep(1);
                obterSaldo(usuario, &saldo);
                saldo = saldo - saque;
                modificarSaldo("cadastro.txt", usuario, saldo);
                erro_saque();
                animarTexto("\nSaque efetivado com sucesso! O C-SECUREBAK agradece a preferência!", 50);
                printf("\n\nSeu saldo atual agora é: R$ %.2f\n", saldo);
                system("pause");
                break;
            }
        }
    }
}


int depositarSaldo(const char* usuario) {
    system("cls");
    analise_deposito();
    while (1) {
        animarTexto("\n\nDigite o valor que deseja depositar: R$ ", 50);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        obterSaldo(usuario, &saldo);
        if (strcmp(buffer, "") == 0) {
            erro_deposito();
            animarTexto("\nImpossível realizar depósito! Solicitação de depósito não pode estar vazia...", 50);
            continue;
        } else {
            sscanf(buffer,"%f", &deposito);
            if (deposito <= 0){
                erro_deposito();
                animarTexto("\nImpossível realizar depósito! Solicitação de depósito não pode ser igual ou inferior a R$ 00,00...", 50);
                continue;
            } else {
                sleep(1);
                obterSaldo(usuario, &saldo);
                saldo = saldo + deposito;
                modificarSaldo("cadastro.txt", usuario, saldo);
                depositando();
                printf("\n\n");
                sleep(2);
                animarTexto("\nDepósito efetivado com sucesso! O C-SECUREBAK agradece a preferência!", 50);
                printf("\n\nSeu saldo atual agora é: R$ %.2f", saldo);
                system("pause");
                break;
            }
        }
    }
}


// Função para modificar o nome do usuário no arquivo
void modificarNome(const char* arquivo, const char* usuario, const char* novoNome) {
    FILE* fpOriginal = fopen(arquivo, "r");
    if (fpOriginal == NULL) {
        printf("Erro ao abrir o arquivo original.\n");
        return;
    }

    FILE* fpTemporario = fopen("temporario.txt", "w");
    if (fpTemporario == NULL) {
        printf("Erro ao abrir o arquivo temporário.\n");
        fclose(fpOriginal);
        return;
    }

    char linha[256];
    int usuarioEncontrado = 0;

    while (fgets(linha, sizeof(linha), fpOriginal)) {
        if (strstr(linha, "USERNAME: ") != NULL && strstr(linha, usuario) != NULL) {
            fputs(linha, fpTemporario);
            usuarioEncontrado = 1;
        }else if (usuarioEncontrado && strstr(linha ,"NOME: ")) {
            fputs("NOME: ", fpTemporario);
            fprintf(fpTemporario, "%s\n", novoNome);
            printf("Nome atualizado com sucesso!\n");
            usuarioEncontrado = 0;
            
        } else {
            fputs(linha, fpTemporario); // Copia a linha para o arquivo temporário
        }
    }

    fclose(fpOriginal);
    fclose(fpTemporario);

    if (remove(arquivo) != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return;
    }
    if (rename("temporario.txt", arquivo) != 0) {
        printf("Erro ao renomear o arquivo temporário.\n");
        return;
    }
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
            if (usuario->nascimento.mes > 12 || usuario->nascimento.mes < 1) {
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
            printf("Cidade Inválido. Digite a Cidade em que você reside corretamente...\n");
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
    cadastro_dados();
    animarTexto("Após o cadastramento de dados pessoais, agora escolha um nome de usuário e senha para acesso a sua conta\n", 50);
    while (1) {
        animarTexto("Digite seu nome de usuario: ", 50);
        fgets(usuario->username, sizeof(usuario->username), stdin);
        usuario->username[strcspn(usuario->username, "\n")] = '\0';
        if (strcmp(usuario->username, "") == 0) {
            printf("Nome de usuário Inválido. Digite o nome de usuário corretamente...\n");
            continue;
        } else if (validar_Usuario(usuario->username)){
            printf("Nome de usuário já existe. Digite outro nome de usuário válido...\n");
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

    animarTexto("\n\nCRIANDO NÚMERO DE CONTA, AGUARDE...", 50);

    for (int i = 0; i < 1; i++) {
        int numeroConta = Gerador_Contas(10000000, 99999999, numerosUtilizados, i);
        numerosUtilizados[i] = numeroConta;
        printf("\nNÚMERO DE CONTA: %08d\n\n", numeroConta);
        usuario->numeroConta = numeroConta;
    }

    animarTexto("NÚMERO GERADO! AGUARDE O PROCESSAMENTO...", 50);

    // CRIANDO ARQUIVO PARA ARMAZENAR DADOS CADASTRADOS
    FILE* cadastro;
    cadastro = fopen("cadastro.txt", "a+");
    if (cadastro == NULL) {
        erro_cadastro();
        return 1;
    }
    fprintf(cadastro, "USERNAME: %s\n", usuario->username);
    fprintf(cadastro, "PASSWORD: %s\n", usuario->password);
    fprintf(cadastro, "NOME: %s\n", usuario->nome);
    fprintf(cadastro, "DIA: %.2d\n", usuario->nascimento.dia);
    fprintf(cadastro, "MÊS: %.2d\n", usuario->nascimento.mes);
    fprintf(cadastro, "ANO: %d\n", usuario->nascimento.ano);
    fprintf(cadastro, "CPF: %d\n", usuario->CPF);
    fprintf(cadastro, "RG: %d\n", usuario->RG);
    fprintf(cadastro, "RUA: %s\n", usuario->endereco.rua);
    fprintf(cadastro, "NÚMERO: %d\n", usuario->endereco.numero);
    fprintf(cadastro, "SETOR: %s\n", usuario->endereco.setor);
    fprintf(cadastro, "CIDADE: %s\n", usuario->endereco.cidade);
    fprintf(cadastro, "ESTADO: %s\n", usuario->endereco.estado);
    fprintf(cadastro, "CEP: %d\n", usuario->endereco.cep);
    fprintf(cadastro, "NUMEROCONTA: %d\n", usuario->numeroConta);
    fprintf(cadastro, "SALDO: %.2f\n\n", usuario->saldo);
    fclose(cadastro);
    cadastro_finalizado();
    system("\npause");
}


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
        erro_usuario();
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
                    cadastrar_usuario(cliente);
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
    char novoNome[CARACTERES];
    do {
        system("cls");
        menu_banco();
        while (1) {
            printf("Digite a opção requerida: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strcmp(buffer, "") == 0) {
                printf("Opção Inválida. Por favor digite uma opção válida...\n");
                continue;
            } else {
                sscanf(buffer,"%d", &opcao);
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
                if (opcao < 1) {
                    printf("Opção Inválida. Por favor digite uma opção válida...\n");
                    continue;
                } else {
                    break;
                }
            }
        }
        switch (opcao) {
            case 1:
                imprimirSaldo(usuario);
                break;
            case 2:
                sacarSaldo(usuario);
                break;
            case 3:
                depositarSaldo(usuario);
                break;
            case 4:
                printf("Digite o novo nome: ");
                fflush(stdin);
                fgets(novoNome, CARACTERES, stdin);
                novoNome[strcspn(novoNome, "\n")] = '\0';
                modificarNome("cadastro.txt", usuario, novoNome);
                break;
            case 5:
                animarTexto("\n\nENCERRANDO SISTEMA...", 50);
                break;
            default:
                printf("\nOpção Inválida! Tente novamente...");
                continue;
        }
    } while (opcao != 5);
}

