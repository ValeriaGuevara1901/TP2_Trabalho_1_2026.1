// Copyright 2026 Valeria Guevara
// Implementacao com funcao auxiliar de valor de caractere

#include "romanos.hpp"
#include <cstring>

// Retorna valor de um caractere romano, ou -1 se invalido
static int valor_char(char c) {
  if (c == 'I') return 1;
  return -1;
}

// Converte numero romano para arabico (suporta apenas I)
int romanos_para_decimal(char const * num_romano) {
  if (num_romano == nullptr) return -1;
  if (strlen(num_romano) == 0) return -1;
  int len = static_cast<int>(strlen(num_romano));
  int resultado = 0;
  for (int i = 0; i < len; i++) {
    int v = valor_char(num_romano[i]);
    if (v == -1) return -1;
    resultado += v;
  }
  return resultado;
}
