// Copyright 2026 Valeria Guevara
// Implementacao: todos os 7 digitos romanos basicos

#include "romanos.hpp"
#include <cstring>

// Retorna o valor de um caractere romano valido, ou -1
static int valor_char(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return -1;
  }
}

// Converte numero romano para arabico (soma simples)
int romanos_para_decimal(char const * num_romano) {
  if (num_romano == nullptr) return -1;
  int len = static_cast<int>(strlen(num_romano));
  if (len == 0) return -1;
  int resultado = 0;
  for (int i = 0; i < len; i++) {
    int v = valor_char(num_romano[i]);
    if (v == -1) return -1;
    resultado += v;
  }
  return resultado;
}
