#A02230175 智能2303 王琪
#汉诺塔问题：

def hanoi(n, source='A', target='C', temp='B'):
    """
    汉诺塔问题解决方案
    :param n: 盘子数量
    :param source: 源底座
    :param target: 目标底座
    :param temp: 临时底座
    """
    if n > 0:
        # 将n-1个盘子从源底座移动到临时底座
        hanoi(n - 1, source, temp, target)

        # 移动最底下的盘子
        print(f"移动盘子 {n} 从 {source} 到 {target}")

        # 将n-1个盘子从临时底座移动到目标底座
        hanoi(n - 1, temp, target, source)


def hanoi_with_status(n, source='A', target='C', temp='B'):
    """
    汉诺塔问题解决方案，显示每次移动后的状态
    :param n: 盘子数量
    :param source: 源底座
    :param target: 目标底座
    :param temp: 临时底座
    """
    # 初始化三个底座的状态
    towers = {
        source: list(range(n, 0, -1)),
        target: [],
        temp: []
    }

    def move_disk(from_tower, to_tower):
        disk = towers[from_tower].pop()
        towers[to_tower].append(disk)
        print(f"移动盘子 {disk} 从 {from_tower} 到 {to_tower}")
        print_status()

    def print_status():
        print(f"当前状态: A: {towers['A']}, B: {towers['B']}, C: {towers['C']}")

    def hanoi_recursive(n, src, tgt, tmp):
        if n > 0:
            hanoi_recursive(n - 1, src, tmp, tgt)
            move_disk(src, tgt)
            hanoi_recursive(n - 1, tmp, tgt, src)

    print("初始状态:")
    print_status()
    hanoi_recursive(n, source, target, temp)


# 测试代码
if __name__ == "__main__":
    while True:
        try:
            num = int(input("请输入盘子数量(输入0退出): "))
            if num == 0:
                break
            if num < 1:
                print("请输入正整数")
                continue

            print("\n简单版解决方案:")
            hanoi(num)

            print("\n详细版解决方案(带状态显示):")
            hanoi_with_status(num)

        except ValueError:
            print("请输入有效的数字")