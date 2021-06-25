#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
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
product P[100];
int n;
void Login()
{
    customer p;
    int i=0;
    int c=1;
    gotoxy(30,6);printf("ENTER YOUR USERNAME :");
    gets(p.name);
    gotoxy(30,7);printf("ENTER YOUR PASSWORD :");
    while(1)
    {
        p.password[i]=getch();
        printf("*");
        if(p.password[i]==13)
        {
            break;
        } else if(p.password[i]==8)
        {
             if(i>0)
             {
                 i--;
                 printf("\b \b");
             }
        }
        i++;
    }
}

void add(int number)
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
void inventory()
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
int found(int code)
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
void purchase()
{
    int i;
    int code;
    int position;
    printf("Input code :");
    scanf("%d",&code);
    position=found(code);
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
product high_sales()
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
void delete_product()
{
    int code;
    int i;
    printf("Input code :");
    scanf("%d",&code);
    if(found(code)==-1)
    {
        printf("PRODUCT UNVAILABLE ");
    } else
    {
        for(i=found(code);i<n;i++)
        {
            P[i]=P[i+1];
        }
        n--;
        printf("\nTHE PRODUCT IS SUCCESFFULLY DELETED FROM THE LIST \n");
    }
}
void edit()
{
    int i;
    int code;
    int position;
    printf("Enter the Product code you wich to edit : ");
    scanf("%d",&code);
    position=found(code);
    if(found(code)==-1)
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
void discount_products()
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
void main()
{
    //Local variables :
    int choice;
    int action;
    int number;
    int *p;
    product max;
    //login to a certain account
    Login();
    do
    { clrscr();
     gotoxy(37,1);printf("*********Welcome To the grocerie store********\n");
     gotoxy(40,4);puts("[1]=Add a New product to the list ");
     gotoxy(40,5);puts("[2]=View inventory ");
     gotoxy(40,6);puts("[3]=Make a Purshase ");
     gotoxy(40,7);puts("[4]=Display products with highest sales  ");
     gotoxy(40,8);puts("[5]=Delete a product ");
     gotoxy(40,9);puts("[6]Edit product ");
     gotoxy(40,10);puts("[7]=Display products with Discounts  ");
     gotoxy(40,11);puts("[8]=Exit programme ");
     gotoxy(40,12);scanf("%d",&choice);
     switch(choice)
     {
     case 1:
        {
            printf("Input the Number of products you wish to add : ");
            scanf("%d",&number);
            p=(int *)malloc(number*sizeof(int));
            if(*p==NULL)
            {
                printf("NOT ENOUGH SPACE");
            } else if(*p==NULL)
            {
                add(number);
            }
        } break;
         case 2:inventory();break;
         case 3:purchase();break;
         case 4:
            {
                //product with highest sales:
                max= high_sales();
                if(n!=0)
                {
                    printf("Code : %d\n",max.code);
                    printf("Name : %s\n",max.name);
                    printf("Price : %.2f \n",max.price);
                    printf("Discount : %.2f %%\n",max.discount);
                    printf("Quantity Purchased : %d\n",max.number);
                    printf("Stock Remaining : %d\n",max.qte-max.number);
                    printf("Total Sales : %.2f MAD\n",max.totalAmount);
                }
            } break;
         case 5:delete_product();break;
         case 6:
            {
                //editing a product :
                //here;
                edit();
            } break;
         case 7:
            {
                discount_products();
            } break;
         case 8:printf("goodbye :) ");getch();exit(0);break;
         default:printf("Wrong");break;
     }
     printf("\n---------------------------------------------\n");
     printf("Do you wan't to perform another action ? \n");
     printf("[1]=YES\n");
     printf("[2]=NOP\n");
     scanf("%d",&action);
    } while(action==1);
}

