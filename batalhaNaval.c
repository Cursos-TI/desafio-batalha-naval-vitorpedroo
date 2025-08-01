#include <stdio.h>
 
int main() {
  int tabuleiro[10][10] = {
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,3,3,3,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,3,0,0,},
    {0,0,0,0,0,0,0,3,0,0,},
    {0,0,0,0,0,0,0,3,0,0,},
    {0,0,0,0,0,0,0,0,0,0,},
  };

  // Exibir o tabuleiro
  printf("== BATALHA NAVAL ==\n");
  printf("Agua = 0, Navio = 3\n\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
    
  }
  printf("\nO navio na horizontal esta nas posições: (2,3) (2,4) (2,5)\n");
  printf("O navio na vertical esta nas posições: (6,7) (7,7) (8,7)\n");



    return 0;
}