
struct NodeCustomer *addC(char *name)
{
   struct NodeCustomer *temp = (NodeCustomer*)malloc(sizeof(NodeCustomer));
   strcpy(temp->Customer.name, name);
   temp->next = temp->prev = NULL;
   temp->headOrder = temp->tailOrder = NULL;
   return temp;
}

unsigned long long int DJB2(char *str)
{
    unsigned long long int hash = 5381;
    int c;
    while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
    return hash % 26;
}

void insert(struct NodeCustomer *temp, char *name) 
{
    unsigned long long int index = DJB2(name);
    if(headCustomer[index]) 
    {
        tailCustomer[index]->next = temp;
        tailCustomer[index] = temp;
    } 
    else 
    {
        headCustomer[index] = tailCustomer[index] = temp;
    }
    totalCustomer++;
}

int validname(char *str)
{
    for(int i = 0;str[i];i++)
    {
        if(str[i]==' ')
        return 1;
    }
    return 0;
}

void AddCustomer()
{
    system("cls || clear");
    char nametemp[255];
    do
	{
	    printf("Insert the Customer's name [without space]: ");
	    getchar();
        scanf("%[^\n]",nametemp);
    }while(validname(nametemp)==1);
    insert(addC(nametemp),nametemp);
    printf("Customer has been added\n");
    printf("Press enter to continue\n");
    getchar();
    getchar();
    main_menu();
}