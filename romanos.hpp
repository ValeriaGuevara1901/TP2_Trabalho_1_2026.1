// Copyright 2026 Valeria Guevara
// Modulo de conversao de numeros romanos para arabicos.
// Suporta numeros de 1 a 3000; strings de ate 30 caracteres.

#ifndef ROMANOS_HPP_
#define ROMANOS_HPP_

// Converte string de numero romano para inteiro arabico.
// Recebe: num_romano - string com simbolos {I,V,X,L,C,D,M} (ate 30 chars)
// Retorna: inteiro correspondente, ou -1 se a entrada for invalida
//          (vazia, chars desconhecidos, repeticoes excessivas, valor > 3000)
int romanos_para_decimal(char const * num_romano);

#endif  // ROMANOS_HPP_
