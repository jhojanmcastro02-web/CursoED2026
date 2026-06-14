/*
Autor: jhojan fernando castro hurtado
Programa: ingenieria de sistemas, estructuras de datos
Unidad 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int ordenado = 0; // 0 = no ordenado, 1 = ordenado

void mostrarMenu();
void registrarManual();
void generarAleatorios();
void mostrarContenedores();
void ordenarBurbuja();
void ordenarSeleccion();
void ordenarInsercion();
void buscarBinaria();

int main() {
    srand(time(NULL));
    int opcion;

    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: registrarManual(); break;
            case 2: generarAleatorios(); break;
            case 3: mostrarContenedores(); break;
            case 4: ordenarBurbuja(); break;
            case 5: ordenarSeleccion(); break;
            case 6: ordenarInsercion(); break;
            case 7: buscarBinaria(); break;
            case 8: printf("Saliendo del sistema...\n"); break;
            default: printf("Opcion invalida, intente nuevamente.\n");
        }
        printf("\n----------------------------------------\n");
    } while(opcion != 8);

    return 0;
}

void mostrarMenu() {
    printf("\n=== SISTEMA DE ORGANIZACION DE CONTENEDORES ===\n");
    printf("MUELLE DE CARGA\n");
    printf("1. Registrar peso de contenedores manualmente\n");
    printf("2. Generar pesos aleatorios de contenedores\n");
    printf("3. Mostrar contenedores registrados\n");
    printf("4. Ordenar contenedores - Metodo Burbuja\n");
    printf("5. Ordenar contenedores - Metodo Seleccion\n");
    printf("6. Ordenar contenedores - Metodo Insercion\n");
    printf("7. Buscar contenedor por peso\n");
    printf("8. Salir\n");
}

void registrarManual() {
    if (cantidad >= MAX_CONTENEDORES) {
        printf("Capacidad maxima de 30 contenedores alcanzada.\n");
        return;
    }
    printf("Ingrese el peso en kilogramos: ");
    scanf("%d", &pesos[cantidad]);
    cantidad++;
    ordenado = 0;
    printf("Contenedor registrado correctamente.\n");
}

void generarAleatorios() {
    int n;
    printf("Cuantos contenedores desea generar (max 30): ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_CONTENEDORES) {
        printf("Cantidad no permitida.\n");
        return;
    }
    cantidad = n;
    for (int i = 0; i < cantidad; i++) {
        pesos[i] = 100 + rand() % 29901; // Rango 100 a 30000 kg
    }
    ordenado = 0;
    printf("Pesos generados exitosamente.\n");
}

void mostrarContenedores() {
    if (cantidad == 0) {
        printf("No hay contenedores registrados.\n");
        return;
    }
    printf("\nLista de contenedores (%d):\n", cantidad);
    for (int i = 0; i < cantidad; i++) {
        printf("Posicion %d: %d kg\n", i + 1, pesos[i]);
    }
}

void ordenarBurbuja() {
    int aux, cambio;
    for (int i = 0; i < cantidad - 1; i++) {
        cambio = 0;
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (pesos[j] > pesos[j + 1]) {
                aux = pesos[j];
                pesos[j] = pesos[j + 1];
                pesos[j + 1] = aux;
                cambio = 1;
            }
        }
        if (cambio == 0) break;
    }
    ordenado = 1;
    printf("Ordenado con metodo Burbuja.\n");
}

void ordenarSeleccion() {
    int posMenor, aux;
    for (int i = 0; i < cantidad - 1; i++) {
        posMenor = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (pesos[j] < pesos[posMenor]) {
                posMenor = j;
            }
        }
        if (posMenor != i) {
            aux = pesos[i];
            pesos[i] = pesos[posMenor];
            pesos[posMenor] = aux;
        }
    }
    ordenado = 1;
    printf("Ordenado con metodo Seleccion.\n");
}

void ordenarInsercion() {
    int actual, j;
    for (int i = 1; i < cantidad; i++) {
        actual = pesos[i];
        j = i - 1;
        while (j >= 0 && pesos[j] > actual) {
            pesos[j + 1] = pesos[j];
            j--;
        }
        pesos[j + 1] = actual;
    }
    ordenado = 1;
    printf("Ordenado con metodo Insercion.\n");
}

void buscarBinaria() {
    if (cantidad == 0) {
        printf("No hay datos para buscar.\n");
        return;
    }
    if (ordenado == 0) {
        printf("Debe ordenar la lista primero para buscar.\n");
        return;
    }
    int valor, inicio = 0, fin = cantidad - 1, medio, encontrado = -1;
    printf("Ingrese el peso a buscar: ");
    scanf("%d", &valor);

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (pesos[medio] == valor) {
            encontrado = medio;
            break;
        } else if (pesos[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (encontrado != -1)
        printf("Peso %d kg encontrado en la posicion %d\n", valor, encontrado + 1);
    else
        printf("Peso %d kg no se encuentra en la lista.\n", valor);
}