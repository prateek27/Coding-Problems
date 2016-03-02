#include<iostream>
#include<cstring>
using namespace std;

class Trie{

public:
    int words;
    int prefixes;
    Trie*edges[26];
    Trie();
    void addWord(string word);
    int countWords(string word);
    int countPrefix(string prefix);
};

Trie::Trie(){
    words =0;
    prefixes =0;

    for(int i=0;i<26;i++){
        edges[i] = NULL;
    }
}
void Trie::addWord(string s){

    if(s.size()==0){
       words = words+1;
        return;
    }
    else{
        prefixes++;
        char k = s[0];
        if(edges[k-'a']==NULL){
            edges[k-'a']=new Trie;
        }
        edges[k-'a']->addWord( s.substr(1));
    }

}

int Trie::countWords(string s){
    if(s.size()==0){
        return words;
    }

    else{
        char k = s[0];

        if(edges[k-'a']==NULL){
            return 0;
        }
         return edges[k-'a']->countWords(s.substr(1));
    }

}
int Trie::countPrefix(string s){
    if(s.size()==0){
        return prefixes;
    }

    else{
        char k = s[0];

        if(edges[k-'a']==NULL){
            return 0;
        }
         return edges[k-'a']->countPrefix(s.substr(1));
    }

}

int main(){

Trie t;

t.addWord("bel");
t.addWord("hbel");
t.addWord("hello");
t.addWord("hel");
return 0;
}
