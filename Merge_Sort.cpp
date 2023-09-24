//From https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html

#include <iostream>
using namespace std;

#define MAX_SIZE 8

int sorted[MAX_SIZE]; // Additional space is needed

// i: Index for the sorted left list
// j: Index for the sorted right list
// k: Index for the list to be sorted
/* Merging process of two adjacent arrays list[left...mid] and list[mid+1...right] */
/* (The actual sorting process) */
void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* Merging the divided sorted lists */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // Copy the remaining values
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    // Copy the sorted array (temporary array) back to the original list[]
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}

// Merge Sort
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2; // Calculate the middle position and divide the list equally - Divide
        merge_sort(list, left, mid); // Sort the front part of the list - Conquer
        merge_sort(list, mid + 1, right); // Sort the back part of the list - Conquer
        merge(list, left, mid, right); // Merge the two sorted sub-arrays - Combine
    }
}

int main() {
    int i;
    const int n = MAX_SIZE;
    int list[n] = { 21, 10, 12, 20, 25, 13, 15, 22 };

    // Perform merge sort (left: start of the array = 0, right: end of the array = 7)
    merge_sort(list, 0, n - 1);

    // Print the sorted result
    for (i = 0; i < n; i++) {
        cout << list[i] << endl;
    }

    return 0;
}
