#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int menuUtama(); 

int login() {
    string username, password;
    string userBenar = "Muhammad Fizriannur";
    string passBenar = "2409106105";
    int attempts = 3; 

    while (attempts > 0) {
        cout << "\n===== LOGIN =====\n";
        cout << "Masukkan Username (atau ketik 'exit' untuk keluar): ";
        cin >> ws;
        getline(cin, username);

        if (username == "exit") {
            cout << "Keluar dari program.\n";
            return 0; 
        }

        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username == userBenar && password == passBenar) {
            cout << "Login berhasil! Selamat datang, " << userBenar << "!\n";
            return menuUtama(); 
        } else {
            attempts--;
            cout << "Username atau password salah! Sisa percobaan: " << attempts << "\n";
            if (attempts == 0) {
                cout << "Anda telah gagal login 3 kali. Program akan keluar.\n";
                return 0;
            }
        }
    }
}

float cekInput(string pesan) {
    float nilai;
    while (true) {
        cout << pesan;
        cin >> nilai;

        if (cin.fail() || nilai < 0) {
            cout << "Input tidak valid! Masukkan angka yang benar.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }
    }
}

float hitungLuas() {
    while (true) {
        cout << "\n===== MENU LUAS =====\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Trapesium\n6. Kembali\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: return pow(cekInput("Masukkan sisi: "), 2);
            case 2: return cekInput("Masukkan panjang: ") * cekInput("Masukkan lebar: ");
            case 3: return M_PI * pow(cekInput("Masukkan jari-jari: "), 2);
            case 4: return 0.5 * cekInput("Masukkan alas: ") * cekInput("Masukkan tinggi: ");
            case 5: return 0.5 * (cekInput("Masukkan alas bawah: ") + cekInput("Masukkan alas atas: ")) * cekInput("Masukkan tinggi: ");
            case 6: return 0;
            default: cout << "Pilihan tidak tersedia.\n";
        }
    }
}

float hitungKeliling() {
    while (true) {
        cout << "\n===== MENU KELILING =====\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: return 4 * cekInput("Masukkan sisi: ");
            case 2: return 2 * (cekInput("Masukkan panjang: ") + cekInput("Masukkan lebar: "));
            case 3: return 2 * M_PI * cekInput("Masukkan jari-jari: ");
            case 4: return cekInput("Masukkan sisi pertama: ") + cekInput("Masukkan sisi kedua: ") + cekInput("Masukkan sisi ketiga: ");
            case 5: return 0;
            default: cout << "Pilihan tidak tersedia.\n";
        }
    }
}

int menuUtama() {
    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Hitung Luas\n2. Hitung Keliling\n3. Logout\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Hasil Luas: " << hitungLuas() << "\n";
                break;
            case 2:
                cout << "Hasil Keliling: " << hitungKeliling() << "\n";
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini!\n";
                return 0; 
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
}

int main() {
    return login();
}
