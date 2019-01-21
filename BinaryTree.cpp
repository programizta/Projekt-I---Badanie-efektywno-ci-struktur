#include <iostream>
#include <fstream>
#include <conio.h>
#include "BinaryTree.h"

using namespace std;

string cr,cl,cp;

BinaryTree::BinaryTree()
{
    int value; // wartość liczby z pliku tekstowego
    ifstream send; // strumień pobierający liczby z pliku tekstowego
    send.open("data.txt", ios::out);

    int powt;
    send >> powt; // wysyłamy liczbę powt strumieniem send
    n = 0;
    for(int i = 0; i < powt; i++)
    {
        send >> value;
        push(value); // dodajemy do kopca binarnego
    }
    send.close();
}

BinaryTree::~BinaryTree()
{
    delete [] root;
    root = NULL;
}

void BinaryTree::push(int x)
{
    if(!n) // jeśli w drzewie nie ma nic
    {
        root = new int [1];
        root[0] = x; // dodaję nowy element drzewa do korzenia
        n++; // inkrementacja liczby elementów drzewa
        return;
    }

    int *Temp; // tablica tymczasowa, pomocnicza
    Temp = new int [n+1]; // alokacja tablicy o jeden indeks większej od starej
    for (int i = 0; i < n; i++)
    {
        Temp[i] = root[i]; // przekopiowanie zawartości starego kopca do nowego
    }
    delete [] root; // usuwanie starego kopca
    root = Temp; // zamiana nazw

    int child = n;
    int parent = (child - 1)/2;
    while(root[parent] < x && child > 0) // dokonujemy naprawiania struktury kopca jeśli nie jest on spełniony w momencie dodania nowego elementu
    {
        root[child] = root[parent];
        child = parent;
        parent = (child - 1)/2;
    }
    root[child] = x;
    n++; // inkrementuję liczbę elementów kopca
}

void BinaryTree::throwRoot()
{
    if(!n) // warunek konieczny, który musi zostać spełniony, w przeciwnym wypadku wykroczymy poza zakres pamięci
    {
        cout << "Drzewo nie posiada zadnych elementow!\n";
        cout << "Kliknij dowolny przycisk, aby wrocic do menu...";
        getch();
        return;
    }
    n--; // dekrementacja liczby elementów podczas usuwania
    int Temp = root[n]; //wartość nogi przesuwanej do korzenia
    int next = 1, current = 0; // zaznaczony górny i jego kolejny element
    while (next < n)
    {
        if( next+1 < n && root[next+1] > root[next]) next++; // wybieramy wiekszą nogę
        if(Temp >= root[next]) // już nie musimy schodzić niżej, gdy węzeł jest większy od potomków
        {
            break;
        }
        root[current] = root[next]; // nowa wartość wezła jest brana z wartości większego potomka
        current = next; // poziom niżej
        next = 2*next + 1; // poziom niżej
    }
    root[current] = Temp;
    int *Temp2;
    Temp2 = new int [n];
    for (int i = 0; i < n; i++)
    {
        Temp2[i] = root[i];
    }
    delete [] root;
    root = Temp2;
    return;
}

bool BinaryTree::search(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == *(root + i)) return true;
    }
    return false;
}

void BinaryTree::display(string sp, string sn, int v)
{
    string s;
    cr = cl = cp = "  ";
    cr[0] = 218;
    cr[1] = 196;
    cl[0] = 192;
    cl[1] = 196;
    cp[0] = 179;

    if(v < n)
    {
        s = sp;
        if(sn == cr) s[s.length() - 2] = ' ';
        display(s + cp, cr, 2 * v + 2);

        s = s.substr(0,sp.length() - 2);

        cout << s << sn << root[v] << endl;

        s = sp;
        if(sn == cl) s[s.length()-2] = ' ';
        display(s + cp, cl, 2 * v + 1);
    }
}

void BinaryTree::popFirstMet(int x)
{
    n--;
    int ind = 0;
    for(int i = 0; i < n; i++)
    {
        if(root[i] == x) break;
        else ind++;
    }
    int Temp = root[n];
    int next = ind+1;
    while(next < n)
    {
        if(next+1 < n && root[next+1] > root[next]) next++;
        if(Temp >= root[next]) break;
        root[ind] = root[next];
        ind = next;
        next = 2*next + 1;
    }
    root[ind] = Temp;
    int *Temp2;
    Temp2 = new int [n];
    for(int i = 0; i < n; i++)
    {
        Temp2[i] = root[i];
    }
    delete [] root;
    root = Temp2;
    return;
}
