// Copyright 2026 Valeria Guevara
// Implementacao minima: suporte a I

#include "romanos.hpp"
#include <cstring>

// Converte numero romano para arabico
// Versao inicial: suporta apenas I
int romanos_para_decimal(char const * num_romano) {
  if (num_romano == nullptr) return -1;
  if (strlen(num_romano) == 0) return -1;
  if (num_romano[0] == 'I' && strlen(num_romano) == 1) return 1;
  return -1;
}
