#include<iostream>
#include<unordered_map>
using namespace std;

struct dllNode{
	int pageno;
	struct dllNode*next,*prev;
};
dllNode*newNode(int no){
	dllNode* temp = new dllNode();
	temp->pageno=no;
	temp->next=NULL;
	temp->prev = NULL;
	return temp;
}

class Queue{
	int count;
	int capacity;

public:
	struct dllNode*head;
	struct dllNode*tail;

	Queue(){
		this->count =0;
		this->capacity = 0;
		head=NULL;
		tail=NULL;
	}
	//Returns a pointer to the pushed node
	void enqueue(int pageno,unordered_map<int,dllNode*>&map){

		if(head==NULL){
          //  cout<<"page no"<<pageno;
			head = newNode(pageno);
			tail=head;
			map[pageno]=head;
		//	cout<<map[pageno]<<" : "<<pageno<<endl;
			count++;
		}

		else{
			if(count<capacity){
				//Add to the front
				//cout<<"---------";
				dllNode* temp = newNode(pageno);
				temp->next = head;
				head->prev = temp;

				head = temp;

				map[pageno]=temp;
				//cout<<map[pageno]<<" : "<<pageno<<endl;
				count++;
     //           cout<<count<<"COUNT"<<endl;
   //             cout<<capacity<<"Capacity"<<endl;
            }
			//If  count becomes greater or equal to capacity,Remove a Node from tail and add a node to the front
			else{
 //               cout<<"................";
				map[tail->pageno]=NULL;
				tail->prev->next = NULL;
				dllNode* tprev = tail->prev;
				tail->prev = NULL;
				tail = tprev;



				dllNode* temp = newNode(pageno);
				temp->next = head;

				head->prev = temp;
				head = temp;
				map[pageno]=temp;

			}


		}

	}
	void setCapacity(int capacity){
		this->capacity= capacity;
	}
	void print(){
	dllNode*temp=head;
		while(temp!=NULL){
			cout<<temp->pageno<<" , ";
			temp=temp->next;
		}
		cout<<endl;
	}

};


class LRUCache{
unordered_map<int,dllNode*> map;
Queue q;
int capacity;

public:
	LRUCache(int capacity){
		q.setCapacity(capacity);
	}

	void ReferencePageNo(int pageno){
		dllNode* reqPage = map[pageno];

		if(reqPage==NULL){
			q.enqueue(pageno,map);

		}
		else{ //Page is Not NULL
			//cout<<"I am here"<<reqPage<<"="<<reqPage->pageno<<endl;
            //cout<<"Q.head"<<q.head;
			if(reqPage==q.head){
				//Do Nothing
                //cout<<"At front";
                return;
            }
            else{
            //Two cases arise -
            //1. Requested page is at last
            //2. Request Page is in the middle

                //Detach the Page , Attach it to the front
            //cout<<"in else";
                if(reqPage->next==NULL){

                    //cout<<"In the end";

                    q.tail = q.tail->prev;
                    reqPage->prev->next = NULL;
                    reqPage->prev=NULL;
                    reqPage->next = q.head;



                    q.head->prev =reqPage;
                    q.head=reqPage;
                }
                else{
                    //cout<<"Int the middle";
                    reqPage->prev->next=reqPage->next;
                    reqPage->next->prev = reqPage->prev;

                    reqPage->next= q.head;
                    q.head->prev =reqPage;
                    q.head=reqPage;
                }

            }


		}


	}
	void print(){
		q.print();
	}
	void printHead(){
        cout<<q.head->pageno<<endl;
	}
};


int main(){
LRUCache myLru(4);
// 1, 2, 3, 1, 4, 5
myLru.ReferencePageNo(1);
myLru.ReferencePageNo(2);
myLru.ReferencePageNo(3);
myLru.print();

myLru.ReferencePageNo(1);
myLru.print();
myLru.ReferencePageNo(4);
myLru.print();

myLru.ReferencePageNo(5);
myLru.print();
//myLru.ReferencePageNo(5);
//myLru.print();
return 0;
}
