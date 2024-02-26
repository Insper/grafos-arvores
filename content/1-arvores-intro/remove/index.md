<script src=https://unpkg.com/graphviz-webcomponent@2.0.0/dist/graph-bundled.min.js></script>

# Remoção 

Remover elementos de árvores é uma operação mais complicada que inserção e busca. Esta aula será auto-guiada: os exemplos e exercícios devem levá-los à construção de um algoritmo para remoção de nós de uma árvore usando operações de rotação (que definiremos a seguir).

Os algoritmos serão comentados na próxima aula.

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
        Cada rotação aumenta o nível do nó em 1. Logo, precisamos de no máximo 10 rotações e isso ocorre quando desejamos tornar a raiz uma folha. Em geral, para um nó raiz (nível 0) chegar a ser folha (nível $h$) precisamos de $h$ rotações. 

Conseguimos descer um nó de nível fazendo uma **rotação** na árvore. A figura abaixo exemplifica rotações para ambos os lados. Note que em ambos os casos a subárvore muda de raiz.

![Animação feita por TarElessar](rotacoes.gif)
**Fonte**: [Feito por TarElessar](https://commons.wikimedia.org/wiki/File:Tree_rotation_animation_250x250.gif)

- Na **rotação à esquerda** desceremos de nível a raiz $A$. Chamamos o elemento $B$ à direita de $A$ de **pivô**, já que ele será a nova raiz. A subárvore $\beta$ muda da direita de $B$ para a esquerda de $A$.
- Na **rotação à direita** desceremos de nível a raiz $B$. Chamamos o elemento $A$ à esquerda de $B$ de **pivô**, já que ele será a nova raiz. A subárvore $\beta$ muda da esquerda de $A$ para a direita de $B$.

!!! exercise long
    Escreva um algoritmo `ROTACAO-DIREITA(R)` que recebe um nó de uma *ABB* e devolve a nova raiz dessa subárvore depois de fazer uma rotação à direita. Simule seu algoritmo com o grafo abaixo e tentando rotacionar os elementos a seguir.

    
    <graphviz-graph graph="
    digraph G {
        20 -> 10
        20 -> 50
        10 -> 6 
        10 -> n1
        6 -> 3
        6 -> n2
        3 -> 1
        3 -> n3
        50 -> 30
        50 -> n4
        30 -> 25
        30 -> 40
        25 -> n5
        25 -> 29
        n1 [shape=point]
        n2 [shape=point]
        n3 [shape=point]
        n4 [shape=point]
        n5 [shape=point]
    }" />

    1. Rotacionar elemento 1
    2. Rotacionar elemento 6
    3. Rotacionar elemento 50
    4. Rotacionar elemento 30

    !!! answer
        Lousa

## Algoritmo para remoção

Agora que conseguimos "descer" um elemento de nível, temos um algoritmo de remoção baseado em rotações que é bem simples:

1. encontre o nó a ser removido
2. rotacione a árvore para a direita  até que esse nó esteja em um dos 3 casos fáceis acima.
3. remova o nó de acordo com as explicações dos 3 casos fáceis
4. devolva a nova raiz da subárvore que iniciava no elemento removido

Vamos simular essa ideia para o grafo abaixo. Todas as rotações serão feitas para a direita. 

<graphviz-graph graph="digraph G {
50 -> 30
50 -> 70
30 -> 10
30 -> 35
10 -> 5
10 -> n2
70 -> 65
70 -> 71
71 -> n1
71 -> 75
n1 [shape=point]
n2 [shape=point]
}" />

!!! exercise
    Simule a remoção do elemento 10

    !!! answer 
        A remoção do `10` é o caso fácil **2**. Para removê-lo basta fazer seu pai (`30`) apontar para a subárvore do nó `5`. O grafo ficaria como abaixo. 

        <graphviz-graph graph="digraph G {
        50 -> 30
        50 -> 70
        30 -> 5
        30 -> 35
        70 -> 65
        70 -> 71
        71 -> n1
        71 -> 75
        n1 [shape=point]
        }" />

!!! exercise
    Simula a remoção do elemento `70`

    !!! answer 
        O nó `70` tem dois filhos, portanto será necessário fazer rotações para descê-lo na árvore até chegar em dos casos fáceis. 

        **Passo 1**: rotação à direita

        <graphviz-graph graph="digraph G {
        50 -> 30
        50 -> 65
        65 -> n4
        65 -> 70
        70 -> n3
        70 -> 71
        30 -> 10
        30 -> 35
        10 -> 5
        10 -> n2
        71 -> n1
        71 -> 75
        n1 [shape=point]
        n2 [shape=point]
        n3 [shape=point]
        n4 [shape=point]
        }" />

        **Passo 2**: Agora o `70` está na posição do caso fácil **1**! Podemos então só apontar o nó direito de `65` para a subárvore `71`

        <graphviz-graph graph="digraph G {
        50 -> 30
        50 -> 65
        65 -> n4
        65 -> 71
        30 -> 10
        30 -> 35
        10 -> 5
        10 -> n2
        71 -> n1
        71 -> 75
        n1 [shape=point]
        n2 [shape=point]
        n4 [shape=point]
        }" />

!!! exercise
    Simula a remoção do elemento `50`

    !!! answer 
        O `50` tem ambos os filhos, então precisaremos rotacioná-lo algumas vezes até chegar em um caso fácil.

        **Passo 1**: rotação

        <graphviz-graph graph="digraph G {
        30 -> 10
        30 -> 50
        10 -> 5
        10 -> n2
        50 -> 35
        50 -> 70
        70 -> 65
        70 -> 71
        71 -> n1
        71 -> 75
        n1 [shape=point]
        n2 [shape=point]
        }" />

        **Passo 2**: ainda não é um caso fácil. Rotaciona de novo

        <graphviz-graph graph="digraph G {
        30 -> 10
        30 -> 35
        10 -> 5
        10 -> n2
        35 -> n4
        35 -> 50
        50 -> n3
        50 -> 70
        70 -> 65
        70 -> 71
        71 -> n1
        71 -> 75
        n1 [shape=point]
        n2 [shape=point]
        n3 [shape=point]
        n4 [shape=point]
        }" />

        **Passo 3**: caso fácil **1** de novo! Basta tirar o `50` e fazer a raiz da subárvore se o elemento `70`. 

        <graphviz-graph graph="digraph G {
        30 -> 10
        30 -> 35
        10 -> 5
        10 -> n2
        35 -> n4
        35 -> 70
        70 -> 65
        70 -> 71
        71 -> n1
        71 -> 75
        n1 [shape=point]
        n2 [shape=point]
        n4 [shape=point]
        }" />

Notem que em alguns casos a remoção de um elemento fez a altura da árvore aumentar! Esse é uma das principais dificuldades em criar árvores balanceadas: quanto mais mexemos na árvore maior a chance de criarmos árvores altas. O vídeo abaixo exemplifica o algoritmo da [AVL](https://en.wikipedia.org/wiki/AVL_tree), uma árvore balanceada relativamente simples.

??? tip "Vídeo explicativo"
    !!! video
        ![](https://www.youtube.com/watch?v=zP2xbKerIds)

## O algoritmo `REMOVE`

Agora que já simulou o algoritmo algumas vezes está na hora de formalizá-lo. 

!!! exercise long
    Escreva um algoritmo `REMOVE(R, K)` que remove o nó `K` da árvore `R`, devolvendo uma nova raiz da árvore se necessário. Você pode supor que as seguintes funções existem:

    - `REMOVE-RAIZ(R)` remove a raiz de uma árvore, devolvendo a nova raiz. 

    !!! answer
        ```
        REMOVE(R, K)

        SE R.key == K ENTÃO
            DEVOLVE REMOVE-RAIZ(R)
        SENÃO SE K < R.key ENTÃO
            R.left = REMOVE(R.left, K)
        SENÃO SE K > R.key ENTÃO
            R.right = REMOVE(R.right, K)
        FIM

        DEVOLVE R
        ```

!!! exercise long
    Escreva um algoritmo recursivo `REMOVE-RAIZ(R)` que remove a raiz `R` da árvore e devolve a nova raiz. Use rotações para a direita como foi feito no exercício anterior.

    !!! answer
        Lousa


!!! warning "Desafio"
    É possível fazer a remoção usando só o caso do nó escolhido ser folha. Você consegue?


## Prática

Implemente o algoritmo deste handout no PrairieLearn.
