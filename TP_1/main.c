#include <stdio.h>

#include "src/tp1.h"

int main(void) {
  unsigned int km = 7090;  // el vuelo comercial mas largo es de 16618km
                           // la circumferencia de la tierra es de 40075km
  float precio_aerolineas = 162965.00f;
  float precio_latam = 159339.00f;

  float precio_aerolineas_debito = descuento_debito(precio_aerolineas);
  float precio_aerolineas_credito = interes_credito(precio_aerolineas);
  float precio_aerolineas_btc = precio_btc(precio_aerolineas);
  float precio_aerolineas_unitario = precio_km(precio_aerolineas, km);

  float precio_latam_debito = descuento_debito(precio_latam);
  float precio_latam_credito = interes_credito(precio_latam);
  float precio_latam_btc = precio_btc(precio_latam);
  float precio_latam_unitario = precio_km(precio_latam, km);

  printf("KMs Ingresados: %d\n", km);
  printf("\n");

  printf(
      "Precio Aerolineas: $%.2f\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.2f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_aerolineas, precio_aerolineas_debito, precio_aerolineas_credito,
      precio_aerolineas_btc, precio_aerolineas_unitario);
  printf("\n");

  printf(
      "Precio Latam: $%.2f\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.2f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_latam, precio_latam_debito, precio_latam_credito, precio_latam_btc,
      precio_latam_unitario);
  printf("\n");

  printf("La diferencia de precio es: $%.2f\n",
         precio_diferencia(precio_aerolineas, precio_latam));

  return 1;
}