Sou aluna do curso de Ciencias da computação agora na UNB - aluna da disciplina TP2 direcionada pelo professor Jan e este é nosso primeiro trabalho:

🧪 Trabalho 1 - Conversão de Números Romanos (TDD)
📌 Objetivo

Este projeto tem como objetivo aplicar Desenvolvimento Orientado a Testes (TDD) para resolver o problema de conversão de números romanos para números arábicos.

⚙️ Requisitos
Converter números romanos (até 3000) para inteiros.
Entrada: string com até 30 caracteres.
Saída:
Número inteiro correspondente (ex: XXX → 30)
-1 para números inválidos (ex: XXXX, VV, VX)
🧱 Estrutura do Projeto

O projeto é modularizado da seguinte forma:

romano.h        # Declarações
romano.c/.cpp   # Implementação
testa_romano.c/.cpp  # Testes
Makefile        # Compilação
🧪 Metodologia (TDD)

O desenvolvimento segue o ciclo:

Criar o teste
Fazer o teste passar
Refatorar o código
Cada teste deve gerar pelo menos 3 commits
Total mínimo: 30 commits
🛠️ Ferramentas
Linguagem: C ou C++
Compilação: Makefile
Debug: GDB
🔍 Validação

Os resultados podem ser comparados com:

http://numeracaoromana.babuo.com/numeros-romanos-de-1-a-3000
▶️ Como executar
make
./testa_romano
📎 Observações
O foco principal é a aplicação correta do TDD
Testes devem cobrir casos válidos e inválidos
Código deve ser limpo e refatorado continuamente

Se quiser, posso te ajudar a montar o Makefile ou já criar a estrutura inicial do projeto 👍
