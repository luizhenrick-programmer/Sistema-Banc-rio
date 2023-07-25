#include "stdio.h" // BIBLIOTECA PADRÃO
#include "stdlib.h" // BIBLIOTECA AUXILIAR A PADRÃO
#include "string.h" // BIBLIOTECA DE STRINGS
#include "ctype.h" // BIBLIOTECA DE MANIPULAÇÃO
#include "locale.h" // BIBLIOTECA PARA PT_BR
#include "time.h"
#include "header.h"
#include "files.h"
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // MÁXIMO DE REGISTRO DE TRANSAÇÕES
#define NUM_CONTAS 10000000


// VARIÁEVIS GLOBAIS
usuarios cliente[100];
int opcao;


int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
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
