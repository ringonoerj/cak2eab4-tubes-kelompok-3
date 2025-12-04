// Header File untuk Penyakit (Parent - DLL)
#ifndef PENYAKIT_H_INCLUDED
#define PENYAKIT_H_INCLUDED

#include <iostream>
using namespace std;

struct dataPenyakit {
    string kode;
    string nama;
    string kategori;
    int tingkatBahaya;
};

struct elmPenyakit {
    dataPenyakit info;
    elmPenyakit* next;
    elmPenyakit* prev;
    struct elmRelasi* firstRelasi;
};

struct ListPenyakit {
    elmPenyakit* first;
    elmPenyakit* last;
};

// Primitif DLL
void createListPenyakit(ListPenyakit &L);
bool isEmptyPenyakit(ListPenyakit L);
elmPenyakit* createElmPenyakit(dataPenyakit x);
void insertFirstPenyakit(ListPenyakit &L, elmPenyakit* p);
void insertLastPenyakit(ListPenyakit &L, elmPenyakit* p);
void deleteFirstPenyakit(ListPenyakit &L, elmPenyakit* p);
void deleteLastPenyakit(ListPenyakit &L, elmPenyakit* p);
elmPenyakit* searchPenyakit(ListPenyakit L, string kode);
void printInfoPenyakit(ListPenyakit L);


#endif // PENYAKIT_H_INCLUDED
