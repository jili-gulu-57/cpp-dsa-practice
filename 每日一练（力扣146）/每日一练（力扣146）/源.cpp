#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


//146.LRU缓存（已通过）
class LRUCache {
public:
    LRUCache(int capacity) 
    {
        _capacity = capacity;
    }

    int get(int key)
    {
        //需更新使用次数（移动到尾端，需保证剩余元素逐个向前移动）
        if (_hash.count(key))
        {
            //交换键值对
            auto it = std::find(_v.begin(), _v.end(), key);
            _v.erase(it);
            _v.push_back(key);
            return _hash[key];
        }
        else
            return -1;
    }

    void put(int key, int value) 
    {
        //先判断是否存在，再判断空间是否足够
        if (_hash.count(key))
        {
            _hash[key] = value;
            //也需要更新
            auto it = std::find(_v.begin(), _v.end(), key);
            _v.erase(it);
            _v.push_back(key);
        }
        else
        {
            //空间足够直接插入
            if (_hash.size() < _capacity)
            {
                _hash[key] = value;
                _v.push_back(key);
            }
            else 
            {
                //删除数组中第一个值对应的哈希表中的键值对
                //空间不足时删掉第一个，再添加
                //注意同时更新数组里的值
                int tmp = _v.front();
                _hash.erase(tmp);
                _hash[key] = value;
                _v.erase(_v.begin());
                _v.push_back(key);

            }
        }
    }
private:
    unordered_map<int, int> _hash;  //无序插入
    vector<int> _v; //记录插入顺序
    int _capacity;
};

int main()
{
    //LRUCache lc(2);
    //lc.put(1, 0);
    //lc.put(2, 2);
    //cout << lc.get(1) << " ";
    //lc.put(3,3);
    //cout << lc.get(2) << " ";
    //lc.put(4, 4);
    //cout << lc.get(1) << " ";
    //cout << lc.get(3) << " ";
    //cout << lc.get(4) << " ";

    //LRUCache lc(2);
    //lc.put(2, 1);
    //lc.put(1, 1);
    //lc.put(2, 3);
    //lc.put(4, 1);
    //cout << lc.get(1) << " ";
    //cout << lc.get(2) << " ";

    LRUCache lc(2);
    cout << lc.get(2) << " ";
    lc.put(2, 6);
    cout << lc.get(1) << " ";
    lc.put(1, 5);
    lc.put(1,2);
    cout << lc.get(1) << " ";
    cout << lc.get(2) << " ";

    return 0;
}