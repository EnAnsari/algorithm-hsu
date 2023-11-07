#include <iostream>

using namespace std;

void merge(int array[], int name[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    auto *leftName = new int[subArrayOne], *rightName = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i], leftName[i] = name[left + i];
    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = array[mid + 1 + j], rightName[j] = name[mid + 1 + j];
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            name[indexOfMergedArray] = leftName[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            name[indexOfMergedArray] = rightName[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        name[indexOfMergedArray] = leftName[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        name[indexOfMergedArray] = rightName[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
    delete[] rightName;
    delete[] leftName;
}

void mergeSort(int array[], int name[], int const begin, int const end) {
    if (begin >= end) return; 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, name, begin, mid);
    mergeSort(array, name, mid + 1, end);
    merge(array, name, begin, mid, end);
}

int main() {

    int n, temp;
    cout << "Enter number of persons: ";
    cin >> n;

    int pay[n] = {0}, name[n];

    for(int i = 0; i < n; i++) {
        name[i] = i;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            cout << "p" << i << " has to pay ? Rs to p" << j << " : ";
            cin >> temp;
            pay[i] -= temp;
            pay[j] += temp;
        }
    }

    mergeSort(pay, name, 0, n - 1);

    for(int i = 0, j = n - 1; pay[i] < 0;) {
        if(pay[i] * (-1) < pay[j]) {
            cout << "P" << name[i] << " pays " << pay[i] * (-1) << " to Rs to P" << name[j] << endl;
            pay[j] -= pay[i] * (-1);
            i++;
        }
        else {
            cout << "P" << name[i] << " pays " << pay[j] << " to Rs to P" << name[j] << endl;
            pay[i] += pay[j];
            j--;
        }
    }

    return 0;
}