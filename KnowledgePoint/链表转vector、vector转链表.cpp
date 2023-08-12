// 链表定义
struct ListNode {
     int val;
     ListNode *next;
 };

// 链表vector
// vector<ListNode*> lists
vector<int> ve;
for (int i = 0;i<lists.size();i++) {
    ListNode* np = lists[i];
    while(np) {
        ve.push_back(np->val);
        np = np->next;
    }
}

for (int i = 0;i<ve.size();i++) { 
    cout << ve[i] << " ";
}
cout << endl;

// start：数组当前下标
ListNode* vectorToList(vector<int> arr, int start = 0){
    // 若序号等于数组长度，说明处理完成，直接返回 null
    if(arr.size() == start) return nullptr;

    // 使用当前数组元素 arr[start] 构建当前链表节点
    ListNode* head = new ListNode(arr[start], nullptr);

    // 递归调用函数，得到当前节点的下一个节点
    head->next = arrToList(arr, ++start);
    return head;
}

