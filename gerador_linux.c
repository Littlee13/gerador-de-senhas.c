#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    //  Initializing the random number generator with a time-based seed
    srand(time(NULL));
    int quantidade;
    int sorteio;
    char especiais[] = "!@#$&*()<>:?" ; // Special characters available for password generation
    int tamanho = sizeof(especiais) - 1;
    int escolhaMenu;
    int escolhaRetorno;

    printf(">>>>>>>>>>GERADOR DE SENHAS<<<<<<<<<<<\n");
    printf("          1 - Gerar senha\n");
    printf("          2 - Sair\n");
    scanf("%d", &escolhaMenu);
    while (escolhaMenu != 1 && escolhaMenu != 2){ // While used for input validation.
        printf("Insira uma opção válida!\n");
        scanf("%d", &escolhaMenu);
    }
    if (escolhaMenu == 1){
        do{
            int tipo; // Catching the password type chosen by the user
            printf("========Tipo de senha========\n");
            printf("   1 - Letras, numeros e caracteres especiais\n");
            printf("   2 - Letras\n");
            printf("   3 - Numeros\n");
            scanf("%d", &tipo);
            while (tipo != 1 && tipo != 2 && tipo != 3){
                printf("Digite uma opção válida!\n");
                scanf("%d", &tipo);
            }
            printf("Escreva o tamanho que deseja sua senha: "); //Length
            scanf("%d", &quantidade);
            while ( quantidade <= 0){
                printf("Digite um tamanho válido: ");
                scanf("%d", &quantidade);
            
            }
            char senha[quantidade];
            // Generating password based on the chosen type
            switch (tipo){
                case 1:
                    for(int i = 0; i < quantidade; i++){
                        sorteio = (rand() % 4); // Randomly selects the character type
                        if (sorteio == 0){
                            senha[i] = (rand() % 26 + 65);
                        }else if (sorteio == 1){
                                senha[i] = (rand() % 26 + 97);
                        }else if (sorteio == 2){
                            char caractere = especiais[rand() % tamanho];
                            senha[i] = caractere;
                        }          
                        else{
                            senha[i] = (rand() % 10 + 48);
                        }
                    }
                    break;
                case 2:
                    for(int i = 0; i < quantidade; i++){
                        sorteio = (rand() % 2);
                        if (sorteio == 0){
                            senha[i] = (rand() % 26 + 65);
                        }else{
                                senha[i] = (rand() % 26 + 97);
                        }
                    }
                    break;
                case 3: 
                   for(int i = 0; i < quantidade; i++){
                        senha[i] = (rand() % 10 + 48);
                   }
                   break;
            }
            // Return menu
            printf("==================================\n");
            senha[quantidade] = '\0' ;
            printf("Sua senha gerada é %s\n", senha);
            printf("==================================\n");
            printf("---Oque deseja fazer agora?---\n");
            printf("   1 - Gerar nova senha\n");
            printf("   2 - Sair\n");
            printf("-----------------------------------\n");
            scanf("%d", &escolhaRetorno);
            while ( escolhaRetorno != 1 && escolhaRetorno!= 2){
                printf("Insira uma opção válida!\n");
                scanf("%d", &escolhaRetorno);
            }
            if (escolhaRetorno == 2){
                printf("Saindo...."); 
            }
        } while (escolhaRetorno == 1);
    }else{
        printf("Saindo...");
    }
    return 0;
}
