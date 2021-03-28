/*
Autor: Mateusz Krupa
Kurs: Struktury danych i złożoność obliczeniowa
Prowadzący: Zbigniew Buchalski
*/
#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "table.h"
#include "list.h"
#include "heap.h"



using namespace std;
Table table;
List list;
Heap heap;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}
int main() {

    int temporary_data;
    int temporary_index;
    int choice;
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    do {

        cout << "+------------------------------------------+" << endl;
        cout << "  1. Tablica dynamiczna " << endl;
        cout << "  2. Lista dwukierunkowa " << endl;
        cout << "  3. Kopiec binarny " << endl;
        cout << "  4. Koniec programu " << endl;
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
                            start = read_QPC();
                            table.display();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;
                        case 2:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = read_QPC();
                            table.pushfront(temporary_data);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 3:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = read_QPC();
                            table.pushback(temporary_data);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
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
                            start = read_QPC();
                            table.insert(temporary_data, temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 5:
                            start = read_QPC();
                            table.popfront();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 6:
                            start = read_QPC();
                            table.popback();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 7:
                            cout << "Podaj index pozycji jaka nalezy usunac:";
                            cin >> temporary_index;
                            if (temporary_index >= table.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << table.size << "(bez 0)" << endl;
                                break;
                            }
                            start = read_QPC();
                            table.pop(temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 8:
                            cout << "Podaj wartosc szukana:";
                            cin >> temporary_index;
                            start = read_QPC();
                            table.search(temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            table.display();
                            break;
                        case 9:
                            start = read_QPC();
                            table.loaddata();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
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
                            start = read_QPC();
                            list.display();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;
                        case 2:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = read_QPC();
                            list.pushfront(temporary_data);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                        case 3:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = read_QPC();
                            list.pushback(temporary_data);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
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
                            start = read_QPC();
                            list.insert(temporary_data, temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                        case 5:
                            start = read_QPC();
                            list.popfront();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                        case 6:
                            start = read_QPC();
                            list.popback();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                        case 7:
                            cout << "Podaj index pozycji jaka nalezy usunac:";
                            cin >> temporary_index;
                            if (temporary_index >= list.size + 1 || temporary_index == 0) {
                                cout << "Dozwolone wartosci pozycji do " << list.size << "(bez 0)" << endl;
                                break;
                            }
                            start = read_QPC();
                            list.pop(temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                        case 8: // wyszukaj
                            cout << "Podaj wartosc szukana:";
                            cin >> temporary_index;
                            start = read_QPC();
                            list.search(temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;
                        case 9:
                            start = read_QPC();
                            list.loaddata();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            list.display();
                            break;
                    }
                } while (choice != 10);
                break;

            case 3:
                do {
                    cout << "+------------------------------------------+" << endl;
                    cout << "  1. Wyswietl " << endl;
                    cout << "  2. Dodaj  " << endl;
                    cout << "  3. Usun  " << endl;
                    cout << "  4. Wyszukaj " << endl;
                    cout << "  5. Wczytaj dane z pliku " << endl;
                    cout << "  6. Powrot " << endl;
                    cout << "+------------------------------------------+" << endl;
                    cout << "Wybor:";
                    cin >> choice;
                    switch (choice) {

                        case 1:
                            start = read_QPC();
                            heap.display();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;

                        case 2:
                            cout << "Podaj wartosc jaka nalezy dodac:";
                            cin >> temporary_data;
                            start = read_QPC();
                            heap.add(temporary_data);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            heap.display();
                            break;

                        case 3:
                            start = read_QPC();
                            heap.sub();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            heap.display();
                            break;

                        case 4:
                            cout << "Podaj wartosc szukana:";
                            cin >> temporary_index;
                            start = read_QPC();
                            heap.search(temporary_index);
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;

                        case 5:
                            start = read_QPC();
                            heap.loaddata();
                            elapsed = read_QPC() - start;
                            cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << endl;
                            break;
                    }
                } while (choice != 6);
                break;
        }

    } while (choice != 4);

    return 0;
}
