// Copyright 2026 Valeria Guevara
// Testes TDD - subtrativas proibidas e caracteres invalidos

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
TEST_CASE("Teste 29 - I limite inferior", "[limites]") { REQUIRE(romanos_para_decimal("I") == 1); }
TEST_CASE("Teste 30 - MMM limite superior", "[limites]") { REQUIRE(romanos_para_decimal("MMM") == 3000); }
TEST_CASE("Teste 31 - XXXX invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("XXXX") == -1); }
TEST_CASE("Teste 32 - VV invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("VV") == -1); }
TEST_CASE("Teste 33 - LL invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("LL") == -1); }
TEST_CASE("Teste 34 - DD invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("DD") == -1); }
TEST_CASE("Teste 35 - IIII invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("IIII") == -1); }
TEST_CASE("Teste 36 - MMMM invalido", "[invalido_repeticao]") { REQUIRE(romanos_para_decimal("MMMM") == -1); }

// TESTE 37: VX invalido - V nao e prefixo valido para subtracao antes de X
// VX computaria como 5 (round-trip: 5 -> V != VX)
TEST_CASE("Teste 37 - VX invalido (V antes de X proibido)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("VX") == -1);
}

// TESTE 38: IIX invalido - subtracao dupla nao e canonica (8 = VIII)
TEST_CASE("Teste 38 - IIX invalido (subtracao dupla)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("IIX") == -1);
}

// TESTE 39: IC invalido - I so pode preceder V ou X (99 = XCIX)
TEST_CASE("Teste 39 - IC invalido (I antes de C)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("IC") == -1);
}

// TESTE 40: LC invalido - L nao pode preceder C em subtracao (40 = XL)
TEST_CASE("Teste 40 - LC invalido (L antes de C)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("LC") == -1);
}

// TESTE 41: IL invalido - I so pode preceder V ou X (49 = XLIX)
TEST_CASE("Teste 41 - IL invalido (I antes de L)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("IL") == -1);
}

// TESTE 42: DM invalido - D nao pode preceder M em subtracao (500 = D)
TEST_CASE("Teste 42 - DM invalido (D antes de M)", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("DM") == -1);
}

// TESTE 43: string vazia deve retornar -1
TEST_CASE("Teste 43 - string vazia invalida", "[invalido_caractere]") {
  REQUIRE(romanos_para_decimal("") == -1);
}

// TESTE 44: 'A' nao e simbolo romano; deve retornar -1
TEST_CASE("Teste 44 - caractere A invalido", "[invalido_caractere]") {
  REQUIRE(romanos_para_decimal("A") == -1);
}

// TESTE 45: espaco nao e simbolo romano valido
TEST_CASE("Teste 45 - string com espaco invalida", "[invalido_caractere]") {
  REQUIRE(romanos_para_decimal("X X") == -1);
}

// TESTE 46: digito arabico nao e aceito
TEST_CASE("Teste 46 - digito arabico invalido", "[invalido_caractere]") {
  REQUIRE(romanos_para_decimal("1") == -1);
}

// TESTE 47: minusculas nao sao aceitas (case-sensitive)
TEST_CASE("Teste 47 - letras minusculas invalidas", "[invalido_caractere]") {
  REQUIRE(romanos_para_decimal("iv") == -1);
}
