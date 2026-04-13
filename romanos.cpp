// Copyright 2026 Valeria Guevara
// Implementacao completa com validacao round-trip e comentarios detalhados

#include "romanos.hpp"
#include <cstring>
#include <string>

namespace {

const int kMaxTamanho    = 30;
const int kMaxValor      = 3000;
const int kTamanhoTabela = 13;

// Associa valor arabico a simbolo romano (inclui pares subtratives)
struct EntradaRomana {
  int valor;
  const char* simbolo;
};

// Tabela em ordem decrescente: cobre adicoes e subtracoes canonicas
const EntradaRomana kTabela[] = {
  {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
  {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
  {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
  {1,    "I"}
};

// Converte inteiro arabico para sua representacao romana canonica.
// Usado para validar entradas por comparacao (round-trip).
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

// Retorna o valor numerico de um simbolo romano, ou -1 se invalido
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

// Converte uma string de numero romano para inteiro arabico.
// Retorna -1 para entradas invalidas (chars desconhecidos, formas nao-canonicas,
// valores fora do intervalo 1-3000, strings maiores que 30 chars).
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
      resultado += proximo - atual;  // par subtrativo: ex. IV=4, CM=900
      i++;
    } else {
      resultado += atual;
    }
  }
  if (resultado < 1 || resultado > kMaxValor) return -1;
  // Validacao round-trip: rejeita XXXX (nao-canonico de XL), VV, LL, etc.
  if (arabico_para_romano(resultado) != std::string(num_romano)) return -1;
  return resultado;
}
