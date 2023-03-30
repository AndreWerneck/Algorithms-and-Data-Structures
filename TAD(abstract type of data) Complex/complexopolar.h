// Copyright 2015 Universidade Federal de Minas Gerais (UFMG)

#ifndef COMPLEXOPOLAR_H_
#define COMPLEXOPOLAR_H_

// Representação Polar de um número complexo.
typedef struct  {
  double mod;  // modulo.
  double arg;  // argumento.
} Complexo;

// Cria o número complexo a + bi.
Complexo ComplexoEuclidiano(double a, double b);

// Retorna a parte real de c.
double real(Complexo c);

// Retorna a parte imaginária de c.
double imag(Complexo c);

// Retorna o módulo de c.
double modulo(Complexo c);

// Retorna o conjugado de c.
Complexo conjugado(Complexo c);

// Retorna o simétrico de c.
Complexo simetrico(Complexo c);

// Retorna o inverso multiplicativo de c.
Complexo inverso(Complexo c);

// Retorna x + y.
Complexo Somar(Complexo x, Complexo y);

// Retorna x - y.
Complexo Subtrair(Complexo x, Complexo y);

// Retorna x * y.
Complexo Multiplicar(Complexo x, Complexo y);

// Retorna x / y.
Complexo Dividir(Complexo x, Complexo y);

#endif  // COMPLEXOPOLAR_H_
