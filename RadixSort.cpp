/*30-04-2020 Anderson Ernani de Oliveira
Mestrado UFPB - Estrutura de Dados - Radix Sort - prof. Gilberto

Trabalha com números de d dígitos.
• Ordena os elementos coluna por coluna (dígitos)
• De forma não intuitiva, a ordenação começa pelo número menos significativo
• O processo continua até os elementos terem sido ordenados sobre todos os dígitos d.

Algoritmo Radix Sort
RADIX-SORT(A, d)
for i ← 1 to d
do usar uma ordenação para o arranjo A sobre o dígito i.
Este procedimento supõe que cada elemento no arranjo de n elementos tem d dígitos, onde o
dígito 1 é o dígito menos significativo e o dígito d é o dígito mais significativo

Vídeo pesquisado https://www.youtube.com/watch?v=XiuSW_mEn7g
		https://www.youtube.com/watch?v=nu4gDuFabIM
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

void CoutingSort(int vet_a[], int N, int M)
{
	//K = é o elemento maior do vetor - 88
	//N = é o número de elementos do vetor - 50 itens 
	const int k = M; //a constante k conterá o valor do maior elemento do vetor, neste meu exemplo é 12
	const int tamanho = N;//sizeof(vet_a) / sizeof(int);
	int vet_c[1000]; // vetor auxiliar
	time_t my_time = time(NULL); //obter data e hora corrente do sistema
	char str[26]; //necessário para cálcular o tempo

	/* Zero o vetor auxiliar */
	for (int i = 0; i <= k; i++)
	{
		vet_c[i] = 0;
	}
	//Abaixo farei C[i] contém o número de elementos iguais a i em A
	for (int j = 0; j < tamanho; j++)
	{
		vet_c[vet_a[j]]++;
	}

	//Abaixo farei vetor_A[i] receber os indices ordenados tantas vezes eles aparecem no antes da ordenação.
	int i = 0;
	int j = 0;
	int n = k;
	for (j = 0; j <= k; j++)
		for (n = vet_c[j]; n > 0; n--)
			vet_a[i++] = j;


}

int getMax(int * vetor,int n)
{ //função para encontrar o maior valor dentro do vetor
	int valor = 0;
	for (int x = 0; x < n; x++)
	{
		if (valor < vetor[x])
			valor = vetor[x];
	}
	return valor;
}

void radixSort(int * vetor, int tam)
{
	//percorro o vetor e encontro o maior valor
	int m = getMax(vetor, tam);
	//linha de teste
	//cout << " maior valor é = " << m << endl;
	for (int exp =1; m/exp > 0; exp *=10 )
		CoutingSort(vetor, tam, m);
}

int main()
{
	int vet[] = { 200,574,3,102,211,378,120,100,3,222,188,344,115,177,320,146,610,479,84,64,78,46,331,44,546,299,58,314
		,190,2,3,12,0,3,22,88,44,15,77,32,46,61,47,84,64,8,4,33,44,54 };
	const int tam_vet = 50;

	/* Imprimio o vetor antes de ser organizado */
	cout << endl;
	cout << "Vetor - Valores Originais:" << endl;
	for (int i = 0; i < tam_vet; i++)
	{
		cout << setw(5) << vet[i];
	}
	cout << endl;
	cout << endl;

	radixSort(vet, tam_vet);

	// imprimo vetor após execução do radixSort
	cout << "Vetor - apos ordenação radixSort:" << endl;
	for (int j = 0; j < tam_vet; j++)
	{
		cout << setw(5) << vet[j];
	}
	cout << endl;
	cout << endl;

	return 0;
}