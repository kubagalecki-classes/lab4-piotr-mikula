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
    Para< T >& operator[](int n) { return tablica[n]; }

    void print()
    {
        for (unsigned int i = 0; i < N; i++)
            std::cout << tablica[i].obiekt1 << "\t" << tablica[i].obiekt2 << std::endl;
    }
};

template < typename T >
struct S
{
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S< double >
{
    void print() { puts("Specjalizacja dla double"); }
};

int main()
{
    S< int >    S_int;
    S< double > S_double;

    S_int.print();
    S_double.print();
    puts("\nOstatnia linijka w kodzie!");
}