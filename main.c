#include "heap_spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  Passageiro *passageiros;
  passageiros = le_passageiro("df.csv");
  Espaconave *lista_espaconaves;
  lista_espaconaves = cria_lista_espaconaves(passageiros, 0, "geladeira");
  recebe_prioridade(lista_espaconaves);

  print_espaconaves(lista_espaconaves);

  puts("\n+++++++++++++++++\n");

  MaxHeap heap_espaconaves = cria_max_heap();
  heap_espaconaves.espaconaves = lista_espaconaves;
  // Testando pra ver se as trocas esão acontecendo - Estão
  teste_troca(heap_espaconaves.espaconaves);
  constroi_heap_vetor(heap_espaconaves.espaconaves, heap_espaconaves.tam);
  //heapsort(heap_espaconaves);
  print_espaconaves(heap_espaconaves.espaconaves);
  free(heap_espaconaves.espaconaves);
  return 0;
}
