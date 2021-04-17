#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca para inserir acentuação
#include <math.h> //Biblioteca matemática para possibilitar a função pow
#include <string.h> //Biblioteca para habilitar função strlen para saber o tamanho de uma string

void conversaoDecBin(int num_decimal); //Função de conversão de decimal para binário
void conversaoBinDec(char num_binario[64]); //Função de conversão de binário em decimal

//Declaração das variáveis globais
int num_decimal, bin_decimal, opcao, i, j;
int dec_binario[64];
char num_binario[64];

int main()
{
setlocale(LC_ALL, "Portuguese"); //Habilita acentuação

do{ //Laço de repetição do menu

    // MENU DA CALCULADORA
   printf("\tCALCULADORA DE CONVERSÃO ENTRE SISTEMAS OPERACIONAIS!\n");
   printf("\tESCOLHA A OPÇÃO DE CONVERSÃO:\n");
   printf("\nDigite [1] para converter um número Decimal em Binário;\n");
   printf("Digite [2] para converter um número Binário em Decimal; ou\n");
   printf("Digite [3] para sair.\n");
   printf("Opcão escolhida: ");
   scanf("%i", &opcao); //Armazena a variável OPCAO
   switch(opcao) { //Estrutura de seleção switch

       case 1: //Opção 1: conversão de decimal para binário
           printf("\nA opcão escolhida foi: %i - Conversão de número Decimal em Binário.\n", opcao);
           printf("\nDigite um número inteiro e positivo em Decimal:\n");
           scanf("%d", &num_decimal); //Armazena a variável num_decimal
           printf("Número Binário: \n");
           conversaoDecBin(num_decimal); //Chamada da função de conversão decimal-binário
           break;

       case 2: //Opção 2: conversão de binário para decimal
           printf("\nA opcão escolhida foi: %i - Conversão de número Binário em Decimal.\n", opcao);
           printf("\nDigite um número inteiro e positivo em Binário:\n");
           scanf("%s", &num_binario); //Armazena a variável num_binario
           conversaoBinDec(num_binario); //Chamada da função de conversão binário-decimal
           break;

       case 3: //Opção (restante) 3: sair da calculadora
           break;

       default: //Quando o usuário digitar um número não previsto
           printf("\nVocê digitou um valor inválido!");
           printf("\n\n\n");
   }

}

while (opcao!=3); //Sair da calculadora
    printf("\nClique em qualquer tecla para sair.");
    printf("\nAté a próxima!");
    printf("\n\n\n");
   return 0;
}

void conversaoDecBin (int num_decimal) //Função conversão decimal-binário
{
    int dec_binario[64], i=0;

if (num_decimal==0) { //Se o número decimal for igual a zero, o número binário também será.
    printf("%d", num_decimal);
    printf("\n\n\n");
    return;//Finaliza condição
    }
    else {
        while (num_decimal>0){ //Enquanto o número decimal for maior que zero...
           dec_binario[i] = num_decimal%2; // ...entra no laço de repetição, obtendo-se o valor do resto da divisão do número decimal por 2;
           num_decimal = num_decimal/2; // Divide-se o número decimal por 2, e inicia o próximo loop
           i++; //Incremento do contador do vetor
           }
        for (i=i-1; i>=0; i--){//Decremento do vetor do máximo a 0, possibilitando a impressão dos restos de trás para frente, formando o número binário
               printf("%d", dec_binario[i]);
            }
         printf("\n\n\n");
         return; //Finaliza loop
        }
}
void conversaoBinDec (char num_binario[64]) //Função conversão decimal-binário
{
    int bin_decimal=0, j=0;
    for (j=0; j<strlen(num_binario); j++)//Laço de repetição para validar apenas valores binários
    if(num_binario[j]!='1' && num_binario[j]!= '0') { //Se o número digitado for diferente de 1 e 0, imprime que o número não é binário na tela
        printf("Você não digitou um número Binário!\n\n\n");
        return; //Finaliza o laço
    }
    for (j=strlen(num_binario)-1; j>=0; j--) //Laço de repetição para obter o número em binário, analisando o da direita para a esquerda
        if (num_binario[j]=='1') //Quando houver o valor 1
        bin_decimal=bin_decimal+1*pow(2,strlen(num_binario)-1-j); //Efetua o cálculo
        printf("Número Decimal:\n%d\n\n\n", bin_decimal);
        return;
}
