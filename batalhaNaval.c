#include <stdio.h>

#define tamanhoTabuleiro 10
#define tamanhoNavio 3
#define navio 3
#define agua 0

int main() {
    
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro] = {0};

    /// Coordenadas do navio
    int linha_horizontal = 0;  
    int coluna_horizontal = 0; 

    int linha_vertical = 1; 
    int coluna_vertical = 1; 

    int linha_diagonal1 = 0;
    int coluna_diagonal1 = 6;

    int linha_diagonal2 = 2;
    int coluna_diagonal2 = 4;


    /*// Amostra das coordenadas do tabuleiro
   printf("Posicione os navios no tabuleiro:\n");
    printf("    0  1  2  3  4  5  6  7  8  9\n");
    for (int i = 0; i < 10; i++) {
        printf("%d| ", i);
        for (int j = 0; j < 10; j++) {
            printf(" 0 ");
        }
        printf("\n");
    }

    /// Entrada das coordenadas do navio
    printf("Informe a linha e coluna do navio horizontal (0 a 9): ");
    scanf("%d %d", &linha_horizontal, &coluna_horizontal);
    printf("Informe a linha e coluna do navio vertical (0 a 9): ");
    scanf("%d %d", &linha_vertical, &coluna_vertical);
    printf("Informe a linha e coluna do primeiro navio na diagonal (0 a 9): ");
    scanf("%d %d", &linha_diagonal1, &coluna_diagonal1);
    printf("Informe a linha e coluna do segundo navio na diagonal (0 a 9): ");
    scanf("%d %d", &linha_diagonal2, &coluna_diagonal2);*/
    
    

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

    /// Verifica se o navio diagonal 1 esta nos limites do tabuleiro
    if(linha_diagonal1 + tamanhoNavio <= tamanhoTabuleiro && coluna_diagonal1 + tamanhoNavio <= tamanhoTabuleiro) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] == navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = navio;
            }
        } else {
            printf("Navios estão se chocando\n");
            return 1;
        }
    } else {
        printf("Navio diagonal 1 fora dos limites.\n");
        return 1;
    }
        

        /// Verifica se o navio diagonal 2 esta nos limites do tabuleiro
    if(linha_diagonal2 + tamanhoNavio <= tamanhoTabuleiro && coluna_diagonal2 + tamanhoNavio <= tamanhoTabuleiro) {
        int sobreposicao = 0;
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] == navio) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = navio;
            }
        } else {
            printf("Navios estão se chocando\n");
            return 1;
         }
    } else {
        printf("Navio diagonal 2 fora dos limites.\n");
        return 1;
    }


///melhorando o visual do tabuleiro
        printf("    ");
    for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
    printf("%2d ", coluna);
}
    printf("\n");

    for (int linha = 0; linha < tamanhoTabuleiro; linha++) {
        printf("%2d| ", linha); 
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]); 
    }
        printf("\n");
}


    return 0;
}
