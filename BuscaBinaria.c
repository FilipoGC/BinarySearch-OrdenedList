#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int BuscaBinaria (int *v, int size, int value, int *indexStart, int *indexEnd) {
	int i = 0;
	int med = 0;
	while(*indexStart<= *indexEnd) {
		med = (*indexStart + *indexEnd) /2;
		if( v[med] == value) {
		printf("Valor encontrado na posiçao: %d Comparacoes: %d\n", med, i+1);
		return med;
		}		
		else if(v[med] > value && ++i>0) *indexEnd = med-1;
		else if(v[med] < value && ++i>0) *indexStart = med+1;
	}
	
	printf("Valor nao encontrado, Comparacoes: %d\n", i);
	return 0;
}
    		
int main () {
	
	clock_t t;
	t = clock();
	int i = 0;
	int v[1000000];
	
	while(scanf("%d", &v[i]) != EOF)i++;
	int indexStart = 0;
	int indexEnd = i;

	BuscaBinaria(v, i, 0965460835, &indexStart, &indexEnd); //Value for search is third argument
	
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f segundos para executar.\n", time_taken);
	
}
