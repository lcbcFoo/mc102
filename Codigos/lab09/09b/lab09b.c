/* Nome: Lucas de Camargo Barros de Castro *
 * RA: 172678 *
 * Laboratorio: 09b */


#include <stdio.h>
#include <stdlib.h>

/* Calcula as medias dos jogadores e as armazena em um vetor auxiliar */
void calcula_medias(double * media, double ** notas, int n){

    int i, j;

    /* Seleciona um jogador, calcula sua media e a armazena na posicao *
     * correta do vetor "media" */
    for(i = 0; i < n; i++){
        media[i] = 0;

        for(j = 0; j < n; j++)
            media[i] +=  notas[j][i];

        media[i] = media[i] / n;
    }
}

int main() {

    int n, t, i, j, k, *times, count, jogador;
    double **notas, *media, aux;

    /* Recebe numero de jogadores e de times a serem formados */
    scanf("%d %d", &n, &t);

    /* Aloca a matriz onde serao armazenadas as notas dos jogadores */
    notas = malloc(n * sizeof(double *));
    
    for(i = 0; i < n; i++)
        notas[i] = malloc(n * sizeof(double));

    /* Aloca o vetor auxiliar "media", onde sao guardadas as medias, e o *
     * "times", onde serao guardados os times formados e seus respectivos *
     * jogadores */
    media = malloc(n * sizeof(double));
    times = malloc(n * sizeof(int));

    /* Recebe as notas */
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%lf", &notas[i][j]);

    /* Chama a funcao que calcula as medias */
    calcula_medias(media, notas, n);

    /* Ao longo do programa, quando um jogador for escolhido, sua media *
     * sera mudada para '- 1' como uma flag de que ele ja tem time */

    /* Cada volta do loop seleciona um capitao */
    for(i = 0; i < t; i++){
        aux = - 1;

        /* Verifica qual jogador eh o proximo capitao */
        for(j = 0; j < n; j++){
            if(media[j] > aux) {
                aux = media[j];
                jogador = j;
                
            }
        }

        /* Armazena na posicao correta do vetor "times" o capitao *
         * selecionado de acordo com a ordem que eles vao escolher seus *
         * jogadores */
        times[i * n / t] = jogador;
        media[jogador] = - 1;
    }

    count = 0;

    /* Cada volta do loop seleciona um jogador para cada time */
    while(count < (n / t) - 1){

        /* Seleciona qual capitao ira escolher */
        for(i = 0; i < t; i++){
            j = times[i * n / t];
            aux = - 1;

            /* Verifica qual jogador recebeu a maior nota desse capitao e *
             * ainda nao foi escolhido */
            for(k = 0; k < n; k++){

                if((notas[j][k] > aux) && (media[k] >= 0)) {
                    aux = notas[j][k];
                    jogador = k;
                }
            }

            /* Armazena esse jogador na posicao correta do vetor "times" *
             * de acordo com o capitao que o escolheu */
            times[(i * n / t) + count + 1] = jogador;
            media[jogador] = - 1;
        }

        count++;
    }

    /* Cada volta do loop ira imprimir o numero do time e seus jogadores */
    for(i = 0; i < t; i++){
        printf("Time %d:", i + 1);

        for(j = i * n / t; j < (i + 1) * n / t; j++)
            printf(" %d", times[j] + 1);

        printf("\n");
    }    
    
    return 0;
}
