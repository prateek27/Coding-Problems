#include<iostream>
#include<set>
#include<queue>
using namespace std;

bool isadjacent(string a, string b)
{
    int count = 0;  // to store count of differences
    int n = a.length();

    // Iterate through all characters and return false
    // if there are more than one mismatching characters
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i]) count++;
        if (count > 1) return false;
    }
    return count == 1 ? true : false;
}

class Node{
public:
    int len;
    string word;
    Node(int l,string w):word(w),len(l){}
};


int shortestChainLen(set<string> &D,string start,string target){

queue<Node> q;
q.push(Node(0,start));
D.erase(start);


    while(!q.empty()){

        Node f = q.front();
        q.pop();
        cout<<f.word<<endl;


            for(auto it=D.begin();it!=D.end();it++){

                if(isadjacent(f.word,*it)){
                    string word = *it;
                    int len  = f.len + 1;
                    cout<<len<<endl;

                        q.push(Node(len,word));
                        D.erase(word);

                        if( word.compare(target)==0){
                        return len;
                        }

                    }


                }
            }

return 0;
}




int main(){

set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");

    string start = "toon";
    string target = "plea";

    cout<<shortestChainLen(D,start,target);

return 0;
}
