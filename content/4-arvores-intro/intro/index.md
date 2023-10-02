# Introdução

<ah-external-content src="slides.html"/>

## Definições

Vamos definir nossa linguagem para trabalhar com árvores nesta aula. Dado um nó $x$ de nossa árvore, 

- $x.left$ é o filho esquerdo de $x$. Se ele não existir seu valor é $NIL$
- $x.right$ é o filho direito de $x$. Se ele não existir seu valor é $NIL$
- $x.parent$ é o pai de $x$. Todo nó possui somente um pai, sendo que se $x$ é o nó raiz $x.parent = x$
- $x.key$ é o valor que $x$ representa na árvore. 

Árvores são estruturas naturalmente recursivas. Se tormarmos um nó $x$ qualquer de uma árvore podemos falar em uma *subárvore enraizada em $x$*. Assim, podemos definir uma árvore como:

- um nó raiz $r$ com uma chave $r.key$
- um apontador para uma subárvore esquerda $r.left$
- um apontador para uma subárvore direita $r.right$

A figura ([fonte](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/) abaixo é um bom resumo do vocabulário usado em árvores.

![Fonte: https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/](https://media.geeksforgeeks.org/wp-content/uploads/20221124153129/Treedatastructure.png)

Uma *Árvore de Busca Binária* é umaárvore especial que guarda seus elementos em ordem crescente de $key$. Para isso ela tem a seguinte propriedade:

!!! tip "Propriedade básica da ABB"
    Para todo nó $x$ em uma *ABB*:

    - $x.key \geq l.key$ para todo nó $l$ na subárvore esquerda de $x$
    - $x.key \leq r.key$ para todo nó $r$ na subárvore direita de $x$

Se uma árvore não respeitar as propriedades acima então ela não é uma *ABB*. Isso facilita muito checarmos se um elemento está na árvore. 

## Buscando por elementos

A busca (*query*) é a operação mais básica de uma ABB e envolve dizer se existe um elemento com chave *k* na árvore. É também um ótimo lugar para começarmos a entender 

Já fizemos uma simulação na parte expositiva. Vamos agora praticar antes de implementarmos esse algoritmo nós mesmos.

<ah-diagram>
graph TD
A(15) --- B(5)
A --- C(20)
B --- D(1)
B --- E(10)
E --- H(7)
E --- NULL3( )
C --- NULL2( )
C --- F(25)
F --- NULL1( )
F --- G(30)
</ah-diagram>

!!! exercise long 
    Busque na árvore acima pelo valor $7$. Escreva abaixo a decisão tomada em cada nó.

    !!! answer
        Nó 15 -> esquerda
        Nó 5 -> direita
        Nó 10 -> esquerda
        Nó 7 -> encontrou!

!!! exercise long 
    Busque na árvore acima pelo valor $3$. Escreva abaixo a decisão tomada em cada nó.

    !!! answer
        Nó 15 -> esquerda
        Nó 5 -> esquerda
        Nó 1 -> direita
        Fim da árvore! -> não encontrou

!!! exercise long 
    Busque na árvore acima pelo valor $23$. Escreva abaixo a decisão tomada em cada nó.

    !!! answer
        Nó 15 -> direita
        Nó 20 -> direita
        Nó 25 -> esquerdaa
        Fim da árvore! -> não encontrou

!!! exercise long
    Escreva abaixo um algoritmo iterativo `query(r, k)` que busca pela chave $k$ na ABB enraizada em $r$. Se encontrar devolve `VERDADEIRO`.

    !!! answer
        Discutiremos esse algoritmo em sala. Use esse espaço para registrar sua solução

Antes de prosseguir, volte nos exercícios acima e simule o seu algoritmo. 

!!! exercise long
    Faça agora uma versão recursiva. Veja que ela é muito mais sucinta que a anterior.

!!! tip 
     Usaremos a seguinte `struct`em todos os exercícios deste módulo.

    ```c
    typedef struct _TreeNode {
        struct _TreeNode *left, *right, *parent;
        int key;
    } TreeNode;
    ```

!!! exercise 
    Implemente o algoritmo de busca no PrairieLearn.

!!! warning
    Realize o exercício acima antes de prosseguir. As próximas soluções são baseadas na mesma ideia.

## Validar uma *ABB*

Vamos começar vendo alguns exemplos de árvores que não são *ABB*.

!!! exercise choice

    Para qual nó da árvore abaixo a propriedade básica da ABB não vale?
    
    <ah-diagram>
    graph TD
    A(15) --- B(14)
    A --- C(21)
    B --- F(10)
    B --- E(16)
    C --- G(17)
    C --- NULL( )
    </ah-diagram>

    - [x] 15
    - [ ] 14
    - [ ] 21 
    - [ ] 10
    - [ ] 16
    - [ ] 21
    - [ ] 17

!!! exercise choice
    Para qual nó da árvore abaixo a propriedade básica da ABB não vale?
    
    <ah-diagram>
    graph TD
    A(17) --- B(14)
    A --- C(22)
    B --- F(10)
    B --- E(16)
    C --- G(21)
    C --- NULL( )
    G --- A2(18)
    G --- A3(23)
    </ah-diagram>

    - [ ] 17
    - [ ] 14
    - [x] 22 
    - [ ] 10
    - [ ] 16
    - [ ] 21
    - [ ] 18
    - [ ] 23

Percebemos que um algoritmo para isso precisa de várias partes!

1. precisamos checar se a propriedade é válida para todosos nós
2. para checar a propriedade precisamos percorrer toda a subárvore esquerda e toda a subárvore direita.

Esses dois passos tem algo em comum: eles envolvem visitar todos os nós da árvore. 

!!! exercise long
    Escreva abaixo um rascunho de um algoritmo para visitar todos os nós de uma árvore.

    !!! answer
        Será discutido em **02/10**.

Com base nesse algoritmo, faça a implementação no PrairieLearn do algoritmo para checar se uma árvore é válida.


## Estudo extra

Os seguintes exercícios do leetcode são interessantes e relacionados ao assunto atual.

1. [Soma de caminho até folha](https://leetcode.com/problems/path-sum/)
2. [Soma K](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
3. [Altura mínima](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
