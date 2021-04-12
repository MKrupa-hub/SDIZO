#include <fstream>
#include "list.h"

using namespace std;
ifstream file2;

List::List() {

    List::head = nullptr;
    List::tail = nullptr;
    List::size = 0;
}

List::~List() {

}

void List::loaddata() {
    int tmp;
    file2.open("input.txt");
    if (file2.fail()) {
        cout << "Nie udalo wczytac sie danych" << endl;
        return;
    }
    while (file2.good()) {
        file2 >> tmp;
        List::pushback(tmp);
    }
    cout << "Danie zostaly wczytane" << endl;
    file2.close();
}

void List::checksize() {
    if (size == 0) {
        cout << "Lista jest pusta !!!" << endl;
        return;
    }
}

void List::pushfront(int data) {
    ListElement *p = new ListElement();
    if (head == NULL) {
        p->data = data;
        head = p;
        tail = head;
        size++;
    } else {
        p->prev = nullptr;
        p->data = data;
        p->next = head;
        head->prev = p;
        head = p;
        size++;
    }

}


void List::pushback(int data) {
    ListElement *p = new ListElement();
    if (head == NULL) {
        p->data = data;
        head = p;
        tail = head;
        size++;
        return;
    } else {
        p->data = data;
        p->next = NULL;
        tail->next = p;
        p->prev = tail;
        tail = p;
        size++;
    }
}

void List::insert(int data, int index) {
    ListElement *p;
    p = head;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
    }
    ListElement *ptemp1 = new ListElement();
    ListElement *ptemp2 = new ListElement();
    ptemp1->prev = p;
    ptemp1->data = data;
    ptemp2 = p;
    if (index != size) {
        p = p->next;
        p->prev = ptemp1;
        ptemp1->next = p;
    }
    ptemp2->next = ptemp1;
    size++;
}

void List::popback() {
    if (size == 0) {
        List::checksize();
        return;
    } else if (size == 1) {
        head = NULL;
        tail = NULL;
        size--;
        return;
    } else {
        tail = tail->prev;
        tail->next = NULL;
        size--;
    }
}

void List::popfront() {
    if (size == 0) {
        List::checksize();
        return;
    } else if (size == 1) {
        head = NULL;
        tail = NULL;
        size--;
        return;
    } else {
        head = head->next;
        head->prev = NULL;
        size--;
    }
}

void List::pop(int index) {
    if (size == 0) {
        List::checksize();
        return;
    } else if (index == 1) {
        popfront();
        return;
    } else if (index == size) {
        popback();
        return;
    }
    ListElement *p = head;
    ListElement *ptemp1 = head;
    for (int i = 0; i < index - 2; i++) {
        p = p->next;
        ptemp1 = ptemp1->next;
    }
    ptemp1 = ptemp1->next;
    ptemp1 = ptemp1->next;
    ptemp1->prev = p;
    p->next = ptemp1;
    size--;
}

void List::display() {

    ListElement *p;
    p = head;

    while (p != nullptr) {
        cout << " [" << p->data << "]";
        p = p->next;
    }
    cout << endl;

}

void List::search(int data) {
    ListElement *p;
    p = head;
    int i = 0;
    while (p != nullptr) {
        if (p->data == data) {
            cout << "      [" << p->data << "]" << endl;
            cout << "Znajduje sie na pozycji o indeksie " << i + 1 << endl;
            return;
        }
        p = p->next;
        i++;
    }
    cout << "Nie ma takiego elementu" << endl;

}

