#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca para inserir acentua��o
#include <math.h> //Biblioteca matem�tica para possibilitar a fun��o pow
#include <string.h> //Biblioteca para habilitar fun��o strlen para saber o tamanho de uma string

void conversaoDecBin(int num_decimal); //Fun��o de convers�o de decimal para bin�rio
void conversaoBinDec(char num_binario[64]); //Fun��o de convers�o de bin�rio em decimal

//Declara��o das vari�veis globais
int num_decimal, bin_decimal, opcao, i, j;
int dec_binario[64];
char num_binario[64];

int main()
{
setlocale(LC_ALL, "Portuguese"); //Habilita acentua��o

do{ //La�o de repeti��o do menu

    // MENU DA CALCULADORA
   printf("\tCALCULADORA DE CONVERS�O ENTRE SISTEMAS OPERACIONAIS!\n");
   printf("\tESCOLHA A OP��O DE CONVERS�O:\n");
   printf("\nDigite [1] para converter um n�mero Decimal em Bin�rio;\n");
   printf("Digite [2] para converter um n�mero Bin�rio em Decimal; ou\n");
   printf("Digite [3] para sair.\n");
   printf("Opc�o escolhida: ");
   scanf("%i", &opcao); //Armazena a vari�vel OPCAO
   switch(opcao) { //Estrutura de sele��o switch

       case 1: //Op��o 1: convers�o de decimal para bin�rio
           printf("\nA opc�o escolhida foi: %i - Convers�o de n�mero Decimal em Bin�rio.\n", opcao);
           printf("\nDigite um n�mero inteiro e positivo em Decimal:\n");
           scanf("%d", &num_decimal); //Armazena a vari�vel num_decimal
           printf("N�mero Bin�rio: \n");
           conversaoDecBin(num_decimal); //Chamada da fun��o de convers�o decimal-bin�rio
           break;

       case 2: //Op��o 2: convers�o de bin�rio para decimal
           printf("\nA opc�o escolhida foi: %i - Convers�o de n�mero Bin�rio em Decimal.\n", opcao);
           printf("\nDigite um n�mero inteiro e positivo em Bin�rio:\n");
           scanf("%s", &num_binario); //Armazena a vari�vel num_binario
           conversaoBinDec(num_binario); //Chamada da fun��o de convers�o bin�rio-decimal
           break;

       case 3: //Op��o (restante) 3: sair da calculadora
           break;

       default: //Quando o usu�rio digitar um n�mero n�o previsto
           printf("\nVoc� digitou um valor inv�lido!");
           printf("\n\n\n");
   }

}

while (opcao!=3); //Sair da calculadora
    printf("\nClique em qualquer tecla para sair.");
    printf("\nAt� a pr�xima!");
    printf("\n\n\n");
   return 0;
}

void conversaoDecBin (int num_decimal) //Fun��o convers�o decimal-bin�rio
{
    int dec_binario[64], i=0;

if (num_decimal==0) { //Se o n�mero decimal for igual a zero, o n�mero bin�rio tamb�m ser�.
    printf("%d", num_decimal);
    printf("\n\n\n");
    return;//Finaliza condi��o
    }
    else {
        while (num_decimal>0){ //Enquanto o n�mero decimal for maior que zero...
           dec_binario[i] = num_decimal%2; // ...entra no la�o de repeti��o, obtendo-se o valor do resto da divis�o do n�mero decimal por 2;
           num_decimal = num_decimal/2; // Divide-se o n�mero decimal por 2, e inicia o pr�ximo loop
           i++; //Incremento do contador do vetor
           }
        for (i=i-1; i>=0; i--){//Decremento do vetor do m�ximo a 0, possibilitando a impress�o dos restos de tr�s para frente, formando o n�mero bin�rio
               printf("%d", dec_binario[i]);
            }
         printf("\n\n\n");
         return; //Finaliza loop
        }
}
void conversaoBinDec (char num_binario[64]) //Fun��o convers�o decimal-bin�rio
{
    int bin_decimal=0, j=0;
    for (j=0; j<strlen(num_binario); j++)//La�o de repeti��o para validar apenas valores bin�rios.
    if(num_binario[j]!='1' && num_binario[j]!= '0') { //Se o n�mero digitado for diferente de 1 e 0, imprime que o n�mero n�o � bin�rio na tela
        printf("Voc� n�o digitou um n�mero Bin�rio!\n\n\n");
        return; //Finaliza o la�o
    }
    for (j=strlen(num_binario)-1; j>=0; j--) //La�o de repeti��o para obter o n�mero em bin�rio, analisando o n�mero de tr�s para frente
        if (num_binario[j]=='1') //Quando houver o valor 1
        bin_decimal=bin_decimal+1*pow(2,strlen(num_binario)-1-j); //Efetua o c�lculo
        printf("N�mero Decimal:\n%d\n\n\n", bin_decimal);
        return;
}
