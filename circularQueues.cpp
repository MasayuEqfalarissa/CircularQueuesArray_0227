#include <iostream>
using namespace std;

class queues
{
    int front, rear, max = 5;
    int queue_array[5];

public:
    queues(){
        front = -1;
        rear = -1;
    }

    void insert(){
        int num;
        cout << "enter a number: ";
        cin >> num;
        cout << endl;

    
        //cek apakah antrian penuh 
        if ((front == 0 && rear == max - 1 ) || (front == rear + 1)){
            cout << "\nqueue overflow\n";
            return;
        }

        //cek apakah antrian penuh
        if (front == -1){
            front = 0;
            rear = 0;
        }
        else {
            //jika rear berada di posisi terakhir array, kembali ke awal array
            if (rear == max -1)
                rear = 0;
                else 
                    rear = rear + 1;
        }
        
    }
}