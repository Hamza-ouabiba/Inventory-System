#ifndef D_H_INCLUDED
#define D_H_INCLUDED
//a managent system :
typedef struct
{
    int d;
    int m;
    int y;
} date;
typedef struct
{
    char name[20];
    int code;
    int qte;
    int purchase;
    float price;
    float discount;
    float totalAmount;
    int number;
    date manufacturing;
} product;
typedef struct
{
   char name[20];
   char password[20];
} customer;
int n;
void Login()
{
    int i=0;
    char user[]="user";
    char passwordd[]="pass";
    do {
            clrscr();
     printf("Username: ");
    fflush(stdin);
    gets(user);
    printf("Password: ");
    while(i<12)
    {
         fflush(stdin);
         passwordd[i]=getch();
          if(passwordd[i]==13)
            {
            break;
           } else {
             printf("*");
           }
          i++;
       }
    passwordd[i]='\0';
    } while(strcmp(user,"user")!=0 || strcmp(passwordd,"pass")!=0);
}
void add(product *P,int number)
{
    int i;
    for(i=n;i<n+number;i++)
    {
        printf("\n---------------------------------------------\n");
        printf("Product Code :");
        scanf("%d",&P[i].code);
        printf("Product Name :");
        fflush(stdin);
        gets(P[i].name);
        printf("Quantity :");
        scanf("%d",&P[i].qte);
        printf("Price of product :");
        scanf("%f",&P[i].price);
        printf("Manufacturing Date(dd-mm-yy):");
        scanf("%d%d%d",&P[i].manufacturing.d,&P[i].manufacturing.m,&P[i].manufacturing.y);
        printf("Discount  : ");
        scanf("%f",&P[i].discount);
    }
    n+=number;
}
void inventory(product *P)
{
    int i;
    if(n!=0)
    {
     for(i=0;i<n;i++)
      {
        printf("\n---------------------------------------------\n");
        printf("\nPRODUCT NUMBER %d\n",i+1);
        printf("Serial Number : %d \n",P[i].code);
        printf("Product Name : %s \n",P[i].name);
        printf("Product Quantity :%d \n",P[i].qte);
        printf("Manufacturing Date :  %d/%d/%d \n",P[i].manufacturing.d,P[i].manufacturing.m,P[i].manufacturing.y);
        printf("Discount : %.2f %%\n",P[i].discount);
      }
    } else
    {
        printf("NO CURRENT PRODUCTS IN LIST");
    }
}
int found(int code,product *P)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(code==P[i].code)
        {
            return i;
        }
    }
    return -1;
}
void purchase(product *P)
{
    int i;
    int code;
    int position;
    printf("Input code :");
    scanf("%d",&code);
    position=found(code,P);
    if(position==-1)
    {
        printf("PRODUCT NO AVAILABLE");
    } else
    {
        printf("***Item Found***\n");
        printf("Name : %s \n",P[position].name);
        printf("Quantity : %d\n",P[position].qte);
        printf("Price : %.2f MAD \n",P[position].price);
        printf("Discount : %.2f %%\n",P[position].discount);
        printf("Input Number of purchases :");
        scanf("%d",&P[position].number);
        printf("\nRemaining in stocks : %d \n",P[position].qte-P[position].number);
        printf("Discount Amount: %.2f\n",P[position].discount*P[position].number);
        P[position].totalAmount=P[position].price*P[position].number-P[position].price*P[position].number*(P[position].discount*P[position].number/100);
        printf("Total Amount : %.2f MAD",P[position].totalAmount);
    }
}
product high_sales(product *P)
{
   int i;
   product max;
   if(n!=0)
   {
       for(i=0;i<n;i++)
       {
           if(i==0)
           {
               max=P[i];
           } else if(P[i].totalAmount>max.totalAmount)
            {
                max=P[i];
            }
       }
   }
   return max;
}
void delete_product(product *P)
{
    int code;
    int i;
    printf("Input code :");
    scanf("%d",&code);
    if(found(code,P)==-1)
    {
        printf("PRODUCT UNVAILABLE ");
    } else
    {
        for(i=found(code,P);i<n;i++)
        {
            P[i]=P[i+1];
        }
        n--;
        printf("\nTHE PRODUCT IS SUCCESFFULLY DELETED FROM THE LIST \n");
    }
}
void edit(product *P)
{
    int i;
    int code;
    int position;
    printf("Enter the Product code you wich to edit : ");
    scanf("%d",&code);
    position=found(code,P);
    if(found(code,P)==-1)
    {
        printf("PRODUCT UNAVAILALE IN THE STOCK LIST ");
    } else
    {
        printf("New Code :");scanf("%d",&P[position].code);
        printf("Name : ");fflush(stdin);gets(P[position].name);
        printf("Quantity : ");scanf("%d",&P[position].qte);
        printf("Price of Product : ");scanf("%f",&P[position].price);
        printf("Discount in percent : ");scanf("%f",&P[position].discount);
        printf("Manufacturing Date : ");scanf("%d%d%d",&P[position].manufacturing.d,&P[position].manufacturing.m,&P[position].manufacturing.y);
    }
}
void discount_products(product *P)
{
    int i;
    if(n!=0)
    {
        for(i=0;i<n;i++)
        {
            if(P[i].discount>0)
            {
                printf("\n---------------------------------------------\n");
                printf("\nPRODUCT NUMBER %d\n",i+1);
                printf("Serial Number : %d \n",P[i].code);
                printf("Product Name : %s \n",P[i].name);
                printf("Product Quantity :%d \n",P[i].qte);
                printf("Manufacturing Date :  %d/%d/%d \n",P[i].manufacturing.d,P[i].manufacturing.m,P[i].manufacturing.y);
                printf("Discount : %.2f %%\n",P[i].discount);
            }
        }
    } else
    {
        printf("NO PRODUCT IN THE INVENTORY  ");
    }
}
void Save(product *P,int n)
{
    FILE *a = NULL;
    int i;
    char location[20];
    if(n!=0)
    {
          printf("Where do you exactly wan't to save this Data (with the extension on it !!)? ");
          fflush(stdin);
          scanf("%s",location);
           a = fopen(location,"w");
    if(a!=NULL)
      {
        for(i=0;i<n;i++)
      {
        fprintf(location,"\n---------------------------------------------\n");
        fprintf(location,"\nPRODUCT NUMBER %d\n",i+1);
        fprintf(location,"Serial Number : %d \n",P[i].code);
        fprintf(location,"Product Name : %s \n",P[i].name);
        fprintf(location,"Product Quantity :%d \n",P[i].qte);
        fprintf(location,"Manufacturing Date :  %d/%d/%d \n",P[i].manufacturing.d,P[i].manufacturing.m,P[i].manufacturing.y);
        fprintf(location,"Discount : %.2f %%\n",P[i].discount);
      }
    }
    }else
    {
        printf("Can't open the file unfortunately :(");
    }
}
#endif
