#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define BIAS 1023;

typedef struct numberIeee{
    int exp;
    double mantissa;

} IeeeNumero;

IeeeNumero Converte(IeeeNumero *ieee, double num){
    ieee->exp = floor(log2(num));
    ieee->mantissa = num / pow (2, ieee->exp) -1.0;
}

double kyuubi(double mantissa,int exp){
    double erro = 0.000000000000001;
    bool impar = 0;
    if (!(exp%2 == 0)){
        impar = true;
        exp--;
    }

    mantissa += 1.0;
    double f = mantissa;
    double g = 0.0;
    exp /= 2;

    do
    {
        g = f;
        f = g + (mantissa - (g * g))/ (2*g);
        printf("\n[g] : %.20lf \t [f] : %.20lf ", g, f);
    } while (fabs(f - g) > erro);

    printf("\n exp : %d\n", exp);

    if(impar) return(f * sqrt(2));
    return f;
}


int main() {
    IeeeNumero numI3e;
    double resultado, num10;

    num10 = 49.0;
    Converte(&numI3e, num10);
    printf("%.20lf\n", kyuubi(numI3e.mantissa, numI3e.exp));
}