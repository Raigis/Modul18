/*
Кролик сидит на нулевой ступеньке большой лестницы.
Он может прыгать на одну или более ступенек вверх, но не далее чем на k.
Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов. 

Напишите рекурсивную функцию, которая принимает число n типа int и число k — максимальную длину прыжка, а возвращает количество способов, которым кролик может доскакать до n-й ступеньки.
В функции для аргумента “максимальная длина прыжка” задать значение, по умолчанию равное 3.
*/

#include <iostream>
//Первый способ
int jumps1 (int n, int k = 3, int count = 0) {
    for (int i = k; i > 0; i--){
        if (n - i > 0) {
            count = jumps1((n-i), k, count); 
        } else if (n - i == 0) {
            count++;
        } 
    }
    return count;
}
//Второй способ
int pow (int degree, int num = 2) {
    if (degree == 1) {
        return num;
    } else {
        return pow(degree-1, num*2);
    }
}
int jumps2 (int n, int k = 3) {
    int count = 0;
    for (; k > 0; k--) {
        if (n-k == 0 || k == 1) {
            count++;
        } else {
            count += pow(n-k);
        }
    }
    return count; 
}

int main () {
    std::cout << "Enter the number of steps and the maximum jump length(0 - none):\n";
    int n, k;
    std::cin >> n >> k;
    if (k == 0) {
        std::cout << jumps1(n) << " ";
        std::cout << jumps2(n);
    } else {
        std::cout << jumps1(n, k) << " ";
        std::cout << jumps2(n, k);
    }
}
