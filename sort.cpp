//
// Created by 孙一恒 on 2020/6/7.
// 排序算法
//

#include "util.h"


/**
 * 插入排序,依次保证数组的前i个有序（来第i+1个元素的时候通过交换使其插入到合适位置)
 * 当 i = length 时,整个数组有序
 */
void insert_sort(int a[], int length) {
    for (int i = 0; i < length; i++) {
        int j = i;
        while (j - 1 >= 0 && a[j - 1] > a[j]) {
            swap(a[j], a[j - 1]);
        }
    }
}

/**
 * 选择排序,第i次选择出第i小/大的元素
 */
void choose_sort(int a[], int length) {
    int min, minIndex;
    for (int i = 0; i < length; i++) {
        min = a[i];
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

/**
 * 冒泡排序
 */
void bubble_sort(int a[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

/**
 * 归并排序
 */
void merge(int a[], int start, int end, int middle, int temp[]) {
    int index1 = start, index2 = middle + 1, current = start;
    while (index1 <= middle && index2 <= end) {
        if (a[index1] < a[index2]) {
            temp[current++] = a[index1++];
        } else {
            temp[current++] = a[index2++];
        }
    }
    while (index1 <= middle) {
        temp[current++] = a[index1++];
    }
    while (index2 <= end) {
        temp[current++] = a[index2++];
    }
}

void merge_sort(int a[], int length, int start, int end, int temp[]) {
    if (start < end) {
        int middle = (start + end) / 2;
        merge_sort(a, length, start, middle, temp);
        merge_sort(a, length, middle + 1, end, temp);
        merge(a, start, end, middle, temp);
    }
}

/**
 * 快速排序
 */
int paritition1(int a[], int start, int end) {
    int pivot = a[start];
    while (start < end) {
        while (start < end && a[end] >= pivot) {
            end--;
        }
        a[start] = a[end];
        while (start < end && a[start] <= pivot) {
            start++;
        }
        a[end] = a[start];
    }
    a[start] = pivot;
    return start;
}

void quick_sort(int a[], int length, int start, int end) {
    if (start < end) {
        int pivot_index = paritition1(a, start, end);
        quick_sort(a, length, start, pivot_index - 1);
        quick_sort(a, length ,pivot_index + 1, end);
    }
}