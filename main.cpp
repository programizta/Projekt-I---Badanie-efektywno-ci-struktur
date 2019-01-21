#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sys/stat.h>
#include "functions.hpp"

using namespace std;

bool ifExists(const char *filename)
{
    struct stat buffer;
    if(stat(filename, &buffer)) return false;
    return true;
}

void program(int choice)
{
    cout << "Czy przed uruchomieniem programu zarzadzajacymi strukturami\n";
    cout << "danych chcialbys uruchomic program do wygenerowania liczb\n";
    cout << "do pliku tekstowego?\n\n";
    cout << "1. Tak\n2. Nie, dane juz zostaly wygenerowane\n\n";
    cout << "Ktora opcje wybierasz? Wprowadz numer: ";
    cin >> choice;

    if(choice == 1)
    {
        system("CLS");
        generator(0, 0, 0, 0);
    }

    while(true)
    {
        system("CLS");
        cout << "Program zarzadzajacy strukturami danych\n\n";
        cout << "Mozliwe struktury do wyboru:\n";
        cout << "1. Tablica\n2. Lista\n3. Kopiec binarny\n4. Koniec dzialania programu\n";
        cout << "Na ktorej strukturze chcialbys przeprowadzac operacje? Podaj numer: ";
        cin.clear();
        cin.sync();
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            if(!(ifExists("data.txt")))
            {
                cout << "\nNie odnaleziono pliku z niezbednymi danymi do wczytania! Uruchomie generator liczb\n";
                cout << "Aby kontynuowac kliknij dowolny klawisz...";
                getch();
                generator(0, 0, 0, 0);
            }
            manage_board(0, 0);
            break;
        }
        case 2:
        {
            if(!(ifExists("data.txt")))
            {
                cout << "\nNie odnaleziono pliku z niezbednymi danymi do wczytania! Uruchomie generator liczb\n";
                cout << "Aby kontynuowac kliknij dowolny klawisz...";
                getch();
                generator(0, 0, 0, 0);
            }
            manage_list(0, 0);
            break;
        }
        case 3:
        {
            if(!(ifExists("data.txt")))
            {
                cout << "\nNie odnaleziono pliku z niezbednymi danymi do wczytania! Uruchomie generator liczb\n";
                cout << "Aby kontynuowac kliknij dowolny klawisz...";
                getch();
                generator(0, 0, 0, 0);
            }
            manage_binary_tree(0, 0);
            break;
        }
        case 4:
        {
            return;
        }
        default:
        {
            cout << "Nie ma takiej opcji!\n";
            cout << "Aby kontynuowac kliknij dowolny klawisz...";
            getch();
            break;
        }
        }
    }
}

int main()
{
    program(0);
    return 0;
}
