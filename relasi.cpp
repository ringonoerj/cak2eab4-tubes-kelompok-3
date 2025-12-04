// relasi.cpp
#include "relasi.h"

void connectPenyakitPasien(elmPenyakit* p, elmPasien* a) {
    // Buat relasi dari sisi penyakit
    elmRelasi* r1 = new elmRelasi;
    r1->parent = p;
    r1->child = a;
    r1->next = p->firstRelasi;
    p->firstRelasi = r1;

    // Buat relasi dari sisi pasien
    elmRelasi* r2 = new elmRelasi;
    r2->parent = p;
    r2->child = a;
    r2->next2 = a->firstRelasi;
    a->firstRelasi = r2;

    // Hubungkan kedua relasi
    r1->next2 = r2;
    r2->next = r1;
}

void showPasienByPenyakit(elmPenyakit* p) {
    cout << "\nPasien dengan Penyakit " << p->info.nama << ":" << endl;
    elmRelasi* r = p->firstRelasi;
    if (r == nullptr) {
        cout << "Tidak ada pasien" << endl;
        return;
    }
    while (r != nullptr) {
        cout << "- " << r->child->info.kode << ": "
             << r->child->info.nama << endl;
        r = r->next;
    }
}

void showPenyakitByPasien(elmPasien* a) {
    cout << "\nPenyakit yang diderita " << a->info.nama << ":" << endl;
    elmRelasi* r = a->firstRelasi;
    if (r == nullptr) {
        cout << "Tidak memiliki penyakit" << endl;
        return;
    }
    while (r != nullptr) {
        cout << "- " << r->parent->info.kode << ": "
             << r->parent->info.nama << endl;
        r = r->next2;
    }
}

int countPasienInPenyakit(elmPenyakit* p) {
    int count = 0;
    elmRelasi* r = p->firstRelasi;
    while (r != nullptr) {
        count++;
        r = r->next;
    }
    return count;
}

int countPenyakitInPasien(elmPasien* a) {
    int count = 0;
    elmRelasi* r = a->firstRelasi;
    while (r != nullptr) {
        count++;
        r = r->next2;
    }
    return count;
}

void showAllRelations(ListPenyakit LP, ListPasien LA) {
    cout << "\n=== SEMUA RELASI PENYAKIT-PASIEN ===" << endl;
    elmPenyakit* p = LP.first;
    while (p != nullptr) {
        elmRelasi* r = p->firstRelasi;
        while (r != nullptr) {
            cout << p->info.kode << " - " << r->child->info.kode << endl;
            r = r->next;
        }
        p = p->next;
    }
}
