
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

**Ideia**: uma (subárvore) está desbalanceada se a altura de sua subárvore esquerda difere da altura da subárvore direita por mais de um.

$|h_L - h_R| > 1$

- $h_L$ é a altura da subárvore esquerda
- $h_R$ é a altura da subárvore direita 

---------------------


# Balanceamento

Como dar um passo em direção a uma árvore melhor balanceada? 

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

--------------------------------------



