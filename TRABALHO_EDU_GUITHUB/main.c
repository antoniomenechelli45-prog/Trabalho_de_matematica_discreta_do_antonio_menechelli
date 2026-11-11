#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LIMITE_N 20

//Funcao auxiliar: fatorial//
long long calcularFatorial(int numero) {
    long long resultado = 1;
    int i;

    for (i = 2; i <= numero; i++) {
        resultado = resultado * i;
    }
    return resultado;
}

// 1 - Triangulo de Pascal //
void trianguloDePascal(void) {
    int triangulo[10][10];
    int linha, coluna, espaco;

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            triangulo[linha][coluna] = 0;
        }
    }

    for (linha = 0; linha < 10; linha++) {
        triangulo[linha][0] = 1;
        triangulo[linha][linha] = 1;
        for (coluna = 1; coluna < linha; coluna++) {
            triangulo[linha][coluna] = triangulo[linha - 1][coluna - 1]
                                     + triangulo[linha - 1][coluna];
        }
    }

    printf("\n--- TRIANGULO DE PASCAL (10 linhas) ---\n\n");
    for (linha = 0; linha < 10; linha++) {
        for (espaco = 0; espaco < (9 - linha) * 2; espaco++) {
            printf(" ");
        }
        for (coluna = 0; coluna <= linha; coluna++) {
            printf("%4d", triangulo[linha][coluna]);
        }
        printf("\n");
    }
}

// 2 - Arranjo Simples //
void arranjoSimples(void) {
    int n, p;
    long long resultado;

    printf("\n--- ARRANJO SIMPLES ---\n");
    printf("Digite o valor do primeiro numro: ");
    scanf("%d", &n);
    printf("Digite o valor do segundo numero: ");
    scanf("%d", &p);

    if (n < 0 || p < 0) {
        printf("Erro: o segundo numeor e o primeiro numero nao podem ser negativos.\n");
    } else if (p > n) {
        printf("Erro: o segundo numero deve ser menor ou igual ao primeiro numero.\n");
    } else if (n > LIMITE_N) {
        printf("Erro: o primeiro numero deve ser no maximo %d.\n", LIMITE_N);
    } else {
        resultado = calcularFatorial(n) / calcularFatorial(n - p);
        printf("A(%d,%d) = %lld\n", n, p, resultado);
    }
}

// 3 - Permutacao Simples //
void permutacaoSimples(void) {
    int n;
    long long resultado;

    printf("\n--- PERMUTACAO SIMPLES ---\n");
    printf("Digite o valor do numero: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro:o numero nao pode ser negativo.\n");
    } else if (n > LIMITE_N) {
        printf("Erro:o numero deve ser no maximo %d.\n", LIMITE_N);
    } else {
        resultado = calcularFatorial(n);
        printf("o numero numero(%d) = %d! = %lld\n", n, n, resultado);
    }
}

// 4 - Combinacao Simples //
void combinacaoSimples(void) {
    int n, p;
    long long resultado;

    printf("\n--- COMBINACAO SIMPLES ---\n");
    printf("Digite o valor do primeiro numero (total de elementos): ");
    scanf("%d", &n);
    printf("Digite o valor do segundo numero (elementos escolhidos): ");
    scanf("%d", &p);

    if (n < 0 || p < 0) {
        printf("Erro: o primeiro numero  e o segundo numero nao podem ser negativos.\n");
    } else if (p > n) {
        printf("Erro: o segundo numero deve ser menor ou igual ao primeiro numero.\n");
    } else if (n > LIMITE_N) {
        printf("Erro: o primeiro numero deve ser no maximo %d (limite do tipo long long).\n", LIMITE_N);
    } else {
        resultado = calcularFatorial(n) / (calcularFatorial(p) * calcularFatorial(n - p));
        printf("resultado:(%d,%d) = %lld\n", n, p, resultado);
    }
}

// Programa principal //
void main() {
    // português //
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Triângulo de Pascal\n");
        printf("2 - Arranjo Simples\n");
        printf("3 - Permutação Simples\n");
        printf("4 - Combinação Simples\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                trianguloDePascal();
                break;
            case 2:
                arranjoSimples();
                break;
            case 3:
                permutacaoSimples();
                break;
            case 4:
                combinacaoSimples();
                break;
            case 0:
                printf("\nEncerrando o programa. Falo BB!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
