//
// Created by super on 2019/3/19.
//
#include <iostream>
#include <algorithm>
#include "SortTestHelp.h"
#include "InsertionSort.h"

using namespace std;

template<typename T>
void __Merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; i++) {
        aux[i - l] = arr[i];
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template<typename T>
void __mergeSort(T arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __Merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {
    __mergeSort(arr, 0, n - 1);
}

int main() {
    int n = 100000;
    int *arr1 = SortTestHelp::generateRandomArry(n, 0, n);
    int *arr2 = SortTestHelp::copyIntArry(arr1, n);
    SortTestHelp::testSort("InsertionSort", ImprovedInsertionSort, arr2, n);
    SortTestHelp::testSort("MergeSort", mergeSort, arr1, n);
    delete[] arr2;
    delete[] arr1;
}
