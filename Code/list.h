#include<iostream>


class List {
public:

    class ListElement {
    public:
        //przechowywana wartosc
        int data;

        //wskaznik na nastepny element
        ListElement *next;

        //wskaznik na poprzedni element
        ListElement *prev;

    };
    //wskaznik na glowe
    ListElement *head;

    //wskaznik na ogon
    ListElement *tail;

    //rozmiar listy
    int size;

    //konstruktor
    List();

    //destruktor
    ~List();

    //sprawdza wielkosc tabeli
    void checksize();

    //dodaj element na poczatek
    void pushfront(int data);

    //dodaj element na koniec
    void pushback(int data);

    //dodaj element w dowolne miejsce
    void insert(int data, int index);

    //usun koncowy element
    void popback();

    //usun pierwszy element
    void popfront();

    //usun dowolny element
    void pop(int index);

    //wyswietl tablice
    void display();

    //wyszukaj element
    void search(int data);

    //wczytaj dane z pliku znajdujacego sie w tym samym folderze co plik exe
    void loaddata();

};


