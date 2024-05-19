#include <stdio.h>
#include <omp.h>

// Función de multiplicación utilizando sumas (OpenMP)
float multiplicacion(float num1, float num2) {
    float resultado = 0;
    #pragma omp parallel for reduction(+:resultado)
    for (int i = 0; i < num2; i++) {
        resultado += num1;
    }
    return resultado;
}

// Función de división utilizando restas (OpenMP)
float division(float num1, float num2) {
    float resultado = 0;
    #pragma omp parallel
    {
        float residuo = num1;
        #pragma omp for
        for (int i = 0; residuo >= num2; i++) {
            resultado++;
            residuo -= num2;
        }
        #pragma omp single
        {
            // Ajustamos el resultado para incluir los decimales
            if (residuo > 0) {
                resultado += residuo / num2;
            }
        }
    }
    return resultado;
}

int main() {
    float a ;
    float b ;
    printf("Ingrese un numero: ");
    scanf("%f",&a);
    printf("Ingrese un numero: ");
    scanf("%f",&b);
    printf("Multiplicación: %.2f\n", multiplicacion(a, b));
    printf("División: %.2f\n", division(a, b));

    return 0;
}
