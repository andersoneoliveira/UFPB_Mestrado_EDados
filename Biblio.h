int dividir(int vet[], int esq, int dir)
{
	int aux; //troca de posições
	int cont = esq; //fixo para comparar com a 1a posição do vetor sempre
	for (int i = esq + 1; i < dir; i++)
	{
		if (vet[i] < vet[esq])
		{
			cont++;
			aux = vet[i];
			vet[i] = vet[cont];
			vet[cont] = aux;

		}
	}
	aux = vet[esq];
	vet[esq] = vet[cont];
	vet[cont] = aux;

	return cont;
}

void quickSort(int vet[], int esq, int dir)
{
	int pos;
	if (esq < dir)
	{
		pos = dividir(vet, esq, dir);
		quickSort(vet, esq, pos - 1);
		quickSort(vet, pos + 1, dir);
	}
}

