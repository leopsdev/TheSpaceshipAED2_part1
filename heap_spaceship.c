#include "heap_spaceship.h"
#include <math.h>
#define tam_max 100

/*
Gera um número aleatorio.
*/
int gera_aleatorios() { return rand(); }

MaxHeap cria_max_heap() {
  MaxHeap heap;
  heap.espaconaves = (Espaconave *)malloc(tam_max * sizeof(Espaconave));
  heap.tam = 0;
  heap.capacidade = tam_max;
  return heap;
}

void constroi_heap_vetor(Espaconave *vetor, int tam) {
  for (int i = (int)floor((tam) / 2) - 1; i >= 0; i--) {
    descer(vetor, i, tam);
  }
}

/*
void heapsort(MaxHeap heap) {
  Espaconave x;
  constroi_heap_vetor(heap.espaconaves, heap.tam);
  for (int i = heap.tam - 1; i > 0; i--) {
    x = remover_na_heap(heap);
    heap.espaconaves[heap.tam - i] = x;
  }
}*/

void heapsort(MaxHeap heap) {
  Espaconave aux;
  constroi_heap_vetor(heap.espaconaves, heap.tam);
  for (int i = heap.tam - 1; i > 0; i--) {
    aux = heap.espaconaves[0];
    heap.espaconaves[0] = heap.espaconaves[i];
    heap.espaconaves[i] = aux;
    descer(heap.espaconaves, 0, i);
  }
}

void subir(Espaconave *espaconaves, int i) {
  int aux;
  if (i <= 0)
    return;
  int j = (int)floor(i / 2);
  if (j >= 1) {
    if (espaconaves[i].prioridade > espaconaves[j].prioridade) {
      aux = espaconaves[i].prioridade;
      espaconaves[i].prioridade = espaconaves[j].prioridade;
      espaconaves[j].prioridade = aux;
      subir(espaconaves, j);
    }
  }
}
/*
void descer(Espaconave *espaconaves, int i, int tam) {
  Espaconave aux;
  int j = 2 * i + 1;
  if (i < 0)
    return;
  if (j < tam) {
    if (j + 1 < tam) {
      if (espaconaves[j + 1].prioridade > espaconaves[j].prioridade) {
        j++;
      }
    }
    if (espaconaves[j].prioridade > espaconaves[i].prioridade) {
      aux = espaconaves[i];
      espaconaves[i] = espaconaves[j];
      espaconaves[j] = aux;
      descer(espaconaves, j, tam);
    }
  }
}*/

void descer(Espaconave *espaconaves, int i, int tam) {
  printf("AAAAKDFOJIDFSBHVPAIJDFIOSDUVBASIPJDVI");
  Espaconave aux;
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;
  if (maior < 0)
    return;
  if (esquerda < tam &&
      espaconaves[esquerda].prioridade > espaconaves[maior].prioridade) {
    maior = esquerda;
  }
  if (direita < tam &&
      espaconaves[direita].prioridade > espaconaves[maior].prioridade) {
    maior = direita;
  }
  if (maior > i) {
    aux = espaconaves[i];
    espaconaves[i] = espaconaves[maior];
    espaconaves[maior] = aux;
    descer(espaconaves, maior, tam);
  }
}

void inserir_na_heap(Espaconave *espaconaves, int prioridade, int capacidade,
                     int tam) {
  if (tam >= capacidade) {
    printf("Heap cheio.\n");
    return;
  }
  espaconaves[tam].prioridade = prioridade;
  subir(espaconaves, tam - 1);
  tam++;
}

Espaconave remover_na_heap(MaxHeap heap) {
  Espaconave *espaconaves = heap.espaconaves;
  if (heap.tam == 0) {
    Espaconave vazia = {0};
    return vazia;
  }

  Espaconave prioritaria = espaconaves[0];
  espaconaves[0] = espaconaves[heap.tam - 1];
  descer(espaconaves, 0, heap.tam);
  heap.tam--;
  return prioritaria;
}

int altera_prioridade(Espaconave *espaconaves, int tam) {
  int aleat = gera_aleatorios();
  while (aleat == espaconaves[tam].prioridade) {
    aleat = gera_aleatorios();
  }
  espaconaves[tam].prioridade = aleat;
  return 0;
}

void teste_troca(Espaconave *espaconaves) {
  int aux = espaconaves[0].prioridade;
  espaconaves[0].prioridade = espaconaves[1].prioridade;
  espaconaves[1].prioridade = aux;
}
