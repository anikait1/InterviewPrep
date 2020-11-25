from typing import List, Union


def find_smallest(arr: List[int], start: int, end: int) -> int:
    """
    Find the index of smallest element from the given range of array
    """
    smallest = arr[start]
    smallest_index = start

    for i in range(start, end):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i

    return smallest_index


def selection_sort(arr: List[int]) -> None:
    length = len(arr)
    for index, _ in enumerate(arr):
        smallest_index = find_smallest(arr, index, length)
        arr[index], arr[smallest_index] = arr[smallest_index], arr[index]


if __name__ == "__main__":
    my_list = [1, 4, 2, 3, 9, 11, 5, 6]
    selection_sort(my_list)

    print(my_list)
