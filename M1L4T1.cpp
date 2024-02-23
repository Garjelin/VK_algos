#include <iostream>
#include <vector>

using namespace std;

// Функция для слияния двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные массивы
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Копируем данные во временные массивы leftArray[] и rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    // Слияние временных массивов обратно в основной массив arr[]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = left; // Индекс объединенного подмассива

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы leftArray[], если они есть
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы rightArray[], если они есть
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Функция для итеративной сортировки слиянием
void mergeSort(vector<int>& arr, int n) {
    // Размер подмассива увеличивается от 1 до n / 2
    for (int currentSize = 1; currentSize <= n - 1; currentSize *= 2) {
        // Перебираем массив от начала до конца с шагом в два текущих размера
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currentSize) {
            // Находим конец левого подмассива
            int middle = min(leftStart + currentSize - 1, n - 1);

            // Находим начало правого подмассива
            int rightEnd = min(leftStart + 2 * currentSize - 1, n - 1);

            // Сливаем два подмассива
            merge(arr, leftStart, middle, rightEnd);
        }
    }
}

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
