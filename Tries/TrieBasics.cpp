#include<iostream>
#include<cstring>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

class Node{
public:
    bool value;
    Node* children[26];

    Node(){
        value=0;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class Trie{
public:
    Node*root;
    int cnt;

    Trie(){
        root = new Node();
        cnt =0;
    }
    //-----------------------------Inserting a key in the trie.
    void insert(char key[]){
        cnt++;
        int len = strlen(key);
        Node* start = root;


        for(int i=0;i<len;i++){

            int index = CHAR_TO_INDEX(key[i]);

            if(start->children[index]==NULL){
                start->children[index] = new Node();
            }
            start = start->children[index];
        }
        start->value = 1; //Mark the end of the leaf.
    }
    //-------------------------------------------Deleting a key in the trie.
    bool search(char key[]){
        int len = strlen(key);
        Node*start = root;

        for(int i=0;i<len;i++){

            int index = CHAR_TO_INDEX(key[i]);

            if(!start->children[index]){

                cout<<"Here";

            }
            else{
                start = start->children[i];
                }
        }
        if(start->value==1 && start!=NULL){
            return true;
        }
        else{
            return false;

        }

    }

};


int main(){

Trie t;

char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};


for(int i=0;i<8;i++){
    t.insert(keys[i]);
}


if(t.search("the"))
{
cout<<"Found";
}

else
{
cout<<"Not found !";
}



return 0;
}
