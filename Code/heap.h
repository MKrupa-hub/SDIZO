#include <iostream>

class Heap {
public:

    //tablica w której jest przechowywany kopiec
    int *table;

    //rozmiar tablicy
    int size;

    //konstruktor
    Heap();

    //destruktor
    ~Heap();

    //dodaje wartosc do kopca
    void add(int data);

    //usuwa wartosc z kopca
    void sub();

    //wyszukuje element
    void search(int data);

    //wyswietla kopiec
    void display();

    //poprawia strukture kopca
    void fix();

    //wczytaj dane z pliku znajdujacego sie w tym samym folderze co plik exe
    void loaddata();

    //sprawdza wielkosc tablicy
    void checksize();
};

