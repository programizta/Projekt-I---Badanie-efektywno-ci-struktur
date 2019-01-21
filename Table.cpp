#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Table.h"

using namespace std;

Table::Table(int m)
{
    n = 0; // tablica ma zero elementów
}

Table::Table()
{
    ifstream send; // strumień wysyłający dane z pliku tekstowego
    send.open("data.txt", ios::out);
    send >> n;
    T = new int [n];

    for(int i = 0; i < n; i++)
    {
        send >> *(T + i);
    }
    send.close();
}

Table::~Table()
{
    delete [] T;
    T = NULL; //wskaźnik *T nie pokazuje już nigdzie w pamięci
}

void Table::push_front(int x)
{
    int *Temp = new int [n+1];

    *Temp = x;
    for(int i = 1; i < n+1; i++)
    {
        *(Temp + i) = *(T + i - 1);
    }

    delete [] T;
    T = Temp;
    n++; // dokonujemy inkrementacji liczby elementów nowej tablicy
}

void Table::push_back(int x)
{
    int *Temp = new int [n+1];

    for(int i = 0; i <= n; i++)
    {
        *(Temp + i) = *(T + i);
    }
    *(Temp + n) = x;

    delete [] T;
    T = Temp;
    n++; // dokonujemy inkrementacji liczby elementów nowej tablicy
}

void Table::pop_front()
{
    if(n)
    {
        n--;
        ind = 0;
        copy();
    }
    else cout << "Tablica nie zawiera juz zadnych elementow!\n";
}

void Table::pop_back()
{
    if(n)
    {
        n--;
        ind = n+1;
        copy();
    }
    else cout << "Tablica nie zawiera juz zadnych elementow!\n";

}

void Table::whereToPush(int index, int x)
{
    int *Temp = new int [n+1];

    for(int i = 0; i < index-1; i++)
    {
        *(Temp + i) = *(T + i);
    }

    *(Temp + index - 1) = x; // wstawiamy podaną liczbę na wskazane miejsce w tablicy

    for(int i = index; i <= n; i++)
    {
        *(Temp + i) = *(T + i - 1);
    }

    delete [] T;
    T = Temp;
    n++; // dokonujemy inkrementacji liczby elementów nowej tablicy
}

void Table::whereToPop(int index)
{
    if(n)
    {
        cout << "Podaj indeks liczby, ktora chcialbys usunac: ";
        do
        {
            cin >> index;
            if(index <= 0 || index > n) cerr << "Tablica nie posiada takiego numeru indeksu! Podaj liczbe jeszcze raz: ";
        }
        while(index <= 0 || index > n);
        n--;
        ind = index;
        copy();
    }
    else cout << "Tablica nie zawiera juz zadnych elementow!\n";

}

void Table::display()
{
    if(n)
    {
        cout << "Oto zawartosc tablicy:\n";
        for(int i = 0; i < n; i++)
        {
            cout << *(T + i) << " ";
        }
    }
    else cout << "Tablica jest pusta!\n";

}

void Table::fill_table(int p, int q)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        *(T + i) = p + rand()%(q-p+1);
    }
}

void Table::copy()
{
    int *Temp = new int [n];

    for(int i = 0; i < ind-1; i++)
    {
        *(Temp + i) = *(T + i);
    }
    for(int i = ind; i <= n; i++)
    {
        *(Temp + i - 1) = *(T + i);
    }

    delete [] T;
    T = Temp;
}

bool Table::search(int x)
{
    for(int i = 0; i < n; i++)
    {
        if(*(T + i) == x) return true;
    }
    return false;
}
