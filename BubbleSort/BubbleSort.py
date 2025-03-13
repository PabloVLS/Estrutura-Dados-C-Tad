import time

def bubbleSort(array):
    n = len(array)
    start_time = time.time()
    for i in range(n-1):
        print("Passada: ",i,array)
        for j in range(n-i-1):
            if(array[j]>array[j+1]):
                array[j], array[j+1] = array[j+1], array[j]
    end_time = time.time()
    print("Ordenados:", array)
    print(f"Tempo de Execução:{end_time - start_time:.6f} segundos")

num = [42, 17, 8, 99, 23, 56, 4, 77, 12, 34, 1, 65, 90, 28, 6, 15, 81,  50, 29]
bubbleSort(num)