/*
Autor: Mateusz Krupa
Kurs: Struktury danych i złożoność obliczeniowa
Prowadzący: Zbigniew Buchalski
*/
#include <iostream>
#include <ctime>
#include "table.h"
#include "list.h"
#include "heap.h"

using namespace std;
Table table;
List list;
Heap head;

int main() {

    int temporary_data;
    int temporary_index;
    int choice;
    clock_t start, elapsed;

    do {

        cout << "+------------------------------------------+" << endl;
        cout << "  1. Tablica dynamiczna " << endl;
        cout << "  2. Lista dwukierunkowa " << endl;
        cout << "  3. Kopiec binarny " << endl;
        cout << "  4. Drzewo poszukiwan binarnych(BST) " << endl;
        cout << "  5. Drzewo czerwono-czarne " << endl;
        cout << "  6. Koniec programu " << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "Wybor: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj na poczatek " << endl;
                    cout << "  3. Dodaj na koniec  " << endl;
                    cout << "  4. Dodaj w dowolne miejsce " << endl;
                    cout << "  5. Usun poczatek " << endl;
                    cout << "  6. Usun koniec " << endl;
                    cout << "  7. Usun dowolne miejsce " << endl;
                    cout << "  8. Wyszukaj element " << endl;
                    cout << "  9. Wczytaj dane z pliku " << endl;
                    cout << "  10. Powrot" << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            start = clock();
                            table.display();
                            elapsed = clock() - start;
                            cout << "Czas [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            break;
                        case 2:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = clock();
                            table.pushfront(temporary_data);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 3:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = clock();
                            table.pushback(temporary_data);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 4:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            cout << "Podaj index miejsca na jaka dodac:";
                            cin >> temporary_index;
                            if (temporary_index > table.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << table.size << "(bez 0)" << endl;
                                break;
                            }
                            start = clock();
                            table.insert(temporary_data, temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 5:
                            start = clock();
                            table.popfront();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 6:
                            start = clock();
                            table.popback();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 7:
                            cout << "Podaj index pozycji jaka nalezy usunac:";
                            cin >> temporary_index;
                            if (temporary_index >= table.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << table.size << "(bez 0)" << endl;
                                break;
                            }
                            start = clock();
                            table.pop(temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 8:
                            cout << "Podaj wartosc szukana:";
                            cin >> temporary_index;
                            start = clock();
                            table.search(temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                        case 9:
                            start = clock();
                            table.loaddata();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            table.display();
                            break;
                    }
                } while (choice != 10);
                break;

            case 2:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj na poczatek " << endl;
                    cout << "  3. Dodaj na koniec  " << endl;
                    cout << "  4. Dodaj w dowolne miejsce " << endl;
                    cout << "  5. Usun poczatek " << endl;
                    cout << "  6. Usun koniec " << endl;
                    cout << "  7. Usun dowolne miejsce " << endl;
                    cout << "  8. Wyszukaj element " << endl;
                    cout << "  9. Wczytaj dane z pliku " << endl;
                    cout << "  10. Powrot " << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            start = clock();
                            list.display();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            break;
                        case 2:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = clock();
                            list.pushfront(temporary_data);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 3:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = clock();
                            list.pushback(temporary_data);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 4:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            cout << "Podaj index miejsca na jaka dodac:";
                            cin >> temporary_index;
                            if (temporary_index > list.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << list.size << "(bez 0)" << endl;
                                break;
                            }
                            start = clock();
                            list.insert(temporary_data, temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 5:
                            start = clock();
                            list.popfront();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 6:
                            start = clock();
                            list.popback();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 7: // usun
                            cout << "Podaj index pozycji jaka nalezy usunac:";
                            cin >> temporary_index;
                            if (temporary_index >= list.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << list.size << "(bez 0)" << endl;
                                break;
                            }
                            start = clock();
                            list.pop(temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 8: // wyszukaj
                            cout << "Podaj wartosc szukana:";
                            cin >> temporary_index;
                            start = clock();
                            list.search(temporary_index);
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                        case 9:
                            start = clock();
                            list.loaddata();
                            elapsed = clock() - start;
                            cout << "Time [ms] = " << (1000 * elapsed) / CLOCKS_PER_SEC << endl;
                            list.display();
                            break;
                    }
                } while (choice != 10);
                break;

            case 3:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj na poczatek " << endl;
                    cout << "  3. Dodaj na koniec  " << endl;
                    cout << "  4. Dodaj w dowolne miejsce " << endl;
                    cout << "  5. Usun poczatek " << endl;
                    cout << "  6. Usun koniec " << endl;
                    cout << "  7. Usun dowolne miejsce " << endl;
                    cout << "  8. Wyszukaj element " << endl;
                    cout << "  9. Powrot " << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                } while (choice != 4);
                break;

            case 4:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj na poczatek " << endl;
                    cout << "  3. Dodaj na koniec  " << endl;
                    cout << "  4. Dodaj w dowolne miejsce " << endl;
                    cout << "  5. Usun poczatek " << endl;
                    cout << "  6. Usun koniec " << endl;
                    cout << "  7. Usun dowolne miejsce " << endl;
                    cout << "  8. Wyszukaj element " << endl;
                    cout << "  9. Powrot " << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                } while (choice != 4);
                break;

            case 5:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj na poczatek " << endl;
                    cout << "  3. Dodaj na koniec  " << endl;
                    cout << "  4. Dodaj w dowolne miejsce " << endl;
                    cout << "  5. Usun poczatek " << endl;
                    cout << "  6. Usun koniec " << endl;
                    cout << "  7. Usun dowolne miejsce " << endl;
                    cout << "  8. Wyszukaj element " << endl;
                    cout << "  9. Powrot " << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                } while (choice != 4);
                break;
        }

    } while (choice != 6);

    return 0;
}
