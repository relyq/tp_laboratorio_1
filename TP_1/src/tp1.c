#include "tp1.h"

#include "math.h"

float descuento_debito(float const x) { return x * 0.9f; }
float interes_credito(float const x) { return x * 1.25f; }
float precio_btc(float const x) { return x / 4606954.55f; }
float precio_km(float const x, int const km) { return x * km; }
float precio_diferencia(float const x, float const y) { return fabs(x - y); }