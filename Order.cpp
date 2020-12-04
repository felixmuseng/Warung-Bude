NodeOrder *createOrder(char *str, int quantity, int price)
{
    NodeOrder *temp = (NodeOrder*)malloc(sizeof(NodeOrder*));
    strcpy(temp->Order.name, str);
    temp->Order.quantity = quantity;
    temp->Order.price = price;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushOrder(struct NodeOrder *temp, char *name)
{
    int flag;
    for(int i = 0;i < 26;i++)
    {
	    currCustomer = headCustomer[i];
	    while(currCustomer)
	    {
		    flag = 0;
		    if(strcmp(currCustomer->Customer.name, name) == 0)
		    {
                if(!currCustomer->headOrder)
			    {
			        totalOrder++;
                    currCustomer->headOrder = currCustomer->tailOrder = temp;
			    }
			    else
			    {
			        currCustomer->currOrder = currCustomer->headOrder;
			        while(currCustomer->currOrder)
			        {
			   	        if(strcmp(currCustomer->currOrder->Order.name, temp->Order.name) == 0)
			   	        {
			   	  	        currCustomer->currOrder->Order.quantity += temp->Order.quantity;
			   	  	        flag = 1;
			   	  	        break;
				        }
				        currCustomer->currOrder = currCustomer->currOrder->next;
			        }
			        if(flag == 0) 
			        {
                        currCustomer->tailOrder->next = temp;
			            temp->prev = currCustomer->tailOrder;
			            currCustomer->tailOrder = temp;
	                }
			    }
			break;
		    }
		currCustomer = currCustomer->next;
	    }
    }
}

int DishAvailable(char *str, char *name)
{
    int flag = 0;
    for(int i = 0;i<strlen(str);i++)
    {
        if(str[i] == 'x' && (str[i+1] >= '0' && str[i+1] <= '9'))
        flag = i;
        if(i == strlen(str) && flag == 0)
        {
            printf("Please enter the order in the right format\n");
            return 0;
        }
    }
    char strTemp[255],numTempstr[5];
    for(int i = 0;i<flag-1;i++)
    {
        strTemp[i] = str[i];
    }
    int n=0;
    for(int i = flag;i<strlen(str);i++)
    {
        numTempstr[n] = str[i];
        n++;
    }
    int qtemp = 0, pow = 1;
    for(int i = 0;numTempstr[i]!='\0';i++)
    {
        qtemp += ((numTempstr[i] - '0') * pow);
	    pow *= 10;
    }
    currDish = headDish;
    while(currDish)
    {
        if(strcmp(currDish->Dish.name, strTemp) == 0)
        {
            if(qtemp < 1 || qtemp > currDish->Dish.quantity)
            {
                printf("there is not enough of that dish in stock\n");
                return 0;
            }
            else
            {
                pushOrder(createOrder(currDish->Dish.name, qtemp, currDish->Dish.price), name);
                currDish->Dish.quantity -= qtemp;
                if(currDish->Dish.quantity == 0)
                {
                    bool LOL = deleteDish(currDish->Dish.name);
                }
                return 1;
            }
        }
        currDish = currDish->next;
    }
    printf("That dish is not in the menu\n");
    return 0;
}

void Order()
{
    system("cls || clear");
    if(totalCustomer == 0)
    {
        printf("There is no customer\n");
        printf("Press enter to continue...\n");
        getchar();
        getchar();
        main_menu();
    }
    else if(No <= 1)
    {
        printf("There is no Dish available\n");
        printf("Press enter to continue...\n");
        getchar();
        getchar();
        main_menu();
    }
    char name[255],dish[258];
    int amount;
    do
    {
        printf("Insert the customer's name: ");
	    getchar();
	    scanf("%[^\n]", name);
    }while(CustomerPresent(name)!=1);
    do
    {
        printf("Insert amount of dish: ");
        scanf("%d", &amount);
        if(amount > (No)-1)
        {
            printf("You cannot order more types of dish than in the menu\n");
        }
    }while(amount > (No)-1);
    for(int i = 0;i<amount;i++)
    {
        do
		{
		getchar();
		printf("[%d] Insert the dish's name and quantity: ", i+1);
		scanf("%[^\n]", dish);
		}while(DishAvailable(dish, name)!=1);
    }
    main_menu();
}