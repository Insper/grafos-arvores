# Tipos de Dados em C

Em Técnicas de Programação já vimos como definir um [Tipo Abstrato de Dados](https://insper.github.io/tecnicas-de-programacao/modulos/01-ADT/). Neste roteiro iremos mostrar como realizar a **implementação** de um ADT em *C*. Vamos exemplificar a estrutura necessária para implementar o tipo [List](https://insper.github.io/tecnicas-de-programacao/modulos/01-ADT/list/) que usamos muito no semestre passado.

Uma primeira grande (e óbvia) diferença é que não existem classes em *C*. O recurso que temos para guardar vários dados agrupados é o `struct`, porém ele serve somente para guardar os dados e não faz nenhuma referência a métodos ou nada do tipo. 

Por esta razão toda implementação de estrutura de dados em *C* segue o seguinte padrão:

- dados são guardados em um `struct` terminando com `_t` (para **t**ipo). Logo, nossa lista se chamaria `list_t`
- toda implementação de uma operação da ADT inicia com o nome do tipo. Veja abaixo alguns exemplos
    - `NOVA_LISTA` seria `list_new`
    - `TAMANHO(L)` seria `list_size`
    - `INSERE` seria `list_insert`
- toda função recebe um apontador para a instância que estamos trabalhando. Veja abaixo exemplos
    - `TAMANHO(L)` seria `int list_size(list_t *l)`
    - `INSERE(L, V, i)` seria `void list_insert(list_t *l, int value, int index)`

Note que, como em *C* não temos Polimorfismo nem Generics, o tipo de dado armazenado na lista acaba aparecendo em todas as funções. É possível contornar isso com `union`, mas isso não será trabalhado nesta disciplina. 

A implementação de um ADT é dividida em dois arquivos:

- `list.h` contém a *declaração* de todas as funções disponíveis, assim como a definição do `struct`
- `list.c` contém a *implementação* de todas as funções e se inicia com `#include "list.h"` 

Vamos implementar o *Vetor Dinâmico* que já fizemos em TecProg, mas agora em *C*.

<ah-button href="{{ PL_malloc_hw }}">Ir para a prática</ah-button>
