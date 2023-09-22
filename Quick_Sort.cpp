#include <iostream>
using namespace std;

#define MAX_SIZE 9

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to partition the array
int partition(int list[], int left, int right) {
    int pivot = list[left]; // Choose the leftmost element as the pivot
    int low = left + 1;
    int high = right;

    while (true) {
        while (low <= high && list[low] <= pivot) {
            low++;
        }

        while (low <= high && list[high] >= pivot) {
            high--;
        }

        if (low <= high) {
            swap(list[low], list[high]);
        }
        else {
            break;
        }
    }

    swap(list[left], list[high]);
    return high;
}

// Function to perform quick sort
void quickSort(int list[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(list, left, right);
        quickSort(list, left, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, right);
    }
}

int main() {
    int n;
    cin >> n;

    int list[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    quickSort(list, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << list[i] << endl;
    }

    return 0;
}