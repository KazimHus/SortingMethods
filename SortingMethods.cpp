// Mirza Kazim Husain
// 5-20-2022
// Testing out different sorting methods and checking which is faster

#include <iostream>
#include <chrono>

using namespace std;
using namespace::chrono;

void swap(int arr[], int i, int j);           // swapping two numbers in an array
void heapSort(int arr[], int end);            // heap sort. it uses the percolate function to 
                                              // take in numbers by each and push them down.
void percolateUp(int arr[], int start, int pivot);
void Merge(int arr[], int left, int m, int end); // this uses the divide and 
                                                 // conquer method where it divides the function into two arrays
                                                 // and then sorts them separately 
                                                 // and then puts them together again
void mergeSort(int arr[], int left, int end);
void quicksort(int arr[], int left, int right); // this also uses the divide and 
                                                // conquer method but it takes a pivot and makes two sections 
                                                // with section 1 having numbers 
                                                // that have values less than the pivot and section 2 having
                                                // numbers more than the pivot
int partition(int arr[], int left, int right);
void heaptime();  // calculates time in nanoseconds for heap sort
void mergetime(); // calculates time in nanoseconds for merge sort
void quicktime(); // calculates time in nanoseconds for quick sort

const int size1 = 10;
const int size2 = 100;
const int size3 = 1000;
const int size4 = 10000;

int main() {
    cout << endl;
    cout << "Heap sorted: " << endl;
    heaptime();
    cout << "Merge sorted: " << endl;
    mergetime();
    cout << "Quick Sorted: " << endl;
    quicktime();
    cout << endl;
    return 0;
}

void heaptime() {
    int array1[size1];
    int array2[size2];
    int array3[size3];
    int array4[size4];
    
    for (int i = 0; i < size1; i++) {
        array1[i] = rand() % 1000000;
    }
    for (int i = 0; i < size2; i++) {
        array2[i] = rand() % 1000000;
    }
    for (int i = 0; i < size3; i++) {
        array3[i] = rand() % 1000000;
    }
    for (int i = 0; i < size4; i++) {
        array4[i] = rand() % 1000000;
    }
    
    cout << endl;
    // using this clock to calculate time for each sorting method
    auto start = high_resolution_clock::now();
    heapSort(array1, size1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    heapSort(array2, size2);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 100: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    heapSort(array3, size3);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 1000: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    heapSort(array4, size4);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10000: " << duration.count() << " nanoseconds " << endl << endl;
}

void mergetime() {
    int array1[size1];
    int array2[size2];
    int array3[size3];
    int array4[size4];
    
    for (int i = 0; i < size1; i++) {
        array1[i] = rand() % 1000000;
    }
    for (int i = 0; i < size2; i++) {
        array2[i] = rand() % 1000000;
    }
    for (int i = 0; i < size3; i++) {
        array3[i] = rand() % 1000000;
    }
    for (int i = 0; i < size4; i++) {
        array4[i] = rand() % 1000000;
    }
    
    cout << endl;
    auto start = high_resolution_clock::now();
    mergeSort(array1, 0, size1 - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    mergeSort(array2, 0, size2 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 100: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    mergeSort(array3, 0, size3 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 1000: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    mergeSort(array4, 0, size4 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10000: " << duration.count() << " nanoseconds " << endl << endl;
}

void quicktime() {
    int array1[size1];
    int array2[size2];
    int array3[size3];
    int array4[size4];
    
    for (int i = 0; i < size1; i++) {
        array1[i] = rand() % 1000000;
    }
    for (int i = 0; i < size2; i++) {
        array2[i] = rand() % 1000000;
    }
    for (int i = 0; i < size3; i++) {
        array3[i] = rand() % 1000000;
    }
    for (int i = 0; i < size4; i++) {
        array4[i] = rand() % 1000000;
    }
    
    cout << endl;
    auto start = high_resolution_clock::now();
    quicksort(array1, 0, size1 - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    quicksort(array2, 0, size2 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 100: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    quicksort(array3, 0, size3 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 1000: " << duration.count() << " nanoseconds " << endl << endl;
    
    start = high_resolution_clock::now();
    quicksort(array4, 0, size4 - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "Execution time for N = 10000: " << duration.count() << " nanoseconds " << endl << endl;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapSort(int arr[], int end) {
    int size = end / 2 - 1;
    for (int i = size; i >= 0; i--) {
        percolateUp(arr, end, i);
    }
    for (int i = end - 1; i > 0; i--) {
        swap(arr, 0, i);
        percolateUp(arr, i, 0);
    }
}
 void percolateUp(int arr[], int start, int end)
 {
    int largest = end;
    int left = 2 * end + 1;
    int right = 2 * end + 2;
    if (left < start && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < start && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != end) {
        swap(arr, end, largest);
        percolateUp(arr, start, largest);
    }
 }
 void Merge(int arr[], int left, int m, int end)
 {
    int const partone = m- left + 1;
    int const parttwo = end - m;
    int* leftA = new int[partone];
    int* rightA = new int[parttwo];
    for (int i = 0; i < partone; i++) {
        leftA[i] = arr[left + i];
    }
    for (int j = 0; j < parttwo; j++) {
        rightA[j] = arr[m + 1 + j];
    }
    int tempone = 0;
    int temptwo = 0;
    int tempArr = left;
    while (tempone < partone && temptwo < parttwo) 
    {
        if (leftA[tempone] <= rightA[temptwo])
        {
            arr[tempArr] = leftA[tempone];
            tempone++;
        }
        else {
            arr[tempArr] = rightA[temptwo];
            temptwo++;
        }
        tempArr++;
    }
    while (tempone < partone)
    {
        arr[tempArr] = leftA[tempone];
        tempone++;
        tempArr++;
    }
    while (temptwo < parttwo) 
    {
        arr[tempArr] = rightA[temptwo];
        temptwo++;
        tempArr++;
    }
 }
 void mergeSort(int arr[], int left, int end)
 {
    if (left < end)
    {
        int mid = (end + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, end);
        Merge(arr, left, mid, end);
    }
 }
 void quicksort(int arr[], int left, int right)
 {
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
    }
 }
 int partition(int arr[], int left, int pivot)
 {
    int low = left - 1;
    int high = pivot - 1;
    for (int j = left; j <= high; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            low++;
            swap(arr, low, j);
        }
    }
    swap(arr, low+1, pivot);
    return  low+1;
 }