#include <iostream>
#include <string>
using namespace std;

class Handler
{
protected:
	Handler* successor = nullptr;
public:
	virtual ~Handler() = default;
	void setSuccessor(Handler* successor)
	{
		this->successor = successor;
	}
	virtual void handleRequest(string n, double cs, double in, double d, int a)
	{
		if (successor)
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};
class AgeHandler : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a) override
	{
		if (a < 18)
		{
			cout << "Refusal for " << n << " : Age < 18" << endl;
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
	void handleRequest(string n, double cs, double in, double d, int a) override
	{
		if (cs < 500)
		{
			cout << "Refusal for " << n << " : Credit score < 500" << endl;
		}
		else
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};
class CreditDebtHandler : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a) override
	{
		if (d > in * 0.5)
		{
			cout << "Refusal for " << n << " : Debt > " << in * 0.5 << endl;
		}
		else
		{
			successor->handleRequest(n, cs, in, d, a);
		}
	}
};
class FinalHardler : public Handler
{
public:
	void handleRequest(string n, double cs, double in, double d, int a) override
	{
		cout << "Success! Load approved for " << n << "!" << endl;
	}
};

int main()
{

	return 0;
}