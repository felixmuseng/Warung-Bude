
void popHeadDish()
{
    if(headDish && headDish == tailDish)
    {
       headDish = tailDish = NULL;
       free(headDish);
    }
    else
    {
       NodeDish *temp = headDish->next; 
       headDish->next = temp->prev = NULL;
       free(headDish);    
       headDish = temp;                     
   }
}

void popTailDish()
{
    if(headDish && headDish == tailDish)
    {
       headDish = tailDish = NULL;
       free(headDish);
    }
    else
    {
       NodeDish *temp = tailDish->prev; 
       tailDish->prev = temp->next = NULL;
       free(tailDish);    
       tailDish = temp;                     
   }
}

bool deleteDish(char * name)
{
    if(strcmp(headDish->Dish.name,name)==0)
    {
        popHeadDish();
        return true;
    }
    else if(strcmp(tailDish->Dish.name,name)==0)
    {
        popTailDish();
        return true;
    }
    else
    {
        currDish = headDish;
        while(currDish)
        {
            if(strcmp(currDish->Dish.name,name)==0)
            {
                currDish->prev->next = currDish->next;   
                currDish->next->prev = currDish->prev;
                currDish->next = currDish->prev = NULL;
                free(currDish);
                return true;
            }
            currDish = currDish->next;
        }
        return false;
    }
}

int calculateWidth()
{
    maxname=0,maxprice=0,maxpricewidth=0,maxnowidth=0;
    currDish = headDish;
    while(currDish)
    {
        if(strlen(currDish->Dish.name) > maxname)
        {
            maxname = strlen(currDish->Dish.name);
        }
        
        if(currDish->Dish.price > maxprice)
        {
            maxprice = currDish->Dish.price;
        }

        do
        {
            maxpricewidth++;
            maxprice /= 10;
        } while(maxprice != 0);

        int notemp = n;
        do
        {
            maxnowidth++;
            notemp /= 10;
        } while(notemp != 0);
        currDish = currDish->next;
    }
    int width = maxname + maxpricewidth + maxnowidth + 8;
    return width;
}

void heading()
{
    int width = calculateWidth();
    for(int i = 0;i < ((width/2)); i++)
    {
        printf(" ");
    }
    printf("Bude's Menu\n");
    for(int i = 0;i < (width+8); i++)
    {
        printf("=");
    }
    printf("\n");
    printf("No.");
    for(int i = 0;i<maxnowidth;i++)
    {
        printf(" ");
    }
    printf("Name");
    for(int i = 0;i<maxname-3;i++)
    {
        printf(" ");
    }
    printf("Quantity");
    printf(" ");
    printf("Price.");
    for(int i = 0;i<maxpricewidth-3;i++)
    {
        printf(" ");
    }
    printf("\n");
    for(int i = 0;i < (width+8); i++)
    {
        printf("=");
    }
    printf("\n");
}

void printdishtable()
{
    heading();
    currDish = headDish;
    int i = 1;
    while (currDish)
    {
        printf("%-*d. %-*s %03d      Rp%-*d\n",maxnowidth+1,i,maxname,currDish->Dish.name,currDish->Dish.quantity,maxpricewidth,currDish->Dish.price);
		i++;
        currDish = currDish->next;
    }

}

void RemoveDish()
{
    system("cls || clear");
    if(!headDish)
    {
        printf("There is No dish in the Menu\n");
        printf("Press enter to continue...\n");
        getchar();
        getchar();
        main_menu();
    }
    printdishtable();
    char rnameTemp[255];
    do
    {
        printf("Insert dish's name to be deleted: ");
        getchar();
        scanf("%[^\n]", rnameTemp);
    }while(!deleteDish(rnameTemp));
    printf("The dish has been removed!\n");
    printf("Press enter to continue...\n");
    getchar();
    getchar();
    main_menu();
}