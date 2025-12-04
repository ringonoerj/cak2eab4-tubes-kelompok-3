// pasien.cpp
#include "pasien.h"

void createListPasien(ListPasien &L) {
    L.first = nullptr;
}

bool isEmptyPasien(ListPasien L) {
    return (L.first == nullptr)
}

elmPasien* createElmPasien(dataPasien x) {
    elmPasien* p = new elmPasien;
    p->info = x;
    p->next = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

void insertFirstPasien(ListPasien &L, elmPasien* p) {
    if (isEmptyPasien(L)) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void insertLastPasien(ListPasien &L, elmPasien* p) {
    if (isEmptyPasien(L)) {
        L.first = p;
    } else {
        elmPasien* q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p
    }
}

void deleteFirstPasien(ListPasien &L, elmPasien* &p) {
    if (isEmptyPasien(L)) {
        p = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        p->next = nullptr;
    }
}

void deleteLastPasien(ListPasien &L, elmPasien* &p) {
    if (isEmptyPasien(L)) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        elmPasien* q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}

elmPasien* searchPasien(ListPasien L, string kode) {
    elmPasien*p = L.first;
    while (p != nullptr) {
        if (p->info.kode == kode) {
            return p;
        }
        p = p->next;
    }
    return nullptr
}

void printInfoPasien(ListPasien L) {
    elmPasien* p = L.first;
    cout << "\n=== DAFTAR PASIEN ===" << endl;
    if (p == nullptr) {
        cout << "List kosong" << endl;
        return;
    }
    while (p != nullptr){
        cout << "Kode: " << p->info.kode
             << ", Nama: " << p->info.name
             << ", Umur: " << p->info.umur
             << ", Alamat: " << p->info.alamat << endl;
        p = p->next
    }
}
