from typing import List
import random


def partition(arr: List[int], start: int, end: int) -> int:
    pivot = arr[start]
    index = end

    for i in range(end, start, -1):
        if arr[i] > pivot:
            arr[i], arr[index] = arr[index], arr[i]
            index -= 1

    arr[index], arr[start] = arr[start], arr[index]
    return index


def recursive_partition(arr: List[int], start, end, index):
    if end == start:
        arr[start], arr[index] = arr[index], arr[start]
        return index

    if arr[end] > arr[start]:
        arr[end], arr[index] = arr[index], arr[end]
        index -= 1

    return recursive_partition(arr, start, end - 1, index)


def quicksort(arr: List[int], start: int, end: int):
    if start < end:
        pivot = partition(arr, start, end)
        # pivot = recursive_partition(arr, start, end, end)
        quicksort(arr, start, pivot - 1)
        quicksort(arr, pivot + 1, end)


if __name__ == "__main__":
    my_list = [random.randint(-11, 40000) for _ in range(10000)]
    copy_list = sorted(my_list)
    start = 0
    end = len(my_list) - 1

    quicksort(my_list, 0, end)
    print(my_list == copy_list)
