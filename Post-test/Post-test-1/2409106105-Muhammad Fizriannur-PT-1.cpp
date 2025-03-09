#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

void menuUtama(); // Deklarasi agar bisa dipanggil dalam login()

void login() {
    string username, password;
    string userBenar = "Muhammad Fizriannur";
    string passBenar = "2409106105";

    while (true) {
        cout << "\n===== LOGIN =====\n";

        cout << "Username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer sebelum input
        getline(cin, username);

        cout << "Password: ";
        getline(cin, password);

        if (username == userBenar && password == passBenar) {
            cout << "Login berhasil! Selamat datang, " << userBenar << "!\n";
            menuUtama(); // Pindahkan ke menu utama setelah login
            break;
        } else {
            cout << "Username atau password salah. Coba lagi.\n";
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

void hitungLuas() {
    while (true) {
        cout << "\n===== MENU LUAS =====\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Trapesium\n6. Kembali\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                float sisi = cekInput("Masukkan sisi: ");
                cout << "Luas Persegi: " << sisi * sisi << "\n";
                break;
            }
            case 2: {
                float p = cekInput("Masukkan panjang: ");
                float l = cekInput("Masukkan lebar: ");
                cout << "Luas Persegi Panjang: " << p * l << "\n";
                break;
            }
            case 3: {
                float r = cekInput("Masukkan jari-jari: ");
                cout << "Luas Lingkaran: " << M_PI * r * r << "\n";
                break;
            }
            case 4: {
                float a = cekInput("Masukkan alas: ");
                float t = cekInput("Masukkan tinggi: ");
                cout << "Luas Segitiga: " << 0.5 * a * t << "\n";
                break;
            }
            case 5: {
                float ab = cekInput("Masukkan alas bawah: ");
                float at = cekInput("Masukkan alas atas: ");
                float t = cekInput("Masukkan tinggi: ");
                cout << "Luas Trapesium: " << 0.5 * (ab + at) * t << "\n";
                break;
            }
            case 6:
                return;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
}

void hitungKeliling() {
    while (true) {
        cout << "\n===== MENU KELILING =====\n";
        cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                float sisi = cekInput("Masukkan sisi: ");
                cout << "Keliling Persegi: " << 4 * sisi << "\n";
                break;
            }
            case 2: {
                float p = cekInput("Masukkan panjang: ");
                float l = cekInput("Masukkan lebar: ");
                cout << "Keliling Persegi Panjang: " << 2 * (p + l) << "\n";
                break;
            }
            case 3: {
                float r = cekInput("Masukkan jari-jari: ");
                cout << "Keliling Lingkaran: " << 2 * M_PI * r << "\n";
                break;
            }
            case 4: {
                float s1 = cekInput("Masukkan sisi pertama: ");
                float s2 = cekInput("Masukkan sisi kedua: ");
                float s3 = cekInput("Masukkan sisi ketiga: ");
                cout << "Keliling Segitiga: " << s1 + s2 + s3 << "\n";
                break;
            }
            case 5:
                return;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
}

void menuUtama() {
    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Hitung Luas\n2. Hitung Keliling\n3. Logout\n";
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                hitungLuas();
                break;
            case 2:
                hitungKeliling();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini!\n";
                return; // Keluar dari menuUtama dan kembali ke main()
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
}

int main() {
    login();
    return 0;
}
