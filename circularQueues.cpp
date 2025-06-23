/**
 * @mainpage Dokumentasi Circularqueues
 * 
 * @section introduction
 * projek ini merupakan projek struktur data
 * menggunakan struktur data queues dengan pendekatan circular array.
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue delate elements from queues
 * -show data / display
 * 
 * @section how to use
 * 1. insert
 * 2. delate
 * 3. display
 * 4. exit
 * 
 * 
 * @author your profil
 * - nama    : Masayu Eqfalarissa
 * - nim     : 20240140227
 * - kelas   : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class queues
 * @brief this class is for operation queues
 * 
 */
class queues
{
private:
    int front; /// private variable front for indicate first element
    int rear; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for maximum capesity of element
    int queue_array[5]; /// private variable queue_array to store elements

public:
    /**
     * @brief Construct a new queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    queues()
    {
        front = -1;
        rear = -1;
    }



    /**
     * @brief method for entering data into a queue
     * meminta pengguna untuk memasukkan satu angka 
     * menyimpan ke dalam variabel num
     */
    void insert()
    {
        int num;
        cout << "enter a number: ";
        cin >> num;
        cout << endl;

        
        if ((front == 0 && rear == max - 1 ) || (front == rear + 1)) /// mengecek apakah antrian penuh 
        {
            cout << "\nqueue overflow\n"; /// menampilkan pesan overflow jika queue sudah penuh 
            return; /// keluar dari fungsi dan tidak lanjut memasukkan data ke dalam queue
        }

       
        if (front == -1) /// mengecek apakah antrian penuh
        {
            front = 0;
            rear = 0;
        }
        else 
        {
            
            if (rear == max -1) ///jika rear berada di posisi terakhir array, kembali ke awal array
                rear = 0; /// rear kembali ke indeks awal karena sudah mencapai akhir array
                else 
                    rear = rear + 1; /// Jika belum di akhir array, geser rear ke indeks berikutnya
        }
        queue_array[rear] =  num; /// menyimpan data ke posisi rera
    }


    /**
     * @brief menghapus elemen dari queue
     * fungsinya untuk menghapus elemen dari antrian (queue) menggunakan prinsip FIFO (First In First Out)
     */
    void remove()
    {
        
        if (front == -1) /// mengecek apakah antrian kosong 
        {
            cout << "queue underflow\n"; /// menampilkan pesan jika queue kosong 
            return; /// keluar dari fungsi karena tidak ada elemen yang bisa dihapus
        }
        cout << "\nthe element from the queue is: " << queue_array[front] << "\n"; /// menampilkan elemen paling depan yang queue telah keluarkan

        
        if (front == rear) /// mengecek jika antrian hanya memiliki satu elemen
        {
            front = -1; /// reset front karena queue kosong setelah penghapusan
            rear = -1; /// reset rear karena queue kosong setelah penghapusan
        }
        else 
        {
            
            if (front == max -1) ///jika elemen yang di hapus berada di posisi terakhir array, kembali ke awal array
                front = 0; /// circular queue mengembalikan front ke awal array
            else
                front = front + 1; /// menggeser front ke indeks selanjutnya 
        }
    }


    /**
     * @brief menampilkan seluruh elemen yang ada di dalam queue
     * fungsinya digunakan  untuk mencetak semua isi queue dari posisi front hingga rear
     */
    void display()
    {
        int front_position = front; /// posisi awal dari front 
        int rear_position = rear; /// posisi akhir dari rear

        
        if (front == -1) /// mengecek apakah antrian kosong 
        {
            cout << "queue is empty\n"; /// menampilkan jika queue kosong
            return; /// keluar dari fungsi karena tidak ada data 
        }
        cout << "\nelements in the queue are...\n"; /// menampilkan elemen paling depan 

        
        if (front_position <= rear_position ) /// jika front_position <= rear_position, iterasi dari front hingga rear
        {
            while (front_position <= rear_position) 
            {
                cout << queue_array[front_position] << " "; /// menampilkan elemen dari posisi saat ini
                front_position++; /// menggeser ke elemen berikutnya 
            }
            cout << endl;

        }

        /**
         * @brief menampilkan elemen pada queue circular
         * elemen di tampilkan dari front hingga akhir array
         */
        else {
        while (front_position <= max -1) 
        {
            cout << queue_array[front_position] << " "; /// menampilkan elemen dari posisi saat ini
            front_position++; /// menggeser ke elemen berikutnya 
        }
    
        /**
         * @brief menampilkan elemen dari awal array 0 hingga array
         * - mencetak elemen dari front hingga akhir array
         */
    front_position = 0;

    while (front_position <= rear_position)
    {
        cout << queue_array[front_position] << " "; /// Tampilkan elemen di posisi front_position
        front_position++; ///  Geser ke elemen berikutnya
    }
    cout << endl;
    }
    }
};


/**
    * @brief Main function to run the queue program interactively.
    * 
    * Menyediakan menu bagi pengguna untuk memilih operasi insert, remove, display, atau keluar dari program.
    * Fungsi ini menjalankan perulangan terus-menerus sampai pengguna memilih untuk keluar.
    */
int main () 
{
    queues q; /// Objek queue untuk menjalankan operasi
    char ch; /// Variabel untuk menyimpan pilihan menu dari user


    while (true)
    {
        try
        {
            cout << "menu" << endl;
            cout << "1, element insert operation" << endl;
            cout << "2, implement delate operation" << endl;
            cout << "3, display values" << endl;
            cout << "4, exit" << endl;
            cout << "enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {

                q.insert(); /// Panggil fungsi insert untuk menambah elemen
                break;
            }
            case '2':
            {
                q.remove(); /// Panggil fungsi remove untuk menghapus elemen
                break;
            }
            case '3':
            {
                q.display(); /// Panggil fungsi display untuk menampilkan elemen
                break;
            }
            case '4':
            {
                return 0; /// Keluar dari program
            }
            default:
            {
                cout << "invalid option!!" << endl;  /// Penanganan input yang tidak valid
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
}