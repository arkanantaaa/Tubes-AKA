#include "header.h"
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void createArray(int arrSort[], int jumlah){
    for (int i=0; i<jumlah;i++){
        arrSort[i] = rand()%10000+1;
    }
}

void printArray(int arrSort[], int jumlah){
    cout << "\n\nArray Anda adalah : " << endl;
    for (int i=0; i<jumlah; i++){
        cout << arrSort[i] << endl;
    }
}


void insert(Node* &node, int newkey)
{
    if (node == NULL){
		node = new Node;
		node-> key = newkey;
		node -> left = NULL;
		node -> right = NULL;
		return;
    }
    else if (newkey < node->key){
        insert(node->left, newkey);
    }
    else
        insert(node->right, newkey);
}

void storeSorted(Node *root, int arrSort[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arrSort, i);
        arrSort[i++] = root->key;
        storeSorted(root->right, arrSort, i);
    }
}

// Using bubble sort
void bubbleSort(int arrSort[], int jumlah){
    for (int i = jumlah-1; i>=0; i--){
        for (int j=1; j<=i;j++){
            if (arrSort[j-1] > arrSort[j]){
                int temp = arrSort[j-1];
                arrSort[j-1] = arrSort[j];
                arrSort[j] = temp;
            }
        }
    }
}


// Using Tree Sort
void treeSort(int arrSort[], int jumlah)
{
    struct Node *root = NULL;
    for (int i=0; i<jumlah; i++)
        insert(root, arrSort[i]);
    int i = 0;
    storeSorted(root, arrSort, i);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arrSort[], int low, int high)
{
    int pivot = arrSort[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arrSort[j] <= pivot)
        {
            i++;
            swap(&arrSort[i], &arrSort[j]);
        }
    }
    swap(&arrSort[i + 1], &arrSort[high]);
    return (i + 1);
}

// QuickSort

void quickSort(int arrSort[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arrSort, low, high);
        quickSort(arrSort, low, pi - 1);
        quickSort(arrSort, pi + 1, high);
    }
}


void menuInput(){
    cout << "Masukkan indeks array (N) :  ";
}

void mainmenu(){
    cout << "---- KELOMPOK 4 ----" << endl;
    cout << "Pilih Menu : " << endl;
    cout << "1. Isi Array" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Binary Tree Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Reset" << endl;
    cout << "0. Close program" << endl;
    cout << "Pilih Menu : ";
}

void pilih(int pilihan, int arrSort[],int jumlah){
    switch (pilihan){
        case 1:
            printArray(arrSort,jumlah);
            break;
        case 2:{
            auto t1 = chrono::high_resolution_clock::now();
            bubbleSort(arrSort,jumlah);
            auto t2 = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
            cout << "Running Time Bubble sort dengan " << jumlah <<" isi array = " << duration << " milisecond " << endl;
            }break;
        case 3:{
            auto t3 = chrono::high_resolution_clock::now();
            treeSort(arrSort,jumlah);
            auto t4 = chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration_cast<chrono::milliseconds>(t4-t3).count();
            cout << "Running Time Binary Tree sort dengan " << jumlah <<" isi array = " << duration2 << " milisecond " << endl;
            }break;
        case 4:{
            auto t5 = chrono::high_resolution_clock::now();
            quickSort(arrSort, 0,jumlah-1);
            auto t6 = chrono::high_resolution_clock::now();
            auto duration3 = chrono::duration_cast<chrono::milliseconds>(t6-t5).count();
            cout << "Running Time Quick sort dengan " << jumlah <<" isi array = " << duration3 << " milisecond " << endl;
            }break;
        case 5:
            createArray(arrSort,jumlah);
            break;
        case 0:
            break;
        default:
            cout << "Masukkan salah" << endl;
            break;
    }
}
