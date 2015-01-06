#include<iostream>
using namespace std;
template <class test, class b>
class Node {
    Node * left;
    Node * right;
    test data;
    public:
        void setData(test d) {
            data = d;
        };
        void setLeft(Node * l) {
            left = l;
        };
};
class Tree {
    Node * root;
    static void printInorder(Node * root) {
        if (root == NULL) 
            return;
        printInorder(root->getLeft());
        cout << root->getData() << endl;
        printInorder(root->getRight());
        return;
    }
    public:
    void inorderPrint() const {
        Tree::printInorder(root);
    }
    operator>>(istream & in) {
        root = NULL;
        int data;
        in >> data;
        root = new node(

    }
}
template <class T>
T average(T * arr, int n) {
    T sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum+= arr[i];
    }
    return sum/n;
};

int main(){
    stack<int> S;
    Node <int> T;
    pair <int, int> p;


    int arr[] = { 1,2,3,3,4};
    float a1[] = { 1.23, 2.32, 4.343, 4.34};
    cout << average(arr, 5) << endl;
    cout << average(a1,4) << endl;
    return 0;
}
