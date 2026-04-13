// Copyright 2026 Valeria Guevara
// Implementacao: notacao subtrativa (menor antes de maior)

#include "romanos.hpp"
#include <cstring>

namespace {

const int kMaxTamanho = 30;
const int kMaxValor   = 3000;

int valor_do_caractere(char c) {
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

}  // namespace

int romanos_para_decimal(char const * num_romano) {
  if (num_romano == nullptr) return -1;
  int len = static_cast<int>(strlen(num_romano));
  if (len == 0 || len > kMaxTamanho) return -1;
  int resultado = 0;
  for (int i = 0; i < len; i++) {
    int atual = valor_do_caractere(num_romano[i]);
    if (atual == -1) return -1;
    int proximo = (i + 1 < len) ? valor_do_caractere(num_romano[i + 1]) : 0;
    // Notacao subtrativa: se atual < proximo, subtrai o par
    if (atual < proximo) {
      resultado += proximo - atual;
      i++;
    } else {
      resultado += atual;
    }
  }
  if (resultado < 1 || resultado > kMaxValor) return -1;
  return resultado;
}
