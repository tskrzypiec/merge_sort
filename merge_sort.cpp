
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

    using namespace std;

    const int N = 10; // Liczebność zbioru.

    int d[N]; //tabliba z posortowanymi liczbami
    int p[N]; //tablica pomocnicza, w której odkładamy scalane elementy dwóch zbiorów

// Procedura sortująca
//--------------------

    void MergeSort(int i_p, int i_k) //i_p czyli index pierwszego elementu zbioru sortowanego, i_k - index końcowego elementu zbioru
    {
        int i_s; //index pierwszego elementu ze zbioru liczb prawej połówki
        int i1; //index elementów lewego zbioru liczb tablicy d[]
        int i2; //index elementów prawego zbioru liczb tablicy d[]
        int i; //index elementów zbioru liczb tablicy p[]

        i_s = (i_p + i_k + 1) / 2; //
        if(i_s - i_p > 1) MergeSort(i_p, i_s - 1);
        if(i_k - i_s > 0) MergeSort(i_s, i_k);
        i1 = i_p; i2 = i_s;
        for(i = i_p; i <= i_k; i++)
            p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
        for(i = i_p; i <= i_k; i++) d[i] = p[i];
    }

// Program główny
//---------------

    int main()
    {
        int i;
        int liczba=0;

       // cout << "Przed sortowaniem:\n\n";

        for (int j =0; j<5; j++)

        {
            cout<< "wpisz" <<j+1<<"liczbe i nacisnij enter"<<endl;
            cin>>i;

        }

        d[i]=i;


       for(i = 0; i < 5; i++)
       {
           cout <<d[i] <<endl;
       }

// Sortujemy

        MergeSort(0,N-1); //indeks początkowy zbioru liczb do posortowania czyli "0" i końcowy czyli N-1 ( N czyli liczebność zbioru minus 1, bo indeksy liczymy od zera).


// Wyświetlamy wynik sortowania

        cout << "Po sortowaniu:\n\n";
        for(i = 0; i < N; i++) cout << setw(4) << d[i];
        cout << endl;
        return 0;
    }









