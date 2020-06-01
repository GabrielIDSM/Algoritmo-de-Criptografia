#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoesenigma.h"

//Rotores Start
    char R0[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char R1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    char R2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    char R3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    char R4[] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    char R5[] = "VZBRGITYUPSDNHLXAWMJQOFECK"; 
//End

//Refletor Start

    char refB[13][2] = {{'Y', 'R'},{'U', 'H'},{'Q', 'S'},{'L', 'D'},{'P', 'X'},{'N', 'G'},{'O', 'K'},
                        {'M', 'I'}, {'E', 'B'},{'F', 'Z'},{'C', 'W'},{'V', 'J'},{'A', 'T'}};   
   
//Refletor End

void ordena(int chave, char vetor[], char vetord[])
{
    int i;
    char auxa[26+chave+1], auxb[26+1];
    for(i=0;i<26;i++)
    {
        auxa[i] = vetor[i];
    }
    for(i=0;i<chave;i++)
    {
        auxa[26+i] = vetor[i];
    }
    for(i=0;i<26;i++)
    {
        vetord[i] = auxa[(chave-1)+i];             
    }
    return;        
}
void prepararotor(int ch ,int rot , char dest[])
{
    if(rot == 1) 
    {
        ordena(ch, R1, dest);
    }
    else if(rot == 2) 
    {
        ordena(ch, R2, dest);
    }
    else if(rot == 3) 
    {
        ordena(ch, R3, dest);
    }
    else if(rot == 4) 
    {
        ordena(ch, R4, dest);
    }
    else 
    {
        ordena(ch, R5, dest);
    }
    return;
} 
void preparastring(int tam, char mensagem[])
{
    int i;
    for(i=0;i<tam;i++)
    {        
        mensagem[i] = toupper(mensagem[i]);
    }        
    return;
}
char cifragem(char l, char origem[], char destino[])
{
    int i;
    for(i=0;i<26;i++)
    {
        if(origem[i]==l) 
        {
            l = destino[i];
            //printf("Origem: %c -",origem[i]);
            //printf("Destino: %c \n\n",destino[i]);
            break;            
        }     
    }
    return(l);        
}
void funcionamento(char mensagem[], int ndel, int rot1, int rot2, int rot3, char U1_[], char U2_[], char U3_[])
{
    int i, cont2 = 0, cont3 = 0;
    for(i=0;i<ndel;i++)
    {        
            char l;
            l = mensagem[i];
          //printf("%c\n",l);
            l = cifragem(l,R0,U1_);
          //printf("%c\n",l);
            l = cifragem(l,R0,U2_);
          //printf("%c\n",l);          
            l = cifragem(l,R0,U3_);
          //printf("%c\n",l);
            //refletor start            
            int a;            
            for(a=0;a<13;a++)
            {
                if(refB[a][0]==l)
                {
                    l = refB[a][1];
                    break;
                }
                if(refB[a][1]==l)
                {
                    l = refB[a][0];
                    break;
                }
            }                       
            //refletor end        
            l = cifragem(l,U3_,R0);
          //printf("%c\n",l);
            l = cifragem(l,U2_,R0);
          //printf("%c\n",l);
            l = cifragem(l,U1_,R0);
          //printf("%c>>\n",l);
            //Giro do rotor
            ordena(2,U1_,U1_);
            cont2++;
            if(cont2==26)
            {
                ordena(2,U2_,U2_);
                cont2 = 0;
                cont3++;
                if(cont3==26)
                {   
                    ordena(2,U3_,U3_);
                    cont3 = 0;                      
                }
            }
            printf("%c",l);
        
    }
}