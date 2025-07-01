#!/bin/bash

# Compila o programa
g++ -Wall -Wextra -Werror -std=c++98 main.cpp -o replace

# Cria arquivo de entrada
# echo "Hello world
# world of programming
# Welcome to the world
# This is a wonderful world" > input.txt

# echo "Arquivo de entrada criado:"
# cat input.txt
# echo "-------------------------"

# Teste 1: Substituir 'world' por 'universe'
./replace input.txt world universe
echo "Resultado do Teste 1 (world -> universe):"
cat input.txt.replace
echo "-------------------------"

# Teste 2: Substituir 'Hello' por 'Hi'
./replace input.txt Hello Hi
echo "Resultado do Teste 2 (Hello -> Hi):"
cat input.txt.replace
echo "-------------------------"

# Teste 3: Substituir 'a' por 'A'
./replace input.txt a A
echo "Resultado do Teste 3 (a -> A):"
cat input.txt.replace
echo "-------------------------"

# Teste 4: Substituir 'nonexistent' por 'X' (não deve mudar nada)
./replace input.txt nonexistent X
echo "Resultado do Teste 4 (nonexistent -> X):"
cat input.txt.replace
echo "-------------------------"

# Teste 5: Substituir string vazia (deve gerar erro)
./replace input.txt "" X

# Limpeza opcional:
# rm replace input.txt input.txt.replace




# Salve o script com nome test.sh na mesma pasta que seu main.cpp.

# Dê permissão de execução:
#       chmod +x test.sh

# Execute:
#       ./test.sh