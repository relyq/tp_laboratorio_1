#include <stdio.h>

#include "src/tp1.h"

int main(void) {
  // el vuelo comercial mas largo es de 16618km - la circumferencia de la tierra es de 40075km
  unsigned int km;  
  // el vuelo más caro del mundo es new york-abu dhabi con costo alrededor de us$64,000 o ar$12800000
  unsigned long precio_aerolineas;
  unsigned long precio_latam;
  
  // no me parece correcto que km y precios tengan que tener signo si no deberian ser negativos.
  // como tengo que usar scanf() que no tiene proteccion contra overflow voy a usar un buffer para hacer error handling
  // la forma correcta seria usar fgets() para pedir input y strtoll() para interpretar como int
  long long buffer;
  
  int err;
  
  printf("Ingresar Kilometros: ");
  do {
    fflush(stdin);
    err = scanf("%I64d", &buffer);
  } while (err == 0 || err == EOF || buffer < 1); 
  // el vuelo más corto del mundo es westray-papa westray con 1.7 millas o 2.73588km. voy a dejar el minimo como 1 de todas formas
  
  km = buffer;
  
  // esto es más complicado. el vuelo más barato sin descuentos es warsaw-brussels de ryanair a us$11 o alrededor de ar$2200. otra vez voy a dejarlo con minimo de $1 de todas formas
  printf("Ingresar Precio de Vuelos: \n");
  printf("- Precio vuelo Aerolineas: ");
  do {
    fflush(stdin);
    err = scanf("%I64d", &buffer);
  } while (err == 0 || err == EOF || buffer < 1);
  
  precio_aerolineas = buffer;

  printf("- Precio vuelo Latam: ");
  do {
    fflush(stdin);
    err = scanf("%I64d", &buffer);
  } while (err == 0 || err == EOF || buffer < 1);
  
  precio_latam = buffer;

  float precio_aerolineas_debito = descuento_debito(precio_aerolineas);
  float precio_aerolineas_credito = interes_credito(precio_aerolineas);
  float precio_aerolineas_btc = precio_btc(precio_aerolineas);
  float precio_aerolineas_unitario = precio_km(precio_aerolineas, km);

  float precio_latam_debito = descuento_debito(precio_latam);
  float precio_latam_credito = interes_credito(precio_latam);
  float precio_latam_btc = precio_btc(precio_latam);
  float precio_latam_unitario = precio_km(precio_latam, km);

  printf("KMs Ingresados: %u\n", km);
  printf("\n");

  printf(
      "Precio Aerolineas: $%lu\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.4f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_aerolineas, precio_aerolineas_debito, precio_aerolineas_credito,
      precio_aerolineas_btc, precio_aerolineas_unitario);
  printf("\n");

  printf(
      "Precio Latam: $%lu\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.8f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_latam, precio_latam_debito, precio_latam_credito, precio_latam_btc,
      precio_latam_unitario);
  printf("\n");

  printf("La diferencia de precio es: $%.2f\n",
         precio_diferencia(precio_aerolineas, precio_latam));
         
         
  // "carga forzada"
  
  km = 7090;
  precio_aerolineas = 162965;
  precio_latam = 159339;
  
  precio_aerolineas_debito = descuento_debito(precio_aerolineas);
  precio_aerolineas_credito = interes_credito(precio_aerolineas);
  precio_aerolineas_btc = precio_btc(precio_aerolineas);
  precio_aerolineas_unitario = precio_km(precio_aerolineas, km);

  precio_latam_debito = descuento_debito(precio_latam);
  precio_latam_credito = interes_credito(precio_latam);
  precio_latam_btc = precio_btc(precio_latam);
  precio_latam_unitario = precio_km(precio_latam, km);
  
  printf("\n");  
  printf("KMs Ingresados: %u\n", km);
  printf("\n");

  printf(
      "Precio Aerolineas: $%lu\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.4f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_aerolineas, precio_aerolineas_debito, precio_aerolineas_credito,
      precio_aerolineas_btc, precio_aerolineas_unitario);
  printf("\n");

  printf(
      "Precio Latam: $%lu\n"
      "a) Precio con tarjeta de debito: $%.2f\n"
      "b) Precio con tarjeta de credito: $%.2f\n"
      "c) Precio pagando con bitcoin: %.8f\n"
      "d) Mostrar precio unitario: $%.2f\n",
      precio_latam, precio_latam_debito, precio_latam_credito, precio_latam_btc,
      precio_latam_unitario);
  printf("\n");

  printf("La diferencia de precio es: $%.2f\n",
         precio_diferencia(precio_aerolineas, precio_latam));

  return 1;
}