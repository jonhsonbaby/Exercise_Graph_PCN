#include<iostream>
#include<fstream>
#include<list>

using namespace std;

class Graph
{
	private:
		bool check;
		int numPoint;
		int** arr;	
	public:
		Graph();
		void displayGraph();
		void makeNextList();
		void levelOfPoint_InDirect();
		void levelOfPoint_Direct();
		void levelOfPoint();
		void egdeOfPoint_InDirection();
		void egdeOfPoint_Direction();
		void egdeOfPoint();
};
Graph::Graph()
{
	ifstream fileInput("input.txt");
	char c;
	fileInput>>c;
	if(c=='+') this->check=true; else this->check= false;
//
	fileInput>>this->numPoint;
//	
	arr= new int*[numPoint];
	for(int i=0;i<numPoint;i++)
	{
		arr[i]= new int[numPoint];
	}	
//	Nhap du lieu vao matrix
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(!fileInput.eof())
				fileInput>>arr[i][j];
		}
	}
	fileInput.close();
}
void Graph::displayGraph()
{
	string type;
	if(check) type="co huong"; else type="vo huong";
	cout<<"Do thi "<<type<<" co "<<numPoint<<" dinh\nMa tran ke:\n"<<endl;	
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			cout<<this->arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Graph::makeNextList()
{
	list<int> a[numPoint];
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(arr[i][j]==1)
			{
				a[i].push_back(j);
			}
		}
	}
	cout<<"\nDanh sach ke: "<<endl;
	for(int i=0; i<numPoint; i++)
	{
		int j=0;
		cout<<char('a'+i)<<" : ";
		for(int x: a[i])
		{
			cout<<char('a'+x)<<" ";
			j++;
		}
		cout<<endl;
	}
}
void Graph::levelOfPoint_InDirect()
{
	int num=0;
	cout<<"\nDanh sach bac cua dinh :"<<endl;
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(arr[i][j]==1) num++;
		}
		cout<<"deg("<<char('a'+i)<<")= "<<num<<endl;
		num=0;
	}
}
void Graph::levelOfPoint_Direct()
{
	int sum1[numPoint];
	int sum2[numPoint];
	for(int i=0; i<numPoint; i++){sum2[i]=0;sum1[i]=0;}
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(arr[i][j]==1){sum1[i]++;sum2[j]++;}
		}
	}
	cout<<"\nDanh sach bac cua dinh :"<<endl;
	for(int i=0; i<numPoint; i++)
	{
		cout<<"deg("<<char('a'+i)<<")+ = "<<sum2[i]<<endl;
		cout<<"deg("<<char('a'+i)<<")- = "<<sum1[i]<<"\n"<<endl;
	}
}
void Graph::levelOfPoint()
{
	if(check==true)
		levelOfPoint_Direct();
	else
		levelOfPoint_InDirect();
}
void Graph::egdeOfPoint_InDirection()
{
	cout<<"\nDanh sach canh cua do thi vo huong: "<<endl;
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(arr[i][j]==1&&j>i)
				cout<<char('a'+i)<<" ---- "<<char('a'+j)<<endl;	
		}
	}
}
void Graph::egdeOfPoint_Direction()
{
	cout<<"\nDanh sach canh cua do thi co huong: "<<endl;
	for(int i=0; i<numPoint; i++)
	{
		for(int j=0; j<numPoint; j++)
		{
			if(arr[i][j]==1)
				cout<<char('a'+i)<<" ---> "<<char('a'+j)<<endl;	
		}
	}
}
void Graph::egdeOfPoint()
{
	if(check==true)
		egdeOfPoint_Direction();
	else
		egdeOfPoint_InDirection();
}
int main()
{
	Graph G;
	G.displayGraph();
	G.makeNextList();
	G.egdeOfPoint();
	G.levelOfPoint();
	return 0;
}
