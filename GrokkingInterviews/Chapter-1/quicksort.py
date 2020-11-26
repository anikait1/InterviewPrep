from typing import List


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
    if end - start == 1:
        arr[start], arr[index] = arr[index], arr[start]
        return index

    if arr[end] > arr[start]:
        arr[end], arr[index] = arr[index], arr[end]
        index -= 1

    return recursive_partition(arr, start, end - 1, index)


if __name__ == "__main__":
    my_list = [2, 1, 4, 7, 3]
