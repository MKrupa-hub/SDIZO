#include <iostream>

class Heap {
public:

    int *tablica;

    //rozmiar listy
    int size;

    //konstruktor
    Heap();

    //destruktor
    ~Heap();

    //dodaje wartosc do kopca
    void add(int);

    //usuwa wartosc z kopca
    void sub(int);

    //wyszukuje element
    void search(int);

    //wyswietla kopiec
    void display();

    //poprawia strukture kopca
    void fix();

    //wyswietla ilosc poziomow
    void layersnum();

    //wczytaj dane z pliku znajdujacego sie w tym samym folderze co plik exe
    void loaddata();

};

