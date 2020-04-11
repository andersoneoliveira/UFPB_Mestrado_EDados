/*-----------------------------------
Andersoneo 08-abr-2020
Implementação algoritimo Selection Sort - 1a Atividade Mestrado UFPB Disciplina Estrutura de Dados
Prof. Gilberto Farias de Sousa Filho
Aluno: Anderson Ernani de Oliveira
Problema: dado um vetor com até 10 números inseridos pelo usuário,
ordená-los conforme escolha (crescente ou decrescente)
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
	int vetor[15]; //vetor que ira conter os valores informados pelo usuário
	int vetor_ordenado[15]; //vetor que ira conter os valores após ordenação
	int tam_vetor = 10;
	int menor_vl = 0; //variavel que contem o menor valor
	int menor_vl_anterior = 0;
	int indice, num_vetor;
	int ordem=0; //0 (crescente) ou 1 (decrescente)
	string tipo_ordem;
	/*--------inicio bloco para obter os vetor do vetor---*/
	cout << " Implementação algoritimo Selection Sort - 1a Atividade Mestrado UFPB Disciplina Estrutura de Dados Prof. Gilberto Farias de Sousa Filho Aluno: Anderson Ernani de Oliveira" << endl;
	cout << "Informe 0 (crescente) ou 1 (decrescente).: ";
	cin >> ordem;
	cout << "Informe " << tam_vetor << " números " << endl;
	indice = 1;
	while (indice <= tam_vetor)
		{
			cin >> vetor[indice];
			indice++;
		}
	/*---- fim bloco ----*/
	/* --- imprimo a data e hora corrente de início ---*/
	auto start = std::chrono::system_clock::now();	
	cout << " Início: " << ctime(&my_time) << endl;

	/* -- imprimo vetor para conferencia --*/
	cout << "Valores informados: " << endl;
	for (indice = 1; indice <= tam_vetor; indice++)
	{
		
		cout << setw(3) << vetor[indice] << " ";
	}
	cout << endl;
	/* organizo os valores no vetor conforme ordem escolhida*/
	if (ordem == 0) //crescente
	for (i1=1; i1 <= tam_vetor; i1++)
	{
		menor_vl = vetor[i1];
		tipo_ordem = " crescente";
		for (i2=1+i1; i2 <= (tam_vetor); i2++)
			{ 
				 if (vetor[i2] < menor_vl)
					{
						menor_vl_anterior = menor_vl;
						menor_vl = vetor[i2];  
						vetor[i2] = menor_vl_anterior;
					}
			}
		/* inicio bloco de teste 1 */
		//cout << " menor_vl=" << menor_vl << ", i1=" << i1 << endl;
		/* fim bloco de teste 1 */
		vetor_ordenado[i1] = menor_vl;
	}
	else
	if (ordem == 1) //decrescente
	for (i1=1; i1 <= tam_vetor; i1++)
	{
		menor_vl = vetor[i1];
		tipo_ordem = " decrescente";
		for (i2=1+i1; i2 <= (tam_vetor); i2++)
			{ 
				 if (vetor[i2] > menor_vl)
					{
						menor_vl_anterior = menor_vl;
						menor_vl = vetor[i2];  
						vetor[i2] = menor_vl_anterior;
					}
			}
		/* inicio bloco de teste 1 */
		//cout << " menor_vl=" << menor_vl << ", i1=" << i1 << endl;
		/* fim bloco de teste 1 */
		vetor_ordenado[i1] = menor_vl;
	}
	/* -- escrevo o vetor após ordenação -- */
	cout << "Valores após ordenação " << tipo_ordem << ": "<< endl;
	for (indice = 1; indice <= tam_vetor; indice++)
	{
		
		cout << setw(3) << vetor_ordenado[indice] << setw(3) << " ";
	}
	cout << endl;
 	/* --- imprimo a data e hora corrente de término ---*/
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;	
	cout << " Término: " << ctime(&my_time) 
	<< " Tempo gasto: " << elapsed_seconds.count() << "s\n" << endl;

	cout << endl;
}
