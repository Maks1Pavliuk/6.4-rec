#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h> 
using namespace std;

// Рекурсивна функція для створення масиву
void createArrayRecursively(vector<int>& array, int n) {
    if (n == 0) return;
    int value;
    cin >> value;
    array.push_back(value);
    createArrayRecursively(array, n - 1);
}

// Рекурсивна функція для виведення масиву
void printArrayRecursively(const vector<int>& array, int index = 0) {
    if (index >= array.size()) {
        cout << endl;
        return;
    }
    cout << array[index] << " ";
    printArrayRecursively(array, index + 1);
}

// Рекурсивна функція для пошуку мінімального за модулем елемента
int findMinAbsElementRecursively(const vector<int>& array, int index = 0, int minAbs = INT_MAX) {
    if (index >= array.size()) return minAbs;
    minAbs = min(minAbs, abs(array[index]));
    return findMinAbsElementRecursively(array, index + 1, minAbs);
}

// Рекурсивна функція для пошуку суми після першого нуля
int sumAfterFirstZeroRecursively(const vector<int>& array, int index = 0, bool zeroFound = false) {
    if (index >= array.size()) return 0;
    if (zeroFound) return abs(array[index]) + sumAfterFirstZeroRecursively(array, index + 1, true);
    if (array[index] == 0) return sumAfterFirstZeroRecursively(array, index + 1, true);
    return sumAfterFirstZeroRecursively(array, index + 1, false);
}

// Рекурсивна функція для перестановки елементів
void transformArrayRecursively(vector<int>& array, vector<int>& evenElements, vector<int>& oddElements, int index = 0) {
    if (index >= array.size()) {
        for (int i = 0; i < evenElements.size(); i++) array[i] = evenElements[i];
        for (int i = 0; i < oddElements.size(); i++) array[evenElements.size() + i] = oddElements[i];
        return;
    }
    if (index % 2 == 0) evenElements.push_back(array[index]);
    else oddElements.push_back(array[index]);
    transformArrayRecursively(array, evenElements, oddElements, index + 1);
}

int main() {
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251); 
    int n;
    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    vector<int> array;

    // Створення масиву
    createArrayRecursively(array, n);

    // Виведення початкового масиву
    cout << "Початковий масив: ";
    printArrayRecursively(array);

    // Знаходження мінімального за модулем елемента
    int minAbsElement = findMinAbsElementRecursively(array);
    cout << "Мінімальний за модулем елемент: " << minAbsElement << endl;

    // Обчислення суми модулів елементів після першого нуля
    int sumModules = sumAfterFirstZeroRecursively(array);
    cout << "Сума модулів елементів після першого нуля: " << sumModules << endl;

    // Перетворення масиву
    vector<int> evenElements, oddElements;
    transformArrayRecursively(array, evenElements, oddElements);

    // Виведення перетвореного масиву
    cout << "Перетворений масив: ";
    printArrayRecursively(array);

    return 0;
}
