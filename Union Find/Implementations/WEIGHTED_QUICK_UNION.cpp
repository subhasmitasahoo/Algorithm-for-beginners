//This is also called as Eager Approach to algorithm design
//Initialization: O(N)
//Union : O(lg N)
//Find : O(lg N)

#include <bits/stdc++.h>

using namespace std;

class WEIGHTED_QUICK_UNION{

private:
	vector<int> id;
	vector<int> size;
	int sz;

public:
	WEIGHTED_QUICK_UNION(int n)
	{
		for(int i=0;i<n;i++){
			id.push_back(i);
			size.push_back(1);
		}
		sz = n;
	}

	int root(int p)
	{
		while(p != id[p])
			p = id[p];
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
		if(size[proot]<size[qroot])
		{
			id[proot] = qroot;
			size[qroot] += size[proot];
		}
		else
		{
			id[qroot] = proot;
			size[proot] += size[qroot];
		}
		
	}

};

int main()
{
	int n;
	cout<<"Enter the value of Object size: ";
	cin>>n;

	WEIGHTED_QUICK_UNION wqu = WEIGHTED_QUICK_UNION(n);

	cout<<"Enter the wqueries in the following format:"<<endl;
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
			wqu.unions(p,q);
			cout<<"united..."<<endl;
		}
		else if(tolower(type) == 'c'){
			if(wqu.connected(p,q))
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