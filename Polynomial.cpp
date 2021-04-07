#include<iostream>
#include<string>
#include <assert.h>
#include <cassert>
using namespace std;

#ifndef pol
#define Pol
#include <string>
using namespace std;
class Polynomial
{
private:
	double* Coef;
	int Max_Dgree = 0;
public:
	Polynomial(int max_dgree);
	~Polynomial();
	bool AddPoly(double coef, int degree = 0);
	string To_string();
	string operator + (Polynomial& obj);
	double getCoef(int dgree);
	string operator * (Polynomial& obj);
	void zero();
	string RemoveZero(string str);
	double Cal(double num);

};


Polynomial::Polynomial(int max_dgree)
{
	Coef = new double[max_dgree + 1];
	Max_Dgree = max_dgree;
}
Polynomial::~Polynomial()
{
	delete[Max_Dgree] Coef;
}
bool Polynomial::AddPoly(double coef, int degree)
{
	Coef[degree] = coef;
	return true;

}
string Polynomial::To_string()
{
	string res = "";
	for (int i = Max_Dgree; i >= 0; i--)
	{
		if (Coef[i] != 0.0)
		{
			if (i != 0)
			{
				res += RemoveZero(std::to_string(Coef[i])) + "x^" + std::to_string(i) + "+";
			}
			else
			{
				res += RemoveZero(std::to_string(Coef[i]));
			}
		}
	}
	if (res != "")
	{
		string r = res.substr(res.length() - 1, 1);
		res = ((r == "+") ? res.substr(0, res.length() - 1) : res);
	}
	return res;
}
void Polynomial::zero()
{
	for (int i = 0; i <= this->Max_Dgree; i++)
	{
		this->AddPoly(0, i);
	}
}
string Polynomial::operator * (Polynomial& obj)
{
	Polynomial pol = Polynomial(obj.Max_Dgree + this->Max_Dgree);
	pol.zero();
	string plo = pol.To_string();
	for (int i = 0; i <= obj.Max_Dgree; i++)
	{
		for (int j = 0; j <= this->Max_Dgree; j++)
		{
			pol.Coef[i + j] += obj.Coef[i] * this->Coef[j];
			plo = pol.To_string();
		}
	}
	return pol.To_string();
}
string Polynomial::operator + (Polynomial& obj) {

	if (this->Max_Dgree >= obj.Max_Dgree)
	{
		Polynomial* res = new Polynomial(this->Max_Dgree);
		for (int i = 0; i <= this->Max_Dgree; i++)
		{
			if (i <= obj.Max_Dgree)
			{
				res->AddPoly(this->Coef[i] + obj.Coef[i], i);
			}
			else {
				res->AddPoly(this->Coef[i], i);
			}

		}
		string ans = res->To_string();
		delete res;
		return ans;
	}
	else
	{
		Polynomial* res = new Polynomial(obj.Max_Dgree);
		for (int i = 0; i <= obj.Max_Dgree; i++)
		{
			if (i <= this->Max_Dgree)
			{
				res->AddPoly(this->Coef[i] + obj.Coef[i], i);
			}
			else {
				res->AddPoly(obj.Coef[i], i);
			}

		}
		string ans = res->To_string();

		return ans;
	}
}
double Polynomial::getCoef(int dgree)
{
	return this->Coef[dgree];
}
string Polynomial::RemoveZero(string str)
{
	while ((str.find('.') != -1 && str[str.length() - 1] == '0') || str[str.length() - 1] == '.')
	{
		str.erase(str.length() - 1, 1);
	}
	return str;
}
double Polynomial::Cal(double num)
{
	double ans = 0;
	for (int i = 0; i <= Max_Dgree; i++)
	{
		ans += Coef[i] * pow(num, i);
	}
	return ans;
}

#endif 


bool Test();

int main()
{
	if (Test())
	{
		cout << "The test was Successfull" << endl << "Try it for yourself" << endl;
	}
		int dgree = 0;
		cout << "Enter frist Polynomial Dgree : ";
		cin >> dgree;
		Polynomial pol1(dgree);
		for (int i = dgree; i >= 0; i--)
		{
			double coef;
			cout << "Enter the Coefficient for Exponent (" << i << ") : ";
			cin >> coef;
			pol1.AddPoly(coef, i);
		}
		cout << pol1.To_string() << endl;
		cout << "Enter second Polynomial Dgree : ";
		cin >> dgree;
		Polynomial pol2(dgree);
		for (int i = dgree; i >= 0; i--)
		{
			double coef;
			cout << "Enter the Coefficient for Exponent (" << i << ") : ";
			cin >> coef;
			pol2.AddPoly(coef, i);
		}
		cout << pol2.To_string() << endl;
		cout << "sum = " << pol1 + pol2 << endl;
		cout << "mult = " << pol1 * pol2 << endl;
		cout << "Enter x for claculate pol1(x) : ";
		int x;
		cin >> x;
		cout << "pol1(" << x << ")" << pol1.Cal(x) << endl;
		cout << "Enter x for claculate pol2(y) : ";
		int y;
		cin >> y;
		cout << "pol1(" << y << ")" << pol2.Cal(y) << endl;

}

bool Test()
{

	string res1 = "5x^3+4x^2+5", res2 = "11x^2+6";
	int dgree1 = 3;
	Polynomial pol1(dgree1);
	// 5x^3+4x^2+5
	pol1.AddPoly(5, 3);
	pol1.AddPoly(4, 2);
	pol1.AddPoly(0, 1);
	pol1.AddPoly(5, 0);
	int dgree2 = 2;
	Polynomial pol2(dgree2);
	// 11x^2+6
	pol2.AddPoly(11, 2);
	pol2.AddPoly(0, 1);
	pol2.AddPoly(6, 0);
	double resd2 = 281.00000000000000;//281.00000000000000
	double resd1 = 176.00000000000000;//176.00000000000000
	string sum = "5x^3+15x^2+11";
	string mult = "55x^5+44x^4+30x^3+79x^2+30"; 


	assert(res1 == pol1.To_string());
	assert(resd1 == pol1.Cal(3));
	assert(res2 == pol2.To_string());
	assert(resd2 == pol2.Cal(5));
	assert(sum == pol1 + pol2);
	assert(mult == pol1 * pol2);
	return true;
}