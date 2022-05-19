# Produtor - Consumidor

## Atividade 6: Infraestrutura de Software
Aluno: João Pedro Cordeiro Abrantes  
Periodo: 3  
Turma: B  
Professor: Erico Souza Teixeira  
Tutor: Michael Alvez  
  
Este repositório tem um programa em C que retrata o problema do Produtor-Consumidor, onde são criadas várias threads produtoras que adicionam itens em um buffer, assim como são criadas várias threads consumidoras que removem esses itens do buffer, de forma que o produtor só pode produzir algo se o buffer não estiver cheio e a posição não estiver ocupada, e o consumidor só pode remover um item se o buffer não estiver vazio e a posição tiver algum dado.  

## Clonar o repositório

Para rodar o programa, primeiro é necessário clonar este repositório e compilar o arquivo .c, para isso, basta rodar os comandos abaixo no seu terminal:  

```bash
$ git clone https://github.com/jpedro7/tutoria-6.git
$ cd tutoria-6
```

## Rodar o programa

Para rodar o programa, rode os seguintes comandos no seu terminal:

```bash
$ make
```
O comando `make` vai compilar o código em um executável  

```bash
$ make run
```
O comando `make run` vai rodar o executável criado

```bash
$ make clean
```
O comando `make clean` vai deletar o executável  

Para fazer este programa foi usada uma trava mutex para evitar que as threads alterassem o valor de uma variável ao mesmo tempo e gerasse algum tipo de conflito. Também foram usados 2 semáforos para indicar se o buffer está cheio ou não, de forma que, se o buffer estiver cheio, o produtor ficará em estado de Wait, enquanto espera por um sinal para que possa produzir, do mesmo jeito que, se o buffer estiver vazio, o consumidor ficará em estado de Wait, esperando por um sinal para que possa consumir.  