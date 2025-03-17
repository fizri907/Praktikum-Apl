#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct PembelianMotor {
    string namaPembeli;
    string merekMotor;
    string tipeMotor;
    int hargaMotor;
};

int main() {
    string namaUser, nimUser;
    string namaInput, nimInput;
    vector<PembelianMotor> daftarPembelian;
    int kesempatan = 3;

    cout << "=== Login Sistem Pembelian Motor ===" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, namaUser);
    cout << "Masukkan NIM: ";
    getline(cin, nimUser);

    while (kesempatan > 0) {
        cout << "\nLogin - Masukkan Nama: ";
        getline(cin, namaInput);
        cout << "Login - Masukkan NIM: ";
        getline(cin, nimInput);

        if (namaInput == namaUser && nimInput == nimUser) {
            cout << "\nLogin berhasil!" << endl;
            break;
        } else {
            kesempatan--;
            cout << "Login gagal! Sisa kesempatan: " << kesempatan << "\n";
        }

        if (kesempatan == 0) {
            cout << "\nAnda telah gagal login 3 kali. Program berhenti.\n";
            return 0;
        }
    }

    int pilihan;
    do {
        cout << "\n=== Menu Pembelian Motor ===\n";
        cout << "1. Tambah Pembelian\n";
        cout << "2. Lihat Data Pembelian\n";
        cout << "3. Edit Data Pembelian\n";
        cout << "4. Hapus Data Pembelian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                PembelianMotor pembelian;
                cout << "\nMasukkan Nama Pembeli: ";
                cin >> pembelian.namaPembeli;
                cout << "Masukkan Merek Motor: ";
                cin >> pembelian.merekMotor;
                cout << "Masukkan Tipe Motor: ";
                cin >> pembelian.tipeMotor;
                cout << "Masukkan Harga Motor: ";
                cin >> pembelian.hargaMotor;
                daftarPembelian.push_back(pembelian);
                cout << "\nData berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                if (daftarPembelian.empty()) {
                    cout << "\nTidak ada data pembelian.\n";
                } else {
                    cout << "\n========================================================\n";
                    cout << "| No | Nama Pembeli | Merek Motor | Tipe Motor | Harga  |\n";
                    cout << "========================================================\n";
                    for (size_t i = 0; i < daftarPembelian.size(); ++i) {
                        cout << "| " << setw(2) << i + 1 << " | "
                            << setw(13) << daftarPembelian[i].namaPembeli << " | "
                            << setw(12) << daftarPembelian[i].merekMotor << " | "
                            << setw(10) << daftarPembelian[i].tipeMotor << " | "
                            << setw(6) << daftarPembelian[i].hargaMotor << " |\n";
                    }
                    cout << "========================================================\n";
                }
                break;
            }
            case 3: {
                if (daftarPembelian.empty()) {
                    cout << "\nTidak ada data pembelian untuk diedit.\n";
                    break;
                }
                cout << "\nMasukkan nomor data yang ingin diedit: ";
                int index;
                cin >> index;
                if (index > 0 && index <= daftarPembelian.size()) {
                    cout << "Masukkan Nama Pembeli baru: ";
                    cin >> daftarPembelian[index - 1].namaPembeli;
                    cout << "Masukkan Merek Motor baru: ";
                    cin >> daftarPembelian[index - 1].merekMotor;
                    cout << "Masukkan Tipe Motor baru: ";
                    cin >> daftarPembelian[index - 1].tipeMotor;
                    cout << "Masukkan Harga Motor baru: ";
                    cin >> daftarPembelian[index - 1].hargaMotor;
                    cout << "\nData berhasil diubah!\n";
                } else {
                    cout << "Nomor tidak valid!\n";
                }
                break;
            }
            case 4: {
                if (daftarPembelian.empty()) {
                    cout << "\nTidak ada data pembelian untuk dihapus.\n";
                    break;
                }
                cout << "\nMasukkan nomor data yang ingin dihapus: ";
                int index;
                cin >> index;
                if (index > 0 && index <= daftarPembelian.size()) {
                    daftarPembelian.erase(daftarPembelian.begin() + index - 1);
                    cout << "\nData berhasil dihapus!\n";
                } else {
                    cout << "Nomor tidak valid!\n";
                }
                break;
            }
            case 5:
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
