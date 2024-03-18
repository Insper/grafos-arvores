<style>
.mermaid {
    font-size: 10pt;
}
</style>

# Grafos e Árvores

## Componentes conexas

--------

# Identificação de regiões isoladas

No carnaval de 2023 tivemos regiões fortes em diversas partes do litoral do Estado de São Paulo. Isso provocou deslizamentos de terras e muitas estradas foram danificadas ou fechadas por risco de desabamentos. Gostaríamos de saber se regiões do estado ficaram isoladas devido a esse acontecimento. Vamos modelar esse problema com grafos:

- O que são os vértices nesse problema?
- E as arestas?

---------------

# Identificação de regiões isoladas

No carnaval de 2023 tivemos regiões fortes em diversas partes do litoral do Estado de São Paulo. Isso provocou deslizamentos de terras e muitas estradas foram danificadas ou fechadas por risco de desabamentos. Gostaríamos de saber se regiões do estado ficaram isoladas devido a esse acontecimento. Vamos modelar esse problema com grafos:

- Vértices = cidades do estado
- Arestas = estradas ligando cidades
- Como representar essa pergunta usando vocabulário de grafos?

-----------

# Definição - Caminho

Um *caminho* $\pi$ de tamanho $n$ em um grafo $G = (V, A)$ é uma sequência de vértices $v_1, \dots, v_n \in V$ tal que a aresta $v_i\textemdash v_{i+1}$ está em $A$

#### Dizemos que $pi$ começa em $v_1$ e termina em $v_n$

----------

# Definição - Componente Conexo

Seja $G = (V, A)$ um grafo não direcionado, um subconjunto $C \subseteq V$  de vértices é um *componente conexo* se e somente se

1. para todos par de vértices $v, w \in C$ existe um caminho que começa em $v$ e termina em $w$
2. para todo $v \in C$ e $w \in V - C$, não existe caminho entre $v$ e $w$.

------------

# Existem regiões do estado que ficaram isoladas?

## Pergunta formulada usando vocabulário de grafos agora

-----------

# Existem regiões do estado que ficaram isoladas?

## Existe mais de um componente conexo no grafo?

----------

# Interpretação

- Componentes conexas são conjuntos de vértices isolados uns dos outros
- **Não há** caminho entre **grupos** de vértices de componentes diferentes
- **Há caminho** entre **grupos** de vértices do mesmo componente
* Todo grafo tem no mínimo 1 e no máximo $V$ componentes

---------------

# Problemas relacionados

1. Segmentação de Imagens
    - área enorme de processamento de imagens baseada em grafos
2. Dependências em projetos 
3. Agrupamentos (clustering)

-------------

# Como contar Componentes Conexos?

<!--
graph LR
    A --- B
    B --- D
    D --- A 
    D --- F

    G --- T
    T --- I
    I --- G
    J --- I
    J --- G

    Z --- W
    Z --- Y
-->

[![](https://mermaid.ink/img/pako:eNpNz8EKgzAMBuBXKTnrC_SmdBNlp00YG70EG6dgq3TtYYjvvq6dYE75-P9DskI3KwIOL4vLwC5XaViYguV5zsqEMkIkiIiCHXWWJrGKbBPaiDqhjqgSmmPS7EniM_J-xAMy0GQ1jiocuv4iCW4gTRJ4WBX16CcnQZotVP2i0NFJjW62wHuc3pQBejffPqYD7qynvSRGDH_rf2v7AhlISCw?type=png)](https://mermaid.live/edit#pako:eNpNz8EKgzAMBuBXKTnrC_SmdBNlp00YG70EG6dgq3TtYYjvvq6dYE75-P9DskI3KwIOL4vLwC5XaViYguV5zsqEMkIkiIiCHXWWJrGKbBPaiDqhjqgSmmPS7EniM_J-xAMy0GQ1jiocuv4iCW4gTRJ4WBX16CcnQZotVP2i0NFJjW62wHuc3pQBejffPqYD7qynvSRGDH_rf2v7AhlISCw)

-------------

# Busca em Profundidade (DFS)

- Visita todos os vértices acessíveis a partir da raiz
- Precisa chamar mais de uma vez
- Pode ser usada para identificar componentes além de somente contá-los

---------


# Atividades

1. seguir handout do dia com mais detalhes sobre Componentes Conexas
2. implementar DFS para identificar componentes em grafos (PrairieLearn)


