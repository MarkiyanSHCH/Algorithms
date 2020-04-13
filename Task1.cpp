#include <iostream>
using namespace std;

// Function Read Array
void readArr(int* arr, int n) {
    cout << "Enter Elem Of Array: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

// Function Print Array
void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}

// Function Shift Right Elem Of Array
int* shiftArr(int* arr, int n, int step) {
    // Create Shifted Array
    int* shiftedArr = new int[n] { 0 };
    // Set Elem In Shifted Index
    for (int i = 0; i < n; i++)
        shiftedArr[(i + step) % n] = arr[i];
    // Return Shifted Array
    return shiftedArr;
    // Clear Memory
    delete[] shiftedArr;
}

// Function Check If An Array Is Sorted Or Not
bool checkSortArr(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// Function Binary Search
int binarySearch(int arr[], int l, int r, int x) {
    // Check If Elem Last In Array Part
    if (r >= l) {
        // Find Index Of mid Elem
        int mid = l + (r - l) / 2;
        // Check If Elem Found
        if (arr[mid] == x)
            return mid;
        // Take Left Or Right Array Parts
        return arr[mid] > x ? binarySearch(arr, l, mid - 1, x) : binarySearch(arr, mid + 1, r, x);

    }
    // Return -1 If 404
    return -1;
}

// Function Search Unsigned
void searchUnsigned(int arr[], int l, int r, int& aboveZero) {
    // Check If Elem Last In Array Part
    if (r >= l) {
        // Find Index Of mid Element
        int mid = l + (r - l) / 2;
        // Check If Elem Below Zero
        if (arr[mid] >= 0) {
            aboveZero++;
        }
        // Call Function For Left Array Part
        searchUnsigned(arr, l, mid - 1, aboveZero);
        // Call Function For Right Array Part
        searchUnsigned(arr, mid + 1, r, aboveZero);
    }
}

int main()
{
    cout << "1. Shift Elem In Array \n2. Find Number In Array \n3. Count Unsigned Elem In Array \nChoose Task: ";
    int task;
    cin >> task;
    cout << "Enter Size Of Array: ";
    int size;
    cin >> size;
    // Create Array
    int* arr = new int[size];
    // Call Function Read Array
    readArr(arr, size);
    
    // Check Which Task Chose User
    switch (task) {
    case 1: {
        cout << "Enter Number Of Shift: ";
        int shift;
        cin >> shift;
        arr = shiftArr(arr, size, shift);
        printArr(arr, size);
        break;
    }
    case 2: {
        if (checkSortArr(arr,size)) {
            cout << "Enter Number Which You Want Find: ";
            int x;
            cin >> x;
            int index = binarySearch(arr, 0, size - 1, x);
            if (index == -1) {
                cout << "404" << endl;
            }
            else {
                cout << "Index Of Elem " << x << " Is: " << index << endl;
            }
        }
        else {
            cout << "Error: Array Not Sorted" << endl;
        }
        break; 
    }
    case 3: {
        int aboveZero = 0;
        searchUnsigned(arr, 0, size - 1, aboveZero);
        cout << "Count Of Positive Numbers Is: " << aboveZero << endl;
        break; 
    }
    // Output Error If User Chose Wrong Task
    default:
        cout << "Error : You Enter Wrong Task" << endl;
        break;
    }
    


    

    

    // Clear Memory
    delete[] arr;
    
}


