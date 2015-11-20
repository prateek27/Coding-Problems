#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include<cstdio>
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

int no;

/*right_min_heap.push(5);
right_min_heap.push(4);
right_min_heap.push(6);
while(!right_min_heap.empty())
{
    cout<<right_min_heap.top();
    right_min_heap.pop();
}*/

    while(1){

        scanf("%d",&no);
        int median=9999;

        if(no==0)
            break;

        else if(no==-1)
           {
            median=left_max_heap.top();
            left_max_heap.pop();
            printf("%d\n",median);

           }
        else{


            if(no>=median)
              {
                  cout<<"Pusing in right heap";
                 right_min_heap.push(no);
              }

            else
                left_max_heap.push(no);

            median=left_max_heap.top();

            int leftSize = left_max_heap.size();
            int rightSize = right_min_heap.size();

            if(leftSize)
                printf("Left : %d",left_max_heap.top());
                printf("Median :%d",median);

            if(leftSize-rightSize>1){
                while(leftSize-rightSize>1)
                {
                    int left = left_max_heap.top();
                    left_max_heap.pop();
                    right_min_heap.push(left);
                }
            }
            else if(rightSize-leftSize>1){
                while(rightSize-leftSize>1){
                    int right=right_min_heap.top();
                    right_min_heap.pop();
                    left_max_heap.push(right);
                }
            }

        }



    }




  return 0;
}
