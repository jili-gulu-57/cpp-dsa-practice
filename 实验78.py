#A02230175 智能2303 王琪
#实验七十八：

# 儿童身高预测线性回归模型

import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt


# 1. 模拟生成数据集
def generate_sample_data(num_samples=100):
    """生成模拟的身高数据集"""
    np.random.seed(42)

    # 生成特征数据
    data = {
        'age': np.random.randint(2, 19, size=num_samples),  # 2-18岁
        'gender': np.random.randint(0, 2, size=num_samples),  # 0:女, 1:男
        'father_height': np.random.normal(170, 5, num_samples),  # 父亲身高
        'mother_height': np.random.normal(160, 5, num_samples),  # 母亲身高
        'grandfather_height': np.random.normal(172, 5, num_samples),  # 祖父身高
        'grandmother_height': np.random.normal(158, 5, num_samples),  # 祖母身高
        'maternal_grandfather_height': np.random.normal(171, 5, num_samples),  # 外祖父身高
        'maternal_grandmother_height': np.random.normal(157, 5, num_samples)  # 外祖母身高
    }

    # 生成目标变量(儿童身高)
    # 使用线性组合加噪声模拟身高
    coefficients = {
        'age': 1.2,
        'gender': 5,  # 男性通常更高
        'father_height': 0.3,
        'mother_height': 0.3,
        'grandfather_height': 0.05,
        'grandmother_height': 0.05,
        'maternal_grandfather_height': 0.05,
        'maternal_grandmother_height': 0.05
    }

    height = 80  # 基础身高(2岁左右)
    for feature, coef in coefficients.items():
        height += coef * data[feature]

    # 添加随机噪声
    data['child_height'] = height + np.random.normal(0, 2, num_samples)

    return pd.DataFrame(data)


# 2. 数据预处理
def preprocess_data(df):
    """数据预处理"""
    # 超过18岁的身高设为18岁时的身高
    df.loc[df['age'] > 18, 'age'] = 18

    # 分离特征和目标变量
    X = df.drop('child_height', axis=1)
    y = df['child_height']

    return X, y


# 3. 训练线性回归模型
def train_linear_regression(X, y):
    """训练线性回归模型"""
    # 划分训练集和测试集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # 创建并训练模型
    model = LinearRegression()
    model.fit(X_train, y_train)

    # 评估模型
    y_pred = model.predict(X_test)
    mse = mean_squared_error(y_test, y_pred)
    print(f"模型均方误差(MSE): {mse:.2f}")
    print(f"模型系数: {model.coef_}")
    print(f"模型截距: {model.intercept_:.2f}")

    return model


# 4. 预测函数
def predict_height(model, age, gender, family_heights):
    """
    预测儿童身高
    :param model: 训练好的模型
    :param age: 年龄(2-18)
    :param gender: 性别(0:女, 1:男)
    :param family_heights: 包含家人身高的字典
    """
    if age > 18:
        age = 18
        print("注意: 超过18岁按18岁计算")

    # 准备输入数据
    input_data = {
        'age': [age],
        'gender': [gender],
        'father_height': [family_heights['father']],
        'mother_height': [family_heights['mother']],
        'grandfather_height': [family_heights['grandfather']],
        'grandmother_height': [family_heights['grandmother']],
        'maternal_grandfather_height': [family_heights['maternal_grandfather']],
        'maternal_grandmother_height': [family_heights['maternal_grandmother']]
    }

    input_df = pd.DataFrame(input_data)

    # 预测身高
    predicted_height = model.predict(input_df)[0]

    return predicted_height


# 主程序
if __name__ == "__main__":
    # 1. 生成数据
    print("正在生成模拟数据...")
    height_data = generate_sample_data(200)
    print("数据样例:")
    print(height_data.head())

    # 2. 数据预处理
    X, y = preprocess_data(height_data)

    # 3. 训练模型
    print("\n训练线性回归模型...")
    model = train_linear_regression(X, y)

    # 4. 示例预测
    print("\n进行身高预测...")
    family_heights = {
        'father': 175,
        'mother': 165,
        'grandfather': 172,
        'grandmother': 158,
        'maternal_grandfather': 170,
        'maternal_grandmother': 156
    }

    # 预测不同年龄的身高
    ages_to_predict = [5, 10, 15, 18]
    gender = 1  # 男性

    print(f"\n预测男性儿童身高(家人身高: {family_heights})")
    for age in ages_to_predict:
        height = predict_height(model, age, gender, family_heights)
        print(f"预测 {age} 岁时的身高: {height:.1f} cm")

    # 可视化年龄与身高的关系
    plt.figure(figsize=(10, 6))
    plt.scatter(height_data['age'], height_data['child_height'], alpha=0.5, label='实际数据')

    # 预测并绘制趋势线
    test_ages = np.linspace(2, 18, 100).reshape(-1, 1)
    test_data = pd.DataFrame({
        'age': test_ages.flatten(),
        'gender': np.ones(100) * gender,
        'father_height': np.ones(100) * family_heights['father'],
        'mother_height': np.ones(100) * family_heights['mother'],
        'grandfather_height': np.ones(100) * family_heights['grandfather'],
        'grandmother_height': np.ones(100) * family_heights['grandmother'],
        'maternal_grandfather_height': np.ones(100) * family_heights['maternal_grandfather'],
        'maternal_grandmother_height': np.ones(100) * family_heights['maternal_grandmother']
    })

    predicted_heights = model.predict(test_data)
    plt.plot(test_ages, predicted_heights, 'r-', linewidth=2, label='预测趋势')

    plt.title('年龄与身高关系')
    plt.xlabel('年龄')
    plt.ylabel('身高(cm)')
    plt.legend()
    plt.grid(True)
    plt.show()