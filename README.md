# Conway's Game of Life

Disciplina: Estrutura de Dados Básicas I, Universidade Federal do Rio Grande do Norte ([UFRN](http://http://www.ufrn.br))

#### Alunos envolvidos
- [Daniel Guerra](https://github.com/Codigos-de-Guerra/)
- [Oziel Alves](https://github.com/ozielalves/)

### Objetivo:
O objetivo deste trabalho é implementar um sistema que realize a simulação do jogo da
vida de Conway, um exemplo bem conhecido de celullar automaton (CA).

### Sobre do jogo:
O universo do *Conway's Game of Life* é uma grade bidimensional infinita de `"Células"`,as quais podem estar em um dos dois estados possíveis, `viva` ou `morta`, (ou "povoado" e "despovoado" respectivamente). Cada célula interage com seus oito vizinhos, que são horizontal, vertical ou diagonalmente adjacentes. Em cada etapa no tempo, as seguintes transições ocorrem:

  1) Qualquer célula viva com menos de dois vizinhos vivos morre, por solidão.
  2) Qualquer célula viva com dois ou três vizinhos vivos vive na próxima geração.
  3) Qualquer célula viva com mais de três vizinhos vivos morre, por superpopulação.
  4) Qualquer célula morta com exatamente três vizinhos vivos torna-se uma célula viva, por reprodução.

A primeira geração é criada aplicando as regras acima simultaneamente a cada célula nos nascimentos e mortes, que ocorrem simultaneamente, o momento discreto em que isso acontece é às vezes chamado de carrapato (em outras palavras, cada geração é a função pura da próxima). As regras continuam a ser aplicadas repetidamente para criar novas gerações.
### Compilação:
// TODO
#### Referências:
// TODO

THE END
