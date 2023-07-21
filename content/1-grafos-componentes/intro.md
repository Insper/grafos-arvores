# Introdução a Grafos



## Atividades básicas

Nessas primeiras atividades iremos praticar as definições básicas de grafos e sua utilização. Esse material é importante para conseguirmos um vocabulário básico a ser usado na disciplina. 

!!! exercise choice

    Qual é o número de vértices e arestas do grafo acima?

    - [X] 5 vértices, 9 arestas 
    - [ ] 9 vértices, 5 arestas
    - [ ] 5 vértices, 5 arestas
    - [ ] 9 vértices, 9 arestas

- O **grau de entrada** de um vértice é o número de arestas que **chegam** nele
- O **grau de saída** de um vértice é o número de arestas que **saem** dele

!!! exercise choice
    No grafo abaixo, qual é o vértice de **menor grau de entrada**?

    - [ ] 0
    - [ ] 1
    - [ ] 2
    - [X] 3
    - [ ] 4

!!! exercise choice
    No grafo abaixo, qual é o vértice de **maior grau de saída**?

    - [X] 0
    - [ ] 1
    - [ ] 2
    - [ ] 3
    - [ ] 4


Agora vamos praticar interpretar problemas "reais" usando grafos. Em cada problema precisamos fazer 4 perguntas básica:

1. o que cada vértice do grafo representa?
2. qual relação  entre vértices uma aresta representa?
3. essa relação tem direção ou é sempre simétrica?
4. essa relação tem pesos/preferências ou todas arestas são equivalentes?

TODO: problema 1 aqui

TODO: problema 2 aqui

Finalmente, vamos criar matrizes para representar os problemas acima. 

TODO: exercício de matriz do grafo problema 1
TODO: exercício de matriz do grafo problema 2

## Entrega

Agora que já estamos mais familiarizados com grafos iremos implementar a estrutura de dados que será usada em todos os trabalhos com grafos no semestre. É recomendado fazer antes a atividade de [Tipos de Dados em C](adt-c.md).

Os objetivos desta atividade são:

1. gerenciar memória corretamente, alocando e liberando conforme necessário
2. representar grafos como matrizes e entender a relação de cada elemento da matriz com a representação visual do grafo
3. encontrar problems em uma implementação em *C* usando como auxílio testes de unidade

Neste módulo teremos uma dificuldade adicional no exercício: além dos testes que estão dentro do workspace dessa atividade teremos também testes cujo código não estará disponível para vocês. Se algum desses falhar vocês terão somente a mensagem de erro do teste como auxílio para debug.
