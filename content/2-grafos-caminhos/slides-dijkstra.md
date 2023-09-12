<style>
.mermaid {
    font-size: 10pt;
}
</style>

# Grafos e Árvores

## Caminhos mínimos (com pesos)

--------

# Busca em Profundidade (DFS)

- Algoritmo recursivo curto que encontra todos os vértices acessíveis a partir da raiz

- Útil para problemas como
    - identificar/contar componentes conexos
    - encontrar ciclos
    - ordenação topológica

-------

# Caminhos mínimos

Dados vértices $v$ e $w$, encontrar o caminho de menor tamanho entre eles.

- Busca em Largura -> grafos sem pesos
- E se tem pesos?

----

# Think-pair-share

Teremos uma sequência de perguntas sobre grafos com pesos

1. reservem um lugar para anotar suas ideias
2. escolham uma dupla
3. para cada pergunta, 30s para pensar em uma resposta
4. 30s para discutir com sua dupla
5. 1m para compartilhar ideias na sala 

----

# A busca em largura funciona em grafos com pesos?

## Se sim explique, se não dê um contra-exemplo

---

# E se modificássemos a BFS para pegar as menores arestas primeiro?

## Isso funciona? Se sim explique, se não dê um contra-exemplo

-----

# E se modificássemos a BFS para pegar os vértices mais próximos primeiro?

## Isso funciona? Se sim explique, se não dê um contra-exemplo

----

# Vamos pro handout!

## 15 min

-----

# Conclusões?

----

# Algoritmo de Dijkstra

- menor caminho em grafos com pesos não negativos
- ideia central: **iterativamente pegar o vértice mais próximo da fonte**
- implementação "ingênua": $\mathcal{O}(V^2)$

----

# Algoritmo de Dijkstra

**Entradas**: 

- $G=(V, E)$ um grafo direcionado com pesos não negativos 
- uma matriz $P \in \mathbb{R}^{|V|,|V|} em que o elemento $P_{i,j}$ representa o peso da aresta que sai de $i$ e chega em $j$
-  $s, t \in V$ dois vértices (fonte e destino)

**Auxiliares**:

- array `pred` de tamanho $|V|$ inicializado com `-1`
- array `dist` de tamanho $|V|$ inicializado com $+\inf$

**Saída**:

- array `path` com o caminho de $s$ até $t$ ou $\emptyset$ se não houver caminho

------

# Algoritmo de Dijkstra

```
dist[s] <- 0
pred[s] <- s
tem-caminho <- FALSO

PARA I=1 até |V| FAÇA
    menor_dist = +infinito
    menor_idx = -1
    PARA J = 1 até |V| FAÇA
        SE dist[J] < menor_dist ENTÃO
            menor_dist <- dist[J]
            menor_idx <- j
        FIM 
    FIM
    SE menor_idx = t ENTÃO
        tem-caminho <- VERDADEIRO
        PARA LOOP
    FIM

    PARA CADA VIZINHO K DE J FAÇA
        distK = dist[J] + P[J, K]
        SE 
           // 
    FIM
FIM

SE tem-caminho = FALSO ENTÃO
    DEVOLVA VAZIO
FIM

PREENCHA path USANDO O ARRAY pred
DEVOLVA pred
```

------

# Algoritmo de Dijkstra

#### Total $\mathcal{O}(E + V^2) = \mathcal{O}(V^2)$

-------

# Dá para fazer melhor?

-------

# Min-heap

![](min-heap.JPG)

**Propriedades**:

1. todo nó tem no máximo dois filhos
2. "completo" à esquerda
3. valor de um nó é menor que o valor de seus filhos

** Operações**:

- `INSERE(H, V)`
- `MENOR(H)` devolve o menor valor e o remove

---- 

# Max-heap (alternativa)

![width:300px](max-heap.png)

**Propriedades**:

1. todo nó tem no máximo dois filhos
2. "completo" à esquerda
3. valor de um nó é maior que o valor de seus filhos

-----------

# Representação como array

![width:300px](max-heap.png)

Dado um nó armazenado no índice $i$

1. em quais índices estão seus dois filhos? 
2. em qual índice está seu pai?

----------

# Representação como array

![width:300px](max-heap.png)

Dado um nó armazenado no índice $i$

1. em quais índices estão seus dois filhos? $2i+1$ e $2i+2$
2. em qual índice está seu pai? $(i-1)//2$

--------

# Melhorando Dijkstra com min-heap

algoritmo aqui

-------



------
