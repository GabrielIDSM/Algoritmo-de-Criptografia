#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoesenigma.h"

char U1[27], U2[27], U3[27]; 

int main()
{
    int rot1, rot2, rot3;
    int ch1, ch2, ch3;
    int ndeletras;
    //input das chaves
    printf("Insira o valor das 3 chaves(valores de 1 a 26)(ex:2 10 18): ");
    scanf("%d %d %d",&ch1,&ch2,&ch3);
        //getchar();
    //printf("\n\n");
    //input dos rotores
    printf("Insira o numero correspondente aos rotores (valor de 1 a 5) (ex:3 4 1): ");
    scanf("%d %d %d",&rot1,&rot2,&rot3);
        //getchar();
    //printf("\n\n");      
    //preparaçao dos rotores
    prepararotor(ch1 ,rot1 ,U1);
    prepararotor(ch2 ,rot2 ,U2);
    prepararotor(ch3 ,rot3 ,U3);    
    //frase que será criptografada
    printf("Quantas caracteres tem na mensagem a ser criptografada?(espacos nao contam): ");
    scanf("%d",&ndeletras);
    char mensagem[ndeletras+1];  
    printf("Insira a mensagem a ser criptografada(sem espacos): ");
    scanf("%s",&mensagem);
    preparastring(ndeletras, mensagem);
    printf("Cript: ");
    funcionamento(mensagem, ndeletras, rot1, rot2, rot3, U1, U2, U3);
        //getchar(); 
    printf("\n");
    system("PAUSE");
    return 0;
}