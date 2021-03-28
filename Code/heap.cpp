#include <fstream>
#include <iostream>
#include "heap.h"

using namespace std;
ifstream file3;


Heap::Heap() {
    Heap::table = NULL;
    Heap::size = 0;

}

Heap::~Heap() {
}


void Heap::add(int data) {
    int *p = new int[size + 1];
    for (int i = 0; i < size; i++) {
        p[i] = table[i];
    }
    p[size] = data;
    table = p;
    size++;
    Heap::fix();
}


void Heap::sub() {
    if (size == 0) {
        return;
    }
    int *p = new int[size - 1];
    size--;
    for (int i = 0; i < size; i++) {

        p[i] = table[i + 1];
    }
    table = p;
    Heap::fix();
}

void Heap::search(int data) {
    Heap::checksize();
    if (table != NULL) {
        for (int i = 0; i < size; i++) {
            if (table[i] == data) {
                cout << "      [" << table[i] << "]" << endl;
                cout << "Znajduje sie na pozycji o indeksie " << i + 1 << endl;
                return;
            }

        }
        cout << "Nie ma takiego elementu" << endl;
    }


}

void Heap::display() {
    Heap::checksize();
    if (table != NULL) {
        for (int i = 0; i < size; i++) {
            cout << " [" << table[i] << "] ";

        }
        cout << endl;
    }
}

void Heap::fix() {
    int p;
    if(size>1){
        for (int i = size-1; i > 0; i--) {
            if (table[i - 1] < table[i]) {
                p = table[i - 1];
                table[i - 1] = table[i];
                table[i] = p;
            }
        }
    }

}

void Heap::loaddata() {
    int tmp;
    file3.open("file.txt");
    if (file3.fail()) {
        cout << "Nie udalo wczytac sie danych" << endl;
        return;
    }
    while (file3.good()) {
        file3 >> tmp;
        Heap::add(tmp);
    }
    cout << "Danie zostaly wczytane" << endl;
    file3.close();
}

void Heap::checksize() {
    if (size == 0) {
        cout << "Tablica jest pusta !!!" << endl;
        return;
    }
}


