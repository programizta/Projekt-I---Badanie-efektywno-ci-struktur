#include <iostream>
#include <windows.h>
#include <conio.h>
#include "BinaryTree.h"

using namespace std;

void manage_binary_tree(int n, int x)
{
    string further = "\nAby kontynuowac kliknij dowolny klawisz...";
    BinaryTree Tree;
    while(true)
    {
        system("CLS");
        cout << "Menu kopca binarnego:\n\n";
        cout << "1. Wyswietl caly kopiec\n";
        cout << "2. Dodaj element do kopca\n";
        cout << "3. Usun korzen drzewa\n";
        cout << "4. Usun wyszukany klucz\n";
        cout << "5. Wyszukaj klucz\n";
        cout << "6. Powrot do glownego menu\n";
        cout << "7. Koniec dzialania programu\n\n";
        cout << "Jaka opcje wybierasz? Wprowadz numer: ";
        cin.clear();
        cin.sync();
        cin >> n;

        switch(n)
        {
        case 1:
        {
            system("CLS");
            Tree.display("", "", 0);
            cout << further;
            getch();
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "Podaj liczbe, ktora chcialbys wstawic do kopca: ";
            cin >> x;
            Tree.push(x);
            cout << further;
            getch();
            break;
        }
        case 3:
        {
            Tree.throwRoot();
            cout << further;
            getch();
            break;
        }
        case 4:
        {
            int x;
            cout << "Jaka liczbe chcialbys usunac z kopca? Podaj jej wartosc: ";
            cin >> x;
            if(Tree.search(x))
            {
                Tree.popFirstMet(x);
                cout << further;
                getch();
                break;
            }
            else
            {
                cout << "Liczba " << x << " nie istnieje w kopcu, wracam do glownego menu...\n";
                cout << further;
                getch();
                break;
            }
        }
        case 5:
        {
            system("CLS");
            cout << "Jaka liczbe chcialbys wyszukac w kopcu? Podaj jej wartosc: ";
            cin >> x;
            if(!(Tree.search(x)))
            {
                cout << "Liczba " << x << " nie istnieje\n";
                cout << further;
                getch();
                break;
            }
            else
            {
                cout << "Liczba " << x << " znajduje sie przynajmniej raz w kopcu\n";
                cout << further;
                getch();
                break;
            }
            Tree.search(x);
            cout << further;
            getch();
            break;
        }
        case 6:
        {
            Tree.~BinaryTree();
            cout << "Kliknij dowolny przycisk, aby wrocic do glownego menu...";
            getch();
            return;
        }
        case 7:
        {
            Tree.~BinaryTree();
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
