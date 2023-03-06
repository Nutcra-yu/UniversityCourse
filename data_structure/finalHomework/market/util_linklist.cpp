#include <iostream>
#include <string>
using namespace std;

typedef struct Product
{
    int id;               //产品编号
    string Name;          //产品
    string Type;          //型号
    int Price;            //价格
    int Num;              //数量
    Product *Nextproduct; //下一个产品
} Product;
typedef Product *Storage;

enum Operate
{
    Parchase = 1,
    Sale = 2,
    Exit = 0,
};
