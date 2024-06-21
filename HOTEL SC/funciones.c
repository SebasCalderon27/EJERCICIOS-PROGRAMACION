#include <stdio.h>
#include <string.h>
#include "funciones.h"

void buscarPorTamano(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char tipo[40];
    printf("Ingrese el tipo de habitacion que busca(simple, doble, triple): ");
    scanf("%s", tipo);

    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tipo) == 0) {
            printf("Habitacion %s: %s - %s, Precio: %.2f\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }

    printf("Seleccione el numero de habitacion que desea: ");
    scanf("%d", numHabitacion);
}

void buscarHotel(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char hotel[40];
    printf("Ingrese el nombre del hotel que esta interesado: ");
    scanf("%s", hotel);

    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("Habitacion %s: %s - %s, Precio: %.2f\n", habitaciones[i][0], habitaciones[i][1], habitaciones[i][2], precios[i]);
        }
    }

    printf("Seleccione el numero de habitacion que desea: ");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[5][2][40], int reservas[10][4]) {
    char nombre[40], cedula[40];
    int clienteIndex = -1;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su N° cedula: ");
    scanf("%s", cedula);

    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], "") == 0) {
            strcpy(clientes[i][0], nombre);
            strcpy(clientes[i][1], cedula);
            clienteIndex = i;
            break;
        }
    }

    if (clienteIndex != -1) {
        for (int i = 0; i < 10; i++) {
            if (reservas[i][3] == 0) {
                reservas[i][0] = clienteIndex;
                reservas[i][1] = numHabitacion - 1;
                reservas[i][2] = 0;
                reservas[i][3] = 1;
                printf("Su reserva se realizo con exito\n");
                return;
            }
        }
    } else {
        printf("Hubo un error: No se puede realizar la reserva.\n");
    }
}

void buscarReservaPorCedula(int *numReserva, char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese su N° cedula: ");
    scanf("%s", cedula);

    for (int i = 0; i < 10; i++) {
        if (reservas[i][3] == 1 && strcmp(clientes[reservas[i][0]][1], cedula) == 0) {
            *numReserva = i;
            return;
        }
    }

    *numReserva = -1;
    printf("Su reserva no se encontro\n");
}

void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    if (numReserva != -1) {
        int habitacionIndex = reservas[numReserva][1];
        printf("Reserva %d: Habitacion %s - %s, %s, Precio: %.2f\n", numReserva, habitaciones[habitacionIndex][0], habitaciones[habitacionIndex][1], habitaciones[habitacionIndex][2], precios[habitacionIndex]);
    } else {
        printf("No hay una reserva para imprimir\n");
    }
}

void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    if (numReserva != -1) {
        reservas[numReserva][2] = 1;
        printf("Su reserva fue pagada con exito\n");
    } else {
        printf("No hay reserva realizada para pagar\n");
    }
}
