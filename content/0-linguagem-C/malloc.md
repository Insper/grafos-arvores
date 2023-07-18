#  Alocação Dinâmica de Memória

<script src="/js/ah-terminal.mjs" type="module"></script>
<script src="/js/ah-button.mjs" type="module"></script>

## Exercícios básicos

!!! tip
    Execute os programas dessa atividade no *Playground* da matéria no PL. 

    <ah-button href="https://us.prairielearn.com/pl/course_instance/137302/assessment/2352640">Abrir Playground</ah-button>

Leia com atenção o seguinte programa.

```c
#include <stdio.h>
#include <stdlib.h>

#define N 12

int *aloca_vetor(int n) {
    int *vetor = malloc(n * sizeof(int));
    return vetor;
}

void atribui(int *vetor, int n) {
    for (int i = 0; i <= n; i++) { // problema!
        vetor[i] = i;
    }
}

int main(int argc, char *argv[]) {
    int *vetor = aloca_vetor(N);
    int i;

    atribui(vetor, N);

    for (i = 0; i <= N; i++) { // problema!
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
$ gcc -Wall -std=c99 -Og ex1.c -o ex1
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

Para poder identificar mais facilmente problemas relativos a memória, iremos utilizar uma ferramenta chamada **Valgrind**.

O Valgrind é um detector de má gestão de memória. Ele roda seu programa em cima de um ambiente modificado e aponta os seguintes erros:

1. memória alocada e não liberada
1. acessos (leituras e escritas) a posições de memória não alocada ou inválidas


!!! tip
    O valgrind já está incluso nos workspaces da disciplina, mas se quiser instalá-lo em também em sua instalação Linux (Debian, Ubuntu ou derivados), basta usar os seguintes comandos.

    <ah-terminal>
    $ sudo apt update
    $ sudo apt install valgrind
    </ah-terminal>

Para que os problemas encontrados pelo Valgrind sejam mais facilmente identificados, iremos passar a compilar utilizando a flag `-g`.

<ah-terminal>
$ gcc -Og -g -Wall -std=c99 ex1.c -o ex1
$ gcc -Og -g -Wall -std=c99 ex1-certo.c -o ex1-certo
</ah-terminal>

!!! exercise text medium
    Rode o Valgrind com `valgrind --leak-check=yes ./ex1`. Quantos erros foram encontrados? Quais são seus tipos (escrita ou leitura de dados)? O que eles significam?

    !!! answer
        Cada erro encontrado será analisado no resto da atividade.

---------------

O primeiro erro encontrado é

```
==1899== Invalid write of size 4
==1899==    at 0x1086C7: main (ex1.c:11)
==1899==  Address 0x522f078 is 0 bytes after a block of size 56 alloc'd
==1899==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==1899==    by 0x1086B9: main (ex1.c:7)
```

!!! exercise text short
    Em qual linha o erro ocorre? O que a mensagem acima significa?

    !!! answer
        O erro ocorre na linha 11, ao escrever em vetor[i] quando `i == N`

---------

O segundo erro é

```
==1899== Invalid read of size 4
==1899==    at 0x1086DD: main (ex1.c:15)
==1899==  Address 0x522f078 is 0 bytes after a block of size 56 alloc'd
==1899==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==1899==    by 0x1086B9: main (ex1.c:7)
```

!!! exercise text short
    Em qual linha o erro ocorre? O que a mensagem acima significa?

    !!! answer
        O erro ocorre na linha 15, ao ler vetor[i] quando `i == N`.

---------

A seção *HEAP SUMMARY* faz um resumo dos dados alocados/desalocados no seu programa. A saída abaixo foi obtida ao rodar o valgrind para o exercício 1 original:

```
==2179== HEAP SUMMARY:
==2179==     in use at exit: 56 bytes in 1 blocks
==2179==   total heap usage: 2 allocs, 1 frees, 1,080 bytes allocated
==2179==
==2179== 56 bytes in 1 blocks are definitely lost in loss record 1 of 1
==2179==    at 0x4C31B0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2179==    by 0x1086B9: main (ex1.c:7)
```

!!! exercise text short
    Ela mostra algum problema? Se sim, qual linha de código é apontada? Qual é o problema diagnosticado por este aviso?

    !!! answer
        Ela indica que houveram 2 `mallocs' e somente 1 `free`. Ou seja, alguma alocação de memória deixou de liberar dados. Abaixo, são indicadas em quais linhas os `malloc` sem `free` ocorreram (linha 7 na função `main` no arquivo `ex1.c`)


!!! warning
    Verifique que seu programa corrigido *ex1-certo.c* roda sem erros no valgrind. Se não, corrija os problema e rode novamente até que rode sem erros.

## Para entregar

A prática mais completa dessa aula está disponível no PrairieLearn e envolverá implementar funções que lidam com strings. Os objetivos são

- revisar uso de strings e sua codificação na memória
- criar funções que aloquem novos objetos na memória e os retorne
- determinar o tamanho correto a ser alocado para cada operação
- usar o valgrind para checar se são feitos acessos indevidos à memória
- usar o valgrind para checar se todo malloc tem um free correspondente

<ah-button href="https://us.prairielearn.com/pl/course_instance/137302/assessment/2352818">Ir para a prática</ah-button>

