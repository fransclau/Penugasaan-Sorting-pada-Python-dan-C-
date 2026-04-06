# ===================================================================================
# Implementasi Quick Sort dalam Python
# Jumlah data yang digunakan:  15
# Data yang digunakan : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24
# ===================================================================================
 
data_awal = [12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24]
 
# ===================================================================================
 
def cetak_header(nama):
    print("\n" + "--" * 50)
    print(f"  {nama}")
    print("=" * 50)
    print(f"  Data awal : {data_awal}")
    print("-" * 50)
 
# ===================================================================================
# Quick Sort = memilih Pivot dan pengurutan yang bekerja dengan memilih
# satu elemen sebagai pivot, lalu membagi elemen lain menjadi dua bagian:
# yang lebih kecil dari pivot dan yang lebih besar.
# Kompleksitas : O(n log n) rata-rata, O(n²) worst case
# ===================================================================================
 
iterasi_quick = [0]   # Pakai list agar bisa diubah di dalam fungsi rekursif
 
def quick_sort(arr, low, high):
    if low < high:
        pi = partisi(arr, low, high)   # Dapatkan posisi pivot setelah partisi
        quick_sort(arr, low, pi - 1)   # Rekursi sisi kiri pivot
        quick_sort(arr, pi + 1, high)  # Rekursi sisi kanan pivot
 
def partisi(arr, low, high):
    pivot = arr[high]                  # Pivot = elemen terakhir
    i = low - 1                        # Indeks elemen lebih kecil dari pivot
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]   # Tukar: dipindahkan ke sisi kiri
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Menempatkan pivot
    iterasi_quick[0] += 1
    print(f"  Iterasi {iterasi_quick[0]:2d} (pivot={pivot:2d}, range [{low}..{high}]): {arr}")
    return i + 1
 
def jalankan_quick_sort(arr):
    cetak_header("QUICK SORT")
    iterasi_quick[0] = 0               # Reset counter iterasi
    quick_sort(arr, 0, len(arr) - 1)
    print(f"\n  ✅ Hasil Quick Sort     : {arr}")
 
# ===================================================================================
# Running Quick Sort
# ===================================================================================
if __name__ == "__main__":
    print("\n" + "==" * 55)
    print("IMPLEMENTASI QUICK SORT")
    print("Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24")
    print("=" * 55)
 
    jalankan_quick_sort(data_awal[:])
 
    print("\n" + "=" * 50)
    print("HASIL AKHIR")
    print("=" * 50)
    print(f"  Data awal   : {data_awal}")
    print(f"  Hasil sort  : {sorted(data_awal)}")
    print("=" * 50)