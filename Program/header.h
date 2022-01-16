#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include<bits/stdc++.h>

void createArray(int arrSort[], int jumlah);
void printArray(int arrSort[], int jumlah);
void swap(int* a, int* b);
int partition (int arrSort[], int low, int high);
void quickSort(int arrSort[], int low, int high);
void bubbleSort(int arrSort[], int jumlah);

void menuInput();
void mainmenu();
void pilih(int pilih, int arrSort[],int jumlah);

#endif // HEADER_H_INCLUDED
