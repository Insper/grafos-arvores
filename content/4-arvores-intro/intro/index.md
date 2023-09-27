# Introdução

TODO: slides

## Definições

Vamos definir nossa linguagem para trabalhar com árvores nesta aula. Dado um nó $x$ de nossa árvore, 

- $x.left$ é o filho esquerdo de $x$. Se ele não existir seu valor é $NIL$
- $x.right$ é o filho direito de $x$. Se ele não existir seu valor é $NIL$
- $x.parent$ é o pai de $x$. Todo nó possui somente um pai, sendo que se $x$ é o nó raiz $x.parent = x$
- $x.key$ é o valor que $x$ representa na árvore. 

TODO: subárvores vão aqui.

!!! tip "Propriedade básica da ABB"
    Para todo nó $x$ em uma *ABB*:

    - $x.key \geq l.key$ para todo nó $l$ na subárvore esquerda de $x$
    - $x.key \leq r.key$ para todo nó $r$ na subárvore direita de $x$


Se uma árvore não respeitar as propriedades acima então ela não é uma *ABB*. Vamos checar manualmente isso? 

## Validar uma *ABB*

Vaoms começar vendo alguns exemplos de árvores que podem ou não serem *ABB*.

!!! exercise choice

    TODO: árvore vai aqui

    A árvore acima é uma *ABB*?

    - [ ] SIM
    - [x] NÃO


Percebemos que um algoritmo para isso precisa de várias partes! 

TODO: algoritmo árvore válida?

## Implementação

Os campos acima já definem tudo o que nosso `struct` precisa guardar para implementarmos *ABB*s. No exemplo abaixo (e em vários que usaremos nas aulas) a nossa *ABB* guardará `int`s. Note, porém, que podemos guardar qualquer tipo de dado em que existe uma ordem entre os elementos. Caso contrário não poderíamos respeitar a Propriedade Básica da ABB!

```
typedef struct _TreeNode {
    struct _TreeNode *left, *right, *parent;
    int key;
} TreeNode;
```

Nosso primeiro exercício será justamente checar se uma árvore é uma ABB! Acesse o PrairieLearn abaixo e implemente a checagem da Propriedade Básica!

<ah-button href=".."> Exercício Prático </ah-button>

