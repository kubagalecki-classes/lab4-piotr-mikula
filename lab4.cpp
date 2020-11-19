#include <iostream>

template < typename T >
class Para
{
public:
    T obiekt1;
    T obiekt2;
    T suma() { return obiekt1 + obiekt2; }
};

int main()
{
    Para< double > parka;
    parka.obiekt1 = 3.14;
    parka.obiekt2 = 2.11;
    std::cout << "Suma rowna jest " << parka.suma() << std::endl;

    puts("Ostatnia linijka w kodzie!");
}