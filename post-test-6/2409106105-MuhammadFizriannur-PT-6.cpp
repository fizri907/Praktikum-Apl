#include <iostream>
#include <string>
using namespace std;

const int MAX_BARANG = 100;
string daftarMotor[MAX_BARANG][2];
int stokMotor[MAX_BARANG];
int jumlahMotor = 5;

string namaPengguna[100];
string nimPengguna[100];
int jumlahPengguna = 1;

int loggedInUser = -1;
bool isAdmin = false;

void bubbleSortNamaAscending(string data[][2], int stok[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j][0] > data[j + 1][0]) {
                string tempNama = data[j][0];
                data[j][0] = data[j + 1][0];
                data[j + 1][0] = tempNama;

                string tempHarga = data[j][1];
                data[j][1] = data[j + 1][1];
                data[j + 1][1] = tempHarga;

                int tempStok = stok[j];
                stok[j] = stok[j + 1];
                stok[j + 1] = tempStok;
            }
        }
    }
}

void bubbleSortHargaDescending(string data[][2], int stok[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (stoi(data[j][1]) < stoi(data[j + 1][1])) {
                string tempNama = data[j][0];
                data[j][0] = data[j + 1][0];
                data[j + 1][0] = tempNama;

                string tempHarga = data[j][1];
                data[j][1] = data[j + 1][1];
                data[j + 1][1] = tempHarga;

                int tempStok = stok[j];
                stok[j] = stok[j + 1];
                stok[j + 1] = tempStok;
            }
        }
    }
}

void tampilMenuUtama(int &menu) {
    cout << "\n===== MENU UTAMA =====" << endl;
    cout << "1. Login" << endl;
    cout << "2. Daftar Akun" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;
}

void daftarAkun(string* namaPengguna, string* nimPengguna, int* jumlahPengguna) {
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, namaPengguna[*jumlahPengguna]);
    cout << "Masukkan NIM: ";
    getline(cin, nimPengguna[*jumlahPengguna]);
    (*jumlahPengguna)++;
    cout << "Akun berhasil didaftarkan! Silakan login." << endl;
}

void lihatMotor(string Barang[][2], int stok[], int jumlahBarang) {
    cout << "\n===== DAFTAR MOTOR =====" << endl;
    for (int i = 0; i < jumlahBarang; i++) {
        cout << i + 1 << ". " << Barang[i][0] << " | Stok: " << stok[i] << " | Harga: Rp" << Barang[i][1] << endl;
    }
}

void menuAdmin() {
    int pilihan;
    do {
        cout << "\n===== MENU ADMIN =====" << endl;
        cout << "1. Lihat Motor" << endl;
        cout << "2. Tambah Motor" << endl;
        cout << "3. Ubah Motor" << endl;
        cout << "4. Hapus Motor" << endl;
        cout << "5. Urutkan Nama Motor (A-Z)" << endl;
        cout << "6. Urutkan Harga Motor (Tinggi ke Rendah)" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            lihatMotor(daftarMotor, stokMotor, jumlahMotor);
        } else if (pilihan == 2) {
            cout << "Masukkan nama Motor: ";
            getline(cin, daftarMotor[jumlahMotor][0]);
            cout << "Masukkan harga Motor: ";
            getline(cin, daftarMotor[jumlahMotor][1]);
            cout << "Masukkan jumlah stok: ";
            cin >> stokMotor[jumlahMotor];
            cin.ignore();
            jumlahMotor++;
            cout << "Motor berhasil ditambahkan!" << endl;
        } else if (pilihan == 3) {
            cout << "Pilih nomor Motor yang ingin diubah: ";
            int index;
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= jumlahMotor) {
                cout << "Masukkan nama baru Motor: ";
                getline(cin, daftarMotor[index - 1][0]);
                cout << "Masukkan harga baru: ";
                getline(cin, daftarMotor[index - 1][1]);
                cout << "Masukkan jumlah stok baru: ";
                cin >> stokMotor[index - 1];
                cin.ignore();
                cout << "Motor berhasil diperbarui!" << endl;
            } else {
                cout << "Nomor Motor tidak valid!" << endl;
            }
        } else if (pilihan == 4) {
            cout << "Pilih nomor Motor yang ingin dihapus: ";
            int index;
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= jumlahMotor) {
                for (int i = index - 1; i < jumlahMotor - 1; i++) {
                    daftarMotor[i][0] = daftarMotor[i + 1][0];
                    daftarMotor[i][1] = daftarMotor[i + 1][1];
                    stokMotor[i] = stokMotor[i + 1];
                }
                jumlahMotor--;
                cout << "Motor berhasil dihapus!" << endl;
            } else {
                cout << "Nomor Motor tidak valid!" << endl;
            }
        } else if (pilihan == 5) {
            bubbleSortNamaAscending(daftarMotor, stokMotor, jumlahMotor);
            cout << "Data motor berhasil diurutkan berdasarkan nama (A-Z)." << endl;
            lihatMotor(daftarMotor, stokMotor, jumlahMotor);
        } else if (pilihan == 6) {
            bubbleSortHargaDescending(daftarMotor, stokMotor, jumlahMotor);
            cout << "Data motor berhasil diurutkan berdasarkan harga (tertinggi ke terendah)." << endl;
            lihatMotor(daftarMotor, stokMotor, jumlahMotor);
        } else if (pilihan != 7) {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);
    cout << "Keluar dari menu admin." << endl;
}

void menuUser() {
    int pilihan;
    do {
        cout << "\n===== MENU PENGGUNA =====" << endl;
        cout << "1. Lihat Motor" << endl;
        cout << "2. Beli Motor" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            lihatMotor(daftarMotor, stokMotor, jumlahMotor);
        } else if (pilihan == 2) {
            lihatMotor(daftarMotor, stokMotor, jumlahMotor);
            cout << "Pilih nomor Motor yang ingin dibeli: ";
            int index;
            cin >> index;
            if (index > 0 && index <= jumlahMotor) {
                int jumlah;
                cout << "Masukkan jumlah yang ingin dibeli: ";
                cin >> jumlah;
                if (jumlah <= stokMotor[index - 1]) {
                    stokMotor[index - 1] -= jumlah;
                    int total = jumlah * stoi(daftarMotor[index - 1][1]);
                    cout << "Pembelian berhasil! Total harga: Rp" << total << endl;
                } else {
                    cout << "Stok tidak mencukupi!" << endl;
                }
            } else {
                cout << "Nomor tidak valid!" << endl;
            }
        } else if (pilihan != 3) {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);
    cout << "Keluar dari menu pengguna." << endl;
}

void login(string* namaPengguna, string* nimPengguna, int jumlahPengguna, bool* isAdmin, int* loginBerhasil) {
    string nama, nim;
    int percobaan = 0;
    *loginBerhasil = 0;
    *isAdmin = false;

    while (percobaan < 3 && *loginBerhasil == 0) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        for (int i = 0; i < jumlahPengguna; i++) {
            if (namaPengguna[i] == nama && nimPengguna[i] == nim) {
                *loginBerhasil = 1;
                loggedInUser = i;
                if (i == 0) *isAdmin = true;
                break;
            }
        }

        if (*loginBerhasil == 0) {
            percobaan++;
            cout << "Nama atau NIM salah! Percobaan ke-" << percobaan << " dari 3 percobaan.\n";
        }
    }
}

int main() {
    namaPengguna[0] = "fizri";
    nimPengguna[0] = "105";

    daftarMotor[0][0] = "Motor Ninja RR";     daftarMotor[0][1] = "150000000"; stokMotor[0] = 10;
    daftarMotor[1][0] = "Motor CBR 150R";     daftarMotor[1][1] = "30000000";  stokMotor[1] = 8;
    daftarMotor[2][0] = "Motor Vario 160";    daftarMotor[2][1] = "25000000";  stokMotor[2] = 12;
    daftarMotor[3][0] = "Motor Beat Deluxe";  daftarMotor[3][1] = "17000000";  stokMotor[3] = 15;
    daftarMotor[4][0] = "Motor PCX 160";      daftarMotor[4][1] = "32000000";  stokMotor[4] = 6;

    int menu;
    do {
        tampilMenuUtama(menu);

        if (menu == 1) {
            int loginBerhasil;
            login(namaPengguna, nimPengguna, jumlahPengguna, &isAdmin, &loginBerhasil);

            if (loginBerhasil == 0) {
                cout << "Anda sudah mencoba 3 kali. Program berhenti." << endl;
                return 0;
            }
            if (isAdmin) {
                menuAdmin();
            } else {
                menuUser();
            }
        } else if (menu == 2) {
            if (jumlahPengguna >= 100) {
                cout << "Pendaftaran penuh! Tidak bisa menambahkan pengguna baru." << endl;
            } else {
                daftarAkun(namaPengguna, nimPengguna, &jumlahPengguna);
            }
        } else if (menu == 3) {
            cout << "Keluar dari program. Sampai jumpa!" << endl;
        } else {
            cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (menu != 3);

    return 0;
}