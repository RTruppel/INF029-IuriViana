#include <stdio.h>

int main(void) {
  int idade[5], media = 0;

  for (int i = 0; i < 5; i++) {
    printf("Informe o %do numero: ", i + 1);
    scanf("%d", &idade[i]);
    media += idade[i];
  }

  media /= 5;

  for (int i = 0; i < 5; i++) {
    if (idade[i] > media)
      printf("Numeros maiores que a media %d\n", idade[i]);
  }

  return 0;
}