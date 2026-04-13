// Copyright 2026 Valeria Guevara
// Testes TDD - digitos simples + repeticao valida

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Teste 01 - I vale 1", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("I") == 1);
}
TEST_CASE("Teste 02 - V vale 5", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("V") == 5);
}
TEST_CASE("Teste 03 - X vale 10", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("X") == 10);
}
TEST_CASE("Teste 04 - L vale 50", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("L") == 50);
}
TEST_CASE("Teste 05 - C vale 100", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("C") == 100);
}
TEST_CASE("Teste 06 - D vale 500", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("D") == 500);
}
TEST_CASE("Teste 07 - M vale 1000", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("M") == 1000);
}

// TESTE 08: II deve retornar 2 (repeticao valida de I)
TEST_CASE("Teste 08 - II vale 2", "[repeticao_valida]") {
  REQUIRE(romanos_para_decimal("II") == 2);
}

// TESTE 09: III deve retornar 3 (3 repeticoes validas)
TEST_CASE("Teste 09 - III vale 3", "[repeticao_valida]") {
  REQUIRE(romanos_para_decimal("III") == 3);
}

// TESTE 10: XXX deve retornar 30
TEST_CASE("Teste 10 - XXX vale 30", "[repeticao_valida]") {
  REQUIRE(romanos_para_decimal("XXX") == 30);
}

// TESTE 11: CCC deve retornar 300
TEST_CASE("Teste 11 - CCC vale 300", "[repeticao_valida]") {
  REQUIRE(romanos_para_decimal("CCC") == 300);
}

// TESTE 12: MMM deve retornar 3000 (limite superior valido)
TEST_CASE("Teste 12 - MMM vale 3000", "[repeticao_valida]") {
  REQUIRE(romanos_para_decimal("MMM") == 3000);
}
