
struct NodeDish *addDish(char *name, int price, int quantity)
{
   struct NodeDish *temp = (NodeDish*)malloc(sizeof(NodeDish));
   strcpy(temp->Dish.name, name);
   temp->Dish.price = price;
   temp->Dish.quantity = quantity;
   temp->next = temp->prev = NULL;
   return temp;
}

void pushNodeDish(struct NodeDish* temp)
{
	if(!headDish)
	{
		headDish = tailDish = temp;
	}
	else
	{
		tailDish->next = temp;
		temp->prev = tailDish;
		tailDish = temp;
	}
}

int lowercasecheck(char nameTemp[])
{
    int i = 0;
    while(nameTemp[i]!='\0')
    {
        if(nameTemp[i]<'a' || nameTemp[i]>'z')
        {
            return 1;
        }
        return 0;
    }
}

void AddDish()
{
    system("cls || clear");
    char nameTemp[255];
    int quantityTemp, priceTemp;

    do
	{
	    printf("Insert the name of the dish [Lowercase letters]: ");
	    getchar();
        scanf("%[^\n]", nameTemp);
    }while(lowercasecheck(nameTemp)==1);

    do
	{
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &priceTemp);
	}while(priceTemp < 1000 || priceTemp > 50000);

    do
	{
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &quantityTemp);
	}while(quantityTemp < 1 || quantityTemp > 999);

    pushNodeDish(addDish(nameTemp, priceTemp, quantityTemp));
    No++;
    printf("The dish has been added!\n");
    printf("Press enter to continue...\n");
    getchar();
    main_menu();
}