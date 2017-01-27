#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int first, int last)
{
	int tempArray[last + 1];
	int middle = (first + last) / 2;
	int left = first;
	int right = middle + 1;

	for (int i = first; i <= last; ++i)
		tempArray[i] = (left <= middle) && ((right > last) || (array[left] < array[right])) ? array[left++] : array[right++];

	for (int i = first; i <= last; ++i)
		array[i] = tempArray[i];
}

void sort(int *array, int first, int last)
{
	if (first < last)
	{
		sort(array, first, (first + last) / 2);
		sort(array, (first + last) / 2 + 1, last);
		merge(array, first, last);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 3, 5, 1, 7, 4, 3};
	sort(arr, 0, 6);
	for (int i = 0; i < 7; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}