#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


ofstream fout("output.txt");

int n , S, v[10], x[10], c[100], gasit = false;

void Afis(int k, ostream & out)
{
	gasit = true;
	for(int i = 1 ; i <= k ; i ++)
		out << x[i] << " ";
	out << "
";
}

void back(int k, int sum)
{
	if(k <= n)
		for(int i = 1 ; i <= min((S - sum) / v[k], c[k]) && !gasit ; i ++)
		{
			x[k] = i;
			if(sum + x[k] * v[k] == S)
				Afis(k, cout);
			else
				back(k + 1 , sum + x[k] * v[k]);
		}
}

int main()
{
	cin >> n >> S;
	for(int i = 1 ; i <= n ; ++i)
		cin >> v[i];
	for(int i = 1 ; i <= n ; ++i)
		cin >> c[i];
    back(1, 0);
	return 0;
}

