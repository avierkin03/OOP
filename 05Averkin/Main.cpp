#include <iostream>
#include "TComplex.h"
#include "AComplex.h"
using namespace std;

int main()
{
	AComplex a(2, 4);
	AComplex a1(2, -2);
	AComplex a2(a);

	TComplex t(1.11, 1.57);
	TComplex t1(1.5, 3.14);
	TComplex t2(t1);

	cout<< "Testing '==' and '!=' for Algebraic Complex numbers:" << endl << endl;
	cout << boolalpha;
	cout << a << "==" << a1 << ": " << (a == a1) << endl;
	cout << a << "!=" << a1 << ": " << (a != a1) << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '+' and '-' for Algebraic Complex numbers:" << endl<<endl;
	double x = 4;
	cout << a << " + " << a1 << " = " << a + a1 << endl;
	cout << a << " + " << x << " = " << a + x << endl;
	cout << x << " + " << a << " = " << x + a << endl<<endl;

	cout << a << " - " << a1 << " = " << a - a1 << endl;
	cout << a << " - " << x << " = "  << a - x << endl;
	cout << x << " - " << a << " = " << x - a << endl;
	
	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '+=' and '-=' for Algebraic Complex numbers:" << endl<<endl;
	cout << a << "+=" << a1 << ": ";
	a += a1;
	cout << a << endl<<endl;

	cout << a << "+=" << x << ": ";
	a += x;
	cout << a << endl << endl;

	cout << x << "+=" << a << ": ";
	x += a;
	cout << a << endl << endl;

	cout << a << "-=" << a1 << ": ";
	a -= a1;
	cout << a << endl << endl;

	cout << a << "-=" << x << ": ";
	a -= x;
	cout << a << endl << endl;

	cout << x << "-=" << a << ": ";
	x -= a;
	cout << a << endl << endl;

	cout << "\n-----------------------------------------\n" << endl;
	cout << "Testing '*' and '/' for Algebraic Complex numbers(casting to the type of Trigonometric Complex Numbers):" << endl << endl;
	cout << a << " * " << a1 << " = " << a * a1 << endl;
	cout << a << " * " << x << " = " << a * x << endl;
	cout << x << " * " << a << " = " << x * a << endl << endl;

	cout << a << " / " << a1 << " = " << a / a1 << endl;
	cout << a << " / " << x << " = " << a / x << endl;
	cout << x << " / " << a << " = " << x / a << endl << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '==' and '!=' for Trigonometric Complex numbers:" << endl << endl;
	cout << t << "==" << t1 << ": " << (t == t1) << endl;
	cout << t << "!=" << t1 << ": " << (t != t1) << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '+' and '-' for Trigonometric Complex numbers(casting to the type of Algebraic Complex Numbers):" << endl<<endl;
	cout << t << " + " << t1 << " = " << t + t1 << endl;
	cout << t << " + " << x << " = " << t + x << endl;
	cout << x << " + " << t << " = " << x + t << endl<< endl;

	cout << t << " - " << t1 << " = " << t - t1 << endl;
	cout << t << " - " << x << " = " << t - x << endl;
	cout << x << " - " << t << " = " << x - t << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '*' and '/' for Trigonometric Complex numbers:" << endl << endl;
	cout << t << " * " << t1 << " = " << t * t1 << endl;
	cout << t << " * " << x << " = " << t * x << endl;
	cout << x << " * " << t << " = " << x * t << endl << endl;

	cout << t << " / " << t1 << " = " << t / t1 << endl;
	cout << t << " / " << x << " = " << t / x << endl;
	cout << x << " / " << t << " = " << x / t << endl << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '*=' and '/=' for Trigonometric Complex numbers:" << endl << endl;
	cout << t << " *= " << t1 << ": ";
	t *= t1;
	cout << t << endl << endl;

	cout << t << " / " << t1 << ": ";
	t /= t1;
	cout << t << endl << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing '*' and '/' for Trigonometric and Algebraic Complex numbers(casting to the type of Trigonometric Complex Numbers):" << endl << endl;
	cout << a << " * " << t << " = " << a * t << endl;
	cout << t << " * " << a << " = " << t * a << endl;

	cout << a << " / " << t << " = " << a / t << endl;
	cout << t << " / " << a << " = " << t / a << endl;

	cout << "\n-----------------------------------------\n" << endl;

	cout << "Testing 'pow' for Trigonometric Complex numbers:" << endl << endl;
	x = 1;
	cout << "pow(" << t << ", " << x << ") = " << pow(t, x) << endl;
	x = 2;
	cout << "pow(" << t << ", " << x << ") = " << pow(t, x) << endl;

	return 0;
}
