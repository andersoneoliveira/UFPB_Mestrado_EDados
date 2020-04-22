/*22-04-2020 Anderson Ernani de Oliveira
Mestrado UFPB - Estrutura de Dados - Divisão e conquista - prof. Gilberto
Implementando o algoritimo de Quick Sort - exemplo youtube: https://www.youtube.com/watch?v=iT5Iofq6i3U
Autor G-Tech Informática.
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
	int vet[] = { 2,1,7,8,3,5,6,4 };
	int tamanho = sizeof(vet) / sizeof(int);
	time_t my_time = time(NULL); //obter data e hora corrente do sistema
	char str[26]; //necessário para cálcular o tempo

	/* Imprimio o vetor antes de ser organizado */
	for (int i = 0; i < tamanho; i++)
	{
		cout << setw(3) << vet[i];
	}
	cout << endl;
	cout << endl;
	/* --- imprimo a data e hora corrente de início ---*/
	auto start = std::chrono::system_clock::now();
	ctime_s(str, sizeof str, &my_time);
	cout << " Inicio: " << str << endl;

	quickSort(vet, 0, tamanho);

	/* --- imprimo a data e hora corrente de término ---*/
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	ctime_s(str, sizeof str, &my_time);
	cout << " Termino: " << str
		<< " Tempo gasto: " << elapsed_seconds.count() << "s\n" << endl;
	cout << endl;

	/* Imprimio o vetor após ser organizado */
	for (int i = 0; i < tamanho; i++)
	{
		cout << setw(3) << vet[i];
	}
	cout << endl;

	return 0;
}