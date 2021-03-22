/*
 * 题目：341. 扁平化嵌套列表迭代器
 * 链接：https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 * 知识点：dfs + stl
 *
 */
lass NestedIterator {
private:
    vector<int> ret;
    int index;

    void dfs(vector<NestedInteger> &nestedList) {
        for (auto nest : nestedList) {
            if (nest.isInteger()) {
                ret.push_back(nest.getInteger());
            } else {
                dfs(nest.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        dfs(nestedList);
    }

    int next() {
        return ret[index++];
    }

    bool hasNext() {
        return index < ret.size();
    }
};
