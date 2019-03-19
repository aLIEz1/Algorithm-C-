//
// Created by super on 2019/3/19.
//

#ifndef C_INSERTIONSORT_H
#define C_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        //寻找元素arr[i]合适的插入位置
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);//swap函数会历经三次赋值多次数组元素查找，耗时较长
            } else {
                break;//可以提前终止循环，理论上效率高于选择排序
            }
        }
    }

}

template<typename T>
void ImprovedInsertionSort(T arr[], int n) {//在排序近乎有序的数组的时候十分有力
    for (int i = 1; i < n; i++) {
        //寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j;//保存元素e应该插入的位置
        for (j = i; j > 0; j--) {
            if (arr[j - 1] > e) {
                arr[j] = arr[j - 1];
            } else {
                break;
            }
        }
        arr[j] = e;
    }

}

#endif //C_INSERTIONSORT_H
