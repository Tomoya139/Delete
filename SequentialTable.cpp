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
    cout << "��ʼ˳������ز�����\n";
    cout << "��ʼ��˳��������\n";
    Init_List(L);
    printf("��������²���:\n\
           0. ��Ϊ˳�������ֵ\n\
           1. ���\n\
           2. �ڵ�i��λ�ò���eֵ\n\
           3. ɾ����i��λ��ֵ�������ɾ����ֵ\n\
           4. ���ҵ�i��λ��Ԫ��\n\
           5. ����e����λ��\n\
           6. ����˳���\n\
           7. ���ӱ�\n\
           8. ���ص�ǰԪ�ظ���\n");
    while (cin >> j)
    {
        if (j == 0)
        {
            cin >> d;
            Scanf_List(L, d);
            cout << "����ɹ�,���������\n";
        }
        if (j == 1)
        {
            Print_List(L);
        }
        if (j == 2)
        {
            cin >> i >> e;
            if (List_Insert(L, i, e)) Print_List(L);
            else  cout << "����ʧ�ܣ����������������\n";
        }
        //��ɾ�������е�eֻ�����Ǹ����ã���������ٵĶ��С�
        if (j == 3)
        {
            cin >> i >> e;
            if (List_Delete(L, i, e))
            {
                cout << "ɾ���ɹ���ɾ����ֵΪ��" << e << endl;
            }
            else cout << "ɾ��ʧ�ܣ��������������\n";
        }
        if (j == 4)
        {
            cin >> i;
            if (Is_i(L, i))
                cout << "���ҳɹ���ֵΪ��" << Get_Elem(L, i) << endl;
            else
                cout << "����ʧ�ܣ��������������\n";
        }
        if (j == 5)
        {
            cin >> e;
            if (Locate_Elem(L, e) > 0)
                cout << "���ҳɹ���λ��Ϊ��" << Locate_Elem(L, e) << endl;
            else
                cout << "����ʧ�ܣ��������������\n";
        }
        if (j == 6)
        {
            cout << "ȷ��Ҫ������?  0 �� ȡ����  1�� ȷ��\n";
            int k;
            cin >> k;
            if (k == 0) cout << "QWQ, лл�ף����������\n";
            if (k == 1)
            {
                cout << "������\n";
                cout << ".......";
                Destroy_List(L);
                cout << "���ٳɹ�; �� 9 �˳�\n";
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
            cout << "��ǰԪ�ظ���Ϊ��" << Len_Size(L) << endl;
        }
    }
    return 0;
}


