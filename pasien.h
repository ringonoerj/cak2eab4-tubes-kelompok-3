// Header File untuk Pasien (Child - DLL)
#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED

#include <iostream>
using namespace std;

struct dataPasien {
    string kode;
    string name;
    int umur;
    string alamat;
};

struct elmPasien {
    dataPasien info;
    elmPasien* next;
    struct elmRelasi* firstRelasi;
};

struct ListPasien {
    elmPasien* first;
};

// Primitif SLL
void createListPasien(ListPasien &L);
bool isEmptyPasien(ListPasien L);
elmPasien* createElmPasien(dataPasien x);
void insertFirstPasien(ListPasien &L, elmPasien* p);
void insertLastPasien(ListPasien &L, elmPasien* p);
void deleteFirstPasien(ListPasien &L, elmPasien* &p);
void deleteLastPasien(ListPasien &L, elmPasien* &p);
elmPasien* searchPasien(ListPasien L, string kode);
void printInfoPasien(ListPasien L);

#endif // PASIEN_H_INCLUDED
