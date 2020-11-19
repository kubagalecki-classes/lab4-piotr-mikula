#include <iostream>

template < typename T >
class Para
{
public:
    T obiekt1;
    T obiekt2;
    T suma() { return obiekt1 + obiekt2; }
};

template < typename T, unsigned int N >
class TablicaPar
{
public:
    Para< T > tablica[N];
};

int main()
{
    TablicaPar< double, 4 > tab;
    std::cout << "Rozmiar tablicy to " << sizeof(tab.tablica) << std::endl;

    puts("\nOstatnia linijka w kodzie!");
}