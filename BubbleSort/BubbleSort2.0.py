import time

def BubbleSort(array):
    n = len(array)
    start_time = time.time()
    for i in range(n-1):
        veri = False
        print("Iteração",i,array)
        for j in range(n-i-1):
            if(array[j] > array[j+1]):
                veri = True
                array[j] , array[j+1] = array[j+1] , array[j]
        if veri == False:
            break
    end_time = time.time()
    print("Ordenados ",array)
    print(f"Tempo de execução: {end_time - start_time:.6f} segundos")


num = [42, 17, 8, 99, 23, 56, 4, 77, 12, 34, 1, 65, 90, 28, 6, 15, 81, 50, 29]
BubbleSort(num)
