#include <iostream>
#include <string>
using namespace std;

class Handler
{
protected:
	Handler* successor;
	string name;
	double creditScore;
	double income;
	double debt;
	int age;
public:
	virtual ~Handler() = default;
	void setSuccessor(Handler* successor)
	{
		this->successor = successor;
	}
	virtual void handleRequest(string n, double cs, double in, double d, int a) = 0;
};
class AgeHandler : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a)
	{
		if (a < 18)
		{
			cout << "Refusal! Age < 18" << endl;
		}
		else
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};
class CreditScoreHandler : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a)
	{
		if (cs < 18)
		{
			cout << "Refusal! Credit score < 500" << endl;
		}
		else
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};
class CreditDebt : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a)
	{
		if (in > in * 0.5)
		{
			cout << "Refusal! Debt > " << in * 0.5 << endl;
		}
		else
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};

int main()
{

	return 0;
}