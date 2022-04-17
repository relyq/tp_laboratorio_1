/**
 * @file
 * @author  Nicolas Mainenti <NicolasAMainenti@gmail.com>
 * @version 1.0
 *
 *
 * @section DESCRIPTION
 *
 * trabajo practico 1 laboratorio
 */
#include <stdbool.h>
#include <stdio.h>

#include "src/tp1.h"

// deberia ser un enum whatever
#define INGRESAR_KM 1
#define INGRESAR_PRECIO 2
#define CALCULAR_COSTOS 3
#define INFORMAR_RESULTADOS 4
#define CARGA_FORZADA 5
#define SALIR 6

int main(void) {
	setbuf(stdout, NULL);
  // el vuelo comercial mas largo es de 16618km
  // la circumferencia de la tierra es de 40075km
  unsigned int km = 0;
  bool km_ingresado = false;

  // el vuelo más caro del mundo es new york-abu dhabi con costo alrededor de
  // us$64,000 o ar$12800000
  unsigned long precio_aerolineas = 0;
  unsigned long precio_latam = 0;
  bool precio_ingresado = false;

  float precio_aerolineas_debito = 0;
  float precio_aerolineas_credito = 0;
  float precio_aerolineas_btc = 0;
  float precio_aerolineas_unitario = 0;

  float precio_latam_debito = 0;
  float precio_latam_credito = 0;
  float precio_latam_btc = 0;
  float precio_latam_unitario = 0;

  bool costo_calculado = false;

  // no me parece correcto que km y precios tengan que tener signo si no
  // deberian ser negativos. como tengo que usar scanf() que no tiene proteccion
  // contra overflow voy a usar un buffer para hacer error handling la forma
  // correcta seria usar fgets() para pedir input y strtoll() para interpretar
  // como int
  long long buffer = 0;

  int err;

  do {
    printf(
        "\n1. Ingresar Kilometros: ( km=%u)\n"
        "2. Ingresar Precio de Vuelos: (Aerolineas=%lu, Latam=%lu)\n"
        "3. Calcular todos los costos: \n"
        "\ta) Tarjeta de debito (descuento 10%%)\n"
        "\tb) Tarjeta de credito (interes 25%%)\n"
        "\tc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
        "\td) Mostrar precio por km (precio unitario)\n"
        "\te) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n"
        "4. Informar Resultados\n"
        "5. Carga forzada de datos\n"
        "6. Salir\n",
        km_ingresado ? km : 0, precio_ingresado ? precio_aerolineas : 0,
        precio_ingresado ? precio_latam : 0);

    do {
      printf("Ingresar opcion: ");
      fflush(stdin);
      err = scanf("%d", (int*)&buffer);
    } while (err == 0 || err == EOF ||
             (buffer < INGRESAR_KM || buffer > SALIR));

    int menu_input = buffer;

    switch (menu_input) {
      case INGRESAR_KM: {
        do {
          printf("\nIngresar Kilometros: ");

          fflush(stdin);
          err = scanf("%I64d", &buffer);
        } while (err == 0 || err == EOF || buffer < 1);
        // el vuelo más corto del mundo es westray-papa westray con 1.7 millas
        // o 2.73588km. voy a dejar el minimo como 1 de todas formas

        km = buffer;
        km_ingresado = true;

        // si cambiaron los km hay que calcular de vuelta
        costo_calculado = false;
        break;
      }
      case INGRESAR_PRECIO: {
        // el vuelo más barato sin descuentos es warsaw-brussels de ryanair a
        // us$11 o
        // alrededor de ar$2200. otra vez voy a dejarlo con minimo de $1 de
        // todas formas
        printf("Ingresar Precio de Vuelos: \n");
        do {
          printf("- Precio vuelo Aerolineas: ");

          fflush(stdin);
          err = scanf("%I64d", &buffer);
        } while (err == 0 || err == EOF || buffer < 1);

        precio_aerolineas = buffer;

        do {
          printf("- Precio vuelo Latam: ");

          fflush(stdin);
          err = scanf("%I64d", &buffer);
        } while (err == 0 || err == EOF || buffer < 1);

        precio_latam = buffer;

        precio_ingresado = true;

        // si cambio el precio hay que calcular de vuelta
        costo_calculado = false;
        break;
      }
      case CALCULAR_COSTOS: {
        if (km_ingresado || precio_ingresado) {
          precio_aerolineas_debito = descuento_debito(precio_aerolineas);
          precio_aerolineas_credito = interes_credito(precio_aerolineas);
          precio_aerolineas_btc = precio_btc(precio_aerolineas);
          precio_aerolineas_unitario = precio_km(precio_aerolineas, km);

          precio_latam_debito = descuento_debito(precio_latam);
          precio_latam_credito = interes_credito(precio_latam);
          precio_latam_btc = precio_btc(precio_latam);
          precio_latam_unitario = precio_km(precio_latam, km);

          costo_calculado = true;
        }

        break;
      }
      case INFORMAR_RESULTADOS: {
        if (costo_calculado) {
          printf("KMs Ingresados: %u\n", km);
          printf("\n");

          printf(
              "Precio Aerolineas: $%lu\n"
              "a) Precio con tarjeta de debito: $%.2f\n"
              "b) Precio con tarjeta de credito: $%.2f\n"
              "c) Precio pagando con bitcoin: %.4f\n"
              "d) Mostrar precio unitario: $%.2f\n",
              precio_aerolineas, precio_aerolineas_debito,
              precio_aerolineas_credito, precio_aerolineas_btc,
              precio_aerolineas_unitario);
          printf("\n");

          printf(
              "Precio Latam: $%lu\n"
              "a) Precio con tarjeta de debito: $%.2f\n"
              "b) Precio con tarjeta de credito: $%.2f\n"
              "c) Precio pagando con bitcoin: %.8f\n"
              "d) Mostrar precio unitario: $%.2f\n",
              precio_latam, precio_latam_debito, precio_latam_credito,
              precio_latam_btc, precio_latam_unitario);
          printf("\n");

          printf("La diferencia de precio es: $%.2f\n",
                 precio_diferencia(precio_aerolineas, precio_latam));
        }

        break;
      }
      case CARGA_FORZADA: {
        unsigned int km_forzado = 7090;
        unsigned long precio_aerolineas_forzado = 162965;
        unsigned long precio_latam_forzado = 159339;

        float precio_aerolineas_forzado_debito =
            descuento_debito(precio_aerolineas_forzado);
        float precio_aerolineas_forzado_credito =
            interes_credito(precio_aerolineas_forzado);
        float precio_aerolineas_forzado_btc =
            precio_btc(precio_aerolineas_forzado);
        float precio_aerolineas_forzado_unitario =
            precio_km(precio_aerolineas_forzado, km_forzado);

        float precio_latam_forzado_debito =
            descuento_debito(precio_latam_forzado);
        float precio_latam_forzado_credito =
            interes_credito(precio_latam_forzado);
        float precio_latam_forzado_btc = precio_btc(precio_latam_forzado);
        float precio_latam_forzado_unitario =
            precio_km(precio_latam_forzado, km_forzado);

        printf("\n");
        printf("KMs Ingresados: %u\n", km_forzado);
        printf("\n");

        printf(
            "Precio Aerolineas: $%lu\n"
            "a) Precio con tarjeta de debito: $%.2f\n"
            "b) Precio con tarjeta de credito: $%.2f\n"
            "c) Precio pagando con bitcoin: %.4f\n"
            "d) Mostrar precio unitario: $%.2f\n",
            precio_aerolineas_forzado, precio_aerolineas_forzado_debito,
            precio_aerolineas_forzado_credito, precio_aerolineas_forzado_btc,
            precio_aerolineas_forzado_unitario);
        printf("\n");

        printf(
            "Precio Latam: $%lu\n"
            "a) Precio con tarjeta de debito: $%.2f\n"
            "b) Precio con tarjeta de credito: $%.2f\n"
            "c) Precio pagando con bitcoin: %.8f\n"
            "d) Mostrar precio unitario: $%.2f\n",
            precio_latam_forzado, precio_latam_forzado_debito,
            precio_latam_forzado_credito, precio_latam_forzado_btc,
            precio_latam_forzado_unitario);
        printf("\n");

        printf(
            "La diferencia de precio es: $%.2f\n",
            precio_diferencia(precio_aerolineas_forzado, precio_latam_forzado));
        break;
      }
      case SALIR: {
        return 0;
      }

      default: {
        break;
      }
    }
  } while (1);

  return 1;
}
