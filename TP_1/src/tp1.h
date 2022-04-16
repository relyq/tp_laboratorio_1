/**
 * @file
 * @author  Nicolas Mainenti <NicolasAMainenti@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * aca estan las funciones de ayuda para calcular costos
 */
#ifndef __TP1_H__
#define __TP1_H__

/**
 * calcular descuento a pagar con debito
 *
 * @param  x precio al cual aplicar el descuento
 * @return precio con el descuento aplicado
 */
float descuento_debito(float const x);

/**
 * calcular interes a pagar con credito
 *
 * @param  x precio al cual aplicar el interes
 * @return precio con el interes aplicado
 */
float interes_credito(float const x);

/**
 * calcular precio a pagar en BTC
 *
 * @param  x precio en pesos a convertir a BTC
 * @return precio en BTC
 */
float precio_btc(float const x);

/**
 * calcular precio por cada kilometro
 *
 * @param  x precio total del viaje
 * @param  km kilometros totales del viaje
 * @return precio por cada kilometro
 */
float precio_km(float const x, int const km);

/**
 * calcular diferencia entre dos precios
 *
 * @param  x primer precio
 * @param  y segundo precio
 * @return diferencia entre los dos precios
 */
float precio_diferencia(float const x, float const y);

#endif  // __TP1_H__