#include "stdio.h"

int num_all = 0;

void bubble(int k[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++) {
			num_all++;
			if (k[j] > k[j + 1]) {
				temp = k[j];
				k[j] = k[j + 1];
				k[j + 1] = temp;
			}
		}
}

void selection_Sort(int k[], int n)
{
	int i, j, d;
	int temp;
	for (i = 0; i< n - 1; i++) {
		d = i;
		for (j = i + 1; j < n; j++) {
			num_all++;
			if (k[j] < k[d]) {
				d = j;
			}
		}
		
		temp = k[d];
		k[d] = k[i];
		k[i] = temp;
	}
}

void adjust(int k[], int i, int n)

{

	int j, temp;

	temp = k[i];

	j = 2 * i + 1;

	while (j<n) {
		num_all++;
		if (j<n - 1 && k[j]<k[j + 1])

			j++;

		if (temp >= k[j])

			break;

		k[(j - 1) / 2] = k[j];

		j = 2 * j + 1;

	}

	k[(j - 1) / 2] = temp;

}

void heap_sort(int arr[], int len) {
	int i, temp;
	for (i = len / 2 - 1; i >= 0; i--)
		adjust(arr, i, len - 1);
	for (i = len - 1; i > 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		adjust(arr, 0, i - 1);
	}
}

void heapSort(int k[], int n)
{
	int i, temp;
	for (i = n / 2 - 1; i >= 0; i--)
		adjust(k, i, n);
	for (i = n-1; i >= 1; i--) {
		temp = k[i];
		k[i] = k[0];
		k[0] = temp;
		adjust(k, 0, i);
	}
}


void merge_sort_recursive(int arr[], int reg[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2) {
		num_all++;
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	}
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

void merge_sort(int arr[], const int len) {
	int *reg = (int *)malloc(len * sizeof(int));
	merge_sort_recursive(arr, reg, 0, len - 1);
}

void quickSort(int k[], int left, int right)

{
	int temp;
	int i, last;

	if (left<right) {

		last = left;

		for (i = left + 1; i <= right; i++) {
			num_all++;
			if (k[i] < k[left]) {
				temp = k[++last];
				k[last] = k[i];
				k[i] = temp;
			}
		}
		temp = k[left];
		k[left] = k[last];
		k[last] = temp;

		quickSort(k, left, last - 1);

		quickSort(k, last + 1, right);

	}

}

int main(int argc, char const *argv[])
{
	int t;
	int a[1000] = { 0 };
	int i, num, index;
	scanf("%d%d", &num, &index);
	for (i = 0; i < num; ++i) {
		scanf("%d", &a[i]);
	}
	if (index == 1)
	{
		selection_Sort(a, num);
	}
	else if (index == 2)
	{
		bubble(a, num);
	}
	else if (index == 3)
	{
		heapSort(a, num);
	}
	else if (index == 4)
	{
		merge_sort(a, num);
	}
	else if (index == 5)
	{
		quickSort(a, 0, num-1);
	}
	
	for (i = 0; i < num; ++i) {
		printf("%d ", a[i]);
	}
	if (index == 1) {
		printf("\n%d", t);
	}
	else
	{
		printf("\n%d", num_all);
	}

	return 0;
}
