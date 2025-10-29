#include <stdio.h>
#include <string.h>


// CONST GLOBAIS
#define MAX_TERRITORIO 5
#define TAM_STRING 100

struct territorio{
    char nome[30];
    char cor[10];
    int tropa;
    
};

//função para limpar buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c =getchar()) != '\n' && c != EOF);
}

//função principal main
// ...existing code...
int main(){
    struct territorio territorio[MAX_TERRITORIO];
    int totalTerritorios = 0;
    int opcao;

    // laco principal do menu
    do {
        printf("___WAR___\n");
        printf("1 - cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("0 - sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) { limparBufferEntrada(); opcao = 0; }
        limparBufferEntrada();

        switch (opcao){
            case 1: // cadastro territorio
                printf("CADASTRO DE TERRITORIO\n\n");

                if (totalTerritorios < MAX_TERRITORIO){
                    printf("Digite o nome do Territorio: ");
                    if (fgets(territorio[totalTerritorios].nome, sizeof(territorio[totalTerritorios].nome), stdin) == NULL) break;
                    territorio[totalTerritorios].nome[strcspn(territorio[totalTerritorios].nome, "\n")] = '\0';

                    printf("Digite a cor: ");
                    if (fgets(territorio[totalTerritorios].cor, sizeof(territorio[totalTerritorios].cor), stdin) == NULL) break;
                    territorio[totalTerritorios].cor[strcspn(territorio[totalTerritorios].cor, "\n")] = '\0';

                    printf("Digite o numero de tropas: ");
                    if (scanf("%d", &territorio[totalTerritorios].tropa) != 1) {
                        limparBufferEntrada();
                        territorio[totalTerritorios].tropa = 0;
                    }
                    limparBufferEntrada();

                    totalTerritorios++;
                    printf("Territorio cadastrado com sucesso.\n\n");
                } else {
                    printf("Limite de territorios atingido.\n");
                }
                break;

            case 2: // listar territorios
                for (int i = 0; i < totalTerritorios; ++i) {
                    printf("%d: %s | cor: %s | tropas: %d\n", i+1,
                        territorio[i].nome, territorio[i].cor, territorio[i].tropa);
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
