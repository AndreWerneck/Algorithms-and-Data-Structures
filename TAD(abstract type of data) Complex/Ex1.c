#include "complexo.h"

#include <stdio.h>
#include <stdlib.h>


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
