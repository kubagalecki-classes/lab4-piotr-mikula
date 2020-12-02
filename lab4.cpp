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

int main()
{
    Para< double >          p1{2, 3};
    Para< double >          p2{3, 5};
    Para< double >          p3{4, 10};
    TablicaPar< double, 3 > tab;
    std::cout << "Rozmiar tablicy to " << sizeof(tab.tablica) << std::endl;

    tab[0] = p1;
    tab[1] = p2;
    tab[2] = p3;

    tab.print();

    double suma = p1.suma() + p2.suma() + p3.suma();
    std::cout << "Suma wszystkich par wynosi " << suma << std::endl;

    puts("\nOstatnia linijka w kodzie!");
}