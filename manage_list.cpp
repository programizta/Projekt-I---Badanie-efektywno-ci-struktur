#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Doubly_Linked_List.h"

using namespace std;

void manage_list(int n, int x)
{
    string further = "\nAby kontynuowac kliknij dowolny klawisz...";
    Doubly_Linked_List list;

    while(true)
    {
        system("CLS");
        cout << "Menu listy:\n\n";
        cout << "1. Wyswietl cala liste\n";
        cout << "2. Dodaj element na poczatku listy\n";
        cout << "3. Dodaj element na koncu listy\n";
        cout << "4. Dodaj element za wybrana liczba\n";
        cout << "5. Usun pierwsza napotkana wartosc\n";
        cout << "6. Usun element na poczatku listy\n";
        cout << "7. Usun element na koncu listy\n";
        cout << "8. Powrot do glownego menu\n";
        cout << "9. Koniec dzialania programu\n\n";
        cout << "Jaka opcje wybierasz? Wprowadz numer: ";
        cin.clear();
        cin.sync();
        cin >> n;

        switch(n)
        {
        case 1:
        {

            list.display();
            cout << further;
            getch();
            break;
        }
        case 2:
        {
            cout << "Podaj liczbe, ktora chcialbys wstawic na poczatku listy: ";
            cin >> x;
            list.push_front(x);
            cout << further;
            getch();
            break;
        }
        case 3:
        {
            cout << "Podaj liczbe, ktora chcialbys wstawic na koncu listy: ";
            cin >> x;
            list.push_back(x);
            cout << further;
            getch();
            break;
        }
        case 4:
        {
            int which;
            cout << "Za jaka liczbe chcialbys wstawic nowa? Podaj ja: ";
            cin >> which;
            cout << "Jaka to ma byc liczba? Wprowadz jej wartosc: ";
            cin >> x;
            if(!(list.search(which)))
            {
                cout << "Liczba " << which << " nie znajduje sie na liscie, wiec nowa zostanie wprowadzona na poczatku listy.\n";
                list.push_front(x);
                cout << further;
                getch();
                break;
            }
            else
            {
                list.whereToPushAfter(which, x, list.head);
                cout << further;
                getch();
                break;
            }

        }
        case 5:
        {
            int which;
            cout << "Podaj wartosc liczby, ktora chcialbys usunac z listy: ";
            cin >> which;
            if(!(list.search(which)))
            {
                cout << "Liczba " << which << " nie istnieje w liscie, wracam do glownego menu.\n";
                cout << further;
                getch();
                break;
            }
            else
            {
                list.popFirstMet(which, list.head);
                cout << further;
                getch();
                break;
            }

        }
        case 6:
        {
            list.pop_front();
            cout << further;
            getch();
            break;
        }
        case 7:
        {
            list.pop_back();
            cout << further;
            getch();
            break;
        }
        case 8:
        {
            list.~Doubly_Linked_List();
            cout << "Kliknij dowolny przycisk, aby wrocic do glownego menu...";
            getch();
            return;
        }
        case 9:
        {
            list.~Doubly_Linked_List();
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
