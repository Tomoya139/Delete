#include<iostream>
using namespace std;

#define InitSize 10  
#define IncreaseSize 5  

typedef struct {
	int maxsize;
	int length;
	int* data;
}SqList;

void Increase_Size(SqList& L, int len) {
    int* p = L.data;    
    L.data = (int*)malloc((L.maxsize + len) * sizeof(int));
    //     L.data = new int[L.maxsize + len];
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];       
    }
    L.maxsize = L.length + len;
    free(p); 
}

void Init_List(SqList& L)  {
    L.data = (int*)malloc(InitSize * sizeof(int));
    //     L.data = new int[InitSize];
    L.length = 0;
    L.maxsize = InitSize; 
    for (int i = 0; i < L.maxsize; i++)
        L.data[i] = 0;
}

void Scanf_List(SqList& L, int d){
    for (int i = 0; i < d; i++) {
        cin >> L.data[i];
        L.length++;
    }
}

void Print_List(SqList L){
    for (int i = 0; i < L.length; i++)
        cout << " " << L.data[i];
}

bool List_Insert(SqList& L, int i, int e) {
    if (i < 1 || i > L.length) return false;
    if (L.length >= L.maxsize)           
    {
        Increase_Size(L, IncreaseSize);
    }
    for (int j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool List_Delete(SqList& L, int i, int& e){
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

bool Is_i(SqList L, int i)                 {
    if (i < 1 || i > L.length) return false;
    else return true;
}

int Get_Elem(SqList L, int i){
    return L.data[i - 1];
}

int Locate_Elem(SqList L, int e){
    for (int i = 0; i < L.length; i++){
        if (L.data[i] == e){
            return i + 1;
        }
    }
    return -1;
}

void Destroy_List(SqList& L){
    free(L.data);
    L.length = 0;
    L.maxsize = InitSize;
}

int Len_Size(SqList L){
    return L.length;
}

int main(){
    SqList L;
    int j, i, e, d;
    cout << "开始顺序表的相关操作：\n";
    cout << "初始化顺序表已完成\n";
    Init_List(L);
    printf("请进行以下操作:\n\
           0. 请为顺序表输入值\n\
           1. 输出\n\
           2. 在第i个位置插入e值\n\
           3. 删除第i个位的值，并输出删除的值\n\
           4. 查找第i个位的元素\n\
           5. 查找e所在位置\n\
           6. 销毁顺序表\n\
           7. 增加表长\n\
           8. 返回当前元素个数\n");
    while (cin >> j)
    {
        if (j == 0)
        {
            cin >> d;
            Scanf_List(L, d);
            cout << "输入成功,请继续操作\n";
        }
        if (j == 1)
        {
            Print_List(L);
        }
        if (j == 2)
        {
            cin >> i >> e;
            if (List_Insert(L, i, e)) Print_List(L);
            else  cout << "插入失败，请重新输入操作：\n";
        }
        //在删除操作中的e只不过是个引用，你输入多少的都行。
        if (j == 3)
        {
            cin >> i >> e;
            if (List_Delete(L, i, e))
            {
                cout << "删除成功，删除的值为：" << e << endl;
            }
            else cout << "删除失败，请重新输入操作\n";
        }
        if (j == 4)
        {
            cin >> i;
            if (Is_i(L, i))
                cout << "查找成功，值为：" << Get_Elem(L, i) << endl;
            else
                cout << "查找失败，请重新输入操作\n";
        }
        if (j == 5)
        {
            cin >> e;
            if (Locate_Elem(L, e) > 0)
                cout << "查找成功，位序为：" << Locate_Elem(L, e) << endl;
            else
                cout << "查找失败，请重新输入操作\n";
        }
        if (j == 6)
        {
            cout << "确定要销毁吗?  0 ： 取消，  1： 确定\n";
            int k;
            cin >> k;
            if (k == 0) cout << "QWQ, 谢谢亲，请继续操作\n";
            if (k == 1)
            {
                cout << "销毁中\n";
                cout << ".......";
                Destroy_List(L);
                cout << "销毁成功; 按 9 退出\n";
                int o;
                cin >> o;
                if (o == 9) return 0;
            }
        }
        if (j == 7)
        {
            Increase_Size(L, IncreaseSize);
        }
        if (j == 8)
        {
            cout << "当前元素个数为：" << Len_Size(L) << endl;
        }
    }
    return 0;
}


