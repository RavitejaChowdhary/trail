#include<iostream>
using namespace std;
#include<vector>
class student
{
	string name;
	int rollno;
	int marks;
	public:
	friend istream& operator>>(istream&, student&);
	friend ostream& operator<<(ostream&,student&);
	bool operator<(student&);
	bool operator>(student&);	
};
// values are passed by reference
void swap(int &a, int & b)
{
		int temp;
		temp = a;
		a = b;
		b = temp;
}
istream &operator >>(istream& in,student& s)
{
    cin.ignore();
    getline(in,s.name);
    in>>s.rollno>>s.marks;
}
ostream &operator <<(ostream& out ,student& s )
{
    out<<s.name<<endl<<s.rollno<<endl<<s.marks<<endl;
}
bool student::operator<(student&s)
{
   return(rollno<s.rollno); 
}
bool student::operator>(student&s)
{
    return(rollno>s.rollno);
}
void swap1(student &a,student &b)
{
    student temp;
		temp = a;
		a = b;
		b = temp;
}



// Vector is passed by reference

void bidirectional_selection_sort(vector<student>& elements)
{
	int n = elements.size(),i,j,min_i,max_i,k,p;
	student max,min;
		//Initialize min and max to first elements of unsorted array
	// Move i in forward and j in reverse direction
	for(int i=0,j=n-1;i<j;i++,j--)
	{
		//Initialize min and max to first elements in the same for loop
		min = elements[i];
		max = elements[i];
		//min index and max index to 0
		min_i = i;
		max_i = i;
		// Move k from index i to index j (inclusive)
		for(int k=i;k<=j;k++)
		{
			if(elements[k]>max)
			{
				max = elements[k];
				max_i=k;
		              
			}
			else if(elements[k]<min)
			{	
                min=elements[k];
				min_i = k;
			}

		}
		// swap element in the first position of unsorted array to minimum element 
		// and element in last position of unsorted array to maximum element
		swap(elements[i], elements[min_i]);
		swap(elements[j], elements[max_i]);		
	}	
}

int main()
{
	vector<student> elements;
	int i,n;
	student ele;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}
	bidirectional_selection_sort(elements);
	for(i=0;i<n;i++)
		cout<<elements[i];
}