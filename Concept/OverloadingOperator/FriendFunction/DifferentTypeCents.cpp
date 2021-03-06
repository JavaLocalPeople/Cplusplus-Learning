#include <iostream>

class Cents 
{
private:
	int m_cents;
public:
	Cents(int cents) { m_cents = cents; }

	// add Cents and Cents using a friend function
	friend Cents operator+(const Cents &c1, int value);

	friend Cents operator+(int value, const Cents &c1);

	int getCents() const { return m_cents; }
};

// note: this function is not a member function!

Cents operator+(const Cents &c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + value);
}

Cents operator+(int value, const Cents &c1)
{
	return Cents(value + c1.m_cents);
}

int main()
{
	Cents c1 = Cents(4) + 6;
	Cents c2 = 6 + Cents(4);

	std::cout << "I have " << c1.getCents() << " cents." << std::endl;
	std::cout << "I have " << c2.getCents() << " cents." << std::endl;

	return 0;
}
