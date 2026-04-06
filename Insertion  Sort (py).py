# ===================================================================================
# Implementasi Insertion Sort dalam Python
# Jumlah data yang digunakan:  15
# Data yang digunakan : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24
# ===================================================================================
 
data_awal = [12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24]
 
# ===================================================================================
 
def cetak_header(nama):
    print("\n" + "=" * 50)
    print(f"  {nama}")
    print("=" * 50)
    print(f"  Data awal : {data_awal}")
    print("-" * 50)
 
# ===================================================================================
# Insertion Sort = mengambil satu elemen dan disisipkan
# ke posisi yang tepat di bagian kiri yang sudah terurut
# Kompleksitas : O(n²)
# ===================================================================================
 
def insertion_sort(arr):
    cetak_header("INSERTION SORT")
    n = len(arr)
 
    for i in range(1, n):
        kunci = arr[i]                     # Elemen yang akan disisipkan
        j = i - 1
        # Geser elemen yang lebih besar ke kanan
        while j >= 0 and arr[j] > kunci:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = kunci                 # Sisipkan kunci ke posisi yang tepat
        print(f"  Iterasi {i:2d} (sisip {kunci:2d}): {arr}")
 
    print(f"\n  ✅ Hasil Insertion Sort : {arr}")
 
# ===================================================================================
# Running Insertion Sort
# ===================================================================================
if __name__ == "__main__":
    print("\n" + "--" * 55)
    print("IMPLEMENTASI INSERTION SORT")
    print("Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24")
    print("=" * 55)
 
    insertion_sort(data_awal[:])
 
    print("\n" + "=" * 50)
    print("HASIL AKHIR")
    print("=" * 50)
    print(f"  Data awal   : {data_awal}")
    print(f"  Hasil sort  : {sorted(data_awal)}")
    print("=" * 50)