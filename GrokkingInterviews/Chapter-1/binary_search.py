from typing import List, Union


def binary_search(arr: List[int], item: int) -> Union[int, None]:
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = arr[mid]

        if guess == item:
            return mid
        elif guess < item:  # guess is too low
            low = mid + 1
        else:
            high = mid - 1  # guess is too high

    return None


if __name__ == "__main__":
    my_list = [-3, 0, 1, 2, 3, 4]

    print(binary_search(my_list, 3))
    print(binary_search(my_list, -1))
