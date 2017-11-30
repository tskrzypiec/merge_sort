
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

    using namespace std;

    const int ile_liczb = 10; // liczba sortowanych liczb

    int tablica_glowna[ile_liczb]; //tabliba z posortowanymi liczbami
    int schowek[ile_liczb]; //tablica pomocnicza, w której odkładamy scalane elementy dwóch zbiorów


    void MergeSort(int i_poczatek, int i_koniec) //"i_poczatek" czyli indeks pierwszego elementu zbioru sortowanego, "i_koniec" - indeks końcowego elementu zbioru
    {
        int i_srodek; //indeks pierwszego elementu ze zbioru liczb prawej połówki
        int i_lewy; //indeks elementów lewego zbioru liczb tablica_glowna
        int i_prawy; //indeks elementów prawego zbioru liczb tablicy_glowna
        int i_schowek; //indeks elementów zbioru liczb tablicy schowek

        i_srodek = (i_poczatek + i_koniec + 1) / 2; // wyznaczanie indeksu "srodek", który dzieli zbiór na dwie połówki

        if(i_srodek - i_poczatek > 1)
        {
            MergeSort(i_poczatek, i_srodek - 1); // sprawdzamy czy lewa połówka zawiera więcej niż jeden element jak tak to rekurencyjnie sortujemy
        }
        if(i_koniec - i_srodek > 0) //sprawdzamy czy w prawej połówce jest chociaż jedna liczba
        {
            MergeSort(i_srodek, i_koniec); //sortujemy prawy podzbiór
        }

        i_lewy = i_poczatek; //przypisujemy indeks pierwszego elementu w lewym podzbiorze
        i_prawy = i_srodek; //przypisujemy indeks pierwszego elementu w prawym podzbiorze

        for(i_schowek = i_poczatek; i_schowek <= i_koniec; i_schowek++)
        {
            //Porównujemy ze sobą najmniejsze elementy scalanych zbiorów. Ponieważ zbiory te są już uporządkowane, to najmniejszymi elementami będą zawsze ich pierwsze elementy.

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

        for(i_schowek = i_poczatek; i_schowek <= i_koniec; i_schowek++) //zapisujemy "tablice_glowna" liczbami posortowanymi umieszczonymi w "schowek"
        {
            tablica_glowna[i_schowek] = schowek[i_schowek];
        }
    }


//int main()
//{
   /* int i;

    cout <<"Przed sortowaniem:\n\n";

    srand((unsigned)time(NULL));

    for(i = 0; i < ile_liczb; i++) tablica_glowna[i] = rand() % 100;
    for(i = 0; i < ile_liczb; i++) cout << setw(4) << tablica_glowna[i];
    cout << endl;

    MergeSort(0,ile_liczb-1);

    cout << "Po sortowaniu:\n\n";
    for(i = 0; i < ile_liczb; i++) cout << setw(4) << tablica_glowna[i];
    cout << endl;
    return 0;
}    */

    int main()
    {
        int i;
        int liczba=0;

        // cout << "Przed sortowaniem:\n\n";

        for (int j =0; j<5; j++)

        {
            cout<< "wpisz " << j+1 <<" liczbe i nacisnij enter"<<endl;
            cin>>liczba;

        }

        tablica_glowna[i]=liczba;


        for(i = 0; i < 5; i++)
        {
            cout <<tablica_glowna[i] <<endl;
        }

// Sortujemy

        MergeSort(0,ile_liczb-1); //indeks początkowy zbioru liczb do posortowania czyli "0" i końcowy czyli N-1 ( N czyli liczebność zbioru minus 1, bo indeksy liczymy od zera).


// Wyświetlamy wynik sortowania

        cout << "Po sortowaniu:\n\n";
        for(i = 0; i < ile_liczb; i++) cout << setw(4) << tablica_glowna[i];
        cout << endl;
        return 0;
    }









