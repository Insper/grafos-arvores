# Componentes Conexos em Grafos

<ah-external-content src="../slides-componentes.html" />

Seja $G = (V, A)$ um grafo não direcionado sem pesos. Um subconjunto $C \subseteq V$  de vértices é um *componente conexo* se e somente se

1. para todos par de vértices $v, w \in C$ existe um caminho que começa em $v$ e termina em $w$
2. para todo $v \in C$ e $w \in V - C$, não existe caminho entre $v$ e $w$.

Vamos praticar um pouco a identificação de componentes conexas?

!!! exercise choice
    
    <graphviz-graph graph="
        graph G {
        0 -- 1
        0 -- 2
        1 -- 2
        3 -- 4
        4 -- 5
    }"> </graphviz-graph>

    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [ ] 1
    - [x] 2 
    - [ ] 3
    - [ ] 4
    - [ ] 5

!!! exercise choice
    <graphviz-graph graph="
        graph G {
        0 -- 1
        0 -- 2
        1 -- 2
        3 -- 4
        4 -- 5
        0 -- 5
    }"> </graphviz-graph>
    
    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [x] 1
    - [ ] 2 
    - [ ] 3
    - [ ] 4
    - [ ] 5


!!! exercise choice
    <graphviz-graph graph="
        graph G {
    0 -- 1
    1 -- 2
    3 -- 4
    6 -- 3
    6 -- 4
    7 -- 4
    5
    }"> </graphviz-graph>

    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [ ] 1
    - [ ] 2 
    - [x] 3
    - [ ] 4
    - [ ] 5


Vamos exercitar nossa compreensão dessa definição com algumas questões teóricas.

!!! exercise long
    Dado um grafo $G = (V, A), |V| > 0$, quais são os números mínimo e máximode componentes conexos?

!!! exercise long
    O item 1 da definição só diz que o início e o fim do caminho tem que estar em $C$. É possível existir um caminho entre dois vértices em $C$ que contenha ao menos um vértice que não está em $C$?

--------------

## Um algoritmo simples para componentes conexas

Em IA e TecProg já vimos um algoritmo que lembra muito a definição de Componente Conexo: Busca em Profundidade (DFS)! Como sempre, vamos começar simulando essa ideia para entender como o algoritmo pode ajudar.

!!! exercise long
    Dado o grafo abaixo, comece uma DFS a partir do vértice `D` e numere os vértices de acordo com quando eles forem visitados. 

    A ordem de visitação dos vizinhos de um vértice é alfabética.

    <graphviz-graph graph="
    graph {
    A -- B
    C -- A
    D -- B
    C -- D
    D -- F
    F -- G
    G -- I
    J -- G
    J -- F
    }"><graphviz-graph>

    !!! answer
        O diagrama numerado pela ordem da DFS ficaria como abaixo. Ele é único pois fixamos a ordem de visitação dos vizinhos. Com outra ordem teria outra numeração igualmente válida.

        <graphviz-graph graph="
        graph {
        3 -- 2
        4 -- 3
        1 -- 2
        4 -- 1
        1 -- 5
        5 -- 6
        6 -- 7
        8 -- 6
        8 -- 5
        }"><graphviz-graph>


!!! exercise long
    Dado o grafo abaixo, comece uma DFS a partir do vértice `D` e numere os vértices de acordo com quando eles forem visitados. 

    A ordem de visitação dos vizinhos de um vértice é alfabética.

    <graphviz-graph graph="
    graph {
    A -- B
    C -- A
    D -- B
    C -- D
    F -- G
    G -- J
    I -- G
    I -- F
    }"><graphviz-graph>

    !!! answer
        Na lousa hoje.


Várias coisas relevantes acontecem nos exemplos acima:

1. no primeiro todos os nós são visitados. Isso acontece pois há somente um componente conexo. 
1. ainda no primeiro, quando temos um ciclo (como na sequência `D-B-A-C`) chega um momento em que encontramos um vértice que já foi visitado e que não é o predecessor.  
1. no segundo exemplo iniciamos no vértice `D`, que não conecta com o componente de baixo. Por isso alguns nós ficam sem número quando acabamos a DFS

!!! tip
    Entenda bem as propriedades acima antes de continuar! Elas são importantes no desenvolvimento desse e de outros algoritmos baseados em DFS

Vamos agora formalizar nosso algoritmo `IDENTIFICA-COMPONENTES(G)`. A saída do algoritmo será um array em que cada vértice contém um número identificador de seu componente (começando em 1). Dois vértices estão no mesmo componente se eles possuem o mesmo identificador. Vejamos um exemplo.

**Entrada**:

<graphviz-graph graph="
graph {
A -- B
C -- A
D -- B
C -- D
F -- G
G -- J
I -- G
I -- F
}"><graphviz-graph>


**Saída**: Duas saídas são possíveis: `[ 1, 1, 1, 1, 2, 2, 2, 2 ]` (se começamos em `A, B, C` ou `D`) ou `[ 2, 2, 2, 2, 1, 1, 1, 1 ]` (se começamos em `F, G, I` ou `J`). Visualmente isso seria equivalente a:

<graphviz-graph graph="
graph G {
A[label=&quot;1&quot;] 
B[label=&quot;1&quot;] 
C[label=&quot;1&quot;] 
D[label=&quot;1&quot;] 
F[label=&quot;2&quot;] 
G[label=&quot;2&quot;] 
I[label=&quot;2&quot;] 
J[label=&quot;2&quot;] 
A -- B
C -- A
D -- B
C -- D
F -- G
G -- J
I -- G
I -- F
}"><graphviz-graph>


Já sabemos que o `IDENTIFICA-COMPONENTES` será baseado em DFS e que esse algoritmo depende de algumas outras subrotinas. Você pode supor que os seguintes algoritmos estão disponíveis para usar como subrotinas.

1. `NVERTICES(G)` retorna o número de vértices do grafo 
1. `EH_VIZINHO(G, I, J)` retorna `VERDADEIRO` se os vértices `I` e `J` são ligados por uma aresta
1. todos algoritmos da ADT [Array](https://insper.github.io/tecnicas-de-programacao/modulos/01-ADT/array/) que já usamos em TecProg. 

Com isso já temos o necessário para criar nosso algoritmo. Vamos tentar?

!!! exercise  long
    Escreva o algoritmo `IDENTIFICA-COMPONENTES(G)` abaixo. Você pode criar uma subrotina separada para a parte recursiva se achar conveniente. 

    !!! answer
        Na lousa ;)


## Entrega

Visite a área da disciplina no PrairieLearn e implemente a DFS baseado no seu pseudo-código acima. 








