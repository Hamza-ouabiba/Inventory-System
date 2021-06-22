#include<stdio.h>
#include<conio.h>
#include<string.h>
//a managent system :
//les prototypes des fonctions et procedures :
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
    float totalamount;
    float price;
    float discount;
    float totalAmount;
    int number;
    date manufacturing;
} product;
product P[100];
int n;
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
        printf("Price : %.2f \n",P[position].price);
        printf("Discount : %.2f %%\n",P[position].discount);
        printf("Input Number of purchases :");
        scanf("%d",&P[position].number);
        printf("\nRemaining in stocks : %d \n",P[position].qte-P[position].number);
        printf("Discount Amount: %.2f\n",P[position].discount*P[position].number);
        P[position].totalAmount=P[position].price-P[position].price*P[position].discount*P[position].number/100;
        printf("Total Amount : %.2f",P[position].totalAmount);
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
           } else if(P[i].price>max.price)
            {
                max=P[i];
            }
       }
   }
   return max;
}
void main()
{
    //Local variables :
    int choice;
    int action;
    int number;
    product max;
    do
    { clrscr();
     printf("*********Welcome To the grocerie store********\n");
     puts("[1]=Add a New product to the list ");
     puts("[2]=View inventory ");
     puts("[3]=Make a Purshase ");
     puts("[4]=Display products with highest sales  ");
     puts("[5]=Edit and Delete a product ");
     puts("[6]=Exit programme ");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:printf("Input number of items youi wich to add :");scanf("%d",&number);add(number);break;
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
                    printf("Discount : %d\n",max.discount);
                    printf("Quantity Purchased : %d\n",max.number);
                    printf("Stock : %d\n",max.qte);
                    printf("Total Sales : %.2f\n",max.totalamount);
                }
            } break;
         case 8:printf("goodbye :) ");getch();exit(0);break;
         default:printf("Wrong");break;
     }
     printf("\n---------------------------------------------\n");
     printf("Do you wan't to perform another action ? \n");
     printf("[1]=YES\n");
     printf("[1]=NOP\n");
     scanf("%d",&action);
    } while(action==1);
}
