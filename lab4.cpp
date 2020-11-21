#include <iostream>

template < typename T >
class Para
{
public:
    Para() {}
    Para(T t1, T t2) : obiekt1{t1}, obiekt2{t2} {}
    T obiekt1;
    T obiekt2;
    T suma() { return obiekt1 + obiekt2; }
};

template < typename T, unsigned int N >
class TablicaPar
{
public:
    TablicaPar() {}
    Para< T >  tablica[N];
    TablicaPar operator[](int n) { return tablica[n]; }
};

int main()
{
    Para< double >          parka(1, 2);
    TablicaPar< double, 4 > tab;
    std::cout << "Rozmiar tablicy to " << sizeof(tab.tablica) << std::endl;

    puts("\nOstatnia linijka w kodzie!");
}