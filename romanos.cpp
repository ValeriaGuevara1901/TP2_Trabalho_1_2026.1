// Copyright 2026 Valeria Guevara
// Implementacao da conversao de numeros romanos para arabicos.
// Usa validacao por conversao inversa (round-trip): converte romano -> arabico,
// depois arabico -> romano e confere se o resultado bate com a entrada.

#include "romanos.hpp"
#include <cstring>
#include <string>

namespace {

// Tamanho maximo de entrada aceito
const int kMaxTamanho = 30;

// Valor maximo de numero romano aceito
const int kMaxValor = 3000;

// Estrutura que associa valor arabico ao simbolo romano correspondente
struct EntradaRomana {
  int valor;
  const char* simbolo;
};

// Tabela de valores em ordem decrescente, incluindo subtrativas canonicas
const EntradaRomana kTabela[] = {
  {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
  {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
  {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
  {1,    "I"}
};

const int kTamanhoTabela = 13;

// Converte um inteiro arabico para string romana canonica.
// Usado internamente para validar a entrada por round-trip.
// Recebe: num - inteiro entre 1 e 3000
// Retorna: string com a representacao romana canonica
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

// Retorna o valor de um caractere romano valido, ou -1 se invalido.
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
// Retorna -1 para qualquer entrada invalida.
int romanos_para_decimal(char const * num_romano) {
  // Rejeita ponteiro nulo
  if (num_romano == nullptr) return -1;

  int len = static_cast<int>(strlen(num_romano));

  // Rejeita string vazia ou muito longa
  if (len == 0 || len > kMaxTamanho) return -1;

  int resultado = 0;

  // Percorre a string somando ou subtraindo valores
  for (int i = 0; i < len; i++) {
    int atual = valor_do_caractere(num_romano[i]);

    // Caractere desconhecido
    if (atual == -1) return -1;

    int proximo = (i + 1 < len) ? valor_do_caractere(num_romano[i + 1]) : 0;

    // Notacao subtrativa: se atual < proximo, subtrai o par
    if (atual < proximo) {
      resultado += proximo - atual;
      i++;  // pula o proximo, ja consumido
    } else {
      resultado += atual;
    }
  }

  // Valor fora do intervalo valido (1 a 3000)
  if (resultado < 1 || resultado > kMaxValor) return -1;

  // Validacao final por round-trip:
  // converte o arabico de volta para romano e compara com a entrada.
  // Isso rejeita formas nao-canonicas como XXXX, IIX, VX, LL, etc.
  if (arabico_para_romano(resultado) != std::string(num_romano)) return -1;

  return resultado;
}
