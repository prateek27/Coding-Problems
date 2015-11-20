#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include<cstdio>
#include<climits>
using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};


  std::priority_queue<int> left_max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int> > right_min_heap;



int main ()
{

int no,leftSize,rightSize;

/*right_min_heap.push(5);
right_min_heap.push(4);
right_min_heap.push(6);
while(!right_min_heap.empty())
{
    cout<<right_min_heap.top();
    right_min_heap.pop();
}*/
int median=INT_MAX;
   leftSize=rightSize=0;
int t;
cin>>t;
while(t--)
{
while(!left_max_heap.empty())
    left_max_heap.pop();
while(!right_min_heap.empty())
    right_min_heap.pop();

leftSize=rightSize=0;
median=INT_MAX;

    while(1){

        scanf("%d",&no);

        if(no==0)
            break;
          else if(no==-1)
           {
               leftSize=left_max_heap.size();
               rightSize=right_min_heap.size();

            if(leftSize==rightSize||leftSize-rightSize==1){
            median=left_max_heap.top();
            left_max_heap.pop();
            leftSize=left_max_heap.size();
            }
            else if(rightSize-leftSize==1){
            median=right_min_heap.top();
            right_min_heap.pop();
            rightSize=right_min_heap.size();
            }

                if(leftSize-rightSize>1){
                while(leftSize-rightSize>1)
                {

                    int left = left_max_heap.top();
                    left_max_heap.pop();
                    right_min_heap.push(left);
                    rightSize++;
                    leftSize--;
                }
            }
            else if(rightSize-leftSize>1){
                while(rightSize-leftSize>1){
                    int right=right_min_heap.top();
                    right_min_heap.pop();
                    left_max_heap.push(right);
                    rightSize--;
                    leftSize++;
                }
            }

            printf("%d\n",median);
            }

        else{

            //cout<<"Checking"<<no<<" "<<median;
            if(no>=median)
              {
                 // cout<<"Pusing in right heap";
                 right_min_heap.push(no);
              }

            else
                left_max_heap.push(no);


            int leftSize = left_max_heap.size();
            int rightSize = right_min_heap.size();




           /* if(leftSize)
               printf("Left heap: %d\n",left_max_heap.top());
            if(rightSize)
               printf("Right heap: %d\n",right_min_heap.top());
        */




            if(leftSize-rightSize>1){
                while(leftSize-rightSize>1)
                {
                    //cout<<"hello1";
                    int left = left_max_heap.top();
                    left_max_heap.pop();
                    right_min_heap.push(left);
                    rightSize++;
                    leftSize--;
                }
            }
            else if(rightSize-leftSize>1){
                while(rightSize-leftSize>1){
                      // cout<<"hello2";
                    int right=right_min_heap.top();
                    right_min_heap.pop();
                    left_max_heap.push(right);
                    rightSize--;
                    leftSize++;
                }
            }
             if(leftSize==rightSize)
                median=left_max_heap.top();
            else if(leftSize-rightSize==1)
                median=left_max_heap.top();
            else if(rightSize-leftSize==1)
                median=right_min_heap.top();

        }
}

}




  return 0;
}
