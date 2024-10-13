/*
Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.
*/

#include <iostream>
#include <vector>

void swapvec(std::vector<int> &v, int* arr) {
    for (int i = 0; i < v.size(); i++) {
        int tmp = v[i];
        v[i] = *(arr+i);
        *(arr+i) = tmp;
    }
}

int main () {
    std::vector<int> v = {1, 2, 3, 4, 5};
    int arr[5] = {10, 20, 30, 40, 50};
    swapvec(v, arr);
    for (int i = 0; i < 5; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}