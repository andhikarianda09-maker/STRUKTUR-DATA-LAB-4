#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;
const int PRIMA = 7;

struct Mahasiswa {
    long long nim;
    string nama;
    int status;
};

Mahasiswa tabel[SIZE];

int hash1(long long nim) {
    return nim % SIZE;
}

// Hash kedua
int hash2(long long nim) {
    return PRIMA - (nim % PRIMA);
}

void insertData(long long nim, string nama) {
    int index = hash1(nim);
    int step = hash2(nim);
    int posisiHapus = -1;

    for (int i = 0; i < SIZE; i++) {
        int posisi = (index + i * step) % SIZE;

        if (tabel[posisi].status == 1) {
            if (tabel[posisi].nim == nim) {
                cout << "NIM sudah terdaftar!\n";
                return;
            }
        }
        else if (tabel[posisi].status == 2) {
            if (posisiHapus == -1) {
                posisiHapus = posisi;
            }
        }
        else {
            if (posisiHapus != -1) {
                posisi = posisiHapus;
            }

            tabel[posisi].nim = nim;
            tabel[posisi].nama = nama;
            tabel[posisi].status = 1;

            cout << "Data berhasil ditambahkan!\n";
            return;
        }
    }

    if (posisiHapus != -1) {
        tabel[posisiHapus].nim = nim;
        tabel[posisiHapus].nama = nama;
        tabel[posisiHapus].status = 1;

        cout << "Data berhasil ditambahkan!\n";
    } else {
        cout << "Hash Table penuh!\n";
    }
}

void searchData(long long nim) {
    int index = hash1(nim);
    int step = hash2(nim);

    for (int i = 0; i < SIZE; i++) {
        int posisi = (index + i * step) % SIZE;

        if (tabel[posisi].status == 0) {
            break;
        }

        if (tabel[posisi].status == 1 &&
            tabel[posisi].nim == nim) {
            cout << "Data ditemukan!\n";
            cout << "NIM  : " << tabel[posisi].nim << endl;
            cout << "Nama : " << tabel[posisi].nama << endl;
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

void removeData(long long nim) {
    int index = hash1(nim);
    int step = hash2(nim);

    for (int i = 0; i < SIZE; i++) {
        int posisi = (index + i * step) % SIZE;

        if (tabel[posisi].status == 0) {
            break;
        }

        if (tabel[posisi].status == 1 &&
            tabel[posisi].nim == nim) {
            tabel[posisi].status = 2;

            cout << "Data berhasil dihapus!\n";
            return;
        }
    }

    cout << "Data tidak ditemukan!\n";
}

void tampilkanData() {
    cout << "\n===== ISI HASH TABLE =====\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Indeks " << i << " : ";

        if (tabel[i].status == 1) {
            cout << tabel[i].nim << " - "
                 << tabel[i].nama;
        }
        else if (tabel[i].status == 2) {
            cout << "Data dihapus";
        }
        else {
            cout << "Kosong";
        }

        cout << endl;
    }
}

int main() {
    int pilihan;
    long long nim;
    string nama;

    for (int i = 0; i < SIZE; i++) {
        tabel[i].status = 0;
    }

    do {
        cout << "\n===== MENU HASH TABLE =====\n";
        cout << "1. Insert Data\n";
        cout << "2. Search Data\n";
        cout << "3. Remove Data\n";
        cout << "4. Tampilkan Hash Table\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;

                cout << "Masukkan Nama: ";
                getline(cin >> ws, nama);

                insertData(nim, nama);
                break;

            case 2:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;

                searchData(nim);
                break;

            case 3:
                cout << "Masukkan NIM yang dihapus: ";
                cin >> nim;

                removeData(nim);
                break;

            case 4:
                tampilkanData();
                break;

            case 5:
                cout << "Program selesai.\n";
                tampilkanData();
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}