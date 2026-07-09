#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool removeValue(int value) {
        if (!head) return false;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        if (!current->next) return false;
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        return true;
    }

    bool searchValue(int value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void display() const {
        if (!head) {
            cout << "Linked list is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Linked list: ";
        while (current) {
            cout << current->data;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = (int)arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayArray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size()) cout << ", ";
    }
    cout << endl;
}

int main() {
    LinkedList list;
    vector<int> arr;
    int mainChoice = 0;

    while (true) {
        cout << "\n=== DSA Project Menu ===" << endl;
        cout << "1. Linked List Operations" << endl;
        cout << "2. Array Operations (Sort + Binary Search)" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> mainChoice;

        if (mainChoice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        switch (mainChoice) {
            case 1: {
                int choice = 0;
                while (true) {
                    cout << "\n--- Linked List Menu ---" << endl;
                    cout << "1. Insert value at end" << endl;
                    cout << "2. Remove value" << endl;
                    cout << "3. Search value" << endl;
                    cout << "4. Display list" << endl;
                    cout << "5. Back to main menu" << endl;
                    cout << "Choose an option: ";
                    cin >> choice;

                    if (choice == 5) break;

                    int value;
                    switch (choice) {
                        case 1:
                            cout << "Enter value to insert: ";
                            cin >> value;
                            list.insertAtEnd(value);
                            cout << "Value inserted." << endl;
                            break;
                        case 2:
                            cout << "Enter value to remove: ";
                            cin >> value;
                            if (list.removeValue(value)) {
                                cout << "Value removed." << endl;
                            } else {
                                cout << "Value not found." << endl;
                            }
                            break;
                        case 3:
                            cout << "Enter value to search: ";
                            cin >> value;
                            if (list.searchValue(value)) {
                                cout << "Value found in the linked list." << endl;
                            } else {
                                cout << "Value not found in the linked list." << endl;
                            }
                            break;
                        case 4:
                            list.display();
                            break;
                        default:
                            cout << "Invalid option. Try again." << endl;
                    }
                }
                break;
            }
            case 2: {
                int choice = 0;
                while (true) {
                    cout << "\n--- Array Operations Menu ---" << endl;
                    cout << "1. Input array elements" << endl;
                    cout << "2. Display current array" << endl;
                    cout << "3. Sort array using Merge Sort" << endl;
                    cout << "4. Sort array using Quick Sort" << endl;
                    cout << "5. Binary search on sorted array" << endl;
                    cout << "6. Back to main menu" << endl;
                    cout << "Choose an option: ";
                    cin >> choice;

                    if (choice == 6) break;

                    if (choice == 1) {
                        int n;
                        cout << "How many elements? ";
                        cin >> n;
                        arr.clear();
                        arr.resize(n);
                        for (int i = 0; i < n; ++i) {
                            cout << "Enter element " << i + 1 << ": ";
                            cin >> arr[i];
                        }
                        cout << "Array input complete." << endl;
                    } else if (choice == 2) {
                        displayArray(arr);
                    } else if (choice == 3) {
                        if (arr.empty()) {
                            cout << "Array is empty. Input values first." << endl;
                        } else {
                            mergeSort(arr, 0, (int)arr.size() - 1);
                            cout << "Array sorted with Merge Sort." << endl;
                            displayArray(arr);
                        }
                    } else if (choice == 4) {
                        if (arr.empty()) {
                            cout << "Array is empty. Input values first." << endl;
                        } else {
                            quickSort(arr, 0, (int)arr.size() - 1);
                            cout << "Array sorted with Quick Sort." << endl;
                            displayArray(arr);
                        }
                    } else if (choice == 5) {
                        if (arr.empty()) {
                            cout << "Array is empty. Input values first." << endl;
                        } else {
                            int key;
                            cout << "Enter value to search: ";
                            cin >> key;
                            int index = binarySearch(arr, key);
                            if (index >= 0) {
                                cout << "Value found at position " << index + 1 << " (0-based index " << index << ")." << endl;
                            } else {
                                cout << "Value not found in the array." << endl;
                            }
                        }
                    } else {
                        cout << "Invalid option. Try again." << endl;
                    }
                }
                break;
            }
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
