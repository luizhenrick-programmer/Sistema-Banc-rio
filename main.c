#include "stdio.h" // BIBLIOTECA PADR�O
#include "stdlib.h" // BIBLIOTECA AUXILIAR A PADR�O
#include "string.h" // BIBLIOTECA DE STRINGS
#include "ctype.h" // BIBLIOTECA DE MANIPULA��O
#include "locale.h" // BIBLIOTECA PARA PT_BR
#include "time.h"
#include "header.h"
#include "files.h"
#define CARACTERES 250 // CARACTERES DAS STRINGS
#define MAX_TRANSACTIONS 100 // M�XIMO DE REGISTRO DE TRANSA��ES
#define NUM_CONTAS 10000000


// VARI�EVIS GLOBAIS
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
        printf("\nDigite a op��o requerida: ");
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
                printf("\nOp��o Inv�lida! Tente novamente...");
                continue;
        }
    } while (opcao != 3);
    printf("\nSAINDO...");
    printf("\nObrigado por utilizar os servi�os do C-Secure Bank! At� logo...");
    return 0;
}
