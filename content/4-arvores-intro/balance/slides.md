
<script src=https://unpkg.com/graphviz-webcomponent@2.0.0/dist/graph-bundled.min.js></script>

# Grafos e Árvores

## Balanceamento de ABBs

--------

A ordem de inserção afeta diretamente a altura de nossas árvores!

<graphviz-graph graph='
digraph G {
1 -> n1
1 -> 2
2 -> n2
2 -> 3
3 -> n3
3 -> 4
4 -> n4
4 -> 5
5 -> n5
5 -> 6
n1 [shape=point]
n2 [shape=point]
n3 [shape=point]
n4 [shape=point]
n5 [shape=point]
}
' />


-----------------

A ordem de inserção afeta diretamente a altura de nossas árvores!

<graphviz-graph graph='
digraph G {
3 -> 2
3 -> 5
2 -> 1
2 -> n1
5 -> 4
5 -> 6
n1 [shape=point]
}
' />

-----------------

- A altura $h$, portanto, pode no pior caso ser $\mathcal{O}(N)$. 
- O desempenho médio não é ruim: $E(h) = \mathcal{O}\log N$
- Seria uma boa conseguir "consertar" uma árvore ruim!

----------------------

# Balanceamento

**Definição**: uma (sub)árvore com $N$ elementos está balanceada se $h = \log N$.

<!--está desbalanceada se a altura de sua subárvore esquerda difere da altura da subárvore direita por mais de um.

$|h_L - h_R| > 1$

- $h_L$ é a altura da subárvore esquerda
- $h_R$ é a altura da subárvore direita 
-->
---------------------

# Alguma primeira ideia de como balancear uma árvore?

-----

# Dica 1: pode usar array auxiliar

--------

# Dica 2: pode criar uma nova árvore

--------

# Balanceamento (I)

1. passa por todos elementos em-ordem, guardando o valor em um array
2. insere como raiz o elemento do meio do array
3. faz o passo *2* recursivamente para cada lado do array

-------

# Balanceamento (I)

- Qual a complexidade computacional disso?
- Qual o consumo de espaço disso?

-----

# Balanceamento (I)

### Isso é bom?

--------

# Balanceamento (II)

### Extra: procure pelo algoritmo Day-Stout-Warren

-----------

# Árvores balanceadas

Algoritmos de inserção/remoção que mantém $h = \log N$

- AVL 
- Red-Black Tree

**Não veremos nesta disciplina**


