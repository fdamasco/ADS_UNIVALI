#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Biblioteca para inserir acentua��o
#include <math.h> //Biblioteca para fun��o pow

int main()
{
setlocale(LC_ALL, "Portuguese"); //Habilita acentua��o
//VARI�VEIS GLOBAIS:
int num_decimal, num_binario, opcao, resto, bin_dec=0; //Declara��o de vari�veis
int dec_bin[64]; //Vetor referente ao n�mero bin�rio em 64 bits
int i=0; //Contador do vetor dec_bin[]
int j=0; // Vari�vel do contador da pot�ncia de 2

do{

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
           printf("\nDigite um n�mero em Decimal:\n");
           printf("\nN�mero Decimal: ");
           scanf("%d", &num_decimal); //Armazena a vari�vel NUM_DECIMAL
           printf("\nN�mero Bin�rio: ");
           while (num_decimal != 0){ //Enquanto o n�mero decimal digitado for diferente de zero...
           dec_bin[i] = num_decimal%2; // ...entra no la�o de repeti��o, imprimindo o valor do resto do n�mero decimal por 2.
           num_decimal = num_decimal/2; // Divide o n�mero decimal por 2, e inicia o pr�ximo loop
           i++; //Incremento do contador do vetor
           }
           while (i--){//Decremento do vetor do m�ximo a 0
            printf("%d", dec_bin[i]); //Imprime os restos de tr�s para frente, formando o n�mero bin�rio
            }
           if (num_decimal=0) // Se o n�mero decimal for igual a zero, o bin�rio tamb�m ser�.
            printf("\nResultado: %d", num_decimal);
            printf("\n\n\n");
           break;

       case 2: //Op��o 2: convers�o de bin�rio para decimal
           printf("\nA opc�o escolhida foi: %i - Convers�o de n�mero Bin�rio em Decimal.\n", opcao);
           printf("\nDigite um n�mero em Bin�rio:\n");
           printf("\nN�mero Bin�rio: ");
           scanf("%i", &num_binario); //Armazena a vari�vel NUM_BINARIO
           printf("\nN�mero Decimal: ");
           while (num_binario !=0){//Enquanto o n�mero bin�rio for diferente de 0
               resto=num_binario%10;
               bin_dec=bin_dec+resto*pow(2,j);
               j++;
               num_binario = num_binario/10;
           }
            printf("%i", bin_dec);
            if (num_binario=0) // Se o n�mero bin�rio informado for igual a zero, o bin�rio tamb�m ser�.
            printf("%d", bin_dec);
            printf("\n\n\n");
           break;
       case 3: //Op��o (restante) 3: sair da calculadora
           break;
       default: //Quando o usu�rio digitar um n�mero n�o previsto
           printf("\nVoc� digitou um valor inv�lido");
           printf("\n\n\n");
   }

} while (opcao!=3);
    printf("\nClique em qualquer tecla para sair.");
    printf("\nAt� a pr�xima!");
    printf("\n\n\n");

   return 0;
}

