#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

void generator(int number, int n, int p, int q)
{
    srand(time(NULL));
    ofstream save("data.txt");

    system("CLS");
    cout << "Generator liczb pseudolosowych do pliku tekstowego\n\n";
    cout << "Jak duzo liczb chcialbys wygenerowac? ";
    do
    {
        cout << "Podaj liczbe liczb: ";
        cin >> n;
        if(n < 0) cout << "Liczba liczb nie moze byc ujemna! Podaj wartosc jeszcze raz\n";
    }
    while(n < 0);

    cout << "Z jakiego przedzialu [p, q] maja byc te liczby? Podaj graniczne wartosci p oraz q: ";
    cin >> p >> q;

    if(save.good())
    {
        save << n << endl;
        for(int i = 0; i < n; i++)
        {
            number = p + rand()%(q-p+1);
            save << number << endl;
        }
        cout << "Pomyslnie wygenerowano liczby do pliku!\n\n";
        save.close();
        cout << "Kliknij dowolny klawisz aby kontynuowac...";
        getch();
    }
}
