/* Nome: Lucas de Camargo Barros de Castro *
 * RA: 172678 *
 * Laboratorio: 06b */

#include <stdio.h>

int main () {
    
    int m, n, sala[100][100], i, j, gas = 2, tempo = 0, teste = 1;
    
    /* Le o tamanho m, n da sala */
    scanf("%d %d", &m, &n);
    
    /* Le as informacoes dos espacos da sala */
    for(i = 0; i < m; i++)
        
        for(j = 0; j < n; j++)
            scanf("%d", &sala[i][j]);
     
    /* O loop a seguir realiza uma volta a cada intervalo de tempo. O loop eh *
     * encerrado quando nao ocorrer propagacao de gas naquela volta. Toda volta *
     * do loop incrementa tempo e gas. Gas eh iniciado com 2, pois eh o valor *
     * recebido para posicoes com aspersores */    
    while (teste) {    
        
        /* Se o gas se propagou o teste sera verdadeiro ao fim do loop */
        teste = 0;
                
        /* Seleciona uma linha i do mapa da sala */
        for(i = 0; i < m; i++) {
            
            /* Seleciona uma coluna j do mapa da sala */
            for(j = 0; j < n; j++) {
            
                /* Se a posicao possui gas, verifica se ele pode se propagar *
                 * para alguma posicao. Caso isso ocorra, essa posicao recebe *
                 * o valor de gas + 1, assim ela soh sera testada para propagar *
                 * gas na proxima volta do loop */
                if(sala[i][j] == gas) {

                    /* Para a posicao (i - 1, j), sem passar numero minimo de * 
                     * linhas */
                    if ((sala[i - 1][j] == 0) && (i - 1 >= 0)) {
                        sala[i - 1][j] = gas + 1; 
                        teste++;
                    }
                
                    /* Para a posicao (i + 1, j), sem passar numero maximo de *
                     * linhas */
                    if((sala[i + 1][j] == 0) && (i + 1 < m)) {
                        sala[i + 1][j] = gas + 1;
                        teste++;
                    }
                
                    /* Para a posicao (i, j - 1), sem passar numero minimo de *
                     * colunas */
                    if((sala[i][j - 1] == 0) && (j - 1 >= 0)) {
                        sala[i][j - 1] = gas + 1;
                        teste++;
                    }
                    
                    /* Para a posicao (i, j + 1), sem passar numero maximo de *
                     * colunas*/
                    if((sala[i][j + 1] == 0) && (j + 1 < n)) {
                        sala[i][j + 1] = gas + 1;
                        teste++;
                    }
                }    
            }
        }
        
        /* Incrementa o tempo */
        tempo++;
        
        /* Incrementa o valor de gas para que as posicoes que receberam gas *
         * nessa volta sejam testadas na proxima volta */
        gas++;   
    }
 
    /* Zera a variavel de teste para o proximo teste */
    teste = 0;
    
    /* Os dois proximos loops selecionam uma posicao (i, j) da sala */
    for(i = 0; (i < m) && (teste == 0); i++) {
        
        for(j = 0; (j < n) && (teste == 0); j++) 
            
            /* Verifica se essa posicao esta vazia. Se sim, incrementa teste *
             * e o loop eh encerrado para nao fazer testes desnecessarios */
            if(sala[i][j] == 0) 
                teste++;
            
    }
    
    /* Caso o teste acima seja verdadeiro, imprime que os jedis podem estar *
     * vivos ! */
    if(teste)
        printf("Perigo: Jedis podem estar vivos\n");
    
    /* Caso contrario, imprime o tempo para eles serem eliminados */
    else
        printf("Tempo = %d\n", tempo);
    
    return 0;
    
}    