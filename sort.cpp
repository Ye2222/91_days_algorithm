#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 插入排序
// 直接插入排序
void direct_insert_sort(int a[], int n) {
    int temp;
    for(int i = 1; i < n; i++) {
        temp = a[i];
        int j = i - 1;
        for(; j >= 0; j--) {
            if(temp < a[j])
                a[j+1] = a[j];
            else break; 
        }
        a[j+1] = temp; 
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

// 折半插入排序


// 希尔排序



// 选择排序

// 堆排序
void adjust(int a[], int k, int size) {
    // 将非叶结点暂时存储，后面可以直接替换该值
    int temp = a[k];
    for(int i = 2*k+1; i < size; i = 2*i+1){
        // 注意这里最后一个叶结点判定时不要越界
        if(i+1 < size && a[i] < a[i+1]) i++;
        if(temp < a[i]) {
            a[k] = a[i];
            k = i;
        }
        else break;
    }
    a[k] = temp;
}

void Build_heap(int a[], int size) {
    for(int i = size/2; i > 0; i--) {
        adjust(a, i-1, size);
    }
}

void heap_sort(int a[], int size) {
    Build_heap(a, size);
    // for(int i = 0; i < size; i++) cout << a[i] << endl;
    for(int i = size - 1; i >= 0; i--) {
        cout << a[0] << endl;
        if(i == 0) break;
        swap(a, 0, i);
        adjust(a, 0, i-1);
    }
    cout << a[0];
}

int main(){
    int a[] = {2, 1, 8, 41, 4, 5, 17, 9, 11, 42};
    int size = sizeof(a) / sizeof(a[0]);
    // direct_insert_sort(a, size);
    heap_sort(a, size);
}