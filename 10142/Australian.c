/* Resuelve el problema "Australian Voting" (UVA ID = 10142), utilizando 
 * arreglos */
#include <stdio.h>
#include <ctype.h>

int* get_ganadores(int** votos, int votantes, int candidatos, int* no_eliminados); 

int main() 
{
  int casos; /* El numero de casos */
  int i, j, k; /* Contadores */
  scanf("%d", &casos);
  getchar();
  for(i = 0; i < casos; ++i){
    int candidatos; /* El numero de candidatos */
    int votantes = 0; /* El numero de votantes */
    int votos[1000][20]; /* Los votos*/
    char nombres[21][81]; /* Arreglo que contiene los nombres de los 
			   * candidatos */
    int no_eliminados[21]; /* Nos dice que candidatos no han sido eliminados */
    scanf("%d", &candidatos);
    for(j = 1; j <= candidatos; j++){
      scanf("%s", &nombres[j][0]);
      no_eliminados[j] = 1;
    }
    int c; /* El caracter actual escaneado */
    while(isdigit(c = getchar())){
      ungetc(c, stdin);
      for(j = 0; j < candidatos; j++)
	scanf("%d", &votos[votantes][j]);
      votantes++;
      getchar();
    }
    /* Hasta aqui solo hemos llenado arreglos */
  }
  return 0;
}
