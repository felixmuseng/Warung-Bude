
struct dish
{
    char name[255];
    int price, quantity;
};

struct order
{
    int quantity, price;
    char name[255];
};

struct customer
{
    char name[255];
};

struct NodeDish
{
    struct dish Dish;
    NodeDish *prev, *next;
}*headDish, *tailDish, *currDish;

struct NodeOrder
{
    struct order Order;
    NodeOrder *prev, *next;
}*currOrder;

struct NodeCustomer
{
    struct customer Customer;
    NodeCustomer *prev, *next;
    NodeOrder *headOrder, *tailOrder, *currOrder;;
}*headCustomer[26], *tailCustomer[26], *currCustomer;

void main_menu();
int No = 1,totalCustomer = 0,totalOrder = 0;
int maxname,maxprice,maxpricewidth,maxnowidth,width;