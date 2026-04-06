# ===================================================================================
# Implementasi Merge Sort dalam Python
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
# Merge Sort = pengurutan yang bekerja dengan cara membagi data
# menjadi dua bagian secara berulang hingga setiap bagian hanya berisi satu elemen
# Kompleksitas : O(n log n)
# ===================================================================================
 
iterasi_merge = [0]   # Counter iterasi merge
 
def merge_sort(arr, kiri, kanan):
    if kiri < kanan:
        tengah = (kiri + kanan) // 2           # Titik tengah
        merge_sort(arr, kiri, tengah)          # Rekursi sisi kiri
        merge_sort(arr, tengah + 1, kanan)     # Rekursi sisi kanan
        merge(arr, kiri, tengah, kanan)        # Gabungkan dua bagian
 
def merge(arr, kiri, tengah, kanan):
    # Buat salinan dua sub-array
    L = arr[kiri:tengah + 1]
    R = arr[tengah + 1:kanan + 1]
 
    i = j = 0
    k = kiri
 
    while i < len(L) and j < len(R):   # Bandingkan dan gabungkan elemen dari L dan R
        if L[i] <= R[j]:
            arr[k] = L[i]; i += 1
        else:
            arr[k] = R[j]; j += 1
        k += 1
 
    # Salin sisa elemen yang belum masuk
    while i < len(L):
        arr[k] = L[i]; i += 1; k += 1
    while j < len(R):
        arr[k] = R[j]; j += 1; k += 1
 
    iterasi_merge[0] += 1
    print(f"  Iterasi {iterasi_merge[0]:2d} (merge [{kiri}..{tengah}] & [{tengah+1}..{kanan}]): {arr}")
 
def jalankan_merge_sort(arr):
    cetak_header("MERGE SORT")
    iterasi_merge[0] = 0               # Reset counter
    merge_sort(arr, 0, len(arr) - 1)
    print(f"\n  ✅ Hasil Merge Sort     : {arr}")
 
# ===================================================================================
# Running Merge Sort
# ===================================================================================
if __name__ == "__main__":
    print("\n" + "--" * 55)
    print("IMPLEMENTASI MERGE SORT")
    print("Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24")
    print("=" * 55)
 
    jalankan_merge_sort(data_awal[:])
 
    print("\n" + "=" * 50)
    print("HASIL AKHIR")
    print("=" * 50)
    print(f"  Data awal   : {data_awal}")
    print(f"  Hasil sort  : {sorted(data_awal)}")
    print("=" * 50)