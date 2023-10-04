<script src=https://unpkg.com/graphviz-webcomponent@2.0.0/dist/graph-bundled.min.js></script>

# Inserção

Na última aula já discutimos ideias sobre a buscas em *ABB*s e vimos o que acontece quando o elemento buscado não está na árvore. Agora iremos inserir o valor $K$ na árvore. Ainda não sabemos fazer isto, então vamos começar pensando em como fazer a inserção. 

Comecemos por organizar nosso raciocínio pela altura da árvore. Alguns casos são bem fáceis:
 
**Árvores com altura 0**: crie um nó com o $key=K$ e faça-o a nova raiz da árvore. 

**Árvores com altura 1**: seja $r$ esse único nó na árvore. Se $K < r.key$ então podemos só inserir na subárvore esquerda, como mostrado abaixo.

<ah-diagram>
graph TD
A1(r)
A2(K)
N1(( ))
A1 --- A2
A1 --- N1
</ah-diagram>

Caso contrário ($K > r.key$), a inserção é na subárvore direita.

<ah-diagram>
graph TD
A1(r)
A2(K)
N1(( ))
A1 --- N1
A1 --- A2
</ah-diagram>

**Árvores com altura 2**: Vamos examinar algumas possibilidades abaixo:

1. só existe subárvore *esquerda* (como no exemplo abaixo) e $r.key < $k. Este caso é fácil!
 
    *Antes**:
    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    N1(( ))
    A1 --- A2
    A1 --- N1
    </ah-diagram>
    **Depois**:
    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    A3(K)
    A1 --- A2
    A1 --- A3
    </ah-diagram>

2. só existe subárvore **direita** e $r.key > K$. Este caso também é fácil!

    **Antes**:
    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    N1(( ))
    A1 --- N1
    A1 --- A2
    </ah-diagram>
    **Depois**:
    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    A3(K)
    A1 --- A3
    A1 --- A2
    </ah-diagram>

3. Existe subárvore esquerda e $r.key > K$. Ou seja, a busca iria para a esquerda em $r$, porém não podemos inserir $K$ diretamente pois já há um nó à esquerda de $r$. 

    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    N1(( ))
    A1 --- A2
    A1 --- N1
    </ah-diagram>

    
3. Existe subárvore direita e $r.key < K$. Esse caso também não é óbvio. A busca iria para a direita em $r$, porém a mesma situação acima ocorre mas desta vez para a direita. 

    <ah-diagram>
    graph TD
    A1(a1)
    A2(a2)
    N1(( ))
    A1 --- N1
    A1 --- A2
    </ah-diagram>

Os casos 1 e 2 já estão resolvidos e são fáceis: é possível inserir o nó diretamente no lugar vazio. Já os casos 3 e 4 parecem complicados mas não são. Árvores são estruturas recursivas: cada nó $r$ contém uma ligação para uma subárvore esquerda (com todos valores $ < r.key$) e uma subárvore direita (com todos valores $ > r.key$). Logo, no caso 3 podemos realizar a inserção na árvore enraizada pelo elemento $a2$. Como a árvore enraizada em $a2$ tem altura1, podemos fazer o procedimento descrito anteriormente. O mesmo vale para o caso 4. 


**Árvores com altura $h > 2$**: Usar o argumento acima nos permite inserir em árvores de qualquer tamanho! Ou a inserção ocorreria em um espaço vazio (ou seja, um dos lados tem uma subárvore de altura 0) ou inserimos na subárvore correspondente (que tem altura $h-1$).

## Exercitando e formalizando esse algoritmo

Vejamos alguns exemplos abaixo. 

!!! exercise short
    Em qual lugar o valor $27$ seria inserido na árvore abaixo?

    <graphviz-graph graph='
    digraph G{
      node [fillcolor="#d9dfff" color="#d9dfff" style="filled"]
      20 -> null1
      null1 [shape=point]
      20 -> 30
      30 -> null2 
      null2 [shape=point]
      30 -> 40
    }'></graphviz-graph>


    !!! answer
        Na subárvore esquerda de $30$

!!! exercise short
    Em qual lugar o valor $15$ seria inserido na árvore abaixo?

    <graphviz-graph graph='
    digraph G{
      node [fillcolor="#d9dfff" color="#d9dfff" style="filled"]
      20 -> 10
      10 -> null1
      10 -> 13
      null1 [shape=point]
      20 -> 30
      30 -> null2 
      null2 [shape=point]
      30 -> 40
    }'></graphviz-graph>


    !!! answer
        Na subárvore direita de $13$



!!! exercise short
    Em qual lugar o valor $7$ seria inserido na árvore abaixo?

    <graphviz-graph graph='
    digraph G{
      node [fillcolor="#d9dfff" color="#d9dfff" style="filled"]
      20 -> 10
      10 -> 5
      5 -> 2
      5 -> null1
      10 -> 13
      20 -> 30
      30 -> null2 
      30 -> 40
      null1 [shape=point]
      null2 [shape=point]
    }'></graphviz-graph>


    !!! answer
        Na subárvore direita de $5$


!!! exercise long
    Agora formalize o algoritmo `insere(r, K)` que aplicamos nos exemplos acima. Escreva um algoritmo iterativo nesta questão.

    !!! answer
        Discutido no fim da aula

!!! exercise long
    Agora formalize o algoritmo `insere(r, K)` que aplicamos nos exemplos acima. Escreva um algoritmo recursivo nesta questão.

    !!! answer
        Discutido no fim da aula

## Entregas

Faça o exercício de implementação do algoritmo no PrairieLearn. Teste ambas as versões do algoritmo criado.

## Estudos extras


