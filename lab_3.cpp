#include <iostream>
#include <Windows.h>

using namespace std;

void printMatrix(int* matrix, int size, int helper) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            destCoord.X = j * 4 + 50;
            destCoord.Y = i + helper;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(matrix + i * size + j) << " ";
        }
        cout << endl;
    }
}

void quicksort(int* matrix, int* end, int* begin) {
    int pivotElement;
    int* start = begin;
    int* finish = end;
    pivotElement = *(begin + (end - begin) / 2);
    while (start < finish) {
        while (*start < pivotElement) start++;
        while (*finish > pivotElement) finish--;
        if (start <= finish) {
            std::swap(*start, *finish);
            start++;
            finish--;
        }
    }
    if (begin < finish) quicksort(matrix, finish, begin);
    if (start < end) quicksort(matrix, end, start);
}

void fillSnake(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = top; i <= bottom; i++) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        left++;

        for (int i = bottom; i >= top; i--) {
            int* num = matrix + i * n + left;
            *num = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        left++;
    }
}
void fillSpiral(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(matrix + top * n + i) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            *(matrix + i * n + right) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        right--;


        for (int i = right; i >= left; i--) {
            *(matrix + bottom * n + i) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            *(matrix + i * n + left) = rand() % (n * n) + 1;
            printMatrix(matrix, n, 0);
            Sleep(200);
        }
        left++;
    }
    printMatrix(matrix, n, 0);
}
void swap_quarters_a(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + i * N + j + middle) = *(temp + i * N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i + middle) * N + j) = *(temp + i * N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + i * N + (j - middle)) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j) = *(temp + i * N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 2);
}
void swap_quarters_b(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle && j < middle) {
                *(matrix + (i + middle) * N + j + middle) = *(temp + i * N + j);
            }
            else if (i < middle && j >= middle) {
                *(matrix + (i + middle) * N + j - middle) = *(temp + i * N + j);
            }
            else if (i >= middle && j >= middle) {
                *(matrix + (i - middle) * N + j - middle) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j + middle) = *(temp + i * N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 2);
}
void swap_quarters_c(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < middle) {
                *(matrix + (i + middle) * N + j) = *(temp + i * N + j);
            }
            else {
                *(matrix + (i - middle) * N + j) = *(temp + i * N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 2);
}

void swap_quarters_d(int* matrix, int N) {
    int* temp = new int[N * N];
    int middle = N / 2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(temp + i * N + j) = *(matrix + i * N + j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < middle) {
                *(matrix + i * N + j + middle) = *(temp + i * N + j);
            }
            else {
                *(matrix + i * N + j - middle) = *(temp + i * N + j);
            }
        }
    }
    printMatrix(matrix, N, N + 2);
}
void enlarge_each_element(int* matrix, int N) {
    int enlarge_num;

    cout << "Enter any number: ";
    cin >> enlarge_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) += enlarge_num;
        }
    }
    printMatrix(matrix, N, N + 22);
}
void reduce_each_element(int* matrix, int N) {
    int reduce_num;

    cout << "Enter any number: ";
    cin >> reduce_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) -= reduce_num;
        }
    }
    printMatrix(matrix, N, N + 22);
}
void divide_each_element(int* matrix, int N) {
    int divide_num;

    cout << "Enter any number: ";
    cin >> divide_num;
    if (divide_num == 0) {
        cout << "You can not divide by zero" << endl;
        return;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) /= divide_num;
        }
    }
    printMatrix(matrix, N, N + 22);
}

void multiply_each_element(int* matrix, int N) {
    int multiply_num;

    cout << "Enter any number: ";
    cin >> multiply_num;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) *= multiply_num;
        }
    }
    printMatrix(matrix, N, N + 22);
}

void start(int* matrix, int size) {
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            *(matrix + i * size + j) = 1;
        }
    }
}
int main() {
    srand(time(0));
    int size, answer, answerFill, answerBlockMove, answerNumber;
    cout << "Choose the size of a matrix (6, 8, 10): ";
    cin >> size;
    int* matrix = new int[size * size];

    while (true) {
        cout << "Choose how you want to fill the matrix: " << endl << "1. Spiral Pattern;" << endl << "2. Snake Pattern." << endl;
        cin >> answerFill;
        start(matrix, size);

        switch (answerFill) {
        case 1:
            fillSpiral(matrix, size);
            break;
        case 2:
            fillSnake(matrix, size);
            break;
        }

        cout << "Choose how you want to move blocks of the matrix: " << endl << "1. Square Pattern;" << endl << "2. Cross Pattern;" << endl << "3. Vertically; " << endl << "4. Horizontally." << endl;
        cin >> answerBlockMove;

        switch (answerBlockMove) {
        case 1:
            swap_quarters_a(matrix, size);
            break;
        case 2:
            swap_quarters_b(matrix, size);
            break;
        case 3:
            swap_quarters_c(matrix, size);
            break;
        case 4:
            swap_quarters_d(matrix, size);
            break;
        }

        quicksort(matrix, matrix + size * size - 1, matrix);
        printMatrix(matrix, size, size + 10);


        cout << "What do you want to do with the elements of the matix: " << endl << "1. To reduce each element;" << endl << "2. To enlarge each element;" << endl << "3. To multiply each element;" << endl << "4. To divide each element." << endl;
        cin >> answerNumber;

        switch (answerNumber) {
        case 1:
            reduce_each_element(matrix, size);
            break;
        case 2:
            enlarge_each_element(matrix, size);
            break;
        case 3:
            multiply_each_element(matrix, size);
            break;
        case 4:
            divide_each_element(matrix, size);
            break;
        }
    }
    return 0;
}
