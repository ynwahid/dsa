// Linked list implementation in Cpp
// Source: https://www.youtube.com/watch?v=VVemCxif9vg&t=2428s (Study With Student)
#include <iostream>

using namespace std;

// Deklarasi singly linked list
struct Buku{
    // Komponen/member
    string judul, pengarang;
    int tahunTerbit;
    
    Buku *next;
};

int main() {
    // Init singly linked list
    Buku *node1, *node2, *node3;

    // Instance struct
    node1 = (Buku*) malloc(sizeof(Buku));
    node2 = new Buku();
    node3 = new Buku();

    // Pengisian node 1
    node1->judul = "Matematika";
    node1->pengarang = "Ahli Matematika";
    node1->tahunTerbit = 1995;
    node1->next = node2;

    // Pengisian node 2
    node2->judul = "Dia adalah Kakakku";
    node2->pengarang = "Tere Liye";
    node2->tahunTerbit = 2009;
    node2->next = node3;

    // Pengisian node 3
    node3->judul = "Kata";
    node3->pengarang = "Geez & Aan";
    node3->tahunTerbit = 2018;
    node3->next = nullptr;

    // Print singly linked list
    Buku *current;
    current = node1;
    while (current != nullptr) {
        cout << "Judul Buku: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Tahun Terbit Buku: " << current->pengarang << endl;

        current = current->next;
    }

    return 0;
}