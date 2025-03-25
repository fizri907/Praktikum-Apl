#include <iostream>
#include <string>

using namespace std;

struct PembelianMotor {
    string namaPembeli;
    string merekMotor;
    string tipeMotor;
    int hargaMotor;
};

struct User {
    string nama;
    string nim;
};

struct SistemPembelian {
    User user;
    PembelianMotor daftarPembelian[100];
    int jumlahPembelian = 0;
};

SistemPembelian sistem[10];
int jumlahUser = 0;

int login(string nama, string nim) {
    int i = 0;
    while (i < jumlahUser) {
        if (sistem[i].user.nama == nama && sistem[i].user.nim == nim) {
            return i;
        }
        i++;
    }
    return -1;
}

int registrasi() {
    if (jumlahUser >= 10) {
        cout << "Kapasitas user penuh!\n";
        return 0;
    }
    cout << "Masukkan Nama: ";
    cin >> sistem[jumlahUser].user.nama;
    cout << "Masukkan NIM: ";
    cin >> sistem[jumlahUser].user.nim;
    jumlahUser++;
    cout << "Registrasi berhasil!\n";
    return 1;
}

int main() {
    int pilihan = 0;
    while (pilihan != 3) {
        cout << "\n=== Sistem Pembelian Motor ===\n";
        cout << "1. Login\n";
        cout << "2. Registrasi\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama, nim;
            int kesempatan = 3;
            int userIndex = -1;

            while (kesempatan > 0) {
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;

                userIndex = login(nama, nim);
                if (userIndex != -1) {
                    cout << "\nLogin berhasil!\n";
                    break;
                } else {
                    kesempatan--;
                    cout << "\nLogin gagal! Sisa kesempatan: " << kesempatan << "\n";
                }
            }

            if (userIndex == -1) {
                cout << "\nAnda telah gagal login 3 kali. Program berhenti.\n";
                return 0;
            }

            int pilihanMenu = 0;
            while (pilihanMenu != 5) {
                cout << "\n=== Menu Pembelian Motor ===\n";
                cout << "1. Tambah Pembelian\n";
                cout << "2. Lihat Data Pembelian\n";
                cout << "3. Edit Data Pembelian\n";
                cout << "4. Hapus Data Pembelian\n";
                cout << "5. Logout\n";
                cout << "Pilih menu: ";
                cin >> pilihanMenu;

                if (pilihanMenu == 1) {
                    cout << "\nMasukkan Nama Pembeli: ";
                    cin >> sistem[userIndex].daftarPembelian[sistem[userIndex].jumlahPembelian].namaPembeli;
                    cout << "Masukkan Merek Motor: ";
                    cin >> sistem[userIndex].daftarPembelian[sistem[userIndex].jumlahPembelian].merekMotor;
                    cout << "Masukkan Tipe Motor: ";
                    cin >> sistem[userIndex].daftarPembelian[sistem[userIndex].jumlahPembelian].tipeMotor;
                    cout << "Masukkan Harga Motor: ";
                    cin >> sistem[userIndex].daftarPembelian[sistem[userIndex].jumlahPembelian].hargaMotor;
                    sistem[userIndex].jumlahPembelian++;
                    cout << "\nData berhasil ditambahkan!\n";
                } else if (pilihanMenu == 2) {
                    if (sistem[userIndex].jumlahPembelian == 0) {
                        cout << "\nTidak ada data pembelian.\n";
                    } else {
                        cout << "\n=== Data Pembelian ===\n";
                        for (int i = 0; i < sistem[userIndex].jumlahPembelian; i++) {
                            cout << i + 1 << ". Nama Pembeli: " << sistem[userIndex].daftarPembelian[i].namaPembeli
                                 << " | Merek: " << sistem[userIndex].daftarPembelian[i].merekMotor
                                 << " | Tipe: " << sistem[userIndex].daftarPembelian[i].tipeMotor
                                 << " | Harga: " << sistem[userIndex].daftarPembelian[i].hargaMotor << endl;
                        }
                    }
                } else if (pilihanMenu == 3) {
                    if (sistem[userIndex].jumlahPembelian == 0) {
                        cout << "\nTidak ada data pembelian untuk diedit.\n";
                    } else {
                        cout << "\nMasukkan nomor data yang ingin diedit: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= sistem[userIndex].jumlahPembelian) {
                            cout << "Masukkan Nama Pembeli baru: ";
                            cin >> sistem[userIndex].daftarPembelian[index - 1].namaPembeli;
                            cout << "Masukkan Merek Motor baru: ";
                            cin >> sistem[userIndex].daftarPembelian[index - 1].merekMotor;
                            cout << "Masukkan Tipe Motor baru: ";
                            cin >> sistem[userIndex].daftarPembelian[index - 1].tipeMotor;
                            cout << "Masukkan Harga Motor baru: ";
                            cin >> sistem[userIndex].daftarPembelian[index - 1].hargaMotor;
                            cout << "\nData berhasil diubah!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                } else if (pilihanMenu == 4) {
                    if (sistem[userIndex].jumlahPembelian == 0) {
                        cout << "\nTidak ada data pembelian untuk dihapus.\n";
                    } else {
                        cout << "\nMasukkan nomor data yang ingin dihapus: ";
                        int index;
                        cin >> index;
                        if (index > 0 && index <= sistem[userIndex].jumlahPembelian) {
                            for (int i = index - 1; i < sistem[userIndex].jumlahPembelian - 1; i++) {
                                sistem[userIndex].daftarPembelian[i] = sistem[userIndex].daftarPembelian[i + 1];
                            }
                            sistem[userIndex].jumlahPembelian--;
                            cout << "\nData berhasil dihapus!\n";
                        } else {
                            cout << "Nomor tidak valid!\n";
                        }
                    }
                } else if (pilihanMenu == 5) {
                    cout << "\nLogout berhasil!\n";
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        } else if (pilihan == 2) {
            registrasi();
        } else if (pilihan == 3) {
            cout << "\nTerima kasih telah menggunakan program ini!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}