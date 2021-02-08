/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Assignment: 1
 * Description: Header file for sorting functions
 */
#ifndef HW1_SORTING_H
#define HW1_SORTING_H
using namespace std;
void insertionSort(int* arr, const int size,
                   int &compCount,
                   int &moveCount);

void mergeSort(int* arr, const int size,
               int &compCount,
               int &moveCount);

void mergeSort(int* arr, const int first, const int last,
               int &compCount,
               int &moveCount);

void quickSort(int* arr, const int size,
               int &compCount,
               int &moveCount);

void quickSort(int* arr, const int first, const int last,
               int &compCount,
               int &moveCount);

void merge(int* arr,
           const int first, const int mid, const int last,
           int &compCount,
           int &moveCount);

void partition(int* arr,
               const int first, const int last,
               int& pivotIndex,
               int &compCount,
               int &moveCount);

void swap(int& x, int& y);

void mergeSortReverse(int* arr,
                      const int& first,
                      const int& last);

void mergeReverse(int* arr,
                  const int& first,
                  const int& mid,
                  const int& last);


#endif
