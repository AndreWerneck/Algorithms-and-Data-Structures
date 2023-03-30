#include <stdio.h>
#include <stdlib.h>

/*int detec(int v[],int n)
{
    int j,i,cont;

    cont=0;
    j=1;

    for(i=0; i<n; i++){

        if(v[i]==v[j]){
            cont++;
           }
        j++;
        }
        if(cont>=(n/2)){
            return cont;
        }else{
        cont =0;}
        printf("\n");
    }

}
*/


int main()
{
    int tam;
    printf("Digite o tamanha do vetor: ");
    scanf("%d",&tam);
    int vetor[tam];
    printf("Digite os valores do vetor: ");
    for (int i =0;i<tam;i++) {
        scanf("%d",&vetor[i]);}
int temp;
int repetidos = 1;

//Verificando numeros repetidos
temp = vetor[0]; // Primeiro valor não entra na varredura
for (int i =1;i<tam;i++) {
    if( vetor[i] == temp ){
        repetidos++; // Enquanto tiverem valores iguais em sequencia, incrementa este contador
    }
    else {
     // Se deu valor diferente do anterior, verifica se teve repetições
        if( repetidos >= tam/2 ) {
            printf("O valor %i esta repetido %i vezes\n", temp, repetidos);
            repetidos = 1;
        }
        // E atualiza este valor de comparação
        temp = vetor[i];
    }
}
// Fim do loop, mas ainda não testamos se o último valor do vetor é repetido ou não, então...
if( repetidos >= tam/2 ) {
    printf("O valor %i esta repetido %i vezes\n", temp, repetidos);
}
}
