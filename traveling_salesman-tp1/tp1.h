
 #ifndef _TP1_H_
 #define _TP1_H_

//Tipo de dados para cada cidade
typedef struct{
    int code;
    int x;
    int y;
}city;

float aux;
float menor_custo;
int*melhor_visita;
int* vetor;

//indica o menor custo
float menor (int n, float v[]);

 // Imprime os elementos de um vetor
 void imprimir_vetor(int n,city vet[]);

//calcula o numero de ciclos gerados
 int num_ciclos(int n);

 //Troca os elementos de 2 cities
 void swap(city *a,city *b);

 //Gera todas as permutacoes dos valores dentro do vetor
 // No caso , sao as coordenadas dos pontos
 // Usa backtracking
 //PARTE 1
 // Nao deve imprimir rotas iguais que comecem por cidades diferenes
 //Ou seja , deve imprimir (n-1)! possibilidades.
 //Ex: para n=4 cidades, deve imprimir 3!(6) rotas
 //pois mesmo mudando o ponto inicial, as rotas seriam as mesmas
 float rotas_possiveis(city *cidade, int first, int last,FILE *f);

 // Calcula a distnacia entre dois pontos
float calcula_distancia(int x1,int x2, int y1, int y2);


 #endif  _TP1_H_
