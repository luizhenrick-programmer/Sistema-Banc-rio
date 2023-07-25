#ifndef FILES_H
#define FILES_H
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES


// VARIÁEVIS GLOBAIS
typedef enum { false, true } bool;

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


void criar_arquivo(char* nome_arquivo);
int verificarUsuario(const char* usuario, const char* senha);
bool validar_CPF(const char* cpf);
bool validar_RG(const char* rg);
bool validar_CEP(const char* cep);
bool validar_Usuario(char* usuario);
int obterSaldo(const char* usuario, float* saldof);
void modificarSaldo(const char* arquivo, const char* usuario, float novoSaldo);
int sacarSaldo(const char* usuario);
int depositarSaldo(const char* usuario);
void modificarNome(const char* arquivo, const char* usuario, const char* novoNome);
int cadastrar_usuario(usuarios *usuario);
void acessar_sistema();
int sistema();

#endif // BANCO_H