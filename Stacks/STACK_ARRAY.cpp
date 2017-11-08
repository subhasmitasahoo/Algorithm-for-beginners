#include <bits/stdc++.h>

using namespace std;

class STACK_ARRAY{
private:
	int size;
	int arr[1000];

public:
	void push(int val){
		if(size == 1000){
			cout<<"Stack overflow..."<<endl;
			return;
		}
		arr[size] = val;
		size++;
	}

	int pop(){
		if(size == 0){
			cout<<"Stack is empty..."<<endl;
			return -1;
		}
		size--;
		return arr[size];
	}

	bool empty(){
		if(size == 0)
			return true;
		return false;
	}

	int top(){
		if(size == 0)
		{
			cout<<"Stack is empty..."<<endl;
			return -1;
		}
		return arr[size-1];
	}

	int get_size(){
		return size;
	}
};

int main(){

	STACK_ARRAY s;
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
					cout<<"Stack is Empty"<<endl;
				else
					cout<<"Stack is not Empty"<<endl;
				break;
			case 4:
				cout<<"Stack size is: "<<s.get_size()<<endl;
				break;
			case 5:
				cout<<"Current top element: "<<s.top()<<endl;
				break;
		}
		 
	}
	return 0;
}