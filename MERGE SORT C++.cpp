#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ===================================================================================
// Merge Sort Implementation in C++
// Number of data used: 15
// Data used: 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24
// ===================================================================================

std::vector<int> data_awal = {12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24};

// ===================================================================================

void print_vector(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void cetak_header(const std::string& nama) {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "  " << nama << "\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "  Data awal : ";
    print_vector(data_awal);
    std::cout << "\n" << std::string(50, '-') << "\n";
}

// ===================================================================================
// Merge Sort = sorting that works by dividing data
// into two parts repeatedly until each part contains only one element
// Complexity: O(n log n)
// ===================================================================================

int iterasi_merge = 0;  // Merge iteration counter

void merge(std::vector<int>& arr, int kiri, int tengah, int kanan) {
    // Create copies of two sub-arrays
    std::vector<int> L(arr.begin() + kiri, arr.begin() + tengah + 1);
    std::vector<int> R(arr.begin() + tengah + 1, arr.begin() + kanan + 1);

    int i = 0, j = 0;
    int k = kiri;

    while (i < (int)L.size() && j < (int)R.size()) {  // Compare and merge elements from L and R
        if (L[i] <= R[j]) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }

    // Copy remaining elements not yet inserted
    while (i < (int)L.size()) {
        arr[k] = L[i]; i++; k++;
    }
    while (j < (int)R.size()) {
        arr[k] = R[j]; j++; k++;
    }

    iterasi_merge++;
    std::cout << "  Iterasi " << iterasi_merge << " (merge [" << kiri << ".." << tengah
              << "] & [" << (tengah + 1) << ".." << kanan << "]): ";
    print_vector(arr);
    std::cout << "\n";
}

void merge_sort(std::vector<int>& arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;          // Midpoint
        merge_sort(arr, kiri, tengah);             // Recurse left side
        merge_sort(arr, tengah + 1, kanan);        // Recurse right side
        merge(arr, kiri, tengah, kanan);           // Merge two parts
    }
}

void jalankan_merge_sort(std::vector<int>& arr) {
    cetak_header("MERGE SORT");
    iterasi_merge = 0;                             // Reset counter
    merge_sort(arr, 0, (int)arr.size() - 1);
    std::cout << "\n  Hasil Merge Sort     : ";
    print_vector(arr);
    std::cout << "\n";
}

// ===================================================================================
// Running Merge Sort
// ===================================================================================
int main() {
    std::cout << "\n" << std::string(110, '-') << "\n";
    std::cout << "IMPLEMENTASI MERGE SORT\n";
    std::cout << "Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24\n";
    std::cout << std::string(55, '=') << "\n";

    std::vector<int> data_copy = data_awal;
    jalankan_merge_sort(data_copy);

    std::vector<int> data_sorted = data_awal;
    std::sort(data_sorted.begin(), data_sorted.end());

    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "HASIL AKHIR\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "  Data awal   : ";
    print_vector(data_awal);
    std::cout << "\n  Hasil sort  : ";
    print_vector(data_sorted);
    std::cout << "\n" << std::string(50, '=') << "\n";

    return 0;
}