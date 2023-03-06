#include <iostream>
#include <malloc.h>
#include <string>
#include "util_linklist.cpp"
using namespace std;

void StorageInit(Storage *storage);             //初始化库存
void ShowStorage(Storage storage);              //显示库存
void ShowProduct(Storage storage, int id);      //显示产品信息
void ParchaseProduct(Product product, int num); //进
void SaleProduct(Product product, int num);     //销

int main()
{
    Storage storage;

    //读取显示库存
    StorageInit(&storage);

    /*选择操作*/
    while (1)
    {
        system("cls");

        ShowStorage(storage); //显示库存

        cout << endl;
        cout << "选择操作: 进货:1 出售:2 退出:0" << endl;
        int operate;
        cin >> operate;

        switch (operate)
        {
        //进
        case Parchase:
            //选择产品
            int id;
            cin >> id;
            ShowProduct(storage, id);
            // //进货数量
            // cin >> num;
            // ParchaseProduct(product, num);
            break;

        //出
        case Sale:
            cout << "2";
            // //选择产品
            // cin >> product;
            // ShowProduct(product);
            // //售卖数量
            // cin >> num;
            // SaleProduct(product, num);
            break;

        case Exit:
            cout << "0";
            return 0;

        default:
            break;
        }
    }
}

void StorageInit(Storage *storage) //初始化库存
{
    *storage = new Product;
    Product *temp_product = *storage;

    string name = "彩电";
    string type = "小米75英寸";
    temp_product->id = 1;
    temp_product->Name = name;
    temp_product->Type = type;
    temp_product->Price = 5000;
    temp_product->Num = 50;
    temp_product->Nextproduct = NULL;

    Product *newproduct = new Product;
    temp_product->Nextproduct = newproduct;
    temp_product = temp_product->Nextproduct;

    name = "冰箱";
    type = "海尔532L";
    temp_product->id = 2;
    temp_product->Name = name;
    temp_product->Type = type;
    temp_product->Price = 2500;
    temp_product->Num = 100;
    temp_product->Nextproduct = NULL;
}

void ShowStorage(Storage storage) //显示库存
{
    cout << "名称 型号 单价 数量" << endl;
    Product *temp_product = storage;
    while (temp_product->Nextproduct != NULL)
    {
        cout << temp_product->id << ' ' << temp_product->Name << ' ' << temp_product->Type << ' ' << temp_product->Price << ' ' << temp_product->Num << endl;
        temp_product = temp_product->Nextproduct;
    }
    cout << temp_product->id << ' ' << temp_product->Name << ' ' << temp_product->Type << ' ' << temp_product->Price << ' ' << temp_product->Num << endl;
}
void ShowProduct(Storage storage, int id) //显示产品信息
{
    while (storage->id != id && storage->Nextproduct != NULL)
        storage = storage->Nextproduct;

//    if (storage->id == id)
//        cout << temp_product->id << ' ' << temp_product->Name << ' ' << temp_product->Type << ' ' << temp_product->Price << ' ' << temp_product->Num << endl;

}
void ParchaseProduct(Product product, int num); //进
void SaleProduct(Product product, int num);     //销
