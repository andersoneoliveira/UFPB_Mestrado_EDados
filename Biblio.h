
void merge(int A[], int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			c[k] = A[i];
			k++;
			i++;
		}
		else
		{
			c[k] = A[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = A[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		A[i] = c[i];
	}
}

void mergeSort(int v[], int baixo, int alto)
{
	if (baixo < alto)
	{
		int meio;
		meio = (baixo + alto) / 2;
		mergeSort(v, baixo, meio);
		mergeSort(v, meio + 1, alto);

		merge(v, baixo, alto, meio);
	}
	return;
}

