#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> data_awal = {12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24};

int iterasi_quick = 0;

void cetak_vektor(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void cetak_header(const string& nama) {
    cout << "\n" << string(100, '-') << "\n";
    cout << "  " << nama << "\n";
    cout << string(50, '=') << "\n";
    cout << "  Data awal : ";
    cetak_vektor(data_awal);
    cout << "\n";
    cout << string(50, '-') << "\n";
}

int partisi(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    iterasi_quick++;
    cout << "  Iterasi " << setw(2) << iterasi_quick
         << " (pivot=" << setw(2) << pivot
         << ", range [" << low << ".." << high << "]): ";
    cetak_vektor(arr);
    cout << "\n";
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partisi(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void jalankan_quick_sort(vector<int> arr) {
    cetak_header("QUICK SORT");
    iterasi_quick = 0;
    quick_sort(arr, 0, (int)arr.size() - 1);
    cout << "\n  Hasil Quick Sort     : ";
    cetak_vektor(arr);
    cout << "\n";
}

int main() {
    cout << "\n" << string(110, '=') << "\n";
    cout << "IMPLEMENTASI QUICK SORT\n";
    cout << "Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24\n";
    cout << string(55, '=') << "\n";

    jalankan_quick_sort(data_awal);

    vector<int> hasil_sort = data_awal;
    sort(hasil_sort.begin(), hasil_sort.end());

    cout << "\n" << string(50, '=') << "\n";
    cout << "HASIL AKHIR\n";
    cout << string(50, '=') << "\n";
    cout << "  Data awal   : ";
    cetak_vektor(data_awal);
    cout << "\n";
    cout << "  Hasil sort  : ";
    cetak_vektor(hasil_sort);
    cout << "\n";
    cout << string(50, '=') << "\n";

    return 0;
}