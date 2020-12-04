void listCustomer()
{
    for(int i = 0;i < 26;i++)
    {
        currCustomer = headCustomer[i];
        while(currCustomer)
        {
            printf("%d. ", i);
			printf("%s\n", currCustomer->Customer.name);
            currCustomer = currCustomer->next;
        }
    }
}

void ViewWarteg()
{
    system("cls || clear");
    if(totalCustomer == 0)
    {
        printf("There is no customer\n");
    }
    else
    {
        printf("Customer's list\n");
        listCustomer();
    }
    printf("Press enter to continue...\n");
	getchar();
	getchar();
    main_menu();
}