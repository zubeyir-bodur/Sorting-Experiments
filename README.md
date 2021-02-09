# Sorting Experiments
A CLI Tool for making experiments on a few sorting algorithms

### Setup
Even though it is a CLI application, it is possible to execute this using CMake, with minimum version 3.17.

If you don't want to use CMake, clone this repository and type
>g++ -o main *.cpp;.\main

### Remarks
- The tool experiments a soring algorithm at least 5 seconds, regardless of the size of the list, for better precision. 

- Quicksort algorithm used is not double-recursive. It would limit the maximum size and the stack would run out of memory, so a different approach is used.

The common recursive approach:
````
 void quicksort(DataType theArray[], int first, int last) {
      int pivotIndex;
      if (first < last) {
          partition(theArray, first, last, pivotIndex);
          quicksort(theArray, first, pivotIndex-1);
          quicksort(theArray, pivotIndex+1, last);
      }
}
````
Iterative approach used:
````
void quicksort(DataType theArray[], int first, int last) {
    int pivotIndex;
    while (first < last) {
         partition(arr, first, last, pivotIndex, compCount, moveCount);
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
}
````
