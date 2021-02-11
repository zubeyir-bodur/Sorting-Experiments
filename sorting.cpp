/**
 * Title: Algorithm Efficiency and Sorting
 * Zubeyir Bodur
 * Description: Source file for sorting functions
 *
 * In this experiment, only important moves and comparisons are
 * counted.
 *
 * For instance, assignments and comparisons that always occur are not
 * counted while a boolean equation ANDed with iteration amount condition.
 *
 * Also swap function has three moves but incrementing are not counted as a move, for instance.
 */
#include "sorting.h"

void insertionSort(int* arr, const int size,
                   int &compCount,
                   int &moveCount) {

    compCount = 0;
    moveCount = 0;
    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        int j = unsorted;

        while( (j > 0) && (arr[j - 1] > nextItem) ) {
            arr[j] = arr[j - 1];
            j--;
            compCount++;
            moveCount++;
        }
        arr[j] = nextItem;
        compCount++; // the missed KK if while loop is false
        moveCount++;
    }
}

void mergeSort(int* arr, const int size,
               int &compCount,
               int &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void mergeSort(int* arr,
               const int& first, const int& last,
               int &compCount,
               int &moveCount) {

    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void merge(int* arr,
           const int& first, const int& mid, const int& last,
           int &compCount,
           int &moveCount) {

    const int size = last - first + 1;

    int* temp = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    // start merging
    while( (first1 <= last1) && (first2 <= last2) ) {

        // if the first sub arrays element is larger, copy it to the temp
        compCount++;
        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            first1++;
        }
            // else, copy the second sub arrays element
        else {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
        moveCount++;
    }

    // if there are items skipped in the first sub array, put them into temp
    while ( first1 <= last1 )  {
        temp[index] = arr[first1];
        first1++;
        moveCount++;
    }

    // if there are items skipped in the second sub array, put them into temp
    while ( first2 <= last2 )  {
        temp[index] = arr[first2];
        first2++;
        moveCount++;
    }

    // finalize the sorting by copying the sorted array (temp) into our array
    for (int i = first; i <= size; i++) {
        arr[i] = temp[i];
        moveCount++;
    }
    delete[] temp;
}

void quickSort(int* arr,
               const int size,
               int &compCount,
               int &moveCount) {
    compCount = 0;
    moveCount = 0;
    int first = 0;
    int last = size - 1;
    quickSort(arr, first, last, compCount, moveCount);
}

/**
 * @param arr
 * @param first
 * @param last
 * @param compCount
 * @param moveCount
 */
void quickSort(int* arr,
               int& first, int& last,
               int &compCount,
               int &moveCount) {
    int pivotIndex;
    while (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        // sort the partition who holds the pivot only
        if (pivotIndex - first < last - pivotIndex ) {
            int l2 = pivotIndex - 1;
            quickSort(arr, first, l2, compCount, moveCount);
            first = pivotIndex + 1;
        }
        else {
            int f2 = pivotIndex + 1;
            quickSort(arr, f2, last, compCount, moveCount);
            last = pivotIndex - 1;
        }
    }
//    if (first < last) {
//        int pivotIndex;
//        partition(arr, first, last, pivotIndex, compCount, moveCount);
//        quickSort(arr, first, pivotIndex, compCount, moveCount);
//        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
//    }
}

void partition(int* arr,
               int& first, int& last,
               int& pivotIndex,
               int& compCount,
               int& moveCount) {
    pivotIndex = first; // take first item as the pivot

    // initially, everything but pivot is unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item until unknown is distributed to S1 & S2
    while (firstUnknown <= last) {

        // move item from unknown
        compCount++;
        if (arr[firstUnknown] < arr[pivotIndex]) { // belongs to S1
            lastS1++;
            swap( arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        } // else belongs to S2
        firstUnknown++;
    }
    // place pivot after S1 and save index
    swap( arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 3;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void mergeSortReverse(int* arr,
                      const int& first,
                      const int& last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSortReverse(arr, first, mid);
        mergeSortReverse(arr, mid + 1, last);
        mergeReverse(arr, first, mid, last);
    }
}

void mergeReverse(int* arr,
                  const int& first,
                  const int& mid,
                  const int& last) {
    const int size = last - first + 1;

    int* temp = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    // start merging
    while( (first1 <= last1) && (first2 <= last2) ) {

        // if the first sub arrays element is larger, copy it to the temp
        if (arr[first1] > arr[first2]) {
            temp[index] = arr[first1];
            first1++;
        }
        // else, copy the second sub arrays element
        else {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
    }

    // if there are items skipped in the first sub array, put them into temp
    while ( first1 <= last1 )  {
        temp[index] = arr[first1];
        first1++;
    }

    // if there are items skipped in the second sub array, put them into temp
    while ( first2 <= last2 )  {
        temp[index] = arr[first2];
        first2++;
    }

    // finalize the sorting by copying the sorted array (temp) into our array
    for (int i = first; i <= size; i++) {
        arr[i] = temp[i];
    }
    delete [] temp;
}
