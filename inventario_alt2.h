#ifndef INVENTARIO_ALT2_H
#define INVENTARIO_ALT2_H

#define MAX_PRODUCTOS 10
#define TAM_NOMBRE 30


void ingresarProductos(char nombres[][TAM_NOMBRE], float precios[], int total);

void procesarInventario(char nombres[][TAM_NOMBRE], float precios[], int total,
                        float *totalInv, float *promedio,
                        char nombreCaro[], float *precioCaro,
                        char nombreBarato[], float *precioBarato);

void mostrarCatalogo(char nombres[][TAM_NOMBRE], float precios[], int total);

int buscarProducto(char nombres[][TAM_NOMBRE], float precios[], int total, char buscado[]);

#endif
