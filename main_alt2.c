#include <stdio.h>
#include <string.h>
#include "inventario_alt2.h"

int main() {
    char nombres[MAX_PRODUCTOS][TAM_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int total, opcion;

    float totalInv, promedio;
    char nombreCaro[TAM_NOMBRE], nombreBarato[TAM_NOMBRE];
    float precioCaro, precioBarato;

    // Validar cantidad de productos
    do {
        printf("Ingrese la cantidad de productos (1-%d): ", MAX_PRODUCTOS);
        scanf("%d", &total);

        if (total < 1 || total > MAX_PRODUCTOS) {
            printf("Error: cantidad invalida. Intente otra vez.\n");
        }
    } while (total < 1 || total > MAX_PRODUCTOS);

    ingresarProductos(nombres, precios, total);

    procesarInventario(nombres, precios, total,
                       &totalInv, &promedio,
                       nombreCaro, &precioCaro,
                       nombreBarato, &precioBarato);

    // Menú con validación de opción
    do {
        printf("\n=== MENU (ALTERNATIVA 2) ===\n");
        printf("1. Ver catalogo\n");
        printf("2. Ver total del inventario\n");
        printf("3. Ver precio promedio\n");
        printf("4. Ver mas caro y mas barato\n");
        printf("5. Buscar producto por nombre\n");
        printf("0. Salir\n");

        // Validar opción
        do {
            printf("Opcion: ");
            scanf("%d", &opcion);

            if (opcion < 0 || opcion > 5) {
                printf("Error: opcion invalida. Intente nuevamente.\n");
            }
        } while (opcion < 0 || opcion > 5);

        // Acciones del menú
        if (opcion == 1) {
            mostrarCatalogo(nombres, precios, total);

        } else if (opcion == 2) {
            printf("Total del inventario: %.2f\n", totalInv);

        } else if (opcion == 3) {
            printf("Promedio de precios: %.2f\n", promedio);

        } else if (opcion == 4) {
            printf("Mas caro: %s ($%.2f)\n", nombreCaro, precioCaro);
            printf("Mas barato: %s ($%.2f)\n", nombreBarato, precioBarato);

        } else if (opcion == 5) {
            char buscado[TAM_NOMBRE];
            printf("Ingrese nombre a buscar: ");
            scanf("%s", buscado);

            int pos = buscarProducto(nombres, precios, total, buscado);

            if (pos == -1)
                printf("No encontrado.\n");
            else
                printf("Encontrado: %s - %.2f\n", nombres[pos], precios[pos]);
        }

    } while (opcion != 0);

    return 0;
}
