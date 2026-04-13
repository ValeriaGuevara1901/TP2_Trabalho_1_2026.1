// Copyright 2026 Valeria Guevara
// Testes unitarios para a funcao romanos_para_decimal usando Catch2.
//
// Metodologia TDD aplicada:
//   - Teste 01-07:  Numeros de digito unico (I, V, X, L, C, D, M)
//   - Teste 08-12:  Repeticao valida de I, X, C, M (2 e 3 vezes)
//   - Teste 13-18:  Notacao subtrativa canonica (IV, IX, XL, XC, CD, CM)
//   - Teste 19-24:  Composicao aditiva comum (VI, XI, LX, etc.)
//   - Teste 25-28:  Numeros compostos e historicos
//   - Teste 29-30:  Limites (1 e 3000)
//   - Teste 31-36:  Invalidos por repeticao excessiva (XXXX, VV, LL, DD)
//   - Teste 37-42:  Invalidos por subtracao proibida (VX, IIX, IC, LC)
//   - Teste 43-47:  Invalidos por caracteres desconhecidos
//   - Teste 48-60:  Casos adicionais para cobertura de 80%+

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
TEST_CASE("Teste 37 - VX invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("VX") == -1); }
TEST_CASE("Teste 38 - IIX invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("IIX") == -1); }
TEST_CASE("Teste 39 - IC invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("IC") == -1); }
TEST_CASE("Teste 40 - LC invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("LC") == -1); }
TEST_CASE("Teste 41 - IL invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("IL") == -1); }
TEST_CASE("Teste 42 - DM invalido", "[invalido_subtrativa]") { REQUIRE(romanos_para_decimal("DM") == -1); }
TEST_CASE("Teste 43 - string vazia invalida", "[invalido_caractere]") { REQUIRE(romanos_para_decimal("") == -1); }
TEST_CASE("Teste 44 - A invalido", "[invalido_caractere]") { REQUIRE(romanos_para_decimal("A") == -1); }
TEST_CASE("Teste 45 - espaco invalido", "[invalido_caractere]") { REQUIRE(romanos_para_decimal("X X") == -1); }
TEST_CASE("Teste 46 - digito arabico invalido", "[invalido_caractere]") { REQUIRE(romanos_para_decimal("1") == -1); }
TEST_CASE("Teste 47 - minusculas invalidas", "[invalido_caractere]") { REQUIRE(romanos_para_decimal("iv") == -1); }

// TESTE 48: MCMXCIX vale 1999
// 1999 = M + CM + XC + IX = 1000 + 900 + 90 + 9
TEST_CASE("Teste 48 - MCMXCIX vale 1999", "[cobertura]") {
  REQUIRE(romanos_para_decimal("MCMXCIX") == 1999);
}

// TESTE 49: CDXLIV vale 444 (tres subtrativas na mesma string)
TEST_CASE("Teste 49 - CDXLIV vale 444", "[cobertura]") {
  REQUIRE(romanos_para_decimal("CDXLIV") == 444);
}

// TESTE 50: CMXCIX vale 999
TEST_CASE("Teste 50 - CMXCIX vale 999", "[cobertura]") {
  REQUIRE(romanos_para_decimal("CMXCIX") == 999);
}

// TESTE 51: DCCCLXXXVIII vale 888 (string de 12 simbolos)
TEST_CASE("Teste 51 - DCCCLXXXVIII vale 888", "[cobertura]") {
  REQUIRE(romanos_para_decimal("DCCCLXXXVIII") == 888);
}

// TESTE 52: XLIV vale 44
TEST_CASE("Teste 52 - XLIV vale 44", "[cobertura]") {
  REQUIRE(romanos_para_decimal("XLIV") == 44);
}

// TESTE 53: XCIX vale 99
TEST_CASE("Teste 53 - XCIX vale 99", "[cobertura]") {
  REQUIRE(romanos_para_decimal("XCIX") == 99);
}

// TESTE 54: CCCXCIX vale 399
TEST_CASE("Teste 54 - CCCXCIX vale 399", "[cobertura]") {
  REQUIRE(romanos_para_decimal("CCCXCIX") == 399);
}

// TESTE 55: IM invalido (I so pode preceder V e X; 999 = CMXCIX)
TEST_CASE("Teste 55 - IM invalido", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("IM") == -1);
}

// TESTE 56: VL invalido (V nao pode preceder L; 45 = XLV)
TEST_CASE("Teste 56 - VL invalido", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("VL") == -1);
}

// TESTE 57: XM invalido (X so pode preceder L, C; 990 = CMXC)
TEST_CASE("Teste 57 - XM invalido", "[invalido_subtrativa]") {
  REQUIRE(romanos_para_decimal("XM") == -1);
}

// TESTE 58: CCCC invalido (quatro C; 400 = CD)
TEST_CASE("Teste 58 - CCCC invalido", "[invalido_repeticao]") {
  REQUIRE(romanos_para_decimal("CCCC") == -1);
}

// TESTE 59: valor 3888 > 3000, deve retornar -1
TEST_CASE("Teste 59 - MMMDCCCLXXXVIII invalido (>3000)", "[invalido_limite]") {
  REQUIRE(romanos_para_decimal("MMMDCCCLXXXVIII") == -1);
}

// TESTE 60: MMCMLXXXVIII vale 2988
// 2988 = MM + CM + LXXX + VIII = 2000 + 900 + 80 + 8
TEST_CASE("Teste 60 - MMCMLXXXVIII vale 2988", "[cobertura]") {
  REQUIRE(romanos_para_decimal("MMCMLXXXVIII") == 2988);
}
