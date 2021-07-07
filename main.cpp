#include <iostream>
#include<vector>
using namespace std;

class BitArray
{
public:

	BitArray()
	{};
	
	BitArray(int n)
	{
	     massiv.resize(n);
	};

	
	BitArray(const BitArray& a)
	{
		massiv = a.massiv;
	};

	
	~BitArray()
	{
		massiv.clear(); 
	};

	
	int size(void)
	{
		return massiv.size();
	};

	
	int operator [] (const unsigned int i) const
	{
		return massiv[i];
	};

	
	void setbit(int i, int v)
	{
		massiv[i] = v;
	};



	
	BitArray& operator = (const BitArray& a)
	{
		massiv = a.massiv;
		return *this;
	};

	BitArray operator &(const BitArray& a) const
	{
		int z = max(massiv.size(), a.massiv.size());
		BitArray div(z);
		z = min(massiv.size(), a.massiv.size());

		for (int i = 0; i < z; ++i)
		{
			div.massiv[i] = massiv[i] & a.massiv[i];
		}
		return div;
	};

	
	BitArray operator | (const BitArray& a) const
	{
		int z = max(massiv.size(), a.massiv.size());
		BitArray div(z);

		for (int i = 0; i < z; ++i)
		{
			if ((i < massiv.size()) && (i < a.massiv.size()))
			{
				div.massiv[i] = massiv[i] | a.massiv[i];
			}
			else
			{
				if (i > massiv.size())
				{
					div.massiv[i] = 0 | a.massiv[i];
				}
				else {
					div.massiv[i] = massiv[i] | 0;
				}
			}
		}
		return div;
	};

	
	BitArray operator ~ (void) const
	{
		BitArray invert(*this);

		for (int i = 0; i < invert.massiv.size(); i++)
		{
			if (massiv[i] == 0) invert.massiv[i] = 1;
			else
				invert.massiv[i] = 0;
		}

		return invert;
	};

	
	friend ostream& operator << (ostream& os, const BitArray& a)
	{
		for (int i = 0; i < a.massiv.size(); i++)
			os << a.massiv[i];
		return os;
	}

	
	bool operator == (const BitArray& a) const
	{
		return massiv == a.massiv;
	};

	bool operator != (const BitArray& a) const
	{
		return !(massiv == a.massiv);
	};

private:

	vector <int> massiv;
};
int main(void)
{
	BitArray a(50), b(80);
	for (int i = 0; i < 60; i++) b.setbit(i, 1);
	a = b;
	for (int i = 0; i < 80; i++) b.setbit(i, 0);
	cout << a << endl << b << endl;
	if (a == b) cout << "YES"; else cout << "NO"; cout << endl;
	if (a != b) cout << "NO"; else cout << "YES"; cout << endl;
	if (a == a) cout << "YES"; else cout << "NO"; cout << endl;
	if (a != a) cout << "NO"; else cout << "YES"; cout << endl;
	BitArray c = a & b;
	cout << c << endl;
	BitArray d(10); d.setbit(0, 1); d.setbit(3, 1);
	c = a | b;
	cout << c << endl;
	c = ~c;
	cout << c << endl;
	return 0;
}

