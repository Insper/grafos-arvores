# Algoritmo de Dijkstra 

<ah-external-content src="../slides-dijkstra.html" />

## Simulações: grafos com pesos

Simule a ideia seguinte com todos os grafos em cada exercício. Iremos usar essas simulações para construir o algoritmo de Dijkstra.

1. A partir da fonte, selecione iterativamente o vértice não visitado `K` com menor distância até a fonte
2. para todos os vizinhos de `K`, atualize suas distâncias até a fonte se o caminho que passa `K` for melhor que o caminho já encontrado
3. marque `K` como visitado
4. continue até não haver mais vértices não visitados ou até chegar ao destino

Você pode usar as seguintes estruturas auxiliares, se quiser:

- `dist` - array com distâncias até a fonte
- `pred` - array com predecessores no menor caminho até o elemento
- `h` - conjunto com vértices já visitados

!!! exercise 
    **Fonte**: A, **Destino**: B
    
    <graphviz-graph graph="digraph {
        A -> C [label=&quot;1&quot;]
        A -> D [label=&quot;5&quot;]
        C -> B [label=&quot;1&quot;]
        B -> D [label=&quot;3&quot;]
    }"> </graphviz-graph>

!!! exercise 
    **Fonte**: D, **Destino**: A

    <graphviz-graph graph="digraph {
        D -> C [label=&quot;3&quot;]
        D -> A [label=&quot;4&quot;]
        D -> E [label=&quot;2&quot;]
        C -> A [label=&quot;2&quot;]
        E -> A [label=&quot;5&quot;]
    }"> </graphviz-graph>


!!! exercise 
    **Fonte**: D, **Destino**: A

    <graphviz-graph graph="digraph {
        D -> C [label=&quot;3&quot;]
        D -> F [label=&quot;4&quot;]
        D -> E [label=&quot;2&quot;]
        C -> A [label=&quot;3&quot;]
        E -> A [label=&quot;5&quot;]
        F -> A [label=&quot;1&quot;]
    }"> </graphviz-graph>

!!! exercise 
    **Fonte**: A, **Destino**: E
    <graphviz-graph graph="digraph {
        A -> B [label=&quot;4&quot;]
        A -> E [label=&quot;7&quot;]
        A -> D [label=&quot;3&quot;]
        B -> E [label=&quot;4&quot;]
        C -> E [label=&quot;3&quot;]
        D -> C [label=&quot;3&quot;]
    }"> </graphviz-graph>


!!! exercise 
    **Fonte**: A, **Destino**: B
    <graphviz-graph graph="digraph {
        A -> B [label=&quot;4&quot;]
        A -> E [label=&quot;7&quot;]
        A -> D [label=&quot;3&quot;]
        B -> E [label=&quot;4&quot;]
        B -> A [label=&quot;1&quot;]
        C -> E [label=&quot;3&quot;]
        C -> B [label=&quot;1&quot;]
        D -> C [label=&quot;3&quot;]
    }"> </graphviz-graph>


!!! exercise 
    **Fonte**: A, **Destino**: B

    <graphviz-graph graph="digraph {
        A -> B [label=&quot;2&quot;]
        A -> C [label=&quot;1&quot;]
        C -> B [label=&quot;1&quot;]
        A -> D [label=&quot;100&quot;]
        D -> B [label=&quot;-150&quot;]
    }"> </graphviz-graph>

    **Atenção**: esse grafo tem pesos negativos! Isso por enquanto não estava nas nossas definições (toda aresta tem peso maior que zero). Vamos só ver o que acontece caso isso exista.


!!! exercise 
    **Fonte**: A, **Destino**: B

    <graphviz-graph graph="digraph {
        A -> B [label=&quot;20&quot;]
        A -> C [label=&quot;10&quot;]
        C -> B [label=&quot;1&quot;]
        A -> D [label=&quot;10&quot;]
        D -> B [label=&quot;15&quot;]
        D -> F [label=&quot;-6&quot;]
        F -> A [label=&quot;-6&quot;]
    }"> </graphviz-graph>

    **Atenção**: esse grafo tem pesos negativos! Isso por enquanto não estava nas nossas definições (toda aresta tem peso maior que zero). Vamos só ver o que acontece caso isso exista.


## Min-heap

!!! exercise long
    Escreva a representação em array do heap abaixo
    
    <ah-diagram>
    graph TD
        n1(1) --- n2(5)
        n1 --- n3(9)
        n2 --- n4(10)
        n2 --- n5(44)
        n3 --- n6(11)
        n3 --- n7(44)
        n4 --- n8(13)
        n4 --- n9(55)
        n5 --- n10(46)
    </ah-diagram>

    !!! answer
        `1 5 9 10 44 11 44 13 55 46`

!!! exercise long
    Execute `MENOR` no heap abaixo e escreva sua representação em array.

    <ah-diagram>
    graph TD
        n1(1) --- n2(5)
        n1 --- n3(9)
        n2 --- n4(10)
        n2 --- n5(44)
        n3 --- n6(11)
        n3 --- n7(44)
        n4 --- n8(13)
        n4 --- n9(55)
        n5 --- n10(46)
    </ah-diagram>

    !!! answer
        `5 10 9 13 44 11 44 46 55`


!!! exercise long
    Execute `INSERE(3)` no heap abaixo e escreva sua representação em array.

    <ah-diagram>
    graph TD
        n1(1) --- n2(5)
        n1 --- n3(9)
        n2 --- n4(10)
        n2 --- n5(44)
        n3 --- n6(11)
        n3 --- n7(44)
        n4 --- n8(13)
        n4 --- n9(55)
        n5 --- n10(46)
    </ah-diagram>

    !!! answer
        `1 3 9 10 5 11 44 13 55 46 44`


## Entregas

Implementações de min-heap e Dijkstra no PrairieLearn
