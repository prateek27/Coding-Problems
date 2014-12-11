#include <iostream>
#include <cstring>
#include <map>
using namespace std;

bool isPermu(string *s1, string *s2, int n)
{
  map<string,int> freq;

  for (int i=0; i<n; i++) {
  freq[s1[i]]++;
  }

  for (int i=0; i<n; i++) {
  freq[s2[i]]--;
  }

  map<string,int>::iterator it;
for (it=freq.begin(); it!=freq.end(); it++) {
  if ( it->second != 0) {
  return false;
    }
  }
  return true;
}



int main()
{
  string s1[]={ "abcd", "pqrs", "110"};
  string s2[] = {"pqrs", "110", "abcd"};

  isPermu(s1, s2, 3);

  if (isPermu(s1, s2, 3))
  cout<<"yes"<<endl;
  else
  cout<<"no"<<endl;


  return 0;

}
