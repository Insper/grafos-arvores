
<script src=https://unpkg.com/graphviz-webcomponent@2.0.0/dist/graph-bundled.min.js></script>

# Balanceamento de árvores

<ah-external-content src="slides.html" />

Vamos começar revisando conceitos básicos.

!!! exercise choice
    Qual a altura da árvore abaixo?

    <graphviz-graph graph='
        digraph G {
            4 -> n1
            4 -> 15
            15 -> 6
            15 -> 25
            6 -> 5
            6 -> 10
            n1 [shape=point]
        }
    ' />

    - [ ] 2
    - [ ] 4
    - [x] 3
    - [ ] 1

!!! exercise choice
    Qual a altura da árvore abaixo?

    <graphviz-graph graph='
        digraph G {
            15 -> 3
            15 -> 25
            3 -> 1
            3 -> n1
            25 -> 20
            25 -> n2
            20 -> n3
            20 -> 21
            21 -> n4
            21 -> 22
            n1 [shape=point]
            n2 [shape=point]
            n3 [shape=point]
            n4 [shape=point]
        }
    ' />

    - [ ] 2
    - [x] 4
    - [ ] 3
    - [ ] 1


Como vimos na expositiva, a ordem de inserção afeta diretamente a altura das ABBs. 

!!! exercise 
    Insira os seguintes nós em uma ABB. 

    `5 7 11 33 3 15 2`

    !!! answer
        Sua resposta deverá ser como a abaixo

        <graphviz-graph graph='
            digraph G {
                5 -> 3
                5 -> 7
                3 -> 2
                3 -> n1
                7 -> n2
                7 -> 11
                11 -> n3
                11 -> 33
                33 -> 15
                33 -> n4
                n1 [shape=point] 
                n2 [shape=point] 
                n3 [shape=point] 
                n4 [shape=point] 
            }
        ' />


!!! exercise choice
    Qual das ordens de inserção abaixo resulta na árvore com menor altura?

    - [ ] `60 10 20 40 30 50`
    - [ ] `10 50 60 30 20 40`
    - [x] `30 20 10 50 40 60`
    - [ ] `50 60 40 20 30 10`

    !!! answer
        Desenhe todas e veja :)

Vamos relembrar o algoritmo visto na parte expositiva:

1. passe por todos elementos em-ordem, guardando o valor em um array
2. insira como raiz o elemento do meio do array
3. faça o passo *2* recursivamente para cada lado do array

Podemos interpretar esse algoritmo como um que encontra a melhor ordem de inserção. Vamos exercitar isso nos exercícios abaixo.

----------

Usaremos a seguinte árvore nos próximos exercícios. A ideia deles é executar os 3 passos acima para um exemplo completo de árvore.

<graphviz-graph graph='
digraph G {
73 -> 1
73 -> 91
1 -> n1
1 -> 10
10 -> n2
10 -> 30
30 -> 20
30 -> 35
35 -> n4
35 -> 55
91 -> 90
91 -> n5
n1 [shape=point]
n2 [shape=point]
n4 [shape=point]
n5 [shape=point]
}' />

!!! exercise short
    Passe pelos nós da árvore em-ordem e coloque-os abaixo.

    !!! answer
        1 10 20 30 35 55 73 90 91

Com este resultado na mão, vamos começar a determinar uma ordem de inserção para que a árvore fique balanceada. Se ficar em dúvida, reveja o passo 2 do algoritmo acima. 

!!! exercise choice
    Qual é o primeiro elemento a ser inserido?

    - [x] 35
    - [ ] 30
    - [ ] 55
    - [ ] 20
    - [ ] 73

    !!! answer
        O elemento 35 está exatamente no meio do array ordenado, logo ele precisa ser o primeiro para que a árvore esteja balanceada!

Vamos agora inserir todos valores menores que a raiz. Aqui temos um problema: com 4 valores no array, não tem um que esteja exatamente no meio. 

!!! exercise short
    Vamos tentar então pegando o elemento à esquerda do meio: 10. Aplique a ideia recursivamente e liste abaixo a ordem ideal de inserção.

    !!! answer
        `10 1 20 30` 

!!! exercise short
    Vamos tentar então pegando o elemento à direita do meio: 20. Aplique a ideia recursivamente e liste abaixo a ordem ideal de inserção.

    !!! answer
        `20 10 1 30`

!!! exercise long
    Agora desenhe as duas árvores dox exercícios anteriores e responda: faz diferença qual das opções escolhemos, em termos de balanceamento da árvore?

    !!! answer
        Vamos iniciar olhando os desenhos. Primeiro temos a ordem de inserção com a mediana esquerda:
        
        <graphviz-graph graph=' 
            digraph G {
                10 -> 1
                10 -> 20
                20 -> n1
                20 -> 30
                n1 [shape=point]
            }
        ' />

        Depois a ordem com a mediana direita:

        <graphviz-graph graph=' 
            digraph G {
                20 -> 10
                10 -> 1
                10 -> n1
                20 -> 30
                n1 [shape=point]
            }
        ' />

        Como ambas tem a mesma altura, então elas são equivalentes quando ao balanceamento da árvore da solução. Para padronizar, **sempre usaremos a mediana esquerda** em nosso algoritmo.



O processo pode ser repetido para os elementos maiores que a raiz para obter a ordem de inserção completa. Escreva ela abaixo.

!!! exercise short
    A ordem de inserção completa para a árvore balanceada é:

    **Antes de submeter, desenhe a árvore com essa ordem de inserção e verifique se ela está com altura ótima.**

    !!! answer
        A solução final é `35 10 1 20 30 73 55 90 91`. A árovre fica como abaixo:

        <graphviz-graph graph='
        digraph G {
            35 -> 10
            10 -> 1
            10 -> 20
            20 -> n1
            20 -> 30
            35 -> 73
            73 -> 55
            73 -> 90
            90 -> n2
            90 -> 91
            n1 [shape=point]
            n2 [shape=point]
        }' />
        

-----------

Finalmente, escreva o algoritmo completo abaixo.

!!! exercise long
    Escreva em pseudo-código um algoritmo `TREE-TO-ARRAY(R)` querecebe uma árvore `R` e devolve um array ordenado com os valores em `R`

    !!! answer
        Lousa

!!! exercise long
    Escreva em pseudo-código um algoritmo `REBALANCEIA(R)` que recebe uma árovore enraizada em `R` e devolve uma nova árvore balanceada que tenha os mesmos valores que `R`
    
    !!! answer
        Feito na lousa

## Entrega

Exercícios de implementação no PrairieLearn

