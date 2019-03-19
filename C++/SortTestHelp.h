//
// Created by super on 2019/3/6.
//

#ifndef C_SORTTESTHELP_H

#include "iostream"
#include "ctime"
#include "assert.h"

using namespace std;
namespace SortTestHelp {
    //生成有n个元素的随机数组，每个元素的随机范围为[RangeL,RangeR]
    int *generateRandomArry(int n, int RangeL, int RangeR) {
        assert(RangeL <= RangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (RangeR - RangeL + 1) + RangeL;
        }
        return arr;
    }

    int *generateNearlyOrderedArry(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int j = 0; j < swapTimes; j++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template<typename T>
    void printArry(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    int *copyIntArry(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }
}

#endif //C_SORTTESTHELP_H
