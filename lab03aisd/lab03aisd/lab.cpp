#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

//���������� ������
void bubble_sort(int* const arr, const int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = j + 1; i < n; i++) {
            if (arr[i] < arr[j]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}

//���������� ������� �������
void ShellSort(int n, int mass[])
{
    int min;
    int tmp;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
            min = (mass[j] < mass[min]) ? j : min;
        if (i != min) {
            tmp = mass[i];
            mass[i] = mass[min];
            mass[min] = tmp;
        }
    }
}

//���������� �������
void SelectionSort(int A[], int n)
{
    int count, key;
    for (int i = 0; i < n - 1; i++)
    {
        count = A[i]; key = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[key]) key = j;
        if (key != i)
        {
            A[i] = A[key];
            A[key] = count;
        }
    }
}

//������� ����������
void quickSort(int* array, int low, int high)
{
    int i = low;
    int j = high;
    int ot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < ot)
            i++;
        while (array[j] > ot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

int main() {

    setlocale(LC_ALL, "Russian");

    int menufor = 1;

    system("cls");



    char n;
    clock_t start_shaker, start_bubble, end_shaker, end_bubble, start_selection, end_selection, start_fast, end_fast;
    double time_bubble, time_shaker, time_selection, time_fast;

    int arr_n;
    cout << " ������� ���������� ��������� � �������\n";
    cin >> arr_n;

    //��������� �������
    static int* arrA = new int[arr_n];
    for (int i = 0; i < arr_n; i++) {
        arrA[i] = rand() % 99;
    }

    //����� �������
    for (int i = 0; i < arr_n; i++) {
        cout << arrA[i] << " ";
    }

    //�������� � ����������� ��������
    static int* arrB = new int[arr_n];
    static int* arrC = new int[arr_n];
    static int* arrD = new int[arr_n];
    static int* arrE = new int[arr_n];
    for (int i = 0; i < arr_n; i++) {
        arrB[i] = arrA[i];
        arrC[i] = arrA[i];
        arrD[i] = arrA[i];
        arrE[i] = arrA[i];
    }



    //������������� ����������------------------------------------------------------------------------------------------------------------------
    start_bubble = clock();
    bubble_sort(arrB, arr_n);
    cout << "\n ��������������� ������ ������:\n";
    for (int i = 0; i < arr_n; i++) {
        cout << arrB[i] << " ";
    }
    end_bubble = clock();
    unsigned int bubble_sort_time = end_bubble - start_bubble;

    //������� ����������-----------------------------------------------------------------------------------------------------------------------
    start_fast = clock();
    quickSort(arrE, 0, arr_n);
    cout << "\n��������������� ��������� ������:\n";
    end_fast = clock();
    for (int i = 1; i < arr_n + 1; i++) {
        cout <<arrE[i] << " ";
    }
    unsigned int quik_sort_time = end_fast - start_fast;

    //���������� ��������-----------------------------------------------------------------------------------------
    start_shaker = clock();
    ShellSort(arr_n, arrC);
    cout << "\n��������������� �������� ������:\n";
    for (int i = 0; i < arr_n; i++) {
        cout << arrC[i] << " ";
    }
    end_shaker = clock();
    unsigned int Shell_sort_time = end_shaker - start_shaker;
    
    //���������� ������-----------------------------------------------------------------------------------------------------------------
    start_selection = clock();
    SelectionSort(arrD, arr_n);
    cout << "\n��������������� ������� ������:\n";
    for (int i = 0; i < arr_n; i++) {
        cout<< arrD[i] << " ";
    }
    end_selection = clock();
    unsigned int Selection_sort_time = end_selection - start_selection;




    cout << "\n����� ���������� ������:" << bubble_sort_time << "���.\n";
    cout << "\n����� ���������� ��������:" << Shell_sort_time << "���.\n";
    cout << "\n����� ���������� �������:" << Selection_sort_time << "���.\n";
    cout << "\n����� ���������� �������:" << quik_sort_time << "���.\n\n"; \

        system("pause");

}