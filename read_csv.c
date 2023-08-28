#include "heap_spaceship.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria um passageiro com base na struct Passageiro e retorna-o.

Passageiro *cria_passageiro(int id, char *nome, int idade,
                            char *planeta_de_origem, int saude, int intruso,
                            int id_espaconave) {
  Passageiro *pass = malloc(sizeof(Passageiro));
  pass->nome = malloc(sizeof(char) * (strlen(nome) + 1));
  pass->planeta_de_origem =
      malloc(sizeof(char) * (strlen(planeta_de_origem) + 1));

  pass->id = id;
  strcpy(pass->nome, nome);
  pass->idade = idade;
  strcpy(pass->planeta_de_origem, planeta_de_origem);
  pass->saude = saude;
  pass->intruso = intruso;
  pass->id_espaconave = id_espaconave;

  return pass;
}

// Lê o arquivo csv com os dados dos passageiros e retorna um vetor com os
// mesmos.

Passageiro *le_passageiro(char *path) {
  FILE *file = fopen(path, "r");
  char buffer[1024];
  int i = 0;
  Passageiro *vet = malloc(151 * sizeof(Passageiro));

  fgets(buffer, sizeof(buffer), file);

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    char *id_str, *nome, *idade_str, *planeta_de_origem, *saude_str,
        *intruso_str, *id_espaconave_str;

    id_str = strtok(buffer, ",");
    nome = strtok(NULL, ",");
    idade_str = strtok(NULL, ",");
    planeta_de_origem = strtok(NULL, ",");
    saude_str = strtok(NULL, ",");
    intruso_str = strtok(NULL, ",");
    id_espaconave_str = strtok(NULL, ",");

    int id = atoi(id_str);
    int idade = atoi(idade_str);
    int saude = atoi(saude_str);
    int intruso = atoi(intruso_str);
    int id_espaconave = atoi(id_espaconave_str);

    // int id_espaco = id_espaco;

    Passageiro *pass = cria_passageiro(id, nome, idade, planeta_de_origem,
                                       saude, intruso, id_espaconave);
    vet[i] = *pass;
    free(pass);
    i++;
  }
  fclose(file);
  return vet;
}

/*Cria espaçonave com base na struct Espaconave.*/
Espaconave cria_espaconave(Passageiro *passageiros, int id, char *recursos) {

  Espaconave apollo;
  Passageiro *vet1 = malloc(151 * sizeof(Passageiro));
  int aux = 0;

  srand((unsigned int)time(NULL));

  for (int i = 0; i < 151; i++) {
    if (passageiros[i].id_espaconave == id) {
      vet1[aux] = passageiros[i];
      aux++;
    }
  }

  // apollo.prioridade = gera_aleatorios() % 10;
  apollo.id = id;
  apollo.passageiros = malloc(aux * sizeof(Passageiro));
  memcpy(apollo.passageiros, vet1, aux * sizeof(Passageiro));
  apollo.recursos = recursos;

  return apollo;
}
Espaconave *cria_lista_espaconaves(Passageiro *passageiros, int id,
                                   char *recursos) {
  Espaconave *lista_espaconaves = malloc(10 * sizeof(Espaconave));
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    lista_espaconaves[i] = cria_espaconave(passageiros, i, recursos);
  }
  return lista_espaconaves;
}

void print_passageiros(Passageiro *passageiros) {
  printf("Passageiros da Nave %d:\n", passageiros->id_espaconave);
  for (int i = 0; i < 14; i++) {

    puts("---------------------------------------");
    printf("id: %d\n", passageiros[i].id);
    printf("nome: %s\n", passageiros[i].nome);
    printf("idade: %d\n", passageiros[i].idade);
    printf("planeta_de_origem: %s\n", passageiros[i].planeta_de_origem);
    printf("saude: %d\n", passageiros[i].saude);
    printf("intruso: %d\n", passageiros[i].intruso);
    printf("id da espaçonave: %d\n", passageiros[i].id_espaconave);
  }
}

void print_espaconaves(Espaconave *espaconaves) {
  printf("Espaçonaves:\n");

  for (int i = 0; i < 10; i++) {
    puts("-------------------------------");
    printf("id: %d\n", espaconaves[i].id);
    printf("prioridade: %d\n", espaconaves[i].prioridade);
    printf("recursos: %s\n", espaconaves[i].recursos);
  }
}

void recebe_prioridade(Espaconave *espaconaves) {
  for (int i = 0; i < 10; i++) {
    espaconaves[i].prioridade = gera_aleatorios() % 10;
  }
}

int quadrado(x) { return x * x; }
