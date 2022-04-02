// Linked list implementation in Cpp
// Source: https://www.youtube.com/watch?v=VVemCxif9vg&t=2428s (Study With Student)
#include <iostream>

using namespace std;

// Deklarasi single linked list
struct Buku{
    // Komponen/member
    string judul, pengarang;
    int tahunTerbit;
    
    Buku *next;
};

Buku *head, *tail, *current, *newNode, *del;

// Init single linked list
void createSingleLinkedList(string judul, string pengarang, int tahunTerbit) {
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
    head->next = nullptr;
    tail = head;
}

// Tambah node di awal linked list
void addFirst(string judul, string pengarang, int tahunTerbit) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = head;
    head = newNode;
}

// Tambah node di awal linked list
void addLast(string judul, string pengarang, int tahunTerbit) {
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tahunTerbit;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
}

// Remove first
void removeFirst() {
    del = head;
    head = head->next;
    delete del;
}

// Remove last
void removeLast() {
    del = tail;
    current = head;
    while (current->next != tail) {
        current = current->next;
    }
    tail = current;
    tail->next = nullptr;
    delete del;
}

// Ubah nilai di node awal linked list
void changeFirst(string judul, string pengarang, int tahunTerbit) {
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tahunTerbit;
}

// Ubah nilai di node awal linked list
void changeLast(string judul, string pengarang, int tahunTerbit) {
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tahunTerbit;
}

// Print single linked list
void printSingleLinkedList(){
    current = head;
    while (current != nullptr) {
        cout << "Judul Buku: " << current->judul << endl;
        cout << "Pengarang: " << current->pengarang << endl;
        cout << "Tahun Terbit Buku: " << current->tahunTerbit << endl;
        cout << endl;
        current = current->next;
    }
}

int main() {
    // Init linked list
    cout << "Inisialisasi linked list:" << endl;
    createSingleLinkedList("Kata", "Geez & Aan", 2018);
    printSingleLinkedList();
    cout << endl;
    
    // Insert element to first node
    cout << "Menambahkan node baru di kiri:" << endl;
    addFirst("Dia adalah Kakakku", "Tere Liye", 2009);
    printSingleLinkedList();
    cout << endl << endl;

    // Insert element to last node
    cout << "Menambahkan node baru di kanan:" << endl;
    addLast("Aroma Karsa", "Dee Lestari", 2018);
    printSingleLinkedList();
    cout << endl << endl;

    // Delete first node
    cout << "Menghapus node awal:" << endl;
    removeFirst();
    printSingleLinkedList();
    cout << endl << endl;

    // Insert element to last node
    cout << "Menambahkan node baru di kanan:" << endl;
    addLast("11.11", "Fiersa Besari", 2018);
    printSingleLinkedList();
    cout << endl << endl;

    // Delete last node
    cout << "Menghapus node akhir:" << endl;
    removeLast();
    printSingleLinkedList();
    cout << endl << endl;

    // Insert element to last node
    cout << "Mengubah nilai node pertama:" << endl;
    changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);
    printSingleLinkedList();
    cout << endl << endl;

    return 0;
};