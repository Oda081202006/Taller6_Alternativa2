#include <stdio.h>
#include <string.h>
#include "inventario_alt2.h"


void ingresarProductos(char nombres[][TAM_NOMBRE], float precios[], int total) {
    int i;

    for (i = 0; i < total; i++) {
        printf("\nProducto %d\n", i + 1);

        // Validar nombre SIN espacios
        int valido;
        do {
            valido = 1;
            printf("Nombre (sin espacios): ");
            scanf("%s", nombres[i]);

            if (strlen(nombres[i]) == 0) {
                printf("Error: el nombre no puede estar vacio.\n");
                valido = 0;
            }
        } while (!valido);

        // Validar precio mayor a 0
        do {
            printf("Precio: ");
            scanf("%f", &precios[i]);

            if (precios[i] <= 0) {
                printf("Error: el precio debe ser mayor que 0.\n");
            }
        } while (precios[i] <= 0);
    }
}

void procesarInventario(char nombres[][TAM_NOMBRE], float precios[], int total,
                        float *totalInv, float *promedio,
                        char nombreCaro[], float *precioCaro,
                        char nombreBarato[], float *precioBarato) {

    int i;
    *totalInv = 0;

    *precioCaro = precios[0];
    *precioBarato = precios[0];
    strcpy(nombreCaro, nombres[0]);
    strcpy(nombreBarato, nombres[0]);

    for (i = 0; i < total; i++) {
        *totalInv += precios[i];

        if (precios[i] > *precioCaro) {
            *precioCaro = precios[i];
            strcpy(nombreCaro, nombres[i]);
        }

        if (precios[i] < *precioBarato) {
            *precioBarato = precios[i];
            strcpy(nombreBarato, nombres[i]);
        }
    }

    *promedio = *totalInv / total;
}

void mostrarCatalogo(char nombres[][TAM_NOMBRE], float precios[], int total) {
    int i;
    printf("\n=== CATALOGO DE PRODUCTOS ===\n");

    for (i = 0; i < total; i++) {
        printf("%d) %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

int buscarProducto(char nombres[][TAM_NOMBRE], float precios[], int total, char buscado[]) {
    int i;
    for (i = 0; i < total; i++) {
        if (strcmp(nombres[i], buscado) == 0) {
            return i;
        }
    }
    return -1;
}
