#ifndef _INTRO_SORT_H_
#define _INTRO_SORT_H_

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable& pivot = a[right - 1];
	int i = left, j = right - 1;
	do {
		while (a[++i] < pivot);
		while (pivot < a[--j]);
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	} while (i < j);

	std::swap(a[i], a[right - 1]);	// Restore pivot
	return i;
}

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void introSort(vector<Comparable>& a, int left, int right) {
	assert(left <= right);
	if (right - left > 15) {
		int i = partition(a, left, right);
		introSort(a, left, i - 1);	// Sort small elements
		introSort(a, i + 1, right);	// Sort large elements
	}
	else {						// Do an insertion sort on the subarray
		for (int i = (left+1); i <= right; ++i)
		{
			Comparable tmp = std::move(a[i]);
			int j;
			for (j = i; j > 0 && tmp < a[j - 1]; --j)
			{
				a[j] = std::move(a[j - 1]);
			}
			a[j] = std::move(tmp);
		}
	}
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable> void introSort(vector < Comparable >& a) {
	introSort(a, 0, a.size() - 1);
}

#endif
