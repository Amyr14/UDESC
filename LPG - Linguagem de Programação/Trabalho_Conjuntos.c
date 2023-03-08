
#include <stdio.h>
#define M 8
#define N 8

void print_menu();
void inserir_dados(int m[M][N], int cont);
void remover_conjunto(int m[M][N], int cont);
void uniao_conjuntos(int m[M][N], int *p_cont);
void inters_conjuntos(int m[M][N], int *p_cont);
void mostrar_conjunto(int m[M][N], int cont);
void mostrar_conjuntos(int m[M][N], int cont);
void buscar_valor(int m[M][N], int cont);
int busca_seq(int v[N], int cont);


int main() {
	int m[M][N], i, j, nao_sair = 1, op;
	int cont = 0;
	
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			m[i][j] = 0;
	
	print_menu();

	while(nao_sair) {
		printf("\nSelecione uma operacao: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				if ( cont == M )
					printf("\nLimite de conjuntos atingido");
				else
					cont++;
				break;
			case 2:
				if ( cont == 0 )
					printf("\nNenhum conjunto registrado");
				else
					inserir_dados(m, cont);
				break;
			case 3:
				if ( cont == 0 )
					printf("\nNenhum conjunto registrado");
				else {
					remover_conjunto(m, cont);
					cont--;
				}
				break;
			case 4:
				if ( cont < 2 )
					printf("\nNao existem conjuntos suficientes");
				else if ( cont == M )
					printf("\nLimite de conjuntos atingido");
				else 
					uniao_conjuntos(m, &cont);
				break;
			case 5:
				if ( cont < 2 )
					printf("\nNao existem conjuntos suficientes");
				else if ( cont == M )
					printf("\nLimite de conjuntos atingido");
				else
					inters_conjuntos(m, &cont);
				break;
			case 6:
				mostrar_conjunto(m, cont);
				break;
			case 7:
				mostrar_conjuntos(m, cont);
				break;
			case 8:
				buscar_valor(m, cont);
				break;
			case 9:
				nao_sair = 0;
				break;
			default:
				printf("\nOpcao invalida!");
				break;
		}
	} 
}


void inserir_dados(int m[M][N], int cont){
	int i, j, input, operando = 1;
	printf("\nDigite o indice do conjunto: ");
	scanf("%d", &i);
	
	while (i < 0 || i >= cont){
		printf("\nO indice digitado nao e valido, digite novamente: ");
		scanf("%d", &i);
	}
	
	j = busca_seq(m[i], 0);

	if (j == -1)
		printf("\nO conjunto esta cheio");		
	else {	
		while ( operando && j < N ) {
			printf("\nDigite um valor: "); 
			scanf("%d", &input);
			if ( input == 0 )
				operando = 0;
			else if ( busca_seq(m[i], input) != -1 )
				printf("\nEste valor ja existe no conjunto");
			else {
				m[i][j] = input;
				j++;
			}
		} 
	}
}

void remover_conjunto(int m[M][N], int cont){
	int i, j;
	printf("Digite o indice do conjunto: ");
	scanf("%d", &i);
	
	while ( i < 0 || i >= cont ) { 
		printf("O indice digitado nao e valido\n");
		printf("Digite o indice do conjunto: ");
		scanf("%d", &i);
	}
	
	for (; i < cont; i++)
		for (j = 0; j < N; j++)
			m[i][j] = m[i + 1][j];
}

void buscar_valor(int m[M][N], int cont){
	int i, chave;
	printf("\nDigite o valor a ser buscado: ");
	scanf("%d", &chave);
	while ( chave == 0 ) {
		printf("\n Zero nao e um valor valido, digite novamente: ");
		scanf("%d", &chave);
	}
	printf("\nConjuntos que contem o valor %d: ", chave);
	for ( i = 0; i < cont; i++ ) {
		if ( busca_seq(m[i], chave) != -1 )
			printf("%d ", i);
	}
}

void uniao_conjuntos(int m[M][N], int *p_cont){
	int i, j, conj1, conj2, card1, card2, card_uniao = 0, card_inters = 0;
	printf("\nDigite o indice do primeiro conjunto: ");
	scanf("%d", &conj1);
	while ( conj1 < 0 || conj1 >= *p_cont ) {
		printf("\nIndice invalido, digite novamente: ");
		scanf("%d", &conj1);
	} 
	printf("\nDigite o indice do segundo conjunto: ");
	scanf("%d", &conj2);
	while ( conj2 < 0 || conj2 >= *p_cont ) {
		printf("Indice invalido, digite novamente: ");
		scanf("%d", &conj2);
	}

	for ( i = 0; i < N && m[conj1][i] != 0; i++ );
	for ( j = 0; j < N && m[conj2][j] != 0; j++ );	

	card1 = i;
	card2 = j;

	for ( i = 0; i < card1; i++ )
		if ( busca_seq( m[conj1], m[conj2][i] ) != -1 )
			card_inters++;

	card_uniao = (card1 + card2) - card_inters;

	if ( card_uniao > N )
		printf("\nA cardinalidade da uniao e maior que o limite de valores");
	else {
		for ( i = 0; i < card1; i++ )
			m[*p_cont][i] = m[conj1][i];
		for ( j = 0; j < card2; j++ )
			if ( busca_seq( m[conj1], m[conj2][j]) == -1 ){
				m[*p_cont][i] = m[conj2][j];
				i++;
			}
		(*p_cont)++;
	}
}

void inters_conjuntos(int m[M][N], int *p_cont){
	int conj1, conj2, i, j, maior, card_maior, menor, card_menor;
	printf("\nDigite o indice do primeiro conjunto: ");
	scanf("%d", &conj1);
	while ( conj1 < 0 || conj1 >= *p_cont ) {
		printf("\nIndice invalido, digite novamente: ");
		scanf("%d", &conj1);
	} 
	printf("\nDigite o indice do segundo conjunto: ");
	scanf("%d", &conj2);
	while ( conj2 < 0 || conj2 >= *p_cont ) {
		printf("\nIndice invalido, digite novamente: ");
		scanf("%d", &conj2);
	}

	for ( i = 0, j = 0; i < N && m[conj2][i] != 0 ; i++ )
		if ( busca_seq(m[conj1], m[conj2][i]) != -1 ) {
			m[*p_cont][j] = m[conj2][i];
			j++;
		}
	(*p_cont)++;
}

void mostrar_conjunto(int m[M][N], int cont){
	int input, j;
	printf("\nDigite o indice do conjunto: ");
	scanf("%d", &input);
	while ( input < 0 || input >= cont ) {
		printf("\nIndice invalido, digite novamente: ");
		scanf("%d", &input);
	}
	printf("\nConjunto %d: ", input);
	for ( j = 0; j < N; j++ ) 
		printf("%d ", m[input][j]);
}

void print_menu(){
	printf("----------------------\n");
	printf("1. Criar novo conjunto vazio\n");
	printf("2. Inserir dados em um conjunto\n");
	printf("3. Remover um conjunto\n");
	printf("4. Fazer a uniao entre dois conjuntos\n");
	printf("5. Fazer a interseccao entre dois conjuntos\n");
	printf("6. Mostrar um conjunto\n");
	printf("7. Mostrar todos os conjuntos\n");
	printf("8. Buscar um valor\n");
	printf("9. Sair do programa\n");
	printf("----------------------\n");
}

int busca_seq(int v[N], int chave){
	int i;
	for(i = 0; i < N; i++)
		if ( v[i] == chave )
			return i;
	return -1;
}

void mostrar_conjuntos(int m[M][N], int cont){
	int i, j;	
	printf ("Ha %d conjuntos:\n",cont);
	for(i = 0; i < cont; i++){ 
		if ( m[i][0] == 0 )
			printf("%d = vazio", i);
		else {
			printf("%d = ", i);
			for (j = 0; j < N; j++)
				if ( m[i][j] != 0 )
					printf("%d ", m[i][j]);
		}	
		printf("\n");
	}		
}
