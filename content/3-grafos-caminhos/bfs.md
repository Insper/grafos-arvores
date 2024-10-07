# Busca em Largura

<ah-external-content src="../bfs-slides.html" />

Nesta aula iremos simular a busca em largura (BFS) em dois grafos e compará-la com a busca em profundidade (DFS) para encontrar caminhos entre dois vértices.

## Grafo 1

Queremos encontrar o menor caminho entre **A** e **F**

<graphviz-graph graph="graph {
A -- B
A -- C
A -- E
B -- D
B -- C
D -- E
E -- F
}"> </graphviz-graph>

!!! exercise long
    Use o campo abaixo para anotações sobre esta simulação.

## Grafo 2

Vamos encontrar o menor caminho entre **A** e **G**

<graphviz-graph graph="
graph {
    A -- G
    A -- B
    B -- C
    C -- G
    C -- D
    C -- E
    D -- E
    E -- G
    E -- F
    F -- G
}">
</graphviz-graph>

!!! exercise long 
    Use o campo abaixo para anotações sobre esta simulação.

## Entrega

Teremos 2 entregas nessa aula:

- implementação de um tipo de dados `queue_t` seguindo a estrutura do arquivo `queue.h`
- implementação da busca em largura usando essa ED


