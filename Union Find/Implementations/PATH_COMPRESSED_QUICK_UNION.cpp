//This is also called as Eager Approach to algorithm design
//Initialization: O(N)
//Union : O(N)
//Find : O(N)

#include <bits/stdc++.h>

using namespace std;

class QUICK_UNION{

private:
	vector<int> id;
	int sz;

public:
	QUICK_UNION(int n)
	{
		for(int i=0;i<n;i++){
			id.push_back(i);
		}
		sz = n;
	}

	int root(int p)
	{
		while(p != id[p]){
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;
	}

	bool connected(int p, int q){
		int proot = root(p);
		int qroot = root(q);

		if(proot == qroot){
			return true; 
		}
		return false;
	}

	void unions(int p, int q){
		int proot = root(p);
		int qroot = root(q);
		id[proot] = qroot;
	}

};

int main()
{
	int n;
	cout<<"Enter the value of Object size: ";
	cin>>n;

	QUICK_UNION qu = QUICK_UNION(n);

	cout<<"Enter the queries in the following format:"<<endl;
	cout<<"\t1. For union: U p q\n\t2. For find: C p q"<<endl;

	char type;
	int p,q;

	int t;
	cout<<"Enter the number of queries: ";
	cin>>t;

	while(t--)
	{
		cin>>type>>p>>q;

		if(tolower(type) == 'u'){
			qu.unions(p,q);
			cout<<"united..."<<endl;
		}
		else if(tolower(type) == 'c'){
			if(qu.connected(p,q))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			cout<<"INVALID..."<<endl;
		}
	}
	return 0;
}