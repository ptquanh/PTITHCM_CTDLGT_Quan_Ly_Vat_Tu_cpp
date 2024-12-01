#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Hàm hoán đổi giá trị
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int *arr = new int[n];

    // Nhập mảng
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Tách dãy số nguyên tố
    int primeCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(arr[i]))
        {
            swap(arr[primeCount], arr[i]);
            primeCount++;
        }
    }

    // Sắp xếp từng phần
    // Sắp xếp phần số nguyên tố
    quickSort(arr, 0, primeCount - 1);

    // Sắp xếp phần còn lại
    quickSort(arr, primeCount, n - 1);

    // In kết quả
    cout << "Mang sau khi tach va sap xep:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}