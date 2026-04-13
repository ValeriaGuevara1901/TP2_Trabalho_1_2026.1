// Copyright 2026 Valeria Guevara
// Modulo de conversao de numeros romanos para arabicos.
// Suporta: I, V, X, L, C, D, M e pares subtratives canonicos.
// Intervalo valido: 1 a 3000. Strings de ate 30 caracteres.

#ifndef ROMANOS_HPP_
#define ROMANOS_HPP_

// Converte string de numero romano para inteiro arabico.
// Parametro: num_romano - ponteiro para string terminada em '\0' (ate 30 chars)
// Retorna: valor arabico (1..3000) ou -1 se invalido.
// Invalido: nullptr, string vazia, chars desconhecidos, repeticoes excessivas,
//           formas nao-canonicas (ex: XXXX, VX, IIX), valor > 3000.
int romanos_para_decimal(char const * num_romano);

#endif  // ROMANOS_HPP_
