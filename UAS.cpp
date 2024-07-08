/*! \mainpage Sistem Manajemen Kelulusan MataKuliah
 *  
 * \section intro_sec Pengantar
 * Selamat datang di dokumentasi Sistem Manajemen Kelulusan MataKuliah.
 * Sistem ini dirancang untuk mengecek kelulusan MataKuliah berdasarkan nilai yang sudah di-input.
 * 
 * \section structure_sec Struktur Kode
 * Kode ini terdiri dari tiga kelas utama:
 * - \b MataKuliah : Kelas dasar yang memiliki function-function yang akan diturunkan ke kelas turunannya.
 * - \b Pemrograman : Kelas turunan dari kelas MataKuliah yang meng-override beberapa function parent-nya.
 * - \b Jaringan : Kelas turunan dari kelas MataKUliah yang meng-override beberapa function parent-nya.
 * 
 * \section setup_sec Setup dan Konfigurasi
 * Untuk menjalankan sistem ini, pastikan anda memiliki compiler yang mendukung standar operasi.
 * Kompilasi dan jalankan file ini menggunakan compiler pilihan anda.
 * 
 * \section author_sec Tentang Pengembang
 * Sistem ini dikembangkan oleh Zhilal Fadiah Krisna sebagai hasil dari UAS mata kuliah Pemrograman Dasar.
 * 
 * \section note_sec Catatan
 * Dokumentasi ini dibuat menggunakan Doxygen.
 * Pastikan untuk mengikuti komentar yang telah dibuat.
 */


/**
 * @file UAS.cpp
 * @author Zhilal Fadiah Krisna 
 * @brief Sistem Manajemen Kelulusan MataKuliah
 * @version 1.0
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */



#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas Dasar yang memiliki beberapa virtual function yang akan diturunkan ke turunannya.
 * 
 */
class MataKuliah
{
private: // isi dengan access modifier yang dibutuhkan
    float presensi; ///< Variable yang menyimpan nilai presensi.
        // tambahkan dengan variabel lain yang dibutuhkan dibawah ini
    float activity; ///< Variable yang menyimpan nilai activity.
    float exercise; ///< Variable yang menyimpan nilai exercise.
    float tugasAkhir; ///< Variable yang menyimpan nilai tugas akhir.
public:

    /**
     * @brief Konstruksi untuk objek MataKuliah
     * Konstruksi ini menginisialisasi variable presensi, activity, exercise, dan tugasAkhir.
     * 
     */
    MataKuliah()
    {
        presensi = 0.0;
        // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini
        activity = 0.0;
        exercise = 0.0;
        tugasAkhir = 0.0;
    }


    /**
     * @brief Sebuah virtual function untuk nama mataKuliah.
     * 
     */
    virtual void namaMataKuliah() { return; }
    // tambahkan virtual fungsi lain yang dibutuhkan dibawah ini

    /**
     * @brief Sebuah virtual function untuk menginput nilai-nilai yang sudah ditentukan.
     * 
     */
    virtual void inputNilai() { return; }

    /**
     * @brief Sebuah virtual function untuk menghitung nilai akhir berdasarkan nilai yang sudah diinput.
     * 
     * @return float tipe data dari function hitungNilaiAkhir.
     */
    virtual float hitungNilaiAkhir() = 0;

    /**
     * @brief Sebuah virtual function untuk mengecek hasil kelulusan berdasarkan hasil dari function hitungNilaiAkhir.
     * 
     */
    virtual void cekKelulusan() { return; }


    /**
     * @brief Function untuk set variable presensi.
     * 
     * @param nilai nilai yang diinput.
     */
    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }

    /**
     * @brief Mengambil nilai dari variable presensi.
     * 
     * @return float tipe data yang diambil.
     */
    float getPresensi()
    {
        return presensi;
    } // tambahkan setter dan getter lain yang dibutuhkan dibawah ini

    /**
     * @brief Function untuk set variable activity.
     * 
     * @param a nilai yang diinput.
     */
    void setActivity(float a) 
    {
        this->activity =  a;
    }

    /**
     * @brief Mengambil nilai dari variable activity.
     * 
     * @return float tipe data yang diambil.
     */
    float getActivity() 
    {
        return activity;
    }

    /**
     * @brief Function untuk set variable exercise.
     * 
     * @param b nilai yang diinput.
     */
    void setExercise(float b) 
    {
        this->exercise = b;
    }

    /**
     * @brief Mengambil nilai dari variable exercise.
     * 
     * @return float tipe data yang diambil.
     */
    float getExercise()
    {
        return exercise;
    }

    /**
     * @brief Function untuk set variable tugasAkhir.
     * 
     * @param c nilai yang d'iinput.
     */
    void setTugasAkhir(float c)
    {
        this->tugasAkhir = c;
    }

    /**
     * @brief Mengambil nilai dari variable tugasAkhir.
     * 
     * @return float tipe data yang diambil.
     */
    float getTugasAkhir() 
    {
        return tugasAkhir;
    }
};


/**
 * @class Pemrograman
 * @brief Kelas turunan dari kelas MataKuliah.
 * 
 */
class Pemrograman : public MataKuliah
{
    // isi disini untuk mengisi kelas pemrograman
    private:
    float temp; 
    public:
    void namaMataKuliah() {
        cout << "Pemrograman";
    }

    void inputNilai()
    {
        cout << "Masukkan nilai presensi: ";
        cin >> temp;
        this->setPresensi(temp);
        cout << "Masukkan nilai activity: ";
        cin >> temp;
        this->setActivity(temp);
        cout << "Masukkan nilai exercise: ";
        cin >> temp;
        this->setExercise(temp);
        cout << "Masukkan nilai tugas akhir: ";
        cin >> temp;
        this->setTugasAkhir(temp);
    }

    float hitungNilaiAkhir()
    {
        return getPresensi()*0.1 + getActivity()*0.2 + getExercise()*0.3 + getTugasAkhir()*0.4;
    }

    void cekKelulusan()
    {
        if (this->hitungNilaiAkhir() >= 75)
        {
            cout << "Nilai Akhir = " << this->hitungNilaiAkhir() << endl;
            cout << "Selamat anda dinyatakan lulus!" << endl;
        }
        else
        {
            cout << "Nilai Akhir = " << this->hitungNilaiAkhir() << endl;
            cout << "Anda dinyatakan tidak lulus" << endl;
        }
    }
};


/**
 * @class Jaringan
 * @brief Kelas turunan dari kelas MataKuliah.
 * 
 */
class Jaringan : public MataKuliah
{
    // isi disini untuk mengisi kelas jaringan
    private: 
    float temp; 
    public:
    void namaMataKuliah()
    {
        cout << "Jaringan";
    }

    void inputNilai()
    {
        cout << "Masukkan nilai activity: ";
        cin >> temp;
        this->setActivity(temp);
        cout << "Masukkan nilai exercise: ";
        cin >> temp;
        this->setExercise(temp);
    }

    float hitungNilaiAkhir() 
    {
        return getActivity()*0.6 + getExercise()*0.4;
    } 

    void cekKelulusan()
    {
        if (this->hitungNilaiAkhir() >= 75) 
        {
            cout << "Nilai Akhir = " << this->hitungNilaiAkhir() << endl;
            cout << "Selamat anda dinyatakan lulus!" << endl;
        }
        else
        {
            cout << "Nilai Akhir = " << this->hitungNilaiAkhir() << endl;
            cout << "Anda dinyatakan tidak lulus" << endl;
        }
    }
};

int main()
{
    char pilih;
    MataKuliah *mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;
    // isi disini untuk menentukan mata kuliah yang dipilih

    do 
    {
        cout << "Pilih Mata Kuliah: " << endl;
        cout << "1. ";
        pemrograman.namaMataKuliah();
        cout << endl;
        cout << "2. ";
        jaringan.namaMataKuliah();
        cout << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) 
        {
        case '1':
            mataKuliah = &pemrograman; //polymorphy
            mataKuliah->inputNilai();
            pemrograman.cekKelulusan();
            break;
        case '2':
            jaringan.inputNilai();
            jaringan.cekKelulusan();
            break;
        case '3':
            break;
        default :
            cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
        cout << endl;
    } while (pilih != '3');

}