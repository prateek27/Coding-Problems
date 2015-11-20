#include <iostream>
#include<queue>
using namespace std ;

class compare{
	public:
	bool operator()(const int&a, const int&b)
	{
            return a>b;
	}
};


int main() {
	// your code goes here
    priority_queue<int> mypq;
	priority_queue<int,vector<int>,compare> q;
	mypq.push(1);
	mypq.push(5);
	mypq.push(3);
    cout<<mypq.top();
    //unordered+map<char, int> mp1;

	return 0;
}
