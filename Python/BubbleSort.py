import time
import psutil
import os


def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr


def read_and_sort_file(file_path):
    with open(file_path, 'r') as file:
        arr = [int(line.strip()) for line in file.readlines()]
    sorted_arr = bubble_sort(arr)

    # Caminho do novo arquivo
    new_file_path = file_path.replace('arq.txt', 'arq-teste-ordenado.txt')

    # Escrever a lista ordenada no novo arquivo
    with open(new_file_path, 'w') as file:
        for item in sorted_arr:
            file.write(f"{item}\n")

    return sorted_arr


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
    f"Arquivo ordenado salvo como: {file_path.replace('arq.txt', 'arq-teste-ordenado.txt')}")
print(f"Tempo de execução: {elapsed_time_ms:.2f} ms")
print(f"RAM utilizada: {mem_used_kb:.2f} KB")

with open('Resultados/resultado-bubble-python.txt', 'a') as result_file:
    # Escrever no arquivo o tempo de execução e a memória utilizada
    result_file.write(
        f"Tempo de execução: {elapsed_time_ms:.2f} ms, RAM utilizada: {mem_used_kb:.2f} KB\n")
