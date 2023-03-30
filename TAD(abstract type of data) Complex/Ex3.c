#include "complexo.h"
#include "complexopolar.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416

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

int main ()
{
    int a,b,c;
    double delta,r1,r2,comp,x;
    Complexo d,e;

    printf("Digite a,b e c \n");
    scanf("%d%d%d",&a,&b,&c);

    delta=pow(b,2)-(4*a*c);

    r1= (-b + sqrt(delta))/(2*a);
    r2= (-b - sqrt(delta))/(2*a);
    x=(double)(-b)/(2*a);
    if(delta<0){
        delta=-delta;
        comp=sqrt(delta)/(2*a);
        d = ComplexoEuclidiano(x,comp);
        e = ComplexoEuclidiano(x,-comp);
        printf("As raizes sao :\n");
        Imprimir(d);
        Imprimir(e);

    }else{
        printf("%.2f + 0.00i e %.2f + 0.00i",r1,r2);
    }

    return 0;
}
