#include <stdio.h>
#include <string.h>

// SUPER TRUNFO - DESAFIO FINAL
// Comparação com dois atributos, menus dinâmicos e soma dos valores

int main() {
    // Dados das duas cartas (poderia vir de cadastro anterior)
    char pais1[30] = "Brasil";
    char pais2[30] = "Japão";

    float populacao1 = 214.0, populacao2 = 125.7; // em milhões
    float area1 = 8516.0, area2 = 377.9;          // em mil km²
    float pib1 = 2.08, pib2 = 5.0;                // em trilhões USD
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao1, opcao2;
    float valorA1 = 0, valorB1 = 0;
    float valorA2 = 0, valorB2 = 0;
    float somaA = 0, somaB = 0;
    char atributo1[30], atributo2[30];

    printf("===== SUPER TRUNFO - DESAFIO FINAL =====\n\n");
    printf("Carta 1: %s\n", pais1);
    printf("Carta 2: %s\n\n", pais2);

    // === Menu 1: Escolher o primeiro atributo ===
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1:
            strcpy(atributo1, "População");
            valorA1 = populacao1;
            valorB1 = populacao2;
            break;
        case 2:
            strcpy(atributo1, "Área");
            valorA1 = area1;
            valorB1 = area2;
            break;
        case 3:
            strcpy(atributo1, "PIB");
            valorA1 = pib1;
            valorB1 = pib2;
            break;
        case 4:
            strcpy(atributo1, "Densidade Demográfica");
            valorA1 = densidade1;
            valorB1 = densidade2;
            break;
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 0;
    }

    // === Menu 2: Escolher o segundo atributo ===
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");

    // Menu dinâmico (oculta o atributo já escolhido)
    if (opcao1 != 1) printf("1 - População\n");
    if (opcao1 != 2) printf("2 - Área\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Densidade Demográfica\n");

    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 4) {
        printf("Atributo inválido ou repetido! Encerrando.\n");
        return 0;
    }

    switch (opcao2) {
        case 1:
            strcpy(atributo2, "População");
            valorA2 = populacao1;
            valorB2 = populacao2;
            break;
        case 2:
            strcpy(atributo2, "Área");
            valorA2 = area1;
            valorB2 = area2;
            break;
        case 3:
            strcpy(atributo2, "PIB");
            valorA2 = pib1;
            valorB2 = pib2;
            break;
        case 4:
            strcpy(atributo2, "Densidade Demográfica");
            valorA2 = densidade1;
            valorB2 = densidade2;
            break;
        default:
            printf("Opção inválida! Encerrando o programa.\n");
            return 0;
    }

    // === Comparação e soma ===
    printf("\n===== RESULTADOS =====\n");
    printf("Comparando %s e %s\n", pais1, pais2);
    printf("--------------------------------------\n");
    printf("%s: %.2f x %.2f\n", atributo1, valorA1, valorB1);
    printf("%s: %.2f x %.2f\n", atributo2, valorA2, valorB2);
    printf("--------------------------------------\n");

    // Regra especial: Densidade Demográfica vence quem tem MENOR valor
    float resultado1 = (strcmp(atributo1, "Densidade Demográfica") == 0)
                           ? (valorA1 < valorB1 ? 1 : 0)
                           : (valorA1 > valorB1 ? 1 : 0);

    float resultado2 = (strcmp(atributo2, "Densidade Demográfica") == 0)
                           ? (valorA2 < valorB2 ? 1 : 0)
                           : (valorA2 > valorB2 ? 1 : 0);

    somaA = valorA1 + valorA2;
    somaB = valorB1 + valorB2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", pais1, somaA);
    printf("%s: %.2f\n", pais2, somaB);
    printf("--------------------------------------\n");

    // Determinar vencedor (com operador ternário)
    (somaA > somaB) ? printf("Vencedor: %s 🏆\n", pais1)
                    : (somaB > somaA) ? printf("Vencedor: %s 🏆\n", pais2)
                                      : printf("Empate!\n");

    return 0;
}

