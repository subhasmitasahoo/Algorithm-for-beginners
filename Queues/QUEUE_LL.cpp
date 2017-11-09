#include <bits/stdc++.h>

using namespace std;

class Node{
	int val;
	Node *next;

public:
	Node(){

	}
	void set_value(int value){
		val = value;
	}

	void set_next(Node *temp){
		next = temp;
	}

	int get_value(){
		return val;
	}

	Node* get_next(){
		return next;
	}
};

class QUEUE_LL{
private:
	Node *head,*last;
	int sz;

public:
	QUEUE_LL(){
		head = NULL;
		last = NULL;
		sz = 0;
	}

	void push(int val){
		Node* temp = new Node();
		sz++;
		temp->set_value(val);
		temp->set_next(NULL);
		if(!last){
			head = temp;
			last = temp;
			return;
		}
		last->set_next(temp);
		last = temp;
	}

	int pop(){
		if(!head){
			cout<<"Queue is empty..."<<endl;
			return -1;
		}
		sz--;
		int temp = head->get_value();
		head = head->get_next();
		return temp;
	}

	bool empty(){
		if(sz == 0)
			return true;
		return false;
	}

	int size(){
		return sz;
	}

	int top(){
		if(!head){
			cout<<"Queue is empty..."<<endl;
			return -1;
		}
		return head->get_value();
	}

};

int main(){

	QUEUE_LL s;
	int t;
	cout<<"Enter the no. of queries: ";
	cin>>t;

	cout<<"\n\tPush: 1 val\n\tPop: 2\n\tIsEmpty: 3\n\tSize: 4\n\tTop: 5"<<endl;
	int type,val;
	while(t--){
		cin>>type;
		switch(type){
			case 1:
				cin>>val;
				s.push(val);
				cout<<"Pushed"<<endl;
				cout<<"Current Top: "<<s.top()<<endl;
				break;
			case 2:
				s.pop();
				cout<<"Popped"<<endl;
				cout<<"Current Top: "<<s.top()<<endl;
				break;
			case 3:
				if(s.empty())
					cout<<"Queue is Empty"<<endl;
				else
					cout<<"Queue is not Empty"<<endl;
				break;
			case 4:
				cout<<"Queue size is: "<<s.size()<<endl;
				break;
			case 5:
				cout<<"Current top element: "<<s.top()<<endl;
				break;
		}
		 
	}
	return 0;
}