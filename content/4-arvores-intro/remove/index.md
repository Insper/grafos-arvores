<script src=https://unpkg.com/graphviz-webcomponent@2.0.0/dist/graph-bundled.min.js></script>

# Remoção 

Remover elementos de árvores é uma operação mais complicada que inserção e busca. Esta aula será auto-guiada: os exemplos e exercícios devem levá-los à construção de um algoritmo para remoção de nós de uma árvore usando operações de rotação (que definiremos a seguir).

Os algoritmos serão comentados em sala de aula no dia 30/10.

## Casos fáceis da remoção

O caso mais fácil é quando **o elemento a ser removido é uma folha**.

<graphviz-graph graph="digraph D {
    label=&quot;Remoção do elemento 10 - folha&quot;
    subgraph cluster1 {
        label=&quot;Antes&quot;
        5 -> 3
        5 -> 10
    }
    subgraph cluster2 {
        label=&quot;Depois&quot;
        a2[label=&quot;5&quot;]
        a3[label=&quot;3&quot;]
        n1[shape=point]
        a2 -> a3
        a2 -> n1
        n1[shape=point]
    }
}"> </graphviz-graph>

Outro caso fácil é quando **o elemento a ser removido não tem um dos filhos**. Veja abaixo os dois casos possíveis.

<graphviz-graph graph="
digraph D {
    label=&quot;Remoção do elemento 10 - sem filho esquerdo&quot;
    subgraph cluster1 {
        label=&quot;Antes&quot;
        5 -> 3
        5 -> 10
        10 -> n11
        10 -> 15
        15 -> 13
        15 -> 25
        n11[shape=point]
    }
    subgraph cluster2 {
        label=&quot;Depois&quot;
        a2[label=&quot;5&quot;]
        a3[label=&quot;3&quot;]
        a4[label=&quot;15&quot;]
        a5[label=&quot;13&quot;]
        a6[label=&quot;25&quot;]
        invis[style=invis]
        a2 -> a3
        a2 -> a4
        a4 -> a5
        a4 -> a6
        a6 -> invis[style=invis]
    }
}" > </graphviz-graph>


<graphviz-graph graph="
digraph D {
    label=&quot;Remoção do elemento 10 - sem filho direito&quot;
    subgraph cluster1 {
        label=&quot;Antes&quot;
        5 -> 3
        5 -> 10
        10 -> 7
        7 -> 6
        7 -> 9
        10 -> n11
        n11[shape=point]
    }
    subgraph cluster2 {
        label=&quot;Depois&quot;
        a2[label=&quot;5&quot;]
        a3[label=&quot;3&quot;]
        a4[label=&quot;7&quot;]
        a5[label=&quot;6&quot;]
        a6[label=&quot;9&quot;]
        invis[style=invis]
        a2 -> a3
        a2 -> a4
        a4 -> a5
        a4 -> a6
        a6 -> invis[style=invis]
    }
}" > </graphviz-graph>


## O caso complicado: nó tem dois filhos

Agora falta só descobrir o que fazer quando o nó a ser removido tem ambos os filhos. Apesar de isso parecer complicado. Veremos como aplicar operações na árvore de maneira que sempre chegaremos em um caso fácil!

O caso mais simples com dois filhos é a árvore balanceada com 3 elementos e fazendo a remoção do elemento raiz (`10` no exemplo abaixo)

<graphviz-graph graph="
digraph G {
10 -> 5
10 -> 15
}
" />

Para conseguirmos chegar em um caso fácil precisaríamos fazer o `10` virar

1. ou um nó com filho direito e sem filho esquerdo
2. ou um nó com filho esquerdo e sem filho direito
3. ou uma folha

!!! exercise
    Redesenhe a árvore acima fazendo com que o nó `10` esteja em cada uma das três posições acima. 

    !!! answer
        1. `10` tem filho esquerdo e não direito

            <graphviz-graph graph="
            digraph G {
                15 -> 10
                15 -> n1
                10 -> 5
                10 -> n2
                n1 [shape=point]
                n2 [shape=point]
            }" />
        3. `10` tem filho direito e não esquerdo

            <graphviz-graph graph="
            digraph G {
                5 -> n1
                5 -> 10
                10 -> n2
                10 -> 15
                n1 [shape=point]
                n2 [shape=point]
            }" />
        1. `10` é folha são dois casos possíveis

            <graphviz-graph graph="
            digraph g {
                15 -> 5
                15 -> n1
                5 -> n2
                5 -> 10
                n1 [shape=point]
                n2 [shape=point]
            }" /> 

            <graphviz-graph graph="
            digraph G {
                5 -> n1
                5 -> 15
                15 -> 10
                15 -> n2
                n1 [shape=point]
                n2 [shape=point]
            }" />

Note que nos 3 casos o nó `10` *desceu de nível na árvore.* Ele inicia na raiz (nível 0) e desce para o nível 1 (nos casos 1 e 2) e nível 2 (no caso 3). 

!!! exercise short
    Em uma árvore com altura $h = 10$, qual é o número máximo de rotações necessárias para fazer um nó qualquer da árvore se tornar uma folha?

    !!! answer
        Cada rotação aumenta o nível do nó em 1. Logo, precisamos de no máximo 10 rotações e isso ocorre quando desejamos tornar a raiz uma folha.

Conseguimos descer um nó de nível fazendo uma **rotação** na árvore. A figura abaixo exemplifica rotações para ambos os lados. Note que em ambos os casos a subárvore muda de raiz.

![Animação feita por TarElessar](rotacoes.gif)
**Fonte**: [Feito por TarElessar](https://commons.wikimedia.org/wiki/File:Tree_rotation_animation_250x250.gif)

- Na **rotação à esquerda** desceremos de nível a raiz $A$. Chamamos o elemento $B$ à direita de $A$ de **pivô**, já que ele será a nova raiz. A subárvore $\beta$ muda da direita de $B$ para a esquerda de $A$.
- Na **rotação à direita** desceremos de nível a raiz $B$. Chamamos o elemento $A$ à esquerda de $B$ de **pivô**, já que ele será a nova raiz. A subárvore $\beta$ muda da esquerda de $A$ para a direita de $B$.

!!! exercise long
    Escreva um algoritmo `ROTACAO-DIREITA(R)` que recebe um nó de uma *ABB* e devolve a nova raiz dessa subárvore depois de fazer uma rotação à direita. Simule seu algoritmo com o grafo abaixo e tentando rotacionar os três elementos passados.

    TODO: grafo + 3 elementos

    !!! answer
        Lousa
    

Agora que conseguimos "descer" um elemento de nível, temos um algoritmo de remoção baseado em rotações que é bem simples:

1. encontre o nó a ser removido.
2. rotacione a árvore até que esse nó esteja em um dos 3 casos fáceis acima.
3. remova o nó de acordo com as explicações dos 3 casos fáceis



