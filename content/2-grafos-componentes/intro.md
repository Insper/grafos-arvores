# Introdução a Grafos

<ah-external-content src="../slides-intro.html" />

## Atividades básicas

Nessas primeiras atividades iremos praticar as definições básicas de grafos e sua utilização. Esse material é importante para conseguirmos um vocabulário básico a ser usado na disciplina. 

!!! exercise choice
    <ah-diagram>
    graph LR
        A --> B
        B --> A
        C --> D
        D --> E
        E --> A
        A --> D
        D --> B
        D --> A
        C --> E

    </ah-diagram>

    Qual é o número de vértices e arestas do grafo acima?

    - [X] 5 vértices, 9 arestas 
    - [ ] 9 vértices, 5 arestas
    - [ ] 5 vértices, 5 arestas
    - [ ] 9 vértices, 9 arestas

    !!! answer
        Temos 5 vértices: A, B, C, D, E. Os nomes deles não importam, então eles poderiam ser numerados e daria na mesma.

        Em um grafo direcionado o número de arestas é o número de setas. Portanto, contamos 9 setas no diagrama acima.

!!! exercise choice
    <ah-diagram>
    graph TD
        0 --- 1
        2 --- 3
        0 --- 3
        2 --- 1
        2 --- 0

    </ah-diagram>

    Qual é o número de vértices e arestas do grafo acima?

    - [X] 4 vértices, 5 arestas 
    - [ ] 5 vértices, 4 arestas
    - [ ] 4 vértices, 4 arestas
    - [ ] 5 vértices, 5 arestas

    !!! answer
        Temos 4 vértices: 0, 1, 2, 3. 

        Em um grafo não direcionado o número de arestas é o número de ligações entre vértices. Portanto, contamos 5 ligações no diagrama acima.



- O **grau de entrada** de um vértice é o número de arestas que **chegam** nele
- O **grau de saída** de um vértice é o número de arestas que **saem** dele

!!! exercise choice
    No grafo abaixo, qual é o vértice de **menor grau de entrada**?

    <ah-diagram>
    graph TD
        0 --> 1
        0 --> 2
        0 --> 4
        1 --> 2
        1 --> 3
        1 --> 4
        2 --> 0
        2 --> 3
        3 --> 0
    </ah-diagram>

    - [ ] 0
    - [x] 1
    - [ ] 2
    - [ ] 3
    - [ ] 4

!!! exercise choice
    No grafo abaixo, qual é o vértice de **maior grau de saída**?

    <ah-diagram>
    graph TD
        0 --> 1
        0 --> 2
        0 --> 3
        0 --> 4
        1 --> 2
        1 --> 3
        1 --> 4
        2 --> 0
        2 --> 3
        3 --> 0
    </ah-diagram>


    - [X] 0
    - [ ] 1
    - [ ] 2
    - [ ] 3
    - [ ] 4


Agora vamos praticar interpretar problemas "reais" usando grafos. Em cada problema precisamos fazer 4 perguntas básica:

1. o que cada vértice do grafo representa?
2. qual relação  entre vértices uma aresta representa?
3. essa relação tem direção ou é sempre simétrica?
4. essa relação tem pesos/preferências ou todas arestas são equivalentes?

## Problema 1 - redes sociais

Medir a influência de pessoas em redes sociais é um tema recente dada sua importância em nossa atual [Economia da Atenção](https://en.wikipedia.org/wiki/Attention_economy). Imagine que temos os seguintes dados de log de uma rede social:

- todos nomes de usuários
- posts de cada usuário
- toda vez que um usuário curte um post

Vamos usar grafos para resolver este problema.

!!! exercise short
    Em nosso grafo, o que seriam os vértices?

!!! exercise short
    Em nosso grafo, qual relação arestas entre dois vértices representa?

!!! exercise short
    O grafo é direcionado? As arestas tem peso?

## Representação computacional

Considere o log de interações abaixo. Os usuários são numerados de 1 a 10

```
Usuário 1 fez post #1

Usuário 10 gostou do post #1

Usuário 5 fez post #2

Usuário 10 gostou do post #2
Usuário 2 gostou do post #1
Usuário 8 gostou do post #1

Usuário 3 fez post #3

Usuário 3 gostou do post #1
Usuário 2 gostou do post #3
Usuário 2 gostou do post #2

Usuário 2 fez post #4

Usuário 4 gostou do post #4
Usuário 6 gostou do post #4
Usuário 6 gostou do post #1

Usuário 5 fez post #5

Usuário 9 gostou do post #5
Usuário 9 gostou do post #2

Usuário 2 fez post #6

Usuário 6 gostou do post #2
Usuário 6 gostou do post #6
Usuário 4 gostou do post #3
Usuário 9 gostou do post #6
Usuário 8 gostou do post #6
```

!!! exercise long
    Com base nas perguntas da seção anterior, escreva abaixo a matriz de adjacências que representa a situação acima

    !!! Answer
        ```
        0 0 0 0 0 0 0 0 0 0 
        1 0 1 0 1 0 0 0 0 0 
        1 0 0 0 0 0 0 0 0 0 
        0 1 1 0 0 0 0 0 0 0 
        0 0 0 0 0 0 0 0 0 0 
        1 2 0 0 1 0 0 0 0 0 
        0 0 0 0 0 0 0 0 0 0 
        1 1 0 0 0 0 0 0 0 0 
        0 1 0 0 2 0 0 0 0 0 
        1 0 0 0 1 0 0 0 0 0 
        ```

Conseguimos tirar diversas informações interessantes diretamente da matriz de adjacências. Responda às questões abaixo:

!!! exercise short
    Como saber quais usuários postaram algo que foi curtido?

    !!! answer
        É só procurar na sua coluna correspondente. Como arestas saem da linha `i` e chegam na coluna `j`, se tiver algum elemento na coluna `j` diferente de 0 então aquele usuário postou algo que foi curtido. 

!!! exercise short
    Como encontrar o usuário com maior número de posts curtidos?

    !!! answer
        Será o usuário com a coluna de maior soma = vértice de maior grau de entrada

!!! exercise short
    Como encontrar o usuário que mais curtiu posts?

    !!! answer
        Será o usuário com a linha de maior soma = vértice de maior grau de saída 
        
<!-- 
## Entrega

Agora que já estamos mais familiarizados com grafos iremos implementar a estrutura de dados que será usada em todos os trabalhos com grafos no semestre. É recomendado fazer antes a atividade de [Tipos de Dados em C](../0-linguagem-C/adt-c.md).

Os objetivos desta atividade são:

1. gerenciar memória corretamente, alocando e liberando conforme necessário
2. representar grafos como matrizes e entender a relação de cada elemento da matriz com a representação visual do grafo
3. encontrar problems em uma implementação em *C* usando como auxílio testes de unidade
 -->
