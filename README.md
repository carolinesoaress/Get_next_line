# Get Next Line

Este projeto tem como objetivo desenvolver uma função que retorne uma linha lida de um descritor de arquivo (FD).

## Descrição do Projeto

A função `get_next_line` deve ser chamada em loop para ler um arquivo de texto, retornando uma linha por vez. Ela deve continuar lendo até que não haja mais linhas ou ocorra um erro, retornando `NULL` nesses casos.

A função deve funcionar de forma eficiente tanto para leitura de arquivos quanto para a entrada padrão (stdin).

O valor do buffer para a função `read()` será determinado no momento da compilação usando a flag `-D BUFFER_SIZE=n`.

## Funcionalidades

- **Leitura Linha a Linha:** A função permite ler um arquivo de texto linha por linha, facilitando o processamento de grandes volumes de texto.
  
- **Tratamento de Erros:** Em caso de erro ou ao alcançar o fim do arquivo, a função retorna `NULL`, garantindo que o loop de leitura possa ser interrompido corretamente.

- **Suporte a Vários FD:** A função é projetada para lidar com diferentes descritores de arquivo em chamadas consecutivas sem perder o estado de leitura de cada um.

## Compilação

Para compilar o projeto com um buffer específico, utilize o seguinte comando:

```sh
gcc -D BUFFER_SIZE=n -o get_next_line get_next_line.c

Substitua n pelo tamanho desejado para o buffer.

Bônus
Como parte do bônus, a função deve utilizar apenas uma variável estática para gerenciar vários descritores de arquivo simultaneamente. Isso permite que ao ler descritores de arquivo diferentes, como 3, 4 e 5, a get_next_line possa alternar entre eles sem perder a posição de leitura em cada um.

Como Usar
Compile o projeto utilizando o comando de compilação com a flag -D BUFFER_SIZE.
Utilize a função get_next_line para ler arquivos ou entrada padrão, chamando-a repetidamente em um loop para processar o texto linha por linha.

 projeto "Get Next Line" oferece um aprendizado fundamental em manipulação de arquivos e gerenciamento de memória em C. Ao trabalhar nesse projeto, você desenvolve habilidades cruciais, como:

Gerenciamento de Buffers: Aprender a usar buffers com a função read() ensina como gerenciar a leitura de dados de forma eficiente, equilibrando entre o tamanho do buffer e a quantidade de chamadas ao sistema.

Manipulação de Strings: A manipulação de strings para construir e retornar linhas completas requer compreensão profunda de alocação dinâmica e concatenação de strings em C.

Gerenciamento de Vários Descritores de Arquivo: A implementação do suporte para múltiplos descritores de arquivo, usando uma única variável estática, desafia a habilidade de gerenciar o estado entre várias chamadas à função, o que é um conceito avançado em programação.

Tratamento de Erros: Aprender a lidar com diferentes cenários de erro e EOF (fim de arquivo) contribui para a criação de código robusto e resiliente.

Pensamento Crítico e Resolução de Problemas: A necessidade de otimizar e fazer o código funcionar corretamente em diferentes condições estimula o desenvolvimento de habilidades de resolução de problemas.

Esse projeto não só aprofunda seu conhecimento em C, mas também prepara você para desafios futuros, onde a manipulação eficiente de dados e o gerenciamento adequado de recursos são essenciais.
