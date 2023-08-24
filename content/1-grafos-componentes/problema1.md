# Compilação de Código *C*

Ao implementarmos o tipo de dados `graph_t` começamos a criar programas que usam vários arquivos diferentes. Com projetos pequenos como os que fazemos nesta disciplina não é um problema compilar tudo em um mesmo comando:

<ah-terminal>
> gcc arq1.c arq2.c ... -o app
</ah-terminal>

Isto começa a complicar quando temos **centenas** de arquivos em um projeto, pois o tempo de compilação cresce conforme o númerode arquivos aumenta, indo de alguns segundos ou menos para **horas**. Por isso um tema importante em qualquer sistema de **build** é a *compilação incremental* (ou *parcial*). 

Um conceito fundamental em sistemas de **build** é a *dependência*. Um arquivo `A`*depende* de outro arquivo `B` se recompilar `B` torna necessário recompilar `A` também. Ou seja, se mexermos em um arquivo `X` precisaremos recompilar o próprio `X` mais todos os arquivos que dependem de `X`. Note, porém, que não acaba por aí! Agora precisamos recompilar todas os arquivos que tem como dependências as dependências de `X! E por aí vai até recompilarmos todos arquivos afetados pela mudança em `X`.

No modelo *incremental* tentamos aproveitar o máximo possível de uma compilação anterior, refazendo trabalho somente para os arquivos que forem modificados. Este modelo tem potencial de ser muito mais rápido que uma *compilação completa* do projeto, já que (em teoria) nossas modificações a cada ciclo de compilação são pequenas enquanto fazemos modificações.


## Entrada

Seu arquivo de entrada poderá conter um número arbitrário de linhas com tamanho máximode 2048 caracteres. 


## Parte 1 - Dependência circular

Dadas as relações de dependência podemos chegar em uma situação em que há um *ciclo* no grafo. Ou seja, um arquivo depende de outros que eventualmente dependem do arquivo inicial. 




