// Copyright 2026 Valeria Guevara
// Implementacao: adicionar arabico_para_romano + validacao round-trip

#include "romanos.hpp"
#include <cstring>
#include <string>

namespace {

const int kMaxTamanho  = 30;
const int kMaxValor    = 3000;
const int kTamanhoTabela = 13;

struct EntradaRomana {
  int valor;
  const char* simbolo;
};

const EntradaRomana kTabela[] = {
  {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
  {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
  {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
  {1,    "I"}
};

// Converte inteiro arabico para string romana canonica
std::string arabico_para_romano(int num) {
  std::string resultado;
  for (int i = 0; i < kTamanhoTabela; i++) {
    while (num >= kTabela[i].valor) {
      resultado += kTabela[i].simbolo;
      num -= kTabela[i].valor;
    }
  }
  return resultado;
}

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
    if (atual < proximo) {
      resultado += proximo - atual;
      i++;
    } else {
      resultado += atual;
    }
  }
  if (resultado < 1 || resultado > kMaxValor) return -1;
  // Validacao por round-trip: rejeita formas nao-canonicas (XXXX, VV, LL...)
  if (arabico_para_romano(resultado) != std::string(num_romano)) return -1;
  return resultado;
}
