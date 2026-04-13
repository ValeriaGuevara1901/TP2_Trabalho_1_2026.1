// Copyright 2026 Valeria Guevara
// Testes TDD - limites e invalidos por repeticao excessiva

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
TEST_CASE("Teste 19 - VI vale 6", "[composicao]") { REQUIRE(romanos_para_decimal("VI") == 6); }
TEST_CASE("Teste 20 - XI vale 11", "[composicao]") { REQUIRE(romanos_para_decimal("XI") == 11); }
TEST_CASE("Teste 21 - XIV vale 14", "[composicao]") { REQUIRE(romanos_para_decimal("XIV") == 14); }
TEST_CASE("Teste 22 - XIX vale 19", "[composicao]") { REQUIRE(romanos_para_decimal("XIX") == 19); }
TEST_CASE("Teste 23 - XLII vale 42", "[composicao]") { REQUIRE(romanos_para_decimal("XLII") == 42); }
TEST_CASE("Teste 24 - DCCC vale 800", "[composicao]") { REQUIRE(romanos_para_decimal("DCCC") == 800); }
TEST_CASE("Teste 25 - MCDXCII vale 1492", "[historico]") { REQUIRE(romanos_para_decimal("MCDXCII") == 1492); }
TEST_CASE("Teste 26 - MCMXLV vale 1945", "[historico]") { REQUIRE(romanos_para_decimal("MCMXLV") == 1945); }
TEST_CASE("Teste 27 - MMXXVI vale 2026", "[historico]") { REQUIRE(romanos_para_decimal("MMXXVI") == 2026); }
TEST_CASE("Teste 28 - MMCMXCIX vale 2999", "[historico]") { REQUIRE(romanos_para_decimal("MMCMXCIX") == 2999); }

// TESTE 29: Limite inferior - I deve retornar 1
TEST_CASE("Teste 29 - I limite inferior (1)", "[limites]") {
  REQUIRE(romanos_para_decimal("I") == 1);
}

// TESTE 30: Limite superior - MMM deve retornar 3000
TEST_CASE("Teste 30 - MMM limite superior (3000)", "[limites]") {
  REQUIRE(romanos_para_decimal("MMM") == 3000);
}

// TESTE 31: XXXX invalido - quatro X equivalem a 40, mas a forma canonica e XL
// Esperado: -1 pois XXXX nao e forma canonica
TEST_CASE("Teste 31 - XXXX invalido (4 X)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("XXXX") == -1);
}

// TESTE 32: VV invalido - V nao pode ser repetido (10 se escreve X)
TEST_CASE("Teste 32 - VV invalido (V repetido)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("VV") == -1);
}

// TESTE 33: LL invalido - L nao pode ser repetido (100 se escreve C)
TEST_CASE("Teste 33 - LL invalido (L repetido)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("LL") == -1);
}

// TESTE 34: DD invalido - D nao pode ser repetido (1000 se escreve M)
TEST_CASE("Teste 34 - DD invalido (D repetido)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("DD") == -1);
}

// TESTE 35: IIII invalido - quatro I equivalem a 4, mas a forma canonica e IV
TEST_CASE("Teste 35 - IIII invalido (4 I)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("IIII") == -1);
}

// TESTE 36: MMMM invalido - valor seria 4000, excede o limite de 3000
TEST_CASE("Teste 36 - MMMM invalido (valor 4000 > 3000)", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("MMMM") == -1);
}
