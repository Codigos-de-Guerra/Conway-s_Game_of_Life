# Conway's Game of Life

Disciplina: Linguagen de Programação I, Universidade Federal do Rio Grande do Norte ([UFRN](http://http://www.ufrn.br))

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
1) Como requisito para compilação do programa é necessário que estejam instalado na maquina:

+ [git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
+ [g++](https://askubuntu.com/questions/348654/how-to-install-g-compiler)

2) Feito isto, o repositório com o projeto poderá ser clonado, usde o comando:
```bash
git clone https://github.com/ozielalves/Conway-s_Game_of_Life/
cd ~/Conway-s_Game_of_Life
# Agora você terá entrado no diretório raiz do projeto.
```
3) Para compilar, usar o seguintes comandos na raiz do repositório:
```bash
# Compilar tudo:
make

# Para limpar somente os objetos e executáveis(arquivos binários), e manter os arquivos contendo dados:
make cleanbin

# Para limpar TODOS dados residuais (objetos, executáveis e arquivos contendo dados gerados e utilizados):
make clean
```

### Execução:
No quesito de execução, o programa segue o seguinte escopo:
```bash
# Roda-se o executável com os seguintes argumentos de linha
$ ./life $[OC]$ $[AE]$ $[AS]$
```
- `$[OC]$`: ``Opção do Cliente``.  Este argumento deve definir a preferência do cliente sobre até quando devemos gerar novas células. Suas opções neste caso são somente digitar ```-u``` ou ```-yn```. Qualquer diferente disso gerará erro. Comando ```-u``` significa gerar até que as regras do jogo me impeçam de criar novas gerações diferentes. Comando ```-yn``` significa que além das regras de estabilidade e extinção, o cliente poderá pedir antecipadamente pela parada do programa.
- `$[AE]$`: ``Arquivo de Entrada``. Este argumento deve representar o arquivo de entrada de dados a ser utilzado. Tal arquivo conterá as informações padrões para geração das células. Por padrão, os arquivos contendo dados a serem lidos devem se encontrar na pasta $data/$. Caso inserido arquivo inexistente, programa falhará.
- `$[AS]$`: ``Arquivo de Saída``. Este argumento deverá apresentar todos os grupos de células gerados desde a geração inicial, até se tornar estável, extinta ou o usuário definir a parada. Também conterá a contagem das gerações. Também por padrão, tais arquivos de saída são criados na pasta $data/$. Caso digite um arquivo já existente, este será sobrescrito.

#### Exemplo:
```bash
$ ./life -u data/entrada.txt data/saida.txt
```
Este comando gerará todas as gerações começadas a partir de 'data/entrada.txt', até que a estabilidade ou extinção ocorra.

```bash
$ ./life -yn data/entrada.dat data/saida.dat
```

Este comando gerará as gerações começadas a partir de 'data/entrada.dat' até onde o cliente desejar que sejam geradas, há não ser que os casos de estabilidade ou extinção sejam obtidos.

