#pragma once

using namespace std;

class BinaryTree
{
    int n; // ilość elementów drzewa binarnego
    int *root; // wskaźnik na korzeń drzewa

public:

    BinaryTree(); // konstruktor drzewa
    ~BinaryTree(); // destruktor drzewa
    void push(int x); // metoda dodająca element do drzewa
    void throwRoot(); // metoda usuwająca pierwszą napotkaną liczbę w drzewie, jeśli nie ma to nic nie robi
    void display(string sp, string sn, int v); // metoda wyświetlająca drzewo
    bool search(int x); // metoda sprawdzająca czy podana liczba znajduje się w kopcu
    void popFirstMet(int x);
};
