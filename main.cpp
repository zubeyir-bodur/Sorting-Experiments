/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Zubeyir Bodur
 * ID: 21702382
 * Assignment: 1
 * Description: Main function and other global functions
 * that make main easier to write
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "sorting.h"

typedef  void (*SortType)(int *, const int, int&, int&);

enum OrderType {
    RANDOM = 1,
    ASCENDING = 2,
    DESCENDING = 3
};

void shuffle(int *arr, const int size) {
    random_device randomDevice;
    for (int i = 0; i < size; i++)
        swap(arr[i], arr[randomDevice() % size] );
}

/**
 * Sort the array back into the descending order
 * Spend least amount of time on this so use merge sort
 * @param arr
 * @param size
 */
void descend(int *arr, const int size) {
    mergeSortReverse(arr, 0, size - 1);
}

/**
 * Revert a array sorted in ascending order into its
 * previous order. Does nothing if order is already ASCENDING
 * @param arr
 * @param size
 * @param order
 */
void revert(int* arr, const int size, OrderType order) {
    if (order == RANDOM)
        shuffle(arr, size);
    else if (order == DESCENDING)
        descend(arr, size);
}

void print(int* arr, const int& size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " - ";
    cout << endl;
}

/**
 * Measure the time passed for one function call in ms
 * @param sort
 * @param arr
 * @param size
 * @param order
 * @param compCount
 * @param moveCount
 * @return
 */
double measureTime(SortType sort, int* arr, const int size, OrderType order, int& compCount, int& moveCount) {
    clock_t start = clock();
    auto timePassed = (clock_t)0;
    int noOfCalls = 0;
    // execute sort function for 5 seconds
    do {
        // start sort
        sort(arr, size, compCount, moveCount);
        // stop counting
        timePassed = timePassed + clock() - start;
        noOfCalls++;
        // revert the function into its original order
        revert(arr, size, order);
        // start counting again
        start = clock();
    } while ( timePassed < 5000l);
    return (1000 * (double)timePassed / CLOCKS_PER_SEC) / noOfCalls;
}

void initValues(int* arr, const int size, OrderType order) {
    for (int i = 0; i < size; i++) {
        if (order == RANDOM)
            arr[i] = rand();
        else if (order == ASCENDING)
            arr[i] = i + 1;
        else if (order == DESCENDING)
            arr[i] = size - i;
    }
}

int main() {
    string input;
    cout << "\nSORTING EXPERIMENTS in CLI, by Zubeyir Bodur" << endl;
    cout << "\nEnter number of each drop down menu to choose\n" << endl;
    do {
        cout << "\nChoose a sorting algorithm to experiment:" << endl;
        cout << "1 - Insertion Sort" << endl;
        cout << "2 - Merge Sort" << endl;
        cout << "3 - Quick Sort" << endl;
        cout << "4 - Quit" << endl;
        cin >> input;
        if ( input == "1" || input == "2" || input ==  "3") {
            int size;
            int orderNo;
            int compCount;
            int moveCount;
            OrderType order;
            SortType algorithm;

            cout << "\nEnter size: " << endl;
            cin >> size;

            // Initialize the array
            int* arr = new int[size];

            // Ask the order of the array
            cout << "Initial order of the array to be experimented" << endl;
            cout << "1 - Random" << endl;
            cout << "2 - Ascending" << endl;
            cout << "3 - Descending" << endl;
            cout << "Choose order:";
            cin >> orderNo;
            order = (OrderType)orderNo;

            // Give values to array for given order
            //TODO  Use the same randomized array for each algorithm
            //      For this, Orders of the arrays should be asked first,
            //      then arrays should be reverted for each sort
            //      Display also needs a change for this
            initValues(arr, size, order);

            // Determine the function to be called and conduct the experiment
            if (input == "1")
                algorithm = &insertionSort;
            else if (input == "2")
                algorithm = &mergeSort;
            else
                algorithm = &quickSort;
            double time = measureTime(algorithm, arr, size, order, compCount, moveCount);

            // Display the results
            cout << "\nRESULTS FOR THE EXPERIMENT" << endl;
            cout << "Size \t\t\t\t: " << size << endl;

            cout << "Order \t\t\t\t: ";
            if (order == 1)
                cout << "Random" << endl;
            else if (order == 2)
                cout << "Ascending" << endl;
            else
                cout << "Descending" << endl;

            cout << "Sorting Algorithm Used \t\t: ";
            if (input == "1")
                cout << "Insertion Sort" << endl;
            else if (input == "2")
                cout << "Merge Sort" << endl;
            else
                cout << "Quick Sort" << endl;

            cout << "# of Important Key Comparisons \t: " << compCount << endl;
            cout << "# of Important Moves \t\t: " << moveCount << endl;
            cout << "Time Elapsed\t\t\t: " << time << " ms"<< endl;

            // Delete the array
            delete [] arr;
        }
    } while (input != "4");
}
