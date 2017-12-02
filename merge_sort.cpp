
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

    using namespace std;

    const int ile_liczb = 5; // liczba sortowanych liczb

    int tablica_glowna[ile_liczb]; // tabliba z posortowanymi liczbami
    int schowek[ile_liczb]; // tablica pomocnicza, w której odkładamy scalane elementy dwóch zbiorów


    void MergeSort(int i_poczatek, int i_koniec) // "i_poczatek" - indeks pierwszego elementu zbioru sortowanego, "i_koniec" - indeks końcowego elementu zbioru
    {
        int i_srodek; // indeks pierwszego elementu ze zbioru liczb prawej połówki
        int i_lewy; // indeks elementów lewego zbioru liczb tablica_glowna
        int i_prawy; // indeks elementów prawego zbioru liczb tablicy_glowna
        int i_schowek; // indeks elementów zbioru liczb tablicy schowek

        i_srodek = (i_poczatek + i_koniec + 1) / 2; // wyznaczanie indeksu "srodek", który dzieli zbiór na dwie połówki

        if(i_srodek - i_poczatek > 1)
        {
            MergeSort(i_poczatek, i_srodek - 1); // sprawdzamy czy lewa połówka zawiera więcej niż jeden element jak tak to rekurencyjnie sortujemy
        }
        if(i_koniec - i_srodek > 0) // sprawdzamy czy w prawej połówce jest chociaż jedna liczba
        {
            MergeSort(i_srodek, i_koniec); // sortujemy prawy podzbiór
        }

        i_lewy = i_poczatek; // przypisujemy indeks pierwszego elementu w lewym podzbiorze
        i_prawy = i_srodek; // przypisujemy indeks pierwszego elementu w prawym podzbiorze

        for(i_schowek = i_poczatek; i_schowek <= i_koniec; i_schowek++)// porównujemy ze sobą najmniejsze czyli pierwsze elementy uporządkowanych scalanych zbiorów
        {
            // dopóki żaden z podzbiorów lewy i prawy nie jest wyczerpany, porównujemy kolejne elementy z tych podzbiorów wg indeksów i_lewy i i_prawy
            if (((i_lewy == i_srodek) || ((i_prawy <= i_koniec) && (tablica_glowna[i_lewy] > tablica_glowna[i_prawy]))))
            {

                schowek[i_schowek] = tablica_glowna[i_prawy++];
            }
            else
            {
                schowek[i_schowek] = tablica_glowna[i_lewy++];
            }

        }

        for(i_schowek = i_poczatek; i_schowek <= i_koniec; i_schowek++) // zapisujemy "tablice_glowna" liczbami posortowanymi ze "schowek"
        {
            tablica_glowna[i_schowek] = schowek[i_schowek];
        }
    }

int main()
{
    int i;

    cout <<"Przed sortowaniem:\n\n";

    srand((unsigned)time(NULL));

    for(i = 0; i < ile_liczb; i++) tablica_glowna[i] = rand() % 100;
    for(i = 0; i < ile_liczb; i++) cout << setw(4) << tablica_glowna[i];
    cout << endl<<endl;

    MergeSort(0,ile_liczb-1);

    cout << "Po sortowaniu:\n\n";
    for(i = 0; i < ile_liczb; i++) cout << setw(4) << tablica_glowna[i];
    cout << endl;
    return 0;
}









