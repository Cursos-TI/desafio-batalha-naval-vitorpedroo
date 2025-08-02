#include <stdio.h>

#define tamanhoTabuleiro 10
#define tamanhoNavio 3
#define navio 3
#define agua 0

int main() {
    
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro] = {0};

    /// Coordenadas do navio
    int linha_horizontal;  
    int coluna_horizontal; 

    int linha_vertical; 
    int coluna_vertical; 

    /// Amostra das coordenadas do tabuleiro
   printf("Posicione os navios no tabuleiro:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 10; i++) {
        printf("%d| ", i);
        for (int j = 0; j < 10; j++) {
            printf("0 ");
        }
        printf("\n");
    }

    /// Entrada das coordenadas do navio
    printf("Informe a linha e coluna do navio horizontal (0 a 9): ");
    scanf("%d %d", &linha_horizontal, &coluna_horizontal);
    printf("Informe a linha e coluna do navio vertical (0 a 9): ");
    scanf("%d %d", &linha_vertical, &coluna_vertical);



    

    /// Verifica se o navio horizontal esta nos limites do tabuleiro
    if (coluna_horizontal + tamanhoNavio <= tamanhoTabuleiro) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio;
        }
    } else {
        printf("Navio horizontal fora dos limites.\n");
        return 1;
    }

    /// Verifica se o navio vertical esta nos limites do tabuleiro
    if (linha_vertical + tamanhoNavio <= tamanhoTabuleiro) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            /// verifica se os navios estão se chocando
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio;
            }
        } else {
            printf("Navios estão se chocando\n");
            return 1;
        }
    } else {
        printf("Navio vertical fora dos limites.\n");
        return 1;
    }


    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int linha = 0; linha < tamanhoTabuleiro; linha++) {
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
