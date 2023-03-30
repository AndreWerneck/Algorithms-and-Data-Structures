// Copyright 2017 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// LISTA DE EXERCÍCIOS
//
// QUESTÃO 1: Implemente o TAD complexo abaixo, assumindo uma representação
// Euclidiana de números complexos. Compile e execute sua implementação
// junto com o arquivo main.c dado.
//
// QUESTÃO 2: Em seguida, Reescreva as funções do TAD assumindo uma
// representação polar. Compile e execute sua nova implementação
// junto com o arquivo main.c dado, e obeserve que não é necessário
// alterar em nada o arquivo main.c, apesar da implementação do TAD
// ser completamente diferente.
//
// QUESTÃO 3: Reescreva o arquivo main.c de forma que o programa leia do
// teclado três números reais a, b, e c e imprima na tela as raízes
// *complexas* da equação de segundo grau ax^2 + bx + c. Por exemplo as
// raízes da equação de segundo grau definida por a = 1, b = -5 e c = 6
// são "3 + 0i" e "2 + 0i". Compile, execute o seu programa, e observe que
// ele funciona para qualquer das duas implementações do TAD Complexo que
// você implementou nas questões anteriores.


Complexo ComplexoEuclidiano(double a, double b) {
  Complexo c;
    c.real=a;
    c.imag=b;
  return c;
}

double real(Complexo c) {
 return c.real;
}

double imag(Complexo c) {
  return c.imag;
}

double modulo(Complexo c) {

 return sqrt(pow(real(c),2)+ pow(imag(c),2)) ;
}

Complexo conjugado(Complexo c) {
  Complexo k;
   k.real=real(c);
   k.imag= -imag(c);
  return k;
}

Complexo simetrico(Complexo c) {
  Complexo s;
    s.real= -real(c);
    s.imag= -imag(c);
  return s;
}

// 1/(a + bi) = (a - bi)/(a^2 + b^2)
Complexo inverso(Complexo c) {
  Complexo i = ComplexoEuclidiano(real(c)/ (pow(modulo(c),2)), - imag(c)/ (pow(modulo(c),2)));

  return i;
}

Complexo Somar(Complexo x, Complexo y) {
  Complexo s;
    s.real= x.real + y.real;
    s.imag= x.imag + y.imag;
  return s;
}

Complexo Subtrair(Complexo x, Complexo y) {
  Complexo s;
    s.real= x.real - y.real;
    s.imag= x.imag - y.imag;
  return s;
}

Complexo Multiplicar(Complexo x, Complexo y) {
  Complexo p = ComplexoEuclidiano((real(x)*real(y)) - (imag(x)*imag(y)),(real(x)*imag(y))+(real(y)*imag(x)));
  return p;
}

Complexo Dividir(Complexo x, Complexo y) {
  Complexo p = Multiplicar(x,inverso(y));

  return p;
}
