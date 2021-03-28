#include <iostream>
#include <fstream>
#include "table.h"

using namespace std;
ifstream file1;

Table::Table() {

    Table::head = NULL;
    Table::size = 0;
}

Table::~Table() {
}

void Table::loaddata() {
    int tmp;
    file1.open("file.txt");
    if (file1.fail()) {
        cout << "Nie udalo wczytac sie danych" << endl;
        return;
    }
    while (file1.good()) {
        file1 >> tmp;
        Table::pushback(tmp);
    }
    cout << "Danie zostaly wczytane" << endl;
    file1.close();
}

void Table::checksize() {
    if (size == 0) {
        cout << "Tablica jest pusta !!!" << endl;
        return;
    }
}


void Table::pushback(int data) {
    int *p = new int[size + 1];
    for (int i = 0; i < size; i++) {
        p[i] = head[i];
    }
    p[size] = data;
    head = p;
    size++;
}

void Table::insert(int data, int index) {
    Table::checksize();
    int *p = new int[size + 1];
    for (int i = 0; i < index - 1; i++) {

        p[i] = head[i];
    }
    p[index - 1] = data;
    size++;
    for (int i = index; i < size; i++) {

        p[i] = head[i - 1];
    }
    head = p;
}

void Table::popback() {
    Table::checksize();
    if (size == 0) {
        return;
    }
    int *p = new int[size - 1];
    size--;
    for (int i = 0; i < size; i++) {

        p[i] = head[i];
    }
    head = p;
}

void Table::popfront() {
    Table::checksize();
    if (size == 0) {
        return;
    }
    int *p = new int[size - 1];
    size--;
    for (int i = 0; i < size; i++) {

        p[i] = head[i + 1];
    }
    head = p;
}

void Table::pop(int index) {
    Table::checksize();
    int *p = new int[size - 1];
    for (int i = 0; i < index - 1; i++) {

        p[i] = head[i];
    }
    size--;
    for (int i = index; i <= size; i++) {

        p[i - 1] = head[i];
    }
    head = p;
}

void Table::display() {

    if (head != NULL) {
        for (int i = 0; i < size; i++) {
            cout << " [" << head[i] << "]";

        }
        cout << endl;
    }

}

void Table::search(int data) {
    Table::checksize();
    if (head != NULL) {
        for (int i = 0; i < size; i++) {
            if (head[i] == data) {
                cout << "      [" << head[i] << "]" << endl;
                cout << "Znajduje sie na pozycji o indeksie " << i + 1 << endl;
                return;
            }

        }
        cout << "Nie ma takiego elementu" << endl;
    }

}


void Table::pushfront(int data) {
    int *p = new int[size + 1];
    p[0] = data;
    for (int i = 0; i < size; i++) {
        p[i + 1] = head[i];
    }
    head = p;
    size++;
}