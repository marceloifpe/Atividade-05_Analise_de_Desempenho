import time
import psutil
import os


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1


def read_and_sort_file(file_path):
    with open(file_path, 'r') as file:
        arr = [int(line.strip()) for line in file.readlines()]

    # Depuração: mostrando os primeiros 10 elementos
    print(f"Original array: {arr[:10]}...")

    merge_sort(arr)

    # Depuração: mostrando os primeiros 10 elementos ordenados
    print(f"Sorted array: {arr[:10]}...")

    # Caminho do novo arquivo
    new_file_path = file_path.replace('arq.txt', 'arq-teste-ordenado_Efic.txt')

    # Escrever a lista ordenada no novo arquivo
    with open(new_file_path, 'w') as file:
        for item in arr:
            file.write(f"{item}\n")

    return arr


file_path = r'arq.txt'

# Medir o uso de memória antes da execução
process = psutil.Process(os.getpid())
mem_before = process.memory_info().rss / 1024  # Convertendo bytes para KB

# Medir o tempo de início
start_time = time.perf_counter()

# Ordenar e salvar a lista ordenada
sorted_arr = read_and_sort_file(file_path)

# Medir o tempo de fim e calcular a diferença
end_time = time.perf_counter()
# Convertendo segundos para milissegundos
elapsed_time_ms = (end_time - start_time) * 1000

# Medir o uso de memória após a execução e calcular a diferença
mem_after = process.memory_info().rss / 1024  # Convertendo bytes para KB
mem_used_kb = mem_after - mem_before

print(
    f"Arquivo ordenado salvo como: {file_path.replace('arq.txt', 'arq-teste-ordenado_Efic.txt')}")
print(f"Tempo de execução: {elapsed_time_ms:.2f} ms")
print(f"RAM utilizada: {mem_used_kb:.2f} KB")

with open('Resultados/resultado-merge-python.txt', 'a') as result_file:
    # Escrever no arquivo o tempo de execução e a memória utilizada
    result_file.write(
        f"Tempo de execução: {elapsed_time_ms:.2f} ms, RAM utilizada: {mem_used_kb:.2f} KB\n")
