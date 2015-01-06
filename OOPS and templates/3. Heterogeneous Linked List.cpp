#include<iostream>
using namespace std;


typedef struct heterogeneous_list
{
        void *item;
    struct heterogeneous_list *next;
}

class Node{
void* data;
Node*next;
enum { CHAR, STRING, FLOAT, INT } type;
}



int main(){

return 0;
}
