// Copyright 2026 Valeria Guevara
// Testes TDD - digitos simples, repeticao, notacao subtrativa canonica

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Teste 01 - I vale 1", "[digito_unico]") { REQUIRE(romanos_para_decimal("I") == 1); }
TEST_CASE("Teste 02 - V vale 5", "[digito_unico]") { REQUIRE(romanos_para_decimal("V") == 5); }
TEST_CASE("Teste 03 - X vale 10", "[digito_unico]") { REQUIRE(romanos_para_decimal("X") == 10); }
TEST_CASE("Teste 04 - L vale 50", "[digito_unico]") { REQUIRE(romanos_para_decimal("L") == 50); }
TEST_CASE("Teste 05 - C vale 100", "[digito_unico]") { REQUIRE(romanos_para_decimal("C") == 100); }
TEST_CASE("Teste 06 - D vale 500", "[digito_unico]") { REQUIRE(romanos_para_decimal("D") == 500); }
TEST_CASE("Teste 07 - M vale 1000", "[digito_unico]") { REQUIRE(romanos_para_decimal("M") == 1000); }
TEST_CASE("Teste 08 - II vale 2", "[repeticao_valida]") { REQUIRE(romanos_para_decimal("II") == 2); }
TEST_CASE("Teste 09 - III vale 3", "[repeticao_valida]") { REQUIRE(romanos_para_decimal("III") == 3); }
TEST_CASE("Teste 10 - XXX vale 30", "[repeticao_valida]") { REQUIRE(romanos_para_decimal("XXX") == 30); }
TEST_CASE("Teste 11 - CCC vale 300", "[repeticao_valida]") { REQUIRE(romanos_para_decimal("CCC") == 300); }
TEST_CASE("Teste 12 - MMM vale 3000", "[repeticao_valida]") { REQUIRE(romanos_para_decimal("MMM") == 3000); }

// TESTE 13: IV deve retornar 4 (5 - 1 = 4)
// Esta e a notacao subtrativa canonica; sem ela IV computaria como 5+1=6 (ERRADO)
TEST_CASE("Teste 13 - IV vale 4 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("IV") == 4);
}

// TESTE 14: IX deve retornar 9 (10 - 1 = 9)
TEST_CASE("Teste 14 - IX vale 9 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("IX") == 9);
}

// TESTE 15: XL deve retornar 40 (50 - 10 = 40)
TEST_CASE("Teste 15 - XL vale 40 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("XL") == 40);
}

// TESTE 16: XC deve retornar 90 (100 - 10 = 90)
TEST_CASE("Teste 16 - XC vale 90 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("XC") == 90);
}

// TESTE 17: CD deve retornar 400 (500 - 100 = 400)
TEST_CASE("Teste 17 - CD vale 400 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("CD") == 400);
}

// TESTE 18: CM deve retornar 900 (1000 - 100 = 900)
TEST_CASE("Teste 18 - CM vale 900 (subtrativa)", "[subtrativa]") {
  REQUIRE(romanos_para_decimal("CM") == 900);
}
