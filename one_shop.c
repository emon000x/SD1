#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define USERNAME "admin"
#define PASSWORD "1234"
#define MAX 20

typedef struct items
{
    char product_code[MAX];
    char product_name[MAX];
    int rate;
    int quantity;
    float weight;
    char description[30];

} ITEM;

ITEM item;
int isCodeAvailable(char code[])
{
    FILE *file;
    file = fopen("Record.txt", "r");
    while (!feof(file))
    {
        fread(&item, sizeof(item), 1, file);
        if (strcmp(code, item.product_code) == 0)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
int isProductAvailable(int quantity)
{
    FILE *file;
    file = fopen("Record.txt", "r");
    while (!feof(file))
    {
        fread(&item, sizeof(item), 1, file);
        if (item.quantity >= quantity)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
int get_int(int input)
{
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
        }
        printf("\n\tMust be positive integer.\n");
        printf("\t\Enter Positive integer value, such as 1,2,3,4: ");
    }

    return input;
}

int check_rate()

{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
        }
        printf("\033[1;31m");
        printf("\n\t\tRate be positive Integer.\n");
        printf("\033[0m");
        printf("\t\tEnter rate of the product in positive integer: ");
    }

    return input;
}
void addProduct()
{
    printf("**********************************\n");
    printf("*    Add Product - One Shop      *\n");
    printf("**********************************\n");
    FILE *file;
    char code[MAX];
    char x[4] = {0};
    int a;
    file = fopen("Record.txt", "ab");
    printf("\n\tEnter 0 to return Main Menu.\n");
    printf("\n\tEnter Product code: ");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    int available;
    available = isCodeAvailable(code);
    if (available == 1)
    {
        system("cls");
        printf("\033[1;31m");
        printf("\n\t*Product is already there.\n");
        printf("\033[0m");
        options();
    }
    strcpy(item.product_code, code);
    printf("\tEnter Product Name: ");
    scanf("%s", item.product_name);
    printf("\n\tEnter Product Rate: ");
    a = check_rate();
    item.rate = a;
    printf("\n\tEnter Quantity: ");
    scanf("%d", &item.quantity);
    printf("\n\tEnter product Weight(in gram): ");
    scanf("%f", &item.weight);
    printf("\n\tEnter product descriptions: ");
    scanf(" %s", item.description);
    fwrite(&item, sizeof(item), 1, file);
    fclose(file);
        system("cls");
        printf("\033[0;32m");
        printf("\n\tProduct added successfully!\n");
        printf("\033[0m");
        display();
}
void updateProduct()
{
    printf("**********************************\n");
    printf("*   Update Product - One Shop    *\n");
    printf("**********************************\n");
    display();
    FILE *file1, *file2;
    char code[MAX], product[MAX];
    int available;
    int a;
    if (file1 == NULL){
         printf("\t\tNo Product is inserted!\n");
         options();
    }
    printf("\n\tEnter 0 to return Main Menu.\n");
    printf("\n\tEnter the Product code to update the record:");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    available = isCodeAvailable(code);
    if (available == 0) {
        system("cls");
        printf("\033[1;31m");
        printf("\n\t*no Product is found for update!\n");
        printf("\033[0m");
    }
    else
    {
        file1 = fopen("Record.txt", "rb");
        file2 = fopen("tempfile.txt", "wb");
        while (fread(&item, sizeof(item), 1, file1))
        {
            strcpy(product, item.product_code);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, file2);
            }
            else
            {
                printf("\n\tUpdating data for the privious product %s\n", code);
                printf("\tEnter Product Name: ");
                scanf("%s", item.product_name);
                printf("\n\tEnter Product Rate: ");
                a = check_rate();
                item.rate = a;
                printf("\n\tEnter Quantity: ");
                scanf("%d", &item.quantity);
                printf("\n\tEnter product Weight(in gram): ");
                scanf("%f", &item.weight);
                printf("\n\tEnter product descriptions: ");
                scanf(" %s", item.description);
                printf("\n\n");
                fwrite(&item, sizeof(item), 1, file2);
            }
        }
        fclose(file1);
        fclose(file2);
        file1 = fopen("Record.txt", "wb");
        file2 = fopen("tempfile.txt", "rb");
        while (fread(&item, sizeof(item), 1, file2))
        {
            fwrite(&item, sizeof(item), 1, file1);
        }
        fclose(file1);
        fclose(file2);

        system("cls");
        printf("\033[0;32m");
        printf("\n\tProduct updated!\n");
        printf("\033[0m");
        display();
    }
}
void updateProductQty()
{
    printf("**********************************\n");
    printf("* Update Product Qty - One Shop  *\n");
    printf("**********************************\n");
    display();
    FILE *file1, *file2;
    char code[MAX], product[MAX];
    int available;
    int a;
    if (file1 == NULL){
         printf("\t\tNo Product is inserted!\n");
         options();
    }
    printf("\n\tEnter 0 to return Main Menu.\n");
    printf("\n\tEnter Product code: ");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    available = isCodeAvailable(code);
    if (available == 0) {
        system("cls");
        printf("\033[1;31m");
        printf("\n\t*no Product is found for update!\n");
        printf("\033[0m");
    }
    else
    {
        file1 = fopen("Record.txt", "rb");
        file2 = fopen("tempfile.txt", "wb");
        while (fread(&item, sizeof(item), 1, file1))
        {
            strcpy(product, item.product_code);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, file2);
            }
            else
            {
                printf("\n\tUpdating quantity for the privious product %s\n", code);
                printf("\n\tEnter Quantity: ");
                scanf("%d", &item.quantity);
                printf("\n\n");
                fwrite(&item, sizeof(item), 1, file2);
            }
        }
        fclose(file1);
        fclose(file2);
        file1 = fopen("Record.txt", "wb");
        file2 = fopen("tempfile.txt", "rb");
        while (fread(&item, sizeof(item), 1, file2))
        {
            fwrite(&item, sizeof(item), 1, file1);
        }
        fclose(file1);
        fclose(file2);

        system("cls");
        printf("\033[0;32m");
        printf("\n\tProduct updated!\n");
        printf("\033[0m");
        display();
    }
}
void updateProductRate()
{
    printf("**********************************\n");
    printf("* Update Product Rate - One Shop *\n");
    printf("**********************************\n");
    display();
    FILE *file1, *file2;
    char code[MAX], product[MAX];
    int available;
    int a;
    if (file1 == NULL){
         printf("\t\tNo Product is inserted!\n");
         options();
    }
    printf("\n\tEnter 0 to return Main Menu.\n");
    printf("\n\tEnter Product code: ");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    available = isCodeAvailable(code);
    if (available == 0) {
        system("cls");
        printf("\033[1;31m");
        printf("\n\t*no Product is found for update!\n");
        printf("\033[0m");
    }
    else
    {
        file1 = fopen("Record.txt", "rb");
        file2 = fopen("tempfile.txt", "wb");
        while (fread(&item, sizeof(item), 1, file1))
        {
            strcpy(product, item.product_code);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, file2);
            }
            else
            {
                printf("\n\tUpdating Rate for the privious product %s\n", code);
                printf("\n\tEnter Product Rate: ");
                a = check_rate();
                item.rate = a;
                printf("\n\n");
                fwrite(&item, sizeof(item), 1, file2);
            }
        }
        fclose(file1);
        fclose(file2);
        file1 = fopen("Record.txt", "wb");
        file2 = fopen("tempfile.txt", "rb");
        while (fread(&item, sizeof(item), 1, file2))
        {
            fwrite(&item, sizeof(item), 1, file1);
        }
        fclose(file1);
        fclose(file2);

        system("cls");
        printf("\033[0;32m");
        printf("\n\tProduct updated!\n");
        printf("\033[0m");
        display();
    }
}
void display()
{
    FILE *file;
    int count = 0;
    file = fopen("Record.txt", "rb");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("CODE\t||\tNAME\t\t||\tRATE\t||\tQUANTITY\t||\tWEIGHT\t||\tDESCRIPTION\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    if (file == NULL)
    {
        printf("\t\tNo Product is inserted.\n");
        options();
    }
    while (fread(&item, sizeof(item), 1, file))
    {
        printf("%s\t||\t%s\t\t||\t%d BDT\t||\t %d\t\t||\t%.2f\t||\t%s \n", item.product_code, item.product_name, item.rate, item.quantity, item.weight, item.description);
        printf("----------------------------------------------------------------------------------------------------------------\n");
    count++;
    }
    if (count == 0)
    {
        system("cls");
        printf("\033[1;31m");
        printf("\n\tNo product available.\n");
        printf("\033[0m");
    }
    fclose(file);
}
void close_app()
{
    char choice;
    printf("\n Do you want to close the applications?(Y/N)");
    scanf("%s", &choice);
    if (choice == 'Y' || choice == 'y'){
        exit(0);
    }
    else if(choice == 'N' || choice == 'n'){
        system("cls");
        options();
    }else{
        system("cls");
        options();
    }
}
void search()
{
    FILE *file;
    char code[MAX], product[MAX];
    int available;
    printf("**********************************\n");
    printf("*   Search Products - One Shop   *\n");
    printf("**********************************\n");
    printf("\tEnter 0 to return main menu.\n");
    printf("\tEnter the Product code to search: ");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    system("cls");
    printf("\t Product information\n");
    printf("\t*********************\n");
    available = isCodeAvailable(code);
    if (available == 0)
    {
        system("cls");
        system("cls");;
        printf("\n\tProduct code is not found.\n");
    }
    else
    {
        file = fopen("Record.txt", "rb");
        while (fread(&item, sizeof(item), 1, file))
        {
            strcpy(product, item.product_code);
            if (strcmp(product, code) == 0)
            {
                printf("\n\tProduct Code:        %s", item.product_code);
                printf("\n\tName of Product:     %s", item.product_name);
                printf("\n\tRate of Product(BDT):%d", item.rate);
                printf("\n\tProduct Weight:      %.2f", item.weight);
                printf("\n\tProduct Description: %s\n", item.description);
            }
        }
        fclose(file);
    }
}
void deleteRecord()
{
    FILE *file1, *file2;
    char code[MAX], product[MAX];
    int available;
    file1 = fopen("Record.txt", "rb");
    if (file1 == NULL)
    {
        printf("\033[1;31m");
        printf("\t\tNo Product is inserted.");
        printf("\033[0m");
        options();
    }
    display();
    printf("\tEnter 0 to return main menu.\n");
    printf("\tEnter the Product code to delete: ");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }
    system("cls");
    available = isCodeAvailable(code);
    if (available == 0)
    {
        system("cls");
        printf("\033[1;31m");
        printf("\n\tProduct is not available!\n");
        printf("\033[0m");
    }
    else
    {

        file2 = fopen("tempfile.txt", "wb");
        while (fread(&item, sizeof(item), 1, file1))
        {
            strcpy(product, item.product_code);
            if (strcmp(product, code) != 0)
            {
                fwrite(&item, sizeof(item), 1, file2);
            }
        }
        fclose(file1);
        fclose(file2);
        file1 = fopen("Record.txt", "wb");
        file2 = fopen("tempfile.txt", "rb");
        while (fread(&item, sizeof(item), 1, file2))
        {
            fwrite(&item, sizeof(item), 1, file1);
        }
        printf("\033[0;32m");
        printf("\n\tProduct deleted!\n\n");
        printf("\033[0m");
        fclose(file1);
        fclose(file2);
    }
}
void login()
{
    printf("************************************\n");
    printf("*         Login - One Shop         *\n");
    printf("************************************\n");
    char username[15], password[10];
    printf("Enter username: ");
    scanf("%s", username);
    printf("\nEnter password: ");
    scanf("%s", password);
    while (1)
    {
        if ((strcmp(USERNAME, username)) == 0 && (strcmp(PASSWORD, password)) == 0)
        {
            printf("\033[0;32m");
            printf("\nLogged in successfully!\n");
            printf("\033[0m");
            system("cls");
            options();
        }
        else
        {
            system("cls");
            printf("\033[1;31m");
            printf("\nWrong Credential,Please try again!\n");
            printf("\033[0m");
            login();
            break;
        }
    }
}
int main()
{
    login();
    system("cls");
    return 0;
}
void salesRepo()
{
    char code[MAX], product[MAX];
    printf("**********************************\n");
    printf("*    Sales Report - One Shop     *\n");
    printf("**********************************\n");

    printf("\n\tEnter 0 to return main menu.\n");
    printf("\033[0;33m");
    printf("\n\t\Coming Soon!\n");
    printf("\033[0m");
    scanf("%s", code);
    if (strcmp(code, "0") == 0)
    {
        system("cls");
        options();
    }


}
void saleProduct()
{
    printf("**********************************\n");
    printf("*    Sale Product - One Shop     *\n");
    printf("**********************************\n");
    display();
    char x[4] = {0};
    int q = 0, size = 0, i = 1;
    int total = 0, gtotal = 0;
    FILE *file;
    file = fopen("Record.txt", "r+b");
    rewind(file);
    int availableC, availableQ;
    printf("\tEnter 0 to finish input");
    int qty = item.quantity;
    while (1)
    {
        printf("\n\t\tEnter Item Code:");
        scanf("%s", x);
        if (strcmp(x, "0") == 0)
        {
            system("cls");
            break;
        }
        availableC = isCodeAvailable(x);
        if (availableC == 0)
        {
            system("cls");
            printf("\033[1;31m");
            printf("\n\t\* no Product is found.\n");
            printf("\033[0m");
            options();
        }
        printf("\t\t\t\tEnter Quantity:");
        scanf("%d", &q);
        qty = qty - q;
        if (qty < 0)
        {
            system("cls");
            printf("\033[1;31m");
            printf("\n\t*Out of stock!\n");
            printf("\033[0m");
            break;
        }
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if ((strcmp(item.product_code, x) == 0))
            {
                total = item.rate * q;
                printf("\n\t\t#%d \n", i);
                printf("\t\tProduct Name: %s \n", item.product_name);
                printf("\t\tProduct Quantity: %d \n", q);
                printf("\t\tProduct Rate: %d BDT\n", item.rate);
                printf("\t\tTotal: %d BDT\n", total);
                gtotal = gtotal + total;
                size = sizeof(item);
                item.quantity = item.quantity - q;

                i++;
                fseek(file, -size, SEEK_CUR);
                fwrite(&item, sizeof(item), 1, file);
                break;
            }
        }
    }
    if (gtotal != 0)
    {
        printf("\033[0;33m");
        printf("\n\tTOTAL AMOUNT = %d BDT\n", gtotal);
        printf("\033[0m");
    }
    fclose(file);
}
void options()
{
    printf("**********************************\n");
    printf("*            One Shop            *\n");
    printf("**********************************\n");
    int num, choice;
    while (1)
    {
        printf("\n\t1. Add product");
        printf("\n\t2. All products");
        printf("\n\t3. Search product");
        printf("\n\t4. Delete Product");
        printf("\n\t5. Sale product");
        printf("\n\t6. Update product");
        printf("\n\t7. Update product Quantity");
        printf("\n\t8. Update product Rate");
        printf("\n\t9. Sales Report");
        printf("\n\t10. Logout\n\n");
        printf("\n\t11. Exit\n\n");
        printf("\tEnter your choice: ");
        choice = get_int(num);
        switch (choice)
        {
        case 1:
            system("cls");
            addProduct();
            break;
        case 2:
            system("cls");
            printf("**********************************\n");
            printf("*    All Products - One Shop     *\n");
            printf("**********************************\n");
            display();

            break;
        case 3:
            system("cls");
            search();
            break;
        case 4:
            system("cls");
            deleteRecord();
            break;
        case 5:
            system("cls");
            saleProduct();
            break;
        case 6:
            system("cls");
            updateProduct();
            break;
        case 7:
            system("cls");
            updateProductQty();
            break;
        case 8:
            system("cls");
            updateProductRate();
            break;
        case 9:
            system("cls");
            salesRepo();
            break;
        case 10:
            system("cls");
            login();
            break;
        case 11:
            system("cls");
            close_app();
            break;
        default:
            system("cls");
            printf("\033[1;31m");
            printf("\t*Invalid choice.\n");
            printf("\033[0m");
            break;
        }
    }
}
