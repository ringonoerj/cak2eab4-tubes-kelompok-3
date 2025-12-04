// relasi.h
#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "penyakit.h"
#include "pasien.h"
using namespace std;

struct elmRelasi {
    elmPenyakit* parent;
    elmPasien* child;
    elmRelasi* next;
    elmRelasi* next2;
};

// Fungsi-fungsi relasi
void connectPenyakitPasien(elmPenyakit* p, elmPasien* a);
void disconnectPenyakitPasien(elmPenyakit* p, elmPasien* a);
void showPasienByPenyakit(elmPenyakit* p);
void showPenyakitByPasien(elmPasien* a);
int countPasienInPenyakit(elmPenyakit* p);
int countPenyakitInPasien(elmPasien* a);
void deleteRelasiByPenyakit(elmPenyakit* p);
void deleteRelasiByPasien(elmPasien* a);
void showAllRelations(ListPenyakit LP, ListPasien LA);

#endif

