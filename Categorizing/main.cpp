#include <iostream>
#include <vector>

using namespace std;

void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "DSA Task: Sorting and Searching Algorithms\n";
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<int> copy = arr;
            selectionSort(copy);
            cout << "After Selection Sort: ";
            displayArray(copy);
        } else if (choice == 2) {
            vector<int> copy = arr;
            mergeSort(copy, 0, n - 1);
            cout << "After Merge Sort: ";
            displayArray(copy);
        } else if (choice == 3) {
            cout << "Enter key to search: ";
            int key;
            cin >> key;
            int index = linearSearch(arr, key);
            if (index >= 0) {
                cout << "Element " << key << " found at index " << index << ".\n";
            } else {
                cout << "Element " << key << " not found.\n";
            }
        } else if (choice == 4) {
            if (!isSorted(arr)) {
                cout << "Array is not sorted. Sorting with Merge Sort before binary search.\n";
            }
            vector<int> sorted = arr;
            mergeSort(sorted, 0, n - 1);
            cout << "Sorted array: ";
            displayArray(sorted);
            cout << "Enter key to search: ";
            int key;
            cin >> key;
            int index = binarySearch(sorted, key);
            if (index >= 0) {
                cout << "Element " << key << " found at index " << index << " in sorted array.\n";
            } else {
                cout << "Element " << key << " not found.\n";
            }
        } else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid option. Please choose again.\n";
        }
    }

    return 0;
}
