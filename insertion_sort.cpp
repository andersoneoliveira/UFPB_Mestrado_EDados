/*-----------------------------------
Andersoneo 09-abr-2020
Implementação algoritimo Insertion Sort - 1a Atividade Mestrado UFPB Disciplina Estrutura de Dados
Prof. Gilberto Farias de Sousa Filho
Aluno: Anderson Ernani de Oliveira
Problema: dado um vetor com 10 números fixos ordenados de forma crescente, todo novo valor inserido pelo usuário deverá ser inserido em sua posição ordenada, e os demais números deverão ser reorganizados à direita
-------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;

int main()
{
	time_t my_time = time(NULL); //obter data e hora corrente do sistema
	int i1; // índice 1
	int i2; // índice 2
	int n1, n2, n3; //números que o usuário irá informar
	int vetor[25]; //vetor que ira conter os valores fixos iniciais
	int indice, novo_valor;
	/* --- início bloco atribuição valores fixos ao vetor ---*/
	/*vetor[0] = 5; vetor[1] = 10; vetor[2] = 15; vetor[3] = 20; vetor[4] = 25;
	vetor[5] = 30; vetor[6] = 35; vetor[7] = 40; vetor[8] = 45; vetor[9] = 50;*/
	vetor[0] = 10; vetor[1] = 15; vetor[2] = 20; vetor[3] = 25; vetor[4] = 30;
	vetor[5] = 35; vetor[6] = 40; vetor[7] = 45; vetor[8] = 50; vetor[9] = 55;
	/* --- fim bloco atribuição valores fixos ao vetor ---*/
	/*--------inicio bloco para obter 3 números por parte do usuário---*/
	cout << " Implementação algoritimo Insertion Sort - 1a Atividade Mestrado UFPB Disciplina Estrutura de Dados Prof. Gilberto Farias de Sousa Filho Aluno: Anderson Ernani de Oliveira" << endl;
	cout << endl;

	/* -- imprimo vetor com valores fixos iniciais --*/
	cout << "Valores iniciais do vetor: " << endl;
	for (indice = 0; indice < 10; indice++)
	{
		
		cout << setw(4) << vetor[indice] << " ";
	}
	cout << endl;
	
	cout << "Informe 3 números para serem inseridos no vetor atual. " << endl;

	cout << "Nr 1= ";
	cin >> n1;
	cout << "Nr 2= ";
	cin >> n2;
	cout << "Nr 3= ";
	cin >> n3;
	cout << endl;
	/* --- imprimo a data e hora corrente de início ---*/
	auto start = std::chrono::system_clock::now();	
	cout << " Início: " << ctime(&my_time) << endl;
	/*---- fim bloco para obter 3 números por parte do usuário ----*/
	/* --- início bloco invoco a função de reordenação --- */
	vetor[10] = n1;
	for (int i = 1; i < 14; i++)
		{
			novo_valor = vetor[i];
			int j = i -1;
			while ((j >= 0) && (vetor[j] > novo_valor))
			{
				vetor[j + 1] = vetor[j];
				j--;
			}
			vetor[j + 1] = novo_valor;
			
		} 

	vetor[13] = n2;
	for (int i = 4; i < 17; i++)
		{
			novo_valor = vetor[i];
			int j = i -1;
			while ((j >= 0) && (vetor[j] > novo_valor))
			{
				vetor[j + 1] = vetor[j];
				j--;
			}
			vetor[j + 1] = novo_valor;
			
		} 
	vetor[15] = n3;
	for (int i = 7; i < 20; i++)
		{
			novo_valor = vetor[i];
			int j = i -1;
			while ((j >= 0) && (vetor[j] > novo_valor))
			{
				vetor[j + 1] = vetor[j];
				j--;
			}
			vetor[j + 1] = novo_valor;
			
		}
	/* -- imprimo vetor com valores novos inseridos --*/
	cout << "Vetor reorganizado: " << endl;
	//for (indice = 2; indice < 14; indice++)
	//for (indice = 3; indice < 15; indice++)
	for (indice = 5; indice < 18; indice++)
	{
		
		cout << setw(4) << vetor[indice] << " ";
	}
	cout << endl; 
	cout << endl;
	/* --- imprimo a data e hora corrente de término ---*/
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;	
	cout << " Término: " << ctime(&my_time) 
	<< " Tempo gasto: " << elapsed_seconds.count() << "s\n" << endl;
	cout << endl;
}
