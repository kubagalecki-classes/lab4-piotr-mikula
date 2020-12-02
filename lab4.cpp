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
    Para< double >          p1{2, 3};
    Para< double >          p2{3, 5};
    Para< double >          p3{4, 10};
    TablicaPar< double, 3 > tab;
    TablicaPar< double, 0 > tab2;
    std::cout << "Rozmiar tablicy to " << sizeof(tab.tablica) << std::endl;

    tab[0] = p1;
    tab[1] = p2;
    tab[2] = p3;

    tab.print();

    double suma = p1.suma() + p2.suma() + p3.suma();
    std::cout << "Suma wszystkich par wynosi " << suma << std::endl;

    double tabelka[5] = {1, 4, 10, 5, 2.5};
    double il         = iloczyn(tabelka, 5);
    std::cout << "Iloczyn elementow tablicy ";
    for (int i = 0; i < 5; i++)
        std::cout << tabelka[i] << " ";
    std::cout << "wynosi " << il << std::endl;

    puts("\nOstatnia linijka w kodzie!");
}