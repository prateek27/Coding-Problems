#include<iostream>
#define SIZE 10
using namespace std;
class DynamicArray {
    int top;
    int * arr;
    int size;
    public:
    DynamicArray() {
        arr = new int[SIZE];
        size = SIZE;
        top = 0;
    };
    DynamicArray(int s) {
        arr = new int[s];
        size = s;
        top = 0;
    };
    ~DynamicArray() {
        delete [] arr;
    }
    DynamicArray(DynamicArray & D) {
        top = D.top;
        arr = D.arr;
        size = D.size;
    }
    void push(const int * element) {
        element = 10;
        arr[top++] = element;
        if (top == size) {
            int * p = new int[size * 2];
            for (int i = 0; i < top;i++) {
                p[i] = arr[i];
            }
            delete [] arr;
            arr = p;
            size <<= 1;
        }
    }
    int pop();
};
int DynamicArray::pop() {
        // Implement By Yourself
        return arr[--top];
}
void F1(DynamicArray D) {
    D.pop();
}
int main () {
    DynamicArray D, E(100);
    int x = 10;
    D.push(&x);
    F1(D);
}
