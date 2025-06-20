#A02230175 智能2303 王琪
#实验十四：
import random

def monty_hall_game():
    # 初始化三扇门，随机放置汽车和山羊
    doors = {1: '山羊', 2: '山羊', 3: '山羊'}
    car_pos = random.randint(1, 3)
    doors[car_pos] = '汽车'

    # 玩家初始选择
    while True:
        try:
            choice = int(input("请选择一扇门(1/2/3): "))
            assert choice in [1, 2, 3]
            break
        except (ValueError, AssertionError):
            print("输入无效，请重新输入1/2/3")

    # 主持人打开一扇有山羊的门
    host_opens = [d for d in doors if d != choice and doors[d] == '山羊']
    host_choice = random.choice(host_opens)
    print(f"主持人打开了{host_choice}号门，后面是一只山羊")

    # 询问是否换门
    while True:
        try:
            change = input("是否换门？(y/n): ").lower()
            assert change in ['y', 'n']
            break
        except AssertionError:
            print("输入无效，请输入y/n")

    # 确定最终选择
    if change == 'y':
        final_choice = [d for d in doors if d != choice and d != host_choice][0]
    else:
        final_choice = choice

    # 公布结果
    result = doors[final_choice]
    print(f"你最终选择了{final_choice}号门，后面是{result}")

    return result == '汽车'

# 主程序
if __name__ == "__main__":
    wins = 0
    total = 0

    while True:
        total += 1
        if monty_hall_game():
            wins += 1

        print(f"当前胜率: {wins}/{total} ({wins/total*100:.1f}%)")

        again = input("再玩一次？(y/n): ").lower()
        if again != 'y':
            break