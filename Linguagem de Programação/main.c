#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Horario {
  int hora;
  int min;
};

struct Data {
  int dia;
  int mes;
  int ano;
};

struct Evento {
  struct Data data;
  struct Horario inicio;
  struct Horario fim;
  char descricao[40];  
  char local[40];
};

void print_menu();
void cadastrar_evento(struct Evento agenda[], int *num_eventos);
void mostrar_eventos(struct Evento agenda[], int num_eventos);
void eventos_data(struct Evento agenda[], int num_eventos);
void printa_evento(struct Evento evento);
void evento_descricao(struct Evento agenda[], int num_eventos);
void remover_evento(struct Evento agenda[], int num_eventos);
void pega_data(struct Data *data);
void pega_horario(struct Horario *horario);
void pega_evento(struct Evento *evento);
void ord_evento(struct Evento agenda[], int num_eventos);
int comp_data(struct Data *data1, struct Data *data2);
int comp_horario(struct Horario *horario1, struct Horario *horario2);
int data_valida(struct Data *data);
int horario_valido(struct Horario *horario);
int choque_evento(struct Evento agenda[], struct Evento *evento,
                  int num_eventos);
int main() {
  struct Evento *agenda = malloc(sizeof(struct Evento));
  char buffer[10];
  int i, opcao, rodando = 1, num_eventos = 0;
  FILE *arq_saida;
  
  FILE *arq_entrada = fopen("arquivo.txt", "rt" );
  	if( arq_entrada == NULL )
  		printf("Erro ao abrir o arquivo!\n");
  
  while (!feof(arq_entrada)) {
    
	  fscanf(arq_entrada, "%d", &agenda[num_eventos].data.dia);
	  fscanf(arq_entrada, "%d", &agenda[num_eventos].data.mes);
	  fscanf(arq_entrada, "%d", &agenda[num_eventos].data.ano);
    fscanf(arq_entrada, "%d", &agenda[num_eventos].inicio.hora);
    fscanf(arq_entrada, "%d", &agenda[num_eventos].inicio.min);
    fscanf(arq_entrada, "%d", &agenda[num_eventos].fim.hora);
    fscanf(arq_entrada, "%d", &agenda[num_eventos].fim.min);    
	
    fgets (agenda[num_eventos].local, 30, arq_entrada);
    fgets (agenda[num_eventos].local, 30, arq_entrada); //buffer
    fgets (agenda[num_eventos].descricao, 30, arq_entrada);
	   
	  num_eventos++;
    agenda = realloc(agenda, (num_eventos+1)*sizeof(struct Evento));  
	}
  fclose (arq_entrada);

  
  while (rodando) {
    print_menu();
    scanf("%d", &opcao);
    switch (opcao) {
      
    case 1:
      cadastrar_evento(agenda, &num_eventos);
      agenda = realloc(agenda, sizeof(struct Evento) * (num_eventos+1));
      ord_evento(agenda, num_eventos);
      break;
    
      case 2:
      if (num_eventos == 0)
        printf("Nao existe nenhum evento cadastrado\n");
      else
        mostrar_eventos(agenda, num_eventos);
      break;
    
      case 3:
      if (num_eventos == 0)
        printf("Nao existe nenhum evento cadastrado\n");
      else
        eventos_data(agenda, num_eventos);
      break;

    case 4:
      if (num_eventos == 0)
        printf("Nao existe nenhum evento cadastrado\n");
      else
        evento_descricao(agenda, num_eventos);
      break;

    case 5:
      if (num_eventos == 0)
        printf("Nao existe nenhum evento cadastrado\n");
      else {
        remover_evento(agenda, num_eventos);
        num_eventos--;
      }
      break;

    case 6:

      arq_saida = fopen("arquivo.txt", "wt");
        if(arq_saida == NULL) {
          printf("Erro na abertura do arquivo de entrada!"); }

      for (i=0; i < num_eventos; i++) {
        fprintf(arq_saida,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%s%s", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano, agenda[i].inicio.hora, agenda[i].inicio.min, agenda[i].fim.hora, agenda[i].fim.min, agenda[i].local, agenda[i].descricao);
    }
      fclose(arq_saida);
      
      rodando = 0;
      break;

    default:

      printf("Opcao invalida\n");

      break;
    }
  }

  free(agenda);

  return 0;
}

void cadastrar_evento(struct Evento agenda[], int *num_eventos) {

  struct Evento evento;
  do {
    pega_evento(&evento);
  } while (choque_evento(agenda, &evento, *num_eventos) == 1);

  printf("Informe uma descricao: ");
  fflush(stdin);
  getchar();
  fgets(evento.descricao, 40, stdin);
  printf("Informe o local: ");
  fflush(stdin);
  fgets(evento.local, 40, stdin);

  *num_eventos += 1;

  agenda[*(num_eventos)-1] = evento;
  
}

void mostrar_eventos(struct Evento agenda[], int num_eventos) {

  int i;
  printf("\n%i mostra\n", num_eventos);
  for (i = 0; i < num_eventos; i++)
    printa_evento(agenda[i]);
    
}

void eventos_data(struct Evento agenda[], int num_eventos) {
  struct Data data;
  int i, nao_achou = 1;
  pega_data(&data);
  for (i = 0; i < num_eventos; i++)
    if (comp_data(&data, &agenda[i].data) == 0) {
      printa_evento(agenda[i]);
      nao_achou = 0;
    }
  if (nao_achou)
    printf("Nenhum evento foi encontrado nessa data\n");
}

void printa_evento(struct Evento evento) {
  printf("------------------\n");
 // puts(evento.descricao);

  printf("Descrição: %s\n", evento.descricao);
  printf("Data: %d/%d/%d\n", evento.data.dia,
         evento.data.mes,
         evento.data.ano);

  printf("Horario de inicio: %d:%d\n", evento.inicio.hora,
         evento.inicio.min);
  printf("Horario de encerramento: %d:%d\n", evento.fim.hora,
         evento.fim.min);
 // printf("Local: ");
 // puts(evento.local);
  printf("Local: %s\n", evento.local);
  printf("------------------\n");
} 

void evento_descricao(struct Evento agenda[], int num_eventos) {
  char descricao[40];
  int i, nao_achou = 1;
  printf("Informe a descricao do evento: ");
  getchar();
  fgets(descricao, 40, stdin);
  for (i = 0; i < num_eventos; i++)
    if (strcmp(descricao, agenda[i].descricao) == 0) {
      printa_evento(agenda[i]);
      nao_achou = 0;
    }
  if (nao_achou)
    printf("Nenhum evento com essa descricao foi encontrado\n");
}

void remover_evento(struct Evento agenda[], int num_eventos) {
  struct Data data;
  struct Horario horario;
  int i, j, nao_achou = 1;
  pega_data(&data);
  pega_horario(&horario);
  for (i = 0; i < num_eventos; i++)
    if (comp_data(&agenda[i].data, &data) == 0 &&
        comp_horario(&agenda[i].inicio, &horario) == 0) {
      for (j = i; j + 1 < num_eventos; j++)
        agenda[j] = agenda[j + 1];
      nao_achou = 0;
    }
  if (nao_achou)
    printf("Nenhum evento foi encontrado nessa data");
  else {
    agenda = realloc(agenda, sizeof(struct Evento) * (num_eventos - 1));
    printf("Evento removido com sucesso");
  }
}

void pega_data(struct Data *data) {
  printf("Informe a data\n");
  printf("Dia: ");
  scanf("%d", &data->dia);
  printf("Mes: ");
  scanf("%d", &data->mes);
  printf("Ano: ");
  scanf("%d", &data->ano);
}

void pega_evento(struct Evento *evento) {
  pega_data(&evento->data);
  while (!data_valida(&evento->data)) {
    printf("Data invalida!\n");
    pega_data(&evento->data);
  }

  printf("Informe o horario de inicio\n");
  pega_horario(&evento->inicio);
  while (!horario_valido(&evento->inicio)) {
    printf("Horario invalido, informe novamente!\n");
    pega_horario(&evento->inicio);
  }

  printf("Infome o horario do fim\n");
  pega_horario(&evento->fim);
  while (!horario_valido(&evento->fim)) {
    printf("Horario invalido, informe novamente!\n");
    pega_horario(&evento->fim);
  }
}

int choque_evento(struct Evento agenda[], struct Evento *evento,
                  int num_eventos) {
  int i;
  for (i = 0; i < num_eventos; i++)
    if (comp_data(&evento->data, &agenda[i].data) == 0 && comp_horario(&evento->inicio, &agenda[i].inicio) == 0) 
      {
        printf("Ja existe um evento com mesma data e horario! Realize a entrada "
               "novamente\n");
        return 1;
      }
  if(comp_data(&evento->data, &agenda[i].data) == 0){
    if (&evento->inicio.hora < &agenda[i].inicio.hora && &evento->fim.hora > &agenda[i].inicio.hora)
      if (&evento->inicio.hora < &agenda[i].inicio.hora || &evento->fim.hora >  &agenda[i].inicio.hora)
       printf("Ja existe um evento com mesma data e horario! Realize a entrada novamente\n");
      return 1;
  }
  return 0;
}

void pega_horario(struct Horario *horario) {
  printf("Hora: ");
  scanf("%d", &horario->hora);
  printf("Minutos: ");
  scanf("%d", &horario->min);
}

int data_valida(struct Data *data) {
  return data->dia >= 1 && data->dia <= 31 && data->mes >= 1 &&
         data->mes <= 12 && data->ano >= 2022;
}

int horario_valido(struct Horario *horario) {
  return horario->hora >= 0 && horario->hora <= 23 && horario->min >= 0 &&
         horario->min <= 59;
}

void ord_evento(struct Evento agenda[], int num_eventos) {
  int i, pos = num_eventos - 1;
  struct Evento aux;
  for (i = 0; i < num_eventos; i++)
    if (comp_data(&agenda[pos].data, &agenda[i].data) == 1 ||
        (comp_data(&agenda[pos].data, &agenda[i].data) == 0 &&
         comp_horario(&agenda[pos].inicio, &agenda[i].inicio) == 1)) {
      
      aux = agenda[pos];
      agenda[pos] = agenda[i];
      agenda[i] = aux;
      pos = i;
    }
}

int comp_data(struct Data *data1, struct Data *data2) {
  if (data1->ano < data2->ano)
    return 1;
  else if (data1->ano > data2->ano)
    return -1;
  else if (data1->mes < data2->mes)
    return 1;
  else if (data1->mes > data2->mes)
    return -1;
  else if (data1->dia < data2->dia)
    return 1;
  else if (data1->dia > data2->dia)
    return -1;
  else
    return 0;
} 

int comp_horario(struct Horario *horario1, struct Horario *horario2) {
  if (horario1->hora < horario2->hora)
    return 1;
  else if (horario1->hora > horario2->hora)
    return -1;
  else if (horario1->min < horario2->min)
    return 1;
  else if (horario1->min > horario2->min)
    return -1;
  else
    return 0;
}

void print_menu() {
  printf("\n1 - Cadastrar novo evento na agenda\n");
  printf("2 - Mostrar todos os eventos da agenda\n");
  printf("3 - Mostrar eventos de uma determinada data\n");
  printf("4 - Verificar eventos por descricao\n");
  printf("5 - Remover evento\n");
  printf("6 - Sair\n");
}