#include <iostream>
#include <vector>
#include <cmath>
#include <Windows.h> 
using namespace std;

// ���������� ������� ��� ��������� ������
void createArrayRecursively(vector<int>& array, int n) {
    if (n == 0) return;
    int value;
    cin >> value;
    array.push_back(value);
    createArrayRecursively(array, n - 1);
}

// ���������� ������� ��� ��������� ������
void printArrayRecursively(const vector<int>& array, int index = 0) {
    if (index >= array.size()) {
        cout << endl;
        return;
    }
    cout << array[index] << " ";
    printArrayRecursively(array, index + 1);
}

// ���������� ������� ��� ������ ���������� �� ������� ��������
int findMinAbsElementRecursively(const vector<int>& array, int index = 0, int minAbs = INT_MAX) {
    if (index >= array.size()) return minAbs;
    minAbs = min(minAbs, abs(array[index]));
    return findMinAbsElementRecursively(array, index + 1, minAbs);
}

// ���������� ������� ��� ������ ���� ���� ������� ����
int sumAfterFirstZeroRecursively(const vector<int>& array, int index = 0, bool zeroFound = false) {
    if (index >= array.size()) return 0;
    if (zeroFound) return abs(array[index]) + sumAfterFirstZeroRecursively(array, index + 1, true);
    if (array[index] == 0) return sumAfterFirstZeroRecursively(array, index + 1, true);
    return sumAfterFirstZeroRecursively(array, index + 1, false);
}

// ���������� ������� ��� ������������ ��������
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
    cout << "������ ������� �������� � �����: ";
    cin >> n;

    vector<int> array;

    // ��������� ������
    createArrayRecursively(array, n);

    // ��������� ����������� ������
    cout << "���������� �����: ";
    printArrayRecursively(array);

    // ����������� ���������� �� ������� ��������
    int minAbsElement = findMinAbsElementRecursively(array);
    cout << "̳�������� �� ������� �������: " << minAbsElement << endl;

    // ���������� ���� ������ �������� ���� ������� ����
    int sumModules = sumAfterFirstZeroRecursively(array);
    cout << "���� ������ �������� ���� ������� ����: " << sumModules << endl;

    // ������������ ������
    vector<int> evenElements, oddElements;
    transformArrayRecursively(array, evenElements, oddElements);

    // ��������� ������������� ������
    cout << "������������ �����: ";
    printArrayRecursively(array);

    return 0;
}
