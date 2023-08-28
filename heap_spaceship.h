#ifndef HEAP_SPACESHIP_H_INCLUDED
#define HEAP_SPACESHIP_H_INCLUDED

// Structs
typedef struct {
  int id, idade, saude, intruso, id_espaconave;
  char *nome, *planeta_de_origem;
} Passageiro;

typedef struct {
  int prioridade, id;
  char *recursos;
  Passageiro *passageiros;
} Espaconave;

typedef struct {
  Espaconave *espaconaves;
  int tam;
  int capacidade;
} MaxHeap;

// Funções da Heap
int gera_aleatorios();
int altera_prioridade(Espaconave *espaconaves, int tam);
MaxHeap cria_max_heap(); // Modificada
void constroi_heap_vetor(Espaconave *vetor, int tam);
void heapsort(MaxHeap heap);
void subir(Espaconave *espaconaves, int i);
void descer(Espaconave *espaconaves, int i, int tam);
void inserir_na_heap(Espaconave *espaconaves, int prioridade, int capacidade,
                     int tam);
Espaconave remover_na_heap(MaxHeap heap);
void recebe_prioridade(Espaconave *espaconaves);
int quadrado(int x);

// Funções para leitura do CSV.
void print_passageiros(Passageiro *passageiros);
void print_espaconaves(Espaconave *espaconaves);
Passageiro *cria_passageiro(int id, char *nome, int idade,
                            char *planeta_de_origem, int saude, int intruso,
                            int id_espaconave);
Passageiro *le_passageiro(char *path);
Espaconave cria_espaconave(Passageiro *passageiros, int num, char *recursos);
Espaconave *cria_lista_espaconaves(Passageiro *passageiros, int id,
                                   char *recursos);

// Testes
void teste_troca(Espaconave *espaconaves);

#endif // HEAP_SPACESHIP_H_INCLUDED
