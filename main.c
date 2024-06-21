#include <stdio.h>

// Función para calcular el saldo contable de un mes
float calcularSaldo(float saldoAnterior, float sueldo, float arriendo, float gastosLogistica, float gastosMercadeo, float gastosBasicos, float ingresoInversion, float ingresoVentas) {
    return saldoAnterior + ingresoVentas + ingresoInversion - sueldo - arriendo - gastosLogistica - gastosMercadeo - gastosBasicos;
}

int main() {
    float saldoAnterior = 0;
    float saldoActual;
    float sueldo, arriendo, gastosLogistica, gastosMercadeo, gastosBasicos, ingresoInversion, ingresoVentas;

    for (int mes = 1; mes <= 5; mes++) {
        printf("Mes %d\n", mes);

        // Solicitar los datos para el mes actual
        printf("Ingrese el gasto para sueldos: ");
        scanf("%f", &sueldo);
        printf("Ingrese el gasto para arriendos: ");
        scanf("%f", &arriendo);
        printf("Ingrese el gasto para logística: ");
        scanf("%f", &gastosLogistica);
        printf("Ingrese el gasto para mercadeo: ");
        scanf("%f", &gastosMercadeo);
        printf("Ingrese el gasto para servicios básicos: ");
        scanf("%f", &gastosBasicos);
        printf("Ingrese el ingreso por inversión: ");
        scanf("%f", &ingresoInversion);
        printf("Ingrese el ingreso por ventas: ");
        scanf("%f", &ingresoVentas);

        // Para el primer mes, el saldo anterior es 0
        if (mes != 1) {
            printf("Ingrese el saldo anterior: ");
            scanf("%f", &saldoAnterior);
        }

        saldoActual = calcularSaldo(saldoAnterior, sueldo, arriendo, gastosLogistica, gastosMercadeo, gastosBasicos, ingresoInversion, ingresoVentas);

        // Mostrar los detalles del balance del mes
        printf("\nDetalles del balance para el mes %d:\n", mes);
        printf("***********Gastos***********\n");
        printf("- Sueldos: %.2f\n", sueldo);
        printf("- Arriendos: %.2f\n", arriendo);
        printf("- Gastos de logística: %.2f\n", gastosLogistica);
        printf("- Gastos de mercadeo: %.2f\n", gastosMercadeo);
        printf("- Gastos de servicios básicos: %.2f\n", gastosBasicos);
        printf("***********Ingresos***********\n");
        printf("- Ingreso por inversión: %.2f\n", ingresoInversion);
        printf("- Ingreso por ventas: %.2f\n", ingresoVentas);
        printf("Saldo contable: %.2f\n\n", saldoActual);
    }

    return 0;
}