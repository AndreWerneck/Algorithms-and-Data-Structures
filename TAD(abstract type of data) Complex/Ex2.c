#include "complexo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

Complexo ComplexoEuclidiano(double a, double b) {
  Complexo c;
    c.mod= sqrt(pow(a,2)+ pow(b,2));
    c.arg= atan2(b,a);
  return c;
}

double real(Complexo c) {
 return c.mod*cos(c.arg);
}

double imag(Complexo c) {
  return c.mod*sin(c.arg);
}

double modulo(Complexo c) {
 return c.mod;
}

Complexo conjugado(Complexo c) {
  Complexo k;
   k.mod=c.mod;
   k.arg=-(c.arg);
  return k;
}

Complexo simetrico(Complexo c) {
  Complexo s;
   s.mod=c.mod;
   s.arg=c.arg + PI;
  return s;
}

// 1/(a + bi) = (a - bi)/(a^2 + b^2)
Complexo inverso(Complexo c) {
  Complexo i;
    i.mod=1/c.mod;
    i.arg=-(c.arg);
  return i;
}

Complexo Somar(Complexo x, Complexo y) {
  Complexo s=ComplexoEuclidiano(real(x)+real(y),imag(x)+imag(y));
  return s;
}

Complexo Subtrair(Complexo x, Complexo y) {
  Complexo s=ComplexoEuclidiano(real(x)-real(y),imag(x)-imag(y));
  return s;
}

Complexo Multiplicar(Complexo x, Complexo y) {
  Complexo p;
  p.mod=x.mod*y.mod;
  p.arg=x.arg+y.arg;
  return p;
}

Complexo Dividir(Complexo x, Complexo y) {
  Complexo p;
  p.mod=x.mod/y.mod;
  p.arg=x.arg-y.arg;
  return p;
}

void Imprimir(Complexo c) {
 printf("%.2f + %.2fi\n", real(c), imag(c));
}

int main() {
  Complexo a = ComplexoEuclidiano(1.0, 2.0);
  Complexo b = ComplexoEuclidiano(3.0, 4.0);
  Complexo soma = Somar(a, b);
  Complexo sub = Subtrair(a, b);
  Complexo multi = Multiplicar(a, b);
  Complexo div = Dividir(a, b);

  printf("a + b = ");
  Imprimir(soma);
  printf("a - b = ");
  Imprimir(sub);
  printf("a * b = ");
  Imprimir(multi);
  printf("a / b = ");
  Imprimir(div);
  return 0;
}
