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
class DebtHandler : public Handler
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
	Handler* h1 = new AgeHandler();
	Handler* h2 = new CreditScoreHandler();
	Handler* h3 = new DebtHandler();
	Handler* h4 = new FinalHardler();

	h1->setSuccessor(h2);
	h2->setSuccessor(h3);
	h3->setSuccessor(h4);

	cout << "- CLIENT #1 -" << endl;
	h1->handleRequest("Masha", 333, 99999999, 67, 67);
	cout << endl;

	cout << "- CLIENT #2 -" << endl;
	h1->handleRequest("Angelina", 666, 99999999, 20, 67);

	delete h1;
	delete h2;
	delete h3;
	delete h4;
	return 0;
}