#include <iostream>

class Something
{
private:
	int m_value1;
	double m_value2;
	char m_value3;

public:
	/*Something() : m_value1(1), m_value2(2.2), m_value3('c')
	{}*/

	Something(int value1, double value2, char value3 = 'c')
		: m_value1(value1), m_value2(value2), m_value3(value3)
	{}

	Something()
	{
		m_value1 = 1;
		m_value2 = 2.2;
		m_value3 = 'c';
	}

	void print()
	{
		std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
	}
};

int main()
{
	Something something(1, 2.2);
	something.print();
	return 0;
}
