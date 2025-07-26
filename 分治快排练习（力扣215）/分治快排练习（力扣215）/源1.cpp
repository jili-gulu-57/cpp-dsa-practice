void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int begin = left, end = right;
	//每次选取左边的值为基值，但在数组有序的情况下，时间复杂度最坏，为O(N^2);
	//int pivot = begin;

	//采用三数取中，避免上述情况
	int index = GetMidIndex(arr, left, right);
	int pivot = index;
	Swap(&arr[begin], &arr[index]);
	int key = arr[begin];

	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
			end--;
		Swap(&arr[pivot], &arr[end]);
		//arr[pivot] = arr[end];
		pivot = end;
		while (begin < end && arr[begin] <= key)
			begin++;
		Swap(&arr[pivot], &arr[begin]);
		//arr[pivot] = arr[begin];
		pivot = begin;

	}

	pivot = begin;
	arr[pivot] = key;

	//小区间优化
	if ((pivot - 1 - left) > 10)
		QuickSort(arr, left, pivot - 1);
	else
		InsertSort(arr + left, pivot - left);
	if ((right - pivot - 1) > 10)
		QuickSort(arr, pivot + 1, right);
	else
		InsertSort(arr + pivot + 1, right - pivot);
}