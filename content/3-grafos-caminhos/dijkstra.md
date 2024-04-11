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
    <ah-diagram>
    graph LR
        A -- 1 --> C
        A -- 5 --> D
        C -- 1 --> B
        B -- 3 --> D
        linkStyle default color: red
    </ah-diagram>

!!! exercise 
    **Fonte**: D, **Destino**: A
    <ah-diagram>
    graph LR
        D -- 3 --> C
        D -- 4 --> A
        D -- 2 --> E
        C -- 2 --> A
        E -- 5 --> A
        linkStyle default color: red
    </ah-diagram>

!!! exercise 
    **Fonte**: D, **Destino**: A
    <ah-diagram>
    graph LR
        D -- 3 --> C
        D -- 4 --> F
        D -- 2 --> E
        C -- 3 --> A
        E -- 5 --> A
        F -- 1 --> A
        linkStyle default color: red
    </ah-diagram>

!!! exercise 
    **Fonte**: A, **Destino**: E
    <ah-diagram>
    graph LR
        A -- 4 --> B
        A -- 7 --> E
        A -- 3 --> D
        B -- 4 --> E
        C -- 3 --> E
        D -- 3 --> C
        linkStyle default color: red
    </ah-diagram>

!!! exercise 
    **Fonte**: A, **Destino**: B
    <ah-diagram>
    graph LR
        A -- 4 --> B
        A -- 7 --> E
        A -- 3 --> D
        B -- 4 --> E
        B -- 1 --> A
        C -- 3 --> E
        C -- 0 --> B
        D -- 3 --> C
        linkStyle default color: red
    </ah-diagram>

!!! exercise 
    **Fonte**: A, **Destino**: B
    <ah-diagram>
    graph LR
        A -- 2 --> B
        A -- 0 --> C
        C -- 1 --> B
        A -- 100 --> D
        D -- -150 --> B
        linkStyle default color: red
    </ah-diagram>

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
