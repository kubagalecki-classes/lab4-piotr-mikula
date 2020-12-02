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
class TablicaPar< T, 0 >
{
public:
    TablicaPar() { puts("Tablica jest pusta"); }
};

template < typename T >
T iloczyn(T tab[], int n)
{
    T wynik = static_cast< T >(1);
    for (int i = 0; i < n; i++)
        wynik = wynik * tab[i];
    return wynik;
}

template < typename T >
T sumaPary(Para< T >& para)
{
    return para.suma();
}

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
    Para< int > para{7, 9};
    std::cout << sumaPary(para) << std::endl;

    puts("\nOstatnia linijka w kodzie!");
}