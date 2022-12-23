def quick_sort(array):
    if len(array) <= 1:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]

        return quick_sort(less) + [pivot] + quick_sort(greater)

array = [10, 5, 100, 9, 0, -49, 49, -20, 1, 1]
print(quick_sort(array))
