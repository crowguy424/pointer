#include <iostream>
using namespace std;
void GetData(double &, double &, double &, double &, double&, double&);
void CalcVOC(double&, double, double, double);
double CalcSTP(double, double, double);
double CalcMP(double, double);
void PrintMetPower(double, double, double, double, double, double, double);
const double c1 = 273, c2 = 0.179;
int main()
{
	double mass, at, cp, pre, post, vaf, voc;
	cout << "This program computes the metabolic power of mammals and reptiles.\n";
	GetData(mass, at, cp, pre, post, vaf);
	CalcVOC(voc, vaf, pre, post);
	PrintMetPower(mass, at, cp, pre, post, vaf, CalcMP(CalcSTP(voc, cp, at), mass));

}

void GetData(double&m, double&a, double&c, double&pr, double&po, double&v)
{
	cout << "Please input the mass of the animal : ";
	cin >> m;
	cout << "Please input the ambient temperature : ";
	cin >> a;
	cout << "Please input chamber pressure : ";
	cin >> c;
	cout << "Please input concentration of oxygen in ambient air(pre - animal) : ";
	cin >> pr;
	cout << "Please input concentration of oxygen in ambient air(post - animal) : ";
	cin >> po;
	cout << "Please input the rate of oxygen : ";
	cin >> v;
	cout << "\n\n";
	return;
}

void CalcVOC(double& vo, double va, double pr, double po)
{
	vo = va*(pr - po) / (1 - po);
}

double CalcSTP(double vo, double c, double a)
{
	return vo*(c / 760)*(c1 / (c1 + a));
}

double CalcMP(double stp, double m)
{
	return stp / (m*c2);
}

void PrintMetPower(double m, double a, double c, double pr, double po, double v, double mp)
{
	cout << "The mass of the animal is " << m << " grams.\nThe ambient temperature is " << a << " degrees.\nThe chamber pressure is " << c << " mmHG.\nThe concentration of ambient air(pre - animal) is " << pr << ".\nThe concentration of ambient air(post - animal) is " << po << ".\nThe rate of oxygen is : " << v << " mL/hr.\n\n\nThe metabolic power for this mammal or reptile is " << mp << ".\n";
	return;
}