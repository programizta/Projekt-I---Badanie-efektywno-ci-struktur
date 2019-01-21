#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Table.h"

using namespace std;

void manage_board(int n, int x)
{
    string further = "\nAby kontynuowac kliknij dowolny klawisz...";
    Table T;
    system("CLS");
    while(true)
    {
        system("CLS");
        cout << "Menu tablicy:\n\n";
        cout << "1. Wyswietl cala tablice\n";
        cout << "2. Dodaj element na poczatku tablicy\n";
        cout << "3. Dodaj element na koncu tablicy\n";
        cout << "4. Dodaj element w wybranym miejscu\n";
        cout << "5. Usun element w wybranym miejscu\n";
        cout << "6. Usun element na poczatku tablicy\n";
        cout << "7. Usun element na koncu tablicy\n";
        cout << "8. Wyszukaj liczbe\n";
        cout << "9. Powrot do glownego menu\n";
        cout << "10. Koniec dzialania programu\n\n";
        cout << "Jaka opcje wybierasz? Wprowadz numer: ";
        cin.clear();
        cin.sync();
        cin >> n;

        switch(n)
        {
        case 1:
        {
            T.display();
            cout << further;
            getch();
            break;
        }
        case 2:
        {
            cout << "Podaj liczbe, ktora chcesz wstawic na poczatku tablicy: ";
            cin >> x;
            T.push_front(x);
            cout << further;
            getch();
            break;
        }
        case 3:
        {
            cout << "Podaj liczbe, ktora chcesz wstawic na koncu tablicy: ";
            cin >> x;
            T.push_back(x);
            cout << further;
            getch();
            break;
        }
        case 4:
        {
            int index;
            cout << "Jaka liczbe chcialbys wstawic? Podaj jej wartosc: ";
            cin >> x;
            cout << "Na ktorym indeksie tablicy wsunac liczbe " << x << "? Wprowadz indeks: ";
            cin >> index;
            T.whereToPush(index, x);
            cout << further;
            getch();
            break;
        }
        case 5:
        {
            T.whereToPop(0);
            cout << further;
            getch();
            break;
        }
        case 6:
        {
            T.pop_front();
            cout << further;
            getch();
            break;
        }
        case 7:
        {
            T.pop_back();
            cout << further;
            getch();
            break;
        }
        case 8:
        {
            cout << "Podaj pozadana liczbe do wyszukania: ";
            cin >> x;
            if(!(T.search(x)))
            {
                cout << "Liczba " << x << " nie znajduje sie w tablicy\n";
                cout << further;
                getch();
                break;
            }
            else
            {
                cout << "Podana liczba istnieje w tablicy przynajmniej raz\n";
                cout << further;
                getch();
                break;
            }

        }
        case 9:
        {
            T.~Table();
            cout << "Kliknij dowolny przycisk, aby wrocic do glownego menu...";
            getch();
            return;
        }
        case 10:
        {
            T.~Table();
            cout << "Zakonczono dzialanie programu";
            exit(0);
        }
        default:
        {
            cout << "Nie ma takiej opcji!\n";
            cout << further;
            getch();
            break;
        }
        }
    }
}
