// Copyright 2026 Valeria Guevara
// Testes TDD para conversao de numeros romanos

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

// TESTE 01: I deve retornar 1
// Objetivo: verificar o numeral romano mais simples
// Esperado: passa quando romanos_para_decimal("I") == 1
TEST_CASE("Teste 01 - I vale 1", "[digito_unico]") {
  REQUIRE(romanos_para_decimal("I") == 1);
}
