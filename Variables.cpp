
struct dish
{
    char name[255];
    int price, quantity;
};

struct order
{
    struct dish Dish;
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
    NodeOrder *headOrder, *tailOrder;
}*headCustomer[26], *tailCustomer[26], *currCustomer;

void main_menu();
int n = 1,totalCustomer = 0;
int maxname,maxprice,maxpricewidth,maxnowidth;