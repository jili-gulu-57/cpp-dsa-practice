# def find_second_largest(arr):
#     """
#     使用分治法找出数组中的第二大元素
#     思路：在归并排序的过程中同时记录最大和第二大元素
#     """
#
#     def merge_find_max(left_result, right_result):
#         """
#         合并左右子数组的结果，返回包含最大和第二大元素的元组
#         """
#         # 解包左右子数组的结果
#         left_max, left_second = left_result
#         right_max, right_second = right_result
#
#         # 找出合并后的最大元素
#         if left_max > right_max:
#             current_max = left_max
#             # 第二大元素候选：左子数组的第二大和右子数组的最大
#             candidates = [left_second, right_max]
#         else:
#             current_max = right_max
#             # 第二大元素候选：右子数组的第二大和左子数组的最大
#             candidates = [right_second, left_max]
#
#         # 从候选者中找出第二大元素
#         current_second = max(candidates)
#
#         return (current_max, current_second)
#
#     def divide_and_conquer(arr, left, right):
#         """
#         分治递归函数
#         """
#         print(f"处理子数组: {arr[left:right + 1]}")
#
#         # 基准情况：只有一个元素
#         if left == right:
#             print(f"  基准情况返回: 最大={arr[left]}, 第二大=-∞")
#             return (arr[left], float('-inf'))
#
#         # 基准情况：有两个元素
#         if right - left == 1:
#             if arr[left] > arr[right]:
#                 result = (arr[left], arr[right])
#             else:
#                 result = (arr[right], arr[left])
#             print(f"  基准情况返回: 最大={result[0]}, 第二大={result[1]}")
#             return result
#
#         # 分治：将数组分成两半
#         mid = (left + right) // 2
#         print(f"  将数组分成: {arr[left:mid + 1]} 和 {arr[mid + 1:right + 1]}")
#
#         # 递归处理左右子数组
#         left_result = divide_and_conquer(arr, left, mid)
#         right_result = divide_and_conquer(arr, mid + 1, right)
#
#         # 合并结果
#         merged_result = merge_find_max(left_result, right_result)
#         print(f"  合并结果: 左{left_result} + 右{right_result} -> {merged_result}")
#
#         return merged_result
#
#     # 调用分治函数
#     print("开始分治查找第二大元素...")
#     print("原始数组:", arr)
#     print("-" * 50)
#
#     result = divide_and_conquer(arr, 0, len(arr) - 1)
#
#     print("-" * 50)
#     print(f"最终结果: 最大元素 = {result[0]}, 第二大元素 = {result[1]}")
#     return result[1]
#
#
# # 测试数据
# arr = [6, 12, 3, 7, 2, 18, 90, 87, 54, 23]
#
# # 调用函数
# second_largest = find_second_largest(arr)
#
# print("\n" + "=" * 50)
# print(f"数组: {arr}")
# print(f"排序后: {sorted(arr)}")
# print(f"第二大元素是: {second_largest}")

import random


def find_kth_smallest(arr, k):
    """
    使用分治法（快速选择算法）找出数组中的第k小元素
    """

    def quick_select(arr, left, right, k_index):
        """
        快速选择递归函数
        """
        print(f"处理子数组: {arr[left:right + 1]}, 寻找第{k_index + 1}小元素")

        # 基准情况：只有一个元素
        if left == right:
            print(f"  基准情况返回: {arr[left]}")
            return arr[left]

        # 随机选择枢轴
        pivot_index = random.randint(left, right)
        pivot_value = arr[pivot_index]
        print(f"  选择枢轴: arr[{pivot_index}] = {pivot_value}")

        # 将枢轴移到末尾
        arr[pivot_index], arr[right] = arr[right], arr[pivot_index]

        # 分区操作
        store_index = left
        for i in range(left, right):
            if arr[i] < pivot_value:
                arr[store_index], arr[i] = arr[i], arr[store_index]
                store_index += 1

        # 将枢轴放回正确位置
        arr[right], arr[store_index] = arr[store_index], arr[right]

        print(f"  分区后数组: {arr[left:right + 1]}")
        print(f"  枢轴最终位置: {store_index}, 左边元素都小于枢轴，右边元素都大于等于枢轴")

        # 检查枢轴位置
        if k_index == store_index:
            print(f"  找到目标! 第{k_index + 1}小元素是: {arr[store_index]}")
            return arr[store_index]
        elif k_index < store_index:
            print(f"  目标在左半部分: 在索引{left}到{store_index - 1}中寻找第{k_index + 1}小")
            return quick_select(arr, left, store_index - 1, k_index)
        else:
            print(f"  目标在右半部分: 在索引{store_index + 1}到{right}中寻找第{k_index + 1}小")
            return quick_select(arr, store_index + 1, right, k_index)

    # 输入验证
    if k < 1 or k > len(arr):
        raise ValueError("k值超出范围")

    print("开始分治查找第k小元素...")
    print(f"原始数组: {arr}")
    print(f"目标: 第{k}小元素")
    print("-" * 60)

    # 创建数组副本以避免修改原数组
    arr_copy = arr.copy()
    result = quick_select(arr_copy, 0, len(arr_copy) - 1, k - 1)

    print("-" * 60)
    print(f"最终结果: 第{k}小元素 = {result}")
    return result


def find_kth_smallest_verbose(arr, k):
    """
    更详细版本，展示完整的分治过程
    """

    def partition(arr, left, right):
        """分区函数，返回枢轴的最终位置"""
        pivot = arr[right]
        i = left
        for j in range(left, right):
            if arr[j] <= pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
        arr[i], arr[right] = arr[right], arr[i]
        return i

    def quick_select_detailed(arr, left, right, k_index, depth=0):
        """详细的快速选择实现"""
        indent = "  " * depth
        print(f"{indent}深度{depth}: 处理{arr[left:right + 1]}, 寻找第{k_index + 1}小")

        if left == right:
            print(f"{indent}  找到结果: {arr[left]}")
            return arr[left]

        # 选择右端作为枢轴（简化演示）
        pivot_index = partition(arr, left, right)
        print(f"{indent}  分区后: {arr[left:right + 1]}, 枢轴位置: {pivot_index}, 值: {arr[pivot_index]}")

        if k_index == pivot_index:
            print(f"{indent}  *** 找到目标! ***")
            return arr[pivot_index]
        elif k_index < pivot_index:
            print(f"{indent}  → 递归左半部分")
            return quick_select_detailed(arr, left, pivot_index - 1, k_index, depth + 1)
        else:
            print(f"{indent}  → 递归右半部分")
            return quick_select_detailed(arr, pivot_index + 1, right, k_index, depth + 1)

    print("详细分治过程:")
    print("=" * 50)
    arr_copy = arr.copy()
    result = quick_select_detailed(arr_copy, 0, len(arr_copy) - 1, k - 1)
    return result


# 测试数据
arr = [89, 10, 21, 5, 2, 8, 33, 27, 63, 55, 66]
k = 8

print("数组:", arr)
print("排序后:", sorted(arr))
print(f"目标: 第{k}小元素")
print()

# 方法1: 标准快速选择
print("方法1: 快速选择算法")
print("=" * 50)
result1 = find_kth_smallest(arr, k)

print("\n" + "=" * 80 + "\n")

# 方法2: 详细分治过程
print("方法2: 详细分治过程")
print("=" * 50)
result2 = find_kth_smallest_verbose(arr, k)

print("\n" + "=" * 80)
print("\n验证结果:")
print(f"数组: {arr}")
print(f"排序后: {sorted(arr)}")
print(f"第{k}小元素是: {result1}")
print(f"验证: 排序后第{k}个元素 = {sorted(arr)[k - 1]}")
print(f"结果正确: {result1 == sorted(arr)[k - 1]}")