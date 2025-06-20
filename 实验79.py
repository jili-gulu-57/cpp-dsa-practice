#A02230175 智能2303 王琪
#实验79：
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
def generate_sample_data(num_samples=200):
    """生成模拟的肥胖程度数据集（修复版）"""
    np.random.seed(42)

    # 生成特征数据
    data = {
        'gender': np.random.choice(['Male', 'Female'], size=num_samples),
        'height': np.random.normal(170, 10, num_samples).astype(int),
        'weight': np.random.normal(70, 15, num_samples).astype(int)
    }

    df = pd.DataFrame(data)
    df['bmi'] = df['weight'] / ((df['height'] / 100) ** 2)

    # 修复1：确保每个条件都是布尔数组
    conditions = [
        (df['bmi'] < 18.5).values,  # 添加.values确保是numpy数组
        ((df['bmi'] >= 18.5) & (df['bmi'] < 25)).values,
        ((df['bmi'] >= 25) & (df['bmi'] < 30)).values,
        (df['bmi'] >= 30).values
    ]

    # 修复2：确保categories是列表或数组
    categories = np.array(['Underweight', 'Normal', 'Overweight', 'Obese'])

    # 修复3：添加默认值参数
    df['obesity'] = np.select(conditions, categories, default='Unknown')

    return df[['gender', 'height', 'weight', 'obesity']]


# 2. 数据预处理
def preprocess_data(df):
    """数据预处理"""
    # 性别编码
    le = LabelEncoder()
    df['gender_encoded'] = le.fit_transform(df['gender'])

    # 分离特征和目标变量
    X = df[['gender_encoded', 'height', 'weight']]
    y = df['obesity']

    return X, y, le


# 3. 训练KNN模型
def train_knn(X, y, k=5):
    """训练KNN分类器"""
    # 划分训练集和测试集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    # 创建并训练模型
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)

    # 评估模型
    y_pred = knn.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    print(f"模型准确率: {accuracy:.2f}")

    return knn


# 4. 可视化决策边界
def plot_decision_boundary(model, X, y):
    """可视化决策边界（简化版，只显示两个主要特征）"""
    # 只取身高和体重两个特征
    X_plot = X[['height', 'weight']].values
    y_plot = y.values

    # 创建网格
    h = 1  # 网格步长
    x_min, x_max = X_plot[:, 0].min() - 10, X_plot[:, 0].max() + 10
    y_min, y_max = X_plot[:, 1].min() - 10, X_plot[:, 1].max() + 10
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                         np.arange(y_min, y_max, h))

    # 预测网格点
    Z = model.predict(np.c_[np.zeros(len(xx.ravel())), xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)

    # 绘制
    plt.figure(figsize=(10, 6))
    plt.contourf(xx, yy, Z, alpha=0.4)
    scatter = plt.scatter(X_plot[:, 0], X_plot[:, 1], c=LabelEncoder().fit_transform(y_plot),
                          s=20, edgecolor='k')
    plt.xlabel('Height (cm)')
    plt.ylabel('Weight (kg)')
    plt.title('KNN Decision Boundary (Gender not shown)')
    plt.legend(handles=scatter.legend_elements()[0],
               labels=list(LabelEncoder().fit(y).classes_))
    plt.show()


# 主程序
if __name__ == "__main__":
    import pandas as pd

    # 1. 生成数据
    print("正在生成模拟数据...")
    obesity_data = generate_sample_data()
    print("\n数据样例:")
    print(obesity_data.head())

    # 2. 数据预处理
    X, y, le = preprocess_data(obesity_data)

    # 3. 训练模型
    print("\n训练KNN模型...")
    knn_model = train_knn(X, y, k=5)

    # 4. 示例预测
    print("\n进行肥胖程度预测...")
    test_cases = [
        ['Male', 180, 85],  # 预期: Overweight
        ['Female', 165, 50],  # 预期: Underweight
        ['Male', 175, 100],  # 预期: Obese
        ['Female', 160, 55]  # 预期: Normal
    ]

    for case in test_cases:
        # 性别编码
        gender_encoded = le.transform([case[0]])[0]
        features = np.array([[gender_encoded, case[1], case[2]]])

        # 预测
        prediction = knn_model.predict(features)
        print(f"性别: {case[0]}, 身高: {case[1]}cm, 体重: {case[2]}kg → 预测肥胖程度: {prediction[0]}")

    # 5. 可视化
    plot_decision_boundary(knn_model, X, y)