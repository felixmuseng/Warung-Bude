int CustomerPresent(char *name)
{
    for(int i = 0; i < 26;i++)
	{
		if(headCustomer[i])
		{
			currCustomer = headCustomer[i];
			while(currCustomer)
			{
				if(strcmp(currCustomer->Customer.name, name) == 0){
					return 1;
				}
				currCustomer = currCustomer->next;
			}
		}
	}
    return 0;
}

void SearchCustomer()
{
    system("cls || clear");
	char name[255];
	printf("Insert the customer's name to be searched: ");
	getchar();
	scanf("%[^\n]", name);
	int present = CustomerPresent(name);
	(present == 1) ? printf("%s is present.\n", name) : printf("%s is not present.\n", name);
	printf("Press enter to continue...\n");
	getchar();
	getchar();
    main_menu();
}