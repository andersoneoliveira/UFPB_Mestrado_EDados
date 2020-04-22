/*21-04-2020 Anderson Ernani de Oliveira
Mestrado UFPB - Estrutura de Dados - Divis�o e conquista - prof. Gilberto
Implementando o algoritimo de Merge Sort - exemplo youtube: https://www.youtube.com/watch?v=RZK6KVpaT3I
Autor Dyllan Sallee.
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "biblio.h"

using namespace std;

int main()
{
	int vet[] = { 5,2,4,7,1,3,2,6 };
	int tamanho = sizeof(vet) / sizeof(int);
	time_t my_time = time(NULL); //obter data e hora corrente do sistema
	char str[26]; //necess�rio para c�lcular o tempo

	int baixo = 0;
	int alto = tamanho - 1;

	/* Imprimio o vetor antes de ser organizado */
	for (int i = 0; i < tamanho; i++)
	{
		cout << setw(3) << vet[i];
	}
	cout << endl;
	cout << endl;

	/* --- imprimo a data e hora corrente de in�cio ---*/
	auto start = std::chrono::system_clock::now();
	ctime_s(str, sizeof str, &my_time);
	cout << " Inicio: " << str << endl;

	mergeSort(vet, baixo, alto);

	/* --- imprimo a data e hora corrente de t�rmino ---*/
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	ctime_s(str, sizeof str, &my_time);
	cout << " Termino: " << str
		<< " Tempo gasto: " << elapsed_seconds.count() << "s\n" << endl;
	cout << endl;

	/* Imprimio o vetor ap�s ser organizado */
	for (int i = 0; i < tamanho; i++)
	{
		cout << setw(3) << vet[i];
	}
	cout << endl;

	return 0;
}