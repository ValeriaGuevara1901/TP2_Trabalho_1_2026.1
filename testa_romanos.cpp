// Copyright 2026 Valeria Guevara
// Testes TDD - digitos simples I, V, X, L, C, D, M

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Teste 01 - I vale 1", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("I") == 1);
}

// TESTE 02: V deve retornar 5
TEST_CASE("Teste 02 - V vale 5", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("V") == 5);
}

// TESTE 03: X deve retornar 10
TEST_CASE("Teste 03 - X vale 10", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("X") == 10);
}

// TESTE 04: L deve retornar 50
TEST_CASE("Teste 04 - L vale 50", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("L") == 50);
}

// TESTE 05: C deve retornar 100
TEST_CASE("Teste 05 - C vale 100", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("C") == 100);
}

// TESTE 06: D deve retornar 500
TEST_CASE("Teste 06 - D vale 500", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("D") == 500);
}

// TESTE 07: M deve retornar 1000
TEST_CASE("Teste 07 - M vale 1000", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("M") == 1000);
}
