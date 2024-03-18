# Compilação de Código *C*

Ao implementarmos o tipo de dados `graph_t` começamos a criar programas que usam vários arquivos diferentes. Com projetos pequenos como os que fazemos nesta disciplina não é um problema compilar tudo em um mesmo comando:

<ah-terminal>
$ gcc arq1.c arq2.c ... -o app
</ah-terminal>

Isto começa a complicar quando temos **centenas** de arquivos em um projeto, pois o tempo de compilação cresce conforme o número de arquivos aumenta, indo de alguns segundos ou menos para **horas**. Por isso um tema importante em qualquer sistema de **build** é a *compilação incremental* (ou *parcial*). 

Neste contexto, se um arquivo foi modificado ele deve ser recompilado. Note que mudanças em um arquivo podem impactar outros, então deve ser recompilada toda a sequência de **dependências** dos arquivos modificados. Um arquivo `A` *depende* de outro arquivo `B` se recompilar `B` torna necessário recompilar `A` também. Ou seja, se mexermos em um arquivo `X` precisaremos recompilar o próprio `X` mais todos os arquivos que dependem de `X`. Note, porém, que não acaba por aí! Agora precisamos recompilar todas os arquivos que tem como dependências as dependências de `X`! E por aí vai até recompilarmos todos arquivos afetados pela mudança em `X`.

Neste mini-projeto você lerá a descrição das dependências de um projeto e terá três objetivos:

1. verificar se o projeto possui dependências circulares. Ou seja, se `A` depende de `B`, que depende de `C`, que depende de `A` de novo! Em geral não é possível compilar **dependências circulares** como esta e existir esse tipo de dependência no código é um sinal de uma arquitetura ruim
2. dado um arquivo modificado, devolver quais outros arquivos precisarão ser recompilados
3. determinar uma ordem possível para compilar o projeto do zero de maneira que um arquivo só seja compilado se todas suas dependências já foram compiladas também.

Este trabalho terá créditos parciais por cada tarefa feita corretamente, sendo que só é possível completar 100% se forem feitas as 3 tarefas.

## Entrada

O arquivo se inicia com dois inteiros `N` (número de arquivos) e `M` (número de arquivos com dependências). Em seguida vem `N` linhas com os nomes dos arquivos e `M` linhas descrevendo as dependências. Cada linha de dependência se inicia com o nome do arquivo seguido de `:` e de uma lista de arquivos separada por espaço. A última linha contém um inteiro `OP`.

```
N M
arq1
....
arqN
arqI: arqD1 ... arqDK # dependencia 1
....
arqII: arqD11 ... arqDKK # dependencia M
OP
```

Você pode supor que

1. `M <= N`
2. os arquivos antes de `:` em cada uma das `M` linhas estão na mesma ordem da entrada
3. os arquivos após `:` em cada uma das `M` linhas também estão na mesma ordem da entrada

## Saída

Se

- `OP == 1`: devolva a string "tem ciclo" se houver dependência circular e "sem ciclo" se não houver
- `OP == 2`: para cada arquivo, mostre quais outros arquivos precisam ser recompilados. A saída deve estar no seguinte formato
```
arq1 -> ....
arq2 -> ...
```
- `OP == 3`:  escreva, em uma só linha, uma ordem em que é possível compilar o projeto do zero respeitando as dependências entre arquivos





