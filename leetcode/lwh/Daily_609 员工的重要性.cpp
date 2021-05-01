/*
 * 题目：690. 员工的重要性
 * 链接：https://leetcode-cn.com/problems/employee-importance/
 * 知识点：bfs, dfs
 */

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    int bfs(vector<Employee*> &employees, unordered_map<int, int> &mapper, int id) {
        int res = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int eid = q.front();
            q.pop();
            Employee *temp = employees[mapper[eid]];
            res += temp->importance;
            for (int i = 0; i < temp->subordinates.size(); i++) {
                q.push(temp->subordinates[i]);
            }
        }
        return res;
    }
public:
    int getImportance(vector<Employee*> &employees, int id) {
        unordered_map<int, int> mapper;
        for (int i = 0; i < employees.size(); i++) {
            Employee *temp = employees[i];
            mapper[temp->id] = i;
        }
        return bfs(employees, mapper, id);
    }
};
