#  Alocação Dinâmica de Memória

!!! warning
    Pessoal, estamos fazendo uma pesquisa para conhecer mais a experiência de vocês no mutirão. Podem responder à pesquisa abaixo? Isso ajuda a melhorar para os próximos semestres.

    <ah-button href="https://docs.google.com/forms/d/e/1FAIpQLSdzSeUM1iFQpDIMELZKmQLC24noiWwkfSSv-8V3JFAgjFqlGA/viewform?usp=sf_link"> Responder pesquisa</ah-button>


<ah-external-content src="../slides-malloc.html"/>


## Exercícios básicos

!!! tip
    <!-- Execute os programas dessa atividade no *Playground* da matéria no PL.  -->
    Execute os programas dessa atividade na área do Mutirão. 

    <ah-button href="{{ PL_malloc_hw }}">Abrir Playground</ah-button>

Leia com atenção o seguinte programa.

```c linenums="1"
#include <stdio.h>
#include <stdlib.h>

#define N 12

int *aloca_vetor(int n) {
    int *vetor = malloc(n * sizeof(int));
    return vetor;
}

void atribui(int *vetor, int n) {
    for (int i = 0; i <= n; i++) { 
        vetor[i] = i;
    }
}

int main(int argc, char *argv[]) {
    int *vetor = aloca_vetor(N);
    int i;

    atribui(vetor, N);

    for (i = 0; i <= N; i++) { 
        printf("Elemento %d: %d\n", i+1, vetor[i]);
    }

    return 0;
}
```

Vamos começar analisando o código do programa **antes de rodá-lo**. 

!!! exercise text short
    Analisando seu código-fonte, o que este programa faz?

    !!! answer
        Aloca um vetor, preenche com $0,1,...,n$ e imprime!

!!! exercise text short
    Na execução deste programa, o que acontece se `malloc` falhar? 

    **Dica**: se não lembra como `malloc` funciona, volte nos slides.

    !!! answer
        A função de alocação irá retornar `NULL`, mas nenhuma verificação está sendo feita.

!!! exercise text short
    O seu programa libera toda memória que aloca? Se não, aponte onde ele deveria fazer isto.

    **Dica**: lembre-se que usamos a função `free` para indicar que não usaremos mais uma área de memória obtida com `malloc`. Se não lembra de como usar volta para os slides.

    !!! answer
        Cada valor retornado por `malloc` deve ser liberado usando a função `free`. No caso, vemos que `vetor` não foi liberado após seu uso.
        Isto deveria ser feito na linha 26.


Agora que entendemos um pouco melhor o programa e percebemos que ele tem vários erros, vamos executá-lo para ver o que acontece :) Salve o conteúdo do programa como `ex1.c` e compile-o com o comando abaixo.


<ah-terminal>
$ gcc -Wall -std=c99 -pedantic -Og ex1.c -o ex1 
</ah-terminal>

!!! tip 
    O terminal do VSCode é muito bom e podemos usá-lo para rodar todos os comandos dessa atividade. 

!!! exercise text short
    Execute o programa. Ocorreu algum problema durante a execução?

    !!! answer
        A resposta aqui é provavelmente não. Porém, isso não significa que o programa está correto, apenas que se ocorreu um erro ele não foi suficientemente grave para finalizar o programa.

!!! exercise text short
    O comportamento de seu programa muda conforme N muda? Começe com `N=10` e vá incrementando de um em um. Você consegue explicar por que? Discuta com seu grupo e valide sua resposta com o professor.

    !!! answer
        Ao chegar em `N=14` seu programa deverá magicamente dar problemas e deve voltar a funcionar com `N=15`. Este é um dos grandes problemas de programas com erro de memória: seu comportamento é imprevisível.

!!! warning 
    Em C é comum programas com problemas funcionarem "por sorte". Essencialmente, coisas erradas acontecem, mas elas podem não ser graves o suficiente para que o programa seja finalizado pelo sistema. Pequenas mudanças no código podem fazer um programa aparentemente OK quebrar. 

!!! exercise text medium
    Existem três problemas no código. O primeiro (`vetor` não é desalocado) já identificamos no exercíco anterior. Você consegue identificar os outros dois?

    !!! answer
        O loop de exibição imprime até a posição $N$, porém as $N$ posições do array são $0,1,\dots,N-1$.
        O mesmo erro é realizado na função `atribui`, que faz um acesso indevido `vetor[N]`.

!!!exercise "Hora de corrigir os erros"
    Corrija os erros apontados na questão anterior e salve o programa em um arquivo *ex1-certo.c*.

## Ferramentas de verificação de memória

Para poder identificar mais facilmente problemas relativos a memória, iremos utilizar uma ferramenta chamada **Address Sanitizer**. Ele é um detector de mau uso de memória que roda seu programa em cima de um ambiente modificado e aponta os seguintes erros:

1. memória alocada e não liberada
1. acessos (leituras e escritas) a posições de memória não alocada ou inválidas

Para que os problemas encontrados sejam mais facilmente identificados, iremos passar a compilar utilizando a flag `-g` e a incluir o **Address Sanitizer** no nosso programa usando `-fsanitize=address`.

<ah-terminal>
$ gcc -Og -g -Wall -std=c99 ex1.c -o ex1 -fsanitize=address
$ gcc -Og -g -Wall -std=c99 ex1-certo.c -o ex1-certo -fsanitize=address
</ah-terminal>

!!! exercise text medium
    Rode o seu programa com `./ex1`. Você consegue identificar o significado dos erros encontrados? 

    !!! answer
        Cada erro encontrado será analisado no resto da atividade.

---------------

O primeiro erro encontrado é

```
==1290==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x606000000058 at pc 0x5645bfb73203 bp 0x7ffc8f16cab0 sp 0x7ffc8f16caa8
WRITE of size 4 at 0x606000000058 thread T0
    #0 0x5645bfb73202 in atribui /home/coder/project/ex1.c:13
    #1 0x5645bfb73223 in main /home/coder/project/ex1.c:21
    #2 0x7f1f461bd1c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #3 0x7f1f461bd284 in __libc_start_main_impl ../csu/libc-start.c:360
    #4 0x5645bfb730e0 in _start (/home/coder/project/ex1+0x10e0)
```

!!! exercise text short
    Em qual linha o erro ocorre? O que a mensagem acima significa?

    !!! answer
        O erro ocorre na linha 13, ao escrever em vetor[i] quando `i == N`

!!! exercise 
    Corrija o erro e rode novamente o programa. Verifique que o erro acima não ocorre mais e que o primeiro erro mostrado mudou antes de prosseguir.

---------

O segundo erro está mostrado abaixo e ocorre logo antes de lermos da linha "Elemento 13" na saída.

```
==1746==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x606000000058 at pc 0x559e63a32274 bp 0x7ffe05b47e20 sp 0x7ffe05b47e18
READ of size 4 at 0x606000000058 thread T0
    #0 0x559e63a32273 in main /home/coder/project/ex1.c:24
    #1 0x7f4a8df131c9 in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #2 0x7f4a8df13284 in __libc_start_main_impl ../csu/libc-start.c:360
    #3 0x559e63a320e0 in _start (/home/coder/project/ex1+0x10e0)
```

!!! exercise text short
    Em qual linha o erro ocorre? O que a mensagem acima significa?

    !!! answer
        O erro ocorre na linha 24, ao ler vetor[i] quando `i == N`.


!!! exercise 
    Corrija o erro e rode novamente o programa. Verifique que o erro acima não ocorre mais e que o primeiro erro mostrado mudou antes de prosseguir.

---------

Agora temos somente o erro abaixo na saída:

```
==1999==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 56 byte(s) in 1 object(s) allocated from:
    #0 0x7fdb357999cf in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:69
    #1 0x55a3fef721b8 in aloca_vetor /home/coder/project/ex1.c:7

SUMMARY: AddressSanitizer: 56 byte(s) leaked in 1 allocation(s). 
```

!!! exercise text short
    Ela mostra algum problema? Se sim, qual linha de código é apontada? Qual é o problema diagnosticado por este aviso?

    !!! answer
        Ele indica que 1 objeto foi alocado e não liberado. Além disso, aponta para a linha `7`, indicando que o `malloc` feito nessa linha não teve um `free` correspondente.

!!! exercise
    Conserte o programa novamente e verifique que agora ele roda sem erros.


## Para entregar

A prática mais completa dessa aula está disponível no PrairieLearn e envolverá implementar funções que lidam com strings. Os objetivos são

- revisar uso de strings e sua codificação na memória
- criar funções que aloquem novos objetos na memória e os retorne
- determinar o tamanho correto a ser alocado para cada operação
- usar o AddressSanitizer para checar se são feitos acessos indevidos à memória
- usar o AddressSanitizer para checar se todo malloc tem um free correspondente

<ah-button href="{{ PL_malloc_hw }}">Ir para a prática</ah-button>

