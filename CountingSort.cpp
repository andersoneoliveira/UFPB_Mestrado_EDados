/*30-04-2020 Anderson Ernani de Oliveira
Mestrado UFPB - Estrutura de Dados - Counting Sort - prof. Gilberto

A Ordena��o por Contagem pressup�e que cada um dos n elementos de entrada � um inteiro no intervalo de 1 a K, para algum inteiro
K.
Id�ia B�sica:
� Determinar para cada elemento de entrada x, o n�mero de elementos menores que x.
� Com esta informa��o podemos inserir o elemento diretamente em sua posi��o no arranjo de sa�da.
Exemplo: Se houver 17 elementos menores que x, logo x deve ser colocado na posi��o 18.

V�deo pesquisado https://www.youtube.com/watch?v=En8daEdcpJU
Linguagem C Programa��o Descomplicada
[ED] Aula 123 - Ordena��o: CountingSort
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int main()
{
	int vet_a[] = { 2,5,3,0,2,3,12,0,3,22,88,44,15,77,32,46,61,47,84,64,8,4,33,44,54,2,5,3,0,2,3,12,0,3,22,88,44,15,77,32,46,61,47,84,64,8,4,33,44,54 };
	const int k = 88; //a constante k conter� o valor do maior elemento do vetor, neste meu exemplo � 12
	int tamanho = sizeof(vet_a) / sizeof(int);
	int vet_c[100]; // vetor auxiliar
	time_t my_time = time(NULL); //obter data e hora corrente do sistema
	char str[26]; //necess�rio para c�lcular o tempo

	/* Imprimio o vetor antes de ser organizado */
	cout << endl;
	cout << "Vetor A - Valores Originais:" << endl;
	for (int i = 0; i < tamanho; i++)
	{
		cout << setw(3) << vet_a[i];
		/* aproveito o looping para Zerar o vetor auxiliar */
		vet_c[i] = 0;
	}
	cout << endl;
	cout << endl;
	
	/* --- imprimo a data e hora corrente de in�cio ---*/
	auto start = std::chrono::system_clock::now();
	ctime_s(str, sizeof str, &my_time);
	cout << " Inicio: " << str << endl;
	cout << endl;
	cout << endl;
	/* Zero o vetor auxiliar */
	for (int i = 0; i <= k; i++)
	{
		vet_c[i] = 0;
	}
	//Abaixo farei C[i] cont�m o n�mero de elementos iguais a i em A
	for (int j = 0; j < tamanho; j++)
	{
		vet_c[vet_a[j]]++;
	}
	
	// imprimo vetor c 
	cout << "Vetor C - contem o numero de ocorrencias para cada indice i no vetor_A:" << endl;
	for (int j = 0; j <= k; j++)
	{
		cout << setw(3) << vet_c[j];
	}
	cout << endl;
	cout << endl;
	//Abaixo farei vetor_A[i] receber os indices ordenados tantas vezes eles aparecem no antes da ordena��o.
	int i = 0;
	int j = 0;
	int n = k;
	for (j = 0; j <= k; j++)
		for (n = vet_c[j]; n > 0; n--)
			vet_a[i++] = j;
		
	
	// imprimo vetor A 
	cout << "Vetor A - ordena��o final:" << endl;
	for (int j = 0; j < tamanho; j++)
	{
		cout << setw(3) << vet_a[j];
	}
	cout << endl;
	cout << endl;

	/* --- imprimo a data e hora corrente de t�rmino ---*/
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	ctime_s(str, sizeof str, &my_time);
	cout << " Termino: " << str
		<< " Tempo gasto: " << elapsed_seconds.count() << "s\n" << endl;
	cout << endl;

	return 0;
}