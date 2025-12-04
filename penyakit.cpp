// penyakit.cpp
#include "penyakit.h"

void createListPenyakit(ListPenyakit &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyPenyakit(ListPenyakit L) {
    return (L.first == nullptr && L.last == nullptr);
}

elmPenyakit* createElmPenyakit(dataPenyakit x) {
    elmPenyakit* p = new elmPenyakit;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

void insertFirstPenyakit(ListPenyakit &L, elmPenyakit* p) {
    if (isEmptyPenyakit(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastPenyakit(ListPenyakit &L, elmPenyakit* p) {
    if (isEmptyPenyakit(L)) {
        insertFirstPenyakit(L, p);
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void deleteFirstPenyakit(ListPenyakit &L, elmPenyakit* &p) {
    if (isEmptyPenyakit(L)) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteLastPenyakit(ListPenyakit &L, elmPenyakit* &p) {
    if (isEmptyPenyakit(L)) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        p = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}

elmPenyakit* searchPenyakit(ListPenyakit L, string kode) {
    elmPenyakit* p = L.first;
    while (p != nullptr) {
        if (p->info.kode == kode) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void printInfoPenyakit(ListPenyakit L) {
    elmPenyakit* p = L.first;
    cout << "\n=== DAFTAR PENYAKIT ===" << endl;
    if (p == nullptr) {
        cout << "List kosong" << endl;
        return
    }
    while (p != nullptr) {
        cout << "Kode: " << p->info.kode
             << ", Nama: " << p->info.nama
             << ", Kategori: " << p->info.kategori
             << ", Bahaya: " << p->info.tingkatBahaya << endl;
        p = p->next;
    }
}
