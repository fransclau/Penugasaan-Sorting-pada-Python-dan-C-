#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> data_awal = {12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24};

void print_vector(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void cetak_header(const string& nama) {
    cout << "\n" << string(50, '=') << "\n";
    cout << "  " << nama << "\n";
    cout << string(50, '=') << "\n";
    cout << "  Data awal : ";
    print_vector(data_awal);
    cout << "\n" << string(50, '-') << "\n";
}

void bubble_sort(vector<int> arr) {
    cetak_header("Bubble Sort");
    int n = arr.size();
    int iterasi = 1;

    for (int i = 0; i < n - 1; i++) {
        bool ada_tukar = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ada_tukar = true;
            }
        }
        cout << "  Iterasi " << iterasi << " (pass " << (i + 1) << "): ";
        print_vector(arr);
        cout << "\n";
        iterasi++;
        if (!ada_tukar) break;
    }

    cout << "\n  Hasil Bubble Sort    : ";
    print_vector(arr);
    cout << "\n";
}

int main() {
    cout << "\n" << string(60, '-') << "\n";
    cout << "IMPLEMENTASI BUBBLE SORT\n";
    cout << "Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24\n";
    cout << string(55, '=') << "\n";

    bubble_sort(data_awal);

    vector<int> sorted_data = data_awal;
    sort(sorted_data.begin(), sorted_data.end());

    cout << "\n" << string(50, '=') << "\n";
    cout << "HASIL AKHIR\n";
    cout << string(50, '=') << "\n";
    cout << "  Data awal   : ";
    print_vector(data_awal);
    cout << "\n";
    cout << "  Hasil sort  : ";
    print_vector(sorted_data);
    cout << "\n" << string(50, '=') << "\n";

    return 0;
}