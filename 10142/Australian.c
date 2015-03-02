/* Resuelve el problema "Australian Voting" (UVA ID = 10142), utilizando 
 * arreglos */
#include <stdio.h>
#include <ctype.h>

int main() 
{
  int casos; /* El numero de casos */
  int i, j, k, l; /* Contadores */
  scanf("%d", &casos);
  getchar();
  getchar();
  for(i = 0; i < casos; ++i){
    if(i > 0)
      putchar('\n');
    int candidatos; /* El numero de candidatos */
    int votantes = 0; /* El numero de votantes */
    int votos[1000][20]; /* Los votos*/
    char nombres[21][81]; /* Arreglo que contiene los nombres de los 
			   * candidatos */
    for(j = 1; j < 21; ++j)
      for(k = 0; k < 81; ++k)
	nombres[j][k] = '\0';
    int d; /* Caracter actual del nombre */
    int no_eliminados[21]; /* Nos dice que candidatos no han sido eliminados */
    int puntuacion[21]; /* Las puntuaciones */
    int mayor, menor; /* El mayor y menor numero de votos */
    int numayores, numenores; /* El numero de personas con el mayor y menor
			       * numero de votos (respectivamente) */
    int ganadores[20];/* Los ganadores */
    int perdedores[20]; /* Los perdedores */
    scanf("%d", &candidatos);
    getchar();
    for(j = 1; j < (candidatos + 1); j++){
      k = 0;
      while((d = getchar()) != '\n')
	nombres[j][k++] = d;
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
    int m = 0;
    while(1){
      for(j = 1; j < 21; ++j)
	puntuacion[j] = 0;
      m++;
      for(j = 0; j < 20; ++j)
	ganadores[j] = perdedores[j] = 0;
      /* Se actualizan las puntuaciones */
      for(j = 0; j < votantes; ++j){
	k = 0;
	while(!no_eliminados[votos[j][k]])
	  k++;
	puntuacion[votos[j][k]]++;
	printf("La puntuacion de %d es: %d\n", votos[j][k], puntuacion[votos[j][k]]);
      }
      /* Se llenan arreglos de ganadores y perdedores */
      mayor = numayores = numenores = 0;
      menor = 1001;
      for(j = 1; j <= candidatos; ++j){
	if(puntuacion[j] > mayor){
	  mayor = puntuacion[j];
	  numayores = 0;
	  ganadores[numayores++] = j;
	}else if(puntuacion[j] == mayor)
	  ganadores[numayores++] = j;
	if(puntuacion[j] < menor){
	  menor = puntuacion[j];
	  numenores = 0;
	  perdedores[numenores++] = j;
	}else if(puntuacion[j] == menor)
	  perdedores[numenores++] = j;
      }
      if(((mayor * 2) > votantes) || (mayor == menor))
	break;
      else{
	  for(j = 0; j < numenores; ++j)
	    no_eliminados[perdedores[j]] = 0;
      }
    }
    for(j = 0; j < numayores; ++j){
      printf("%s\n", &nombres[ganadores[j]][0]);
    }
  }
  return 0;
}
