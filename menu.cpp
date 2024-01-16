#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

void Dodaj(int *n, int *&p)
{
    int el;
    cout << "Podaj wartosc elementu do dodania: ";
    cin >> el;

    int *tmp = new int[*n + 1];

    for (int i = 0; i < *n; i++)
    {
        tmp[i] = p[i];
    }

    tmp[*n] = el;

    delete[] p;
    p = tmp;
    (*n)++;
    system("cls");
}

void Wstaw(int *n, int *&p)
{
    int x;
    do
    {
        cout << "Numer indeksu gdzie chcesz wstawic element: ";
        cin >> x;
    } while (x >= *n);

    int w;
    cout << "Podaj wartosc elementu do wstawienia: ";
    cin >> w;

    int *tmp = new int[*n + 1];

    for (int i = 0; i < x; i++)
    {
        tmp[i] = p[i];
    }

    tmp[x] = w;

    for (int i = x + 1; i < *n + 1; i++)
    {
        tmp[i] = p[i - 1];
    }

    delete[] p;
    p = tmp;
    (*n)++;
    system("cls");
}

void Usun(int *n, int *&p)
{
    int x;
    do
    {
        cout << "Numer indeksu, z ktorego chcesz usunac element (0-" << *n - 1 << "): ";
        cin >> x;
    } while (x < 0 || x >= *n);

    int *tmp = new int[*n - 1];

    for (int i = 0; i < x; i++)
    {
        tmp[i] = p[i];
    }

    for (int i = x; i < *n - 1; i++)
    {
        tmp[i] = p[i + 1];
    }

    delete[] p;
    p = tmp;
    (*n)--;
    system("cls");
}

void Wyswietl(int *n, int *&p)
{
    if (*n == 0)
    {
        cout << "Tablica jest pusta." << endl;
    }
    else
    {
        cout << "Tablica: [";
        for (int i = 0; i < *n - 1; i++)
        {
            cout << p[i] << ",";
        }
        cout << p[*n - 1] << "]" << endl;
    }
    system("pause");
}

void Zapisz(int *n, int *&p)
{
    fstream plik("tablica.txt");

    if (plik.is_open())
    {
        plik << *n << " ";
        for (int i = 0; i < *n; i++)
        {
            plik << p[i] << " ";
        }
        plik.close();
        cout << "Zawartosc tablicy zostala zapisana do pliku 'tablica.txt'." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku do zapisu." << endl;
        system("pause");
    }
}

void Wczytaj(int *n, int *&p)
{
    fstream plik("tablica.txt");

    if (plik.is_open())
    {
        plik >> *n;

        delete[] p;
        p = new int[*n];

        for (int i = 0; i < *n; i++)
        {
            plik >> p[i];
        }

        plik.close();
        cout << "Zawartosc tablicy zostala wczytana." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku do wczytania." << endl;
        system("pause");
    }
}


int menu()
{
    int opcja;
    system("cls");
    cout << "Menu" << endl;
    cout << "-------------------------" << endl;
    cout << " [1] Dodaj element" << endl;
    cout << " [2] Wstaw element" << endl;
    cout << " [3] Usun element" << endl;
    cout << " [4] Wyswietl tablice" << endl;
    cout << " [5] Zapisz plik" << endl;
    cout << " [6] Wczytywanie pliku" << endl;
    cout << " [0] Wyjdz z programu" << endl;
    cout << "-------------------------" << endl;
    cout << "Wybierz opcje: ";

    cin >> opcja;

    return opcja;
}


int main()
{
    int *p = NULL;
    int n = 0;

    while (true)
    {
        switch (menu())
        {
            case 1:
                Dodaj(&n, p);
                break;
            case 2:
                Wstaw(&n, p);
                break;
            case 3:
                Usun(&n, p);
                break;
            case 4:
                Wyswietl(&n, p);
                break;
            case 5:
                Zapisz(&n, p);
                break;
            case 6:
                Wczytaj(&n, p);
                break;
            case 0:
                delete[] p;
                return 0;
            default:
                cout << "Wprowadz poprawna liczbe!" << endl;
                system("pause");
        }
    }

    return 0;
}
