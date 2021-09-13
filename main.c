#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    //Local variables :
    int choice;
    int action;
    int number;
    product max;
    product *P;
    //login to a certain account
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
     gotoxy(40,10);puts("[8]=Save products in a specific file   ");
     gotoxy(40,11);puts("[9]=Exit programme ");
     gotoxy(40,12);scanf("%d",&choice);
     switch(choice)
     {
         case 1:
             {
                printf("Input number of items youi wich to add :");
                scanf("%d",&number);
                //Allocate the memory
                P = (product *)malloc(sizeof(product)*number);
                if(P!=NULL)
                {
                    add(P,number);
                    //free memory
                    free(P);
                } else
                {
                    printf("Full storage");
                }
             }break;
         case 2:inventory(P);break;
         case 3:purchase(P);break;
         case 4:
            {
                //product with highest sales:
                max= high_sales(P);
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
         case 5:delete_product(P);break;
         case 6:
            {
                //editing a product :
                //here;
                edit(P);
            } break;
         case 7:
            {
                discount_products(P);
            } break;
         case 8: Save(P,n);break;
         case 9:printf("goodbye :) ");getch();exit(0);break;
         default:printf("Wrong");break;
     }
     printf("\n---------------------------------------------\n");
     printf("Do you wan't to perform another action ? \n");
     printf("[1]=YES\n");
     printf("[2]=NOP\n");
     scanf("%d",&action);
    } while(action==1);
}

