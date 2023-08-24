# Componentes Conexos em Grafos

TODO: slides

Seja $G = (V, A)$ um grafo não direcionado sem pesos. Um subconjunto $C \subseteq V$  de vértices é um *componente conexo* se e somente se

1. para todos par de vértices $v, w \in C$ existe um caminho que começa em $v$ e termina em $w$
2. para todo $v \in C$ e $w \in V \\ C$, não existe caminho entre $v$ e $w$.

Vamos praticar um pouco a identificação de componentes conexas?

!!! exercise choice
    <ah-diagram>
    graph LR
    0 --- 1
    0 --- 2
    1 --- 2
    3 --- 4
    4 --- 5
    </ah-diagram>

    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [ ] 1
    - [x] 2 
    - [ ] 3
    - [ ] 4
    - [ ] 5

!!! exercise choice
    <ah-diagram>
    graph LR
    0 --- 1
    0 --- 2
    1 --- 2
    3 --- 4
    4 --- 5
    0 --- 5
    </ah-diagram>

    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [x] 1
    - [ ] 2 
    - [ ] 3
    - [ ] 4
    - [ ] 5


!!! exercise choice
    <ah-diagram>
    graph LR
    0 --- 1
    1 --- 2
    3 --- 4
    6 --- 3
    6 --- 4
    7 --- 4
    5[5]
    </ah-diagram>

    Quantos componentes conexos tem o grafo acima?

    - [ ] 0
    - [ ] 1
    - [x] 2 
    - [ ] 3
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

    <ah-diagram>
    graph LR
    A --- B
    C --- A
    D --- B
    C --- D
    D --- F
    F --- G
    G --- I
    J --- G
    J --- F
    </ah-diagram>

    !!! answer
        O diagrama numerado pela ordem da DFS ficaria como abaixo. Ele é único pois fixamos a ordem de visitação dos vizinhos. Com outra ordem teria outra numeração igualmente válida.

        <ah-diagram>
        graph LR
        A --- B
        C(4) --- A(3)
        D(1) --- B(2)
        C --- D
        D --- F(5)
        F --- G(6)
        G --- I(7)
        J(8) --- G
        J --- F
        </ah-diagram>


!!! exercise long
    Dado o grafo abaixo, comece uma DFS a partir do vértice `D` e numere os vértices de acordo com quando eles forem visitados. 

    A ordem de visitação dos vizinhos de um vértice é alfabética.

    <ah-diagram>
    graph LR
    A --- B
    C --- A
    D --- B
    C --- D
    F --- G
    G --- J
    I --- G
    I --- F
    </ah-diagram>

    !!! answer
        Na lousa hoje.


Numerar vértices em três exemplos: um componente semciclo, dois compnentes (com ciclo e sem ciclo)

Revisar quando aplicamos esse algoritmo para o Labirinto em TecProg e pedir pro aluno listar variáveis de estado do algoritmo

Escrever pseudo código como exercício aqui. Usar ADT grafo que criamos

(resposta na próxima aula nalousa)

exercício de código no PL. Contador de componentes conexas. Devolve número mais um vetorcom o component id de cada vértice







