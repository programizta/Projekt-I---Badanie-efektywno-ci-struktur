#pragma once

class Table
{
    int n; // rozmiar tablicy dynamicznej
    int ind; // pomocnicza zmienna, dzięki której przechowamy sobie indeks do dalszych operacji na tablicy
    int *T; // utworzenie wskaźnika na obszar pamięci, w którym zaalokujemy naszą tablicę

public:

    Table(int m); // przeciążony konstruktor
    Table(); // konstruktor klasy Table
    ~Table(); // destruktor klasy Table
    void push_front(int x); // metoda dodająca element na początku tablicy
    void push_back(int x); // metoda dodająca element na końcu tablicy
    void pop_front(); // metoda usuwająca element na początku tablicy
    void pop_back(); // metoda usuwąjaca element na końcu tablicy
    void whereToPush(int index, int x); // metoda dodająca element we wskazanym miejscu przez użytkownika
    void whereToPop(int index); // metoda usuwajaca element we wskazany miejscu przez uzytkownika
    void display(); // metoda wyświetlająca tablicę
    void fill_table(int p, int q); // metoda pomocnicza* wypełniajaca liczbami tablicę
    void copy(); // metoda kopiująca zawartość jednej tablicy do drugiej
    bool search(int x); // metoda służaca do sprawdzenia czy podana liczba znajduje się w tablicy
};
