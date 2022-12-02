#include <iostream>

template <typename T>
void bubbleSort(T arr[], int sizeOfArray){
    for (int j = 0; j < sizeOfArray - 1; j++) { // sizeOfArray - 1, т.к достаточно пройтись n-1 раз для того, чтобы целиком отсортировать массив (n - число элементов)

        for (int i = 0; i < sizeOfArray - 1; i++) { // sizeOfArray - 1, т.к последний элемент не с чем сравнивать

            if (arr[i] > arr[i + 1]) { // если элемент больше последующего, меняем их местами
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }

    for (int i = 0; i < sizeOfArray; i++){
        std::cout << arr[i] << " "; // печатаем отсортированный массив
    }

}

template <typename T>
void insertionSort(T arr[], int sizeOfArray){
    for (int i = 1; i < sizeOfArray; i++) { // начинаем цикл с 1 элемента, т.к нулевой условно отсортирован

        int key = arr[i]; // храним значение i-го элемента
        int j = i - 1; // устанавливаем указатель i на последний элемент отсортированной части

        while (j >= 0 && arr[j] > key) { // сравниваем условно отсортированный (предыдущий) элемент с проверяемым: если он больше, то записываем на его место проверяемый и наоборот
            arr[j+1] = arr[j];
            arr[j] = key;
            j--;
        }
    }

    for (int i = 0; i < sizeOfArray; i++){
        std::cout << arr[i] << " "; // печатаем отсортированный массив
    }
}

template <typename T>
void selectionSort(T arr[], int sizeOfArray){
    for (int i = 0; i < sizeOfArray - 1; i++) {

        int min_index = i; // храним индекс минимального элемента изначально равного i
        for (int j = i; j < sizeOfArray; j++) {
            if (arr[j] < arr[min_index]) {  // сравниваем j-й элемент цикла с минимальным элементом
                min_index = j;
            }


        }
        if (i != min_index) { // если индекс эл-та не равен минимальному, обмениваем их значения
            std::swap(arr[i], arr[min_index]);
        }
    }

    for (int i = 0; i < sizeOfArray; i++) { // выводим отсортированный массив
        std::cout << arr[i] << " ";
    }
}


int main() {
    int arr[] = {10,4,3,9,2};
    int sizeOfArray = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < sizeOfArray; i++){
        std::cout << arr[i] << " "; // печатаем исходный массив
    }
    std::cout << std::endl;

    bubbleSort(arr, sizeOfArray);
    insertionSort(arr, sizeOfArray);
    selectionSort(arr, sizeOfArray);


    return 0;
}
