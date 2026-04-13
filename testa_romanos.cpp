// Copyright 2026 Valeria Guevara
// Testes TDD - ate composicoes aditivas comuns

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
TEST_CASE("Teste 13 - IV vale 4", "[subtrativa]") { REQUIRE(romanos_para_decimal("IV") == 4); }
TEST_CASE("Teste 14 - IX vale 9", "[subtrativa]") { REQUIRE(romanos_para_decimal("IX") == 9); }
TEST_CASE("Teste 15 - XL vale 40", "[subtrativa]") { REQUIRE(romanos_para_decimal("XL") == 40); }
TEST_CASE("Teste 16 - XC vale 90", "[subtrativa]") { REQUIRE(romanos_para_decimal("XC") == 90); }
TEST_CASE("Teste 17 - CD vale 400", "[subtrativa]") { REQUIRE(romanos_para_decimal("CD") == 400); }
TEST_CASE("Teste 18 - CM vale 900", "[subtrativa]") { REQUIRE(romanos_para_decimal("CM") == 900); }

// TESTE 19: VI deve retornar 6 (composicao aditiva simples)
TEST_CASE("Teste 19 - VI vale 6", "[composicao]") {
  REQUIRE(romanos_para_decimal("VI") == 6);
}

// TESTE 20: XI deve retornar 11
TEST_CASE("Teste 20 - XI vale 11", "[composicao]") {
  REQUIRE(romanos_para_decimal("XI") == 11);
}

// TESTE 21: XIV deve retornar 14 (10 + 4)
TEST_CASE("Teste 21 - XIV vale 14", "[composicao]") {
  REQUIRE(romanos_para_decimal("XIV") == 14);
}

// TESTE 22: XIX deve retornar 19 (10 + 9)
TEST_CASE("Teste 22 - XIX vale 19", "[composicao]") {
  REQUIRE(romanos_para_decimal("XIX") == 19);
}

// TESTE 23: XLII deve retornar 42 (40 + 2)
TEST_CASE("Teste 23 - XLII vale 42", "[composicao]") {
  REQUIRE(romanos_para_decimal("XLII") == 42);
}

// TESTE 24: DCCC deve retornar 800 (500 + 300)
TEST_CASE("Teste 24 - DCCC vale 800", "[composicao]") {
  REQUIRE(romanos_para_decimal("DCCC") == 800);
}
