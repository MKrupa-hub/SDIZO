class Table {
public:

    //wskaznik na pierwszy element tablicy
    int *head;

    //rozmiar tablicy
    int size;

    //konstruktor
    Table();

    //destruktor
    ~Table();

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


