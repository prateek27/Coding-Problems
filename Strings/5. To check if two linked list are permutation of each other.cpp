#include<iostream>
#include<list>
#include<map>
#include<string>
using namespace std;

typedef list<char> LinkedList;
typedef map<char,int> HashMap;

LinkedList makeList(string s){
    list<char> myList;

    for(int i=0;i<s.length();i++){
        myList.push_back(s[i]);
    }
return myList;
}

void printLinkedList(LinkedList l){
LinkedList::iterator it;
for(it=l.begin();it!=l.end();it++){
    cout<<(*it)<<" -> ";

    }
    cout<<endl;
return;
}


bool isPermutation(LinkedList &l1,LinkedList &l2){




LinkedList::iterator it;
// or You can write list<char>::iterator it
HashMap h1,h2;

//Initialsize the value with 0 count.
for(char ch='a';ch<='z';ch++){
    h1[ch]=0;
    h2[ch] = 0;
}


for(it = l1.begin();it!=l1.end();it++){
    h1[*it]++;
}


for(it = l2.begin();it!=l2.end();it++){
    h2[*it]++;
}

bool ans=true;
for(char ch='a';ch<='z';ch++){
        if(h1[ch]!=h2[ch]){
            ans=false;
            break;
    }
}
return ans;
}



int main(){
LinkedList l1 = makeList("abc");
LinkedList l2 = makeList("cdba");
printLinkedList(l1);
printLinkedList(l2);
if(isPermutation(l1,l2))
    cout<<"Yes its a permutation";
else
    cout<<"Not a permuation";

return 0;
}

