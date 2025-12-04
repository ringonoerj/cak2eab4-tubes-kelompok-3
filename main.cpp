// main.cpp
#include <iostream>
#include "penyakit.h"
#include "pasien.h"
#include "relasi.h"
using namespace std;

ListPenyakit LP;
ListPasien LA;

void init() {
    createListPenyakit(LP);
    createListPasien(LA);
}

dataPenyakit inputPenyakit() {
    dataPenyakit p;
    cout << "Kode Penyakit: ";
    cin >> p.kode;
    cout << "Nama Penyakit: ";
    cin.ignore();
    getline(cin, p.nama);
    cout << "Kategori: ";
    cin >> p.kategori;
    cout << "Tingkat Bahaya (1-10): ";
    cin >> p.tingkatBahaya;
    return p;
}

dataPasien inputPasien() {
    dataPasien a;
    cout << "Kode Pasien: ";
    cin >> a.kode;
    cout << "Nama Pasien: ";
    cin.ignore();
    getline(cin, a.nama);
    cout << "Umur: ";
    cin >> a.umur;
    cout << "Alamat: ";
    cin.ignore();
    getline(cin, a.alamat);
    return a;
}

void tambahPenyakit() {
    cout << "\n=== TAMBAH PENYAKIT ===" << endl;
    dataPenyakit p = inputPenyakit();
    elmPenyakit* newP = createElmPenyakit(p);

    // Aturan: Parent insert FIRST
    insertFirstPenyakit(LP, newP);
    cout << "Penyakit berhasil ditambahkan!" << endl;
}

void tambahPasien() {
    cout << "\n=== TAMBAH PASIEN ===" << endl;
    dataPasien a = inputPasien();
    elmPasien* newA = createElmPasien(a);

    // Aturan: Child insert LAST
    insertLastPasien(LA, newA);
    cout << "Pasien berhasil ditambahkan!" << endl;
}

void hubungkanRelasi() {
    cout << "\n=== HUBUNGKAN PENYAKIT-PASIEN ===" << endl;
    string kodeP, kodeA;
    cout << "Kode Penyakit: ";
    cin >> kodeP;
    cout << "Kode Pasien: ";
    cin >> kodeA;

    elmPenyakit* p = searchPenyakit(LP, kodeP);
    elmPasien* a = searchPasien(LA, kodeA);

    if (p != nullptr && a != nullptr) {
        connectPenyakitPasien(p, a);
        cout << "Relasi berhasil dibuat!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void hapusPenyakit() {
    cout << "\n=== HAPUS PENYAKIT ===" << endl;
    string kode;
    cout << "Kode Penyakit yang dihapus: ";
    cin >> kode;

    elmPenyakit* p = searchPenyakit(LP, kode);
    if (p != NULL) {
        // Cek apakah ini elemen terakhir (sesuai aturan: delete LAST)
        if (LP.last == p) {
            elmPenyakit* temp;
            deleteRelasiByPenyakit(p);  // Hapus semua relasinya
            deleteLastPenyakit(LP, temp);  // Hapus penyakitnya
            cout << "Penyakit berhasil dihapus!" << endl;
        } else {
            cout << "Hanya bisa menghapus penyakit terakhir (Delete Last)!" << endl;
            cout << "Penyakit terakhir adalah: " << LP.last->info.kode << endl;
        }
    } else {
        cout << "Penyakit tidak ditemukan!" << endl;
    }
}

void hapusPasien() {
    cout << "\n=== HAPUS PASIEN ===" << endl;
    string kode;
    cout << "Kode Pasien yang dihapus: ";
    cin >> kode;

    elmPasien* a = searchPasien(LA, kode);
    if (a != NULL) {
        // Cek apakah ini elemen pertama (sesuai aturan: delete FIRST)
        if (LA.first == a) {
            elmPasien* temp;
            deleteRelasiByPasien(a);  // Hapus semua relasinya
            deleteFirstPasien(LA, temp);  // Hapus pasiennya
            cout << "Pasien berhasil dihapus!" << endl;
        } else {
            cout << "Hanya bisa menghapus pasien pertama (Delete First)!" << endl;
            cout << "Pasien pertama adalah: " << LA.first->info.kode << endl;
        }
    } else {
        cout << "Pasien tidak ditemukan!" << endl;
    }
}

void top5Penyakit() {
    cout << "\n=== TOP 5 PENYAKIT PALING BANYAK ===" << endl;

    // Array untuk menyimpan penyakit dan jumlah pasiennya
    const int MAX = 100;
    elmPenyakit* penyakitArr[MAX];
    int countArr[MAX];
    int n = 0;

    // Hitung jumlah pasien per penyakit
    elmPenyakit* p = LP.first;
    while (p != NULL && n < MAX) {
        penyakitArr[n] = p;
        countArr[n] = countPasienInPenyakit(p);
        n++;
        p = p->next;
    }

    if (n == 0) {
        cout << "Tidak ada data penyakit" << endl;
        return;
    }

    // Bubble sort sederhana (descending)
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (countArr[j] < countArr[j+1]) {
                // Tukar count
                int tempCount = countArr[j];
                countArr[j] = countArr[j+1];
                countArr[j+1] = tempCount;

                // Tukar pointer penyakit
                elmPenyakit* tempP = penyakitArr[j];
                penyakitArr[j] = penyakitArr[j+1];
                penyakitArr[j+1] = tempP;
            }
        }
    }

    // Tampilkan maksimal 5
    int limit = (n < 5) ? n : 5;
    for (int i = 0; i < limit; i++) {
        cout << i+1 << ". " << penyakitArr[i]->info.nama
             << " (" << countArr[i] << " pasien)" << endl;
        cout << "   Kode: " << penyakitArr[i]->info.kode
             << ", Kategori: " << penyakitArr[i]->info.kategori << endl;
    }

    if (n > 5) {
        cout << "\n... dan " << (n - 5) << " penyakit lainnya" << endl;
    }
}

void showMenu() {
    cout << "\n=== SISTEM DATA PASIEN & PENYAKIT ===" << endl;
    cout << "1. Tambah Penyakit (Insert First)" << endl;
    cout << "2. Tambah Pasien (Insert Last)" << endl;
    cout << "3. Hubungkan Penyakit-Pasien" << endl;
    cout << "4. Tampilkan Semua Penyakit" << endl;
    cout << "5. Tampilkan Semua Pasien" << endl;
    cout << "6. Tampilkan Pasien dengan Penyakit Tertentu" << endl;
    cout << "7. Tampilkan Penyakit dari Pasien Tertentu" << endl;
    cout << "8. Hapus Penyakit (Delete Last)" << endl;
    cout << "9. Hapus Pasien (Delete First)" << endl;
    cout << "10. Hitung Jumlah Pasien dari Penyakit" << endl;
    cout << "11. Tampilkan Semua Relasi" << endl;
    cout << "12. Top 5 Penyakit Paling Banyak" << endl;  // TAMBAHAN
    cout << "0. Keluar" << endl;
    cout << "Pilihan: ";
}

int main() {
    init();
    int pilihan;

    // Data dummy untuk testing
    dataPenyakit p1 = {"P1", "Flu", "Menular", 3};
    dataPenyakit p2 = {"P2", "Diabetes", "Tidak Menular", 7};
    dataPenyakit p3 = {"P3", "Hipertensi", "Tidak Menular", 6};

    dataPasien a1 = {"A1", "Budi", 25, "Jakarta"};
    dataPasien a2 = {"A2", "Siti", 30, "Bandung"};
    dataPasien a3 = {"A3", "Ahmad", 45, "Surabaya"};

    elmPenyakit* ep1 = createElmPenyakit(p1);
    elmPenyakit* ep2 = createElmPenyakit(p2);
    elmPenyakit* ep3 = createElmPenyakit(p3);

    elmPasien* ea1 = createElmPasien(a1);
    elmPasien* ea2 = createElmPasien(a2);
    elmPasien* ea3 = createElmPasien(a3);

    insertFirstPenyakit(LP, ep1);
    insertFirstPenyakit(LP, ep2);
    insertFirstPenyakit(LP, ep3);

    insertLastPasien(LA, ea1);
    insertLastPasien(LA, ea2);
    insertLastPasien(LA, ea3);

    // Buat relasi dummy
    connectPenyakitPasien(ep1, ea1);
    connectPenyakitPasien(ep1, ea2);
    connectPenyakitPasien(ep2, ea2);
    connectPenyakitPasien(ep3, ea3);

    do {
        showMenu();
        cin >> pilihan;

        switch(pilihan) {
            case 1: tambahPenyakit(); break;
            case 2: tambahPasien(); break;
            case 3: hubungkanRelasi(); break;
            case 4: printInfoPenyakit(LP); break;
            case 5: printInfoPasien(LA); break;
            case 6: {
                string kode;
                cout << "Kode Penyakit: ";
                cin >> kode;
                elmPenyakit* p = searchPenyakit(LP, kode);
                if (p != nullptr) showPasienByPenyakit(p);
                else cout << "Penyakit tidak ditemukan!" << endl;
                break;
            }
            case 7: {
                string kode;
                cout << "Kode Pasien: ";
                cin >> kode;
                elmPasien* a = searchPasien(LA, kode);
                if (a != nullptr) showPenyakitByPasien(a);
                else cout << "Pasien tidak ditemukan!" << endl;
                break;
            }
            case 8: hapusPenyakit(); break;
            case 9: hapusPasien(); break;
            case 10: {
                string kode;
                cout << "Kode Penyakit: ";
                cin >> kode;
                elmPenyakit* p = searchPenyakit(LP, kode);
                if (p != nullptr) {
                    int count = countPasienInPenyakit(p);
                    cout << "Jumlah pasien: " << count << endl;
                } else {
                    cout << "Penyakit tidak ditemukan!" << endl;
                }
                break;
            }
            case 11: showAllRelations(LP, LA); break;
            case 12: top5Penyakit(); break;
            case 0: cout << "Keluar..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
