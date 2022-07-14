#include <iostream>
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //散列表长度
#define NULLKEY -32768

typedef class
{
public:
    int *elem;
    int count;
} HashTable;
int m = 0; //散列表长度

void InitHashTable(HashTable *H) //初始化
{
    int i;
    m = HASHSIZE;
    H->elem = (int *)malloc(sizeof(int) * m);
    H->count = 0;
    for (int i = 0; i < m; i++)
    {
        H->elem[i] = NULLKEY;
    }
}

int Hash(int key) //哈希函数
{
    return key % m; //除留取余法
}

void InsertHash(HashTable *H, int key) //插入关键词
{
    int count = 0, x = 0;
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY) //哈希冲突
    {
        count++;
        // addr=(addr+1)%m; //开放定址的线性检测

        {
            if (count % 2 == 0)
            {
                if ((addr - x * x) % m > 0)
                    addr = (addr - x * x) % m;
            }
            else
            {
                x++;
                addr = (addr + x * x) % m;
            }
        } //二次探测法
    }
    H->elem[addr] = key;
}

int SearchHash(HashTable H, int key, int *addr)
{
    *addr = Hash(key);
    while (H.elem[*addr] != key)
    {
        *addr = (*addr + 1) % m; //开放定址法的线性探测法

        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) //遍历一遍都没有
        {
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}

int main()
{
    int i, result;
    int addr;
    HashTable hashTable;
    int arr[HASHSIZE] = {1, 2, 12, 24, 13, 15};
    //初始化哈希表
    InitHashTable(&hashTable);

    //利用插入函数构造哈希表
    for (i = 0; i < HASHSIZE; i++)
    {
        InsertHash(&hashTable, arr[i]);
    }
    //调用查找算法
    result = SearchHash(hashTable, 13, &addr);
    if (result == 0)
        printf("查找失败");
    else
        printf("13在哈希表中的位置是:%d\n", addr);
    for (int i = 0; i < m; i++)
        std::cout << hashTable.elem[i] << " ";
    free(hashTable.elem);
    return 0;
}
