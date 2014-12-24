/* This program remove comments from the program
 * Author: Prateek
 */
#include<iostream>
using namespace std;
int main() {
    char ch,nextchar, prevchar;
    bool quotes = false;
    char str[] = "http://www.facebook.com /*PQRSTUV*/";
    char str1[] = "Prateek says-\"hi!!\"";
    while((ch = cin.get())!=EOF) {
        if (!quotes && ch == '/') {
            nextchar = cin.get();
            if (nextchar == '/') { // For Single Line Comments
                while((ch = cin.get())!='\n' && ch!=EOF);
                cout << ch;
            } else if (nextchar == '*') { // For Multi line Comments
                ch=cin.get();
                nextchar = cin.get();
                while(ch!='*' || nextchar!='/') {
                    ch = nextchar;
                    nextchar = cin.get();
                }
            } else {
                cout << ch << nextchar;
            }
            continue;
        } else if (!quotes && ch == '"') {
            quotes = true;
        } else if (quotes && prevchar != '\\' && ch == '"') {
            quotes = false;
        }
        prevchar = ch;
        cout << ch;
    }
}
