#include "stdio.h"
#include "string.h"

struct book {
    int year;
    char author[20];
    char name[50];
    char pubhouse[30];
    int isDelete;
} ;

struct book books[500];

void qs(int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    struct book key = books[left];
    while (i < j) {
        while (i < j && strcmp(books[j].name, key.name) >= 0)
            j--;
        books[i] = books[j];
        while (i < j && strcmp(books[i].name, key.name) <= 0)
            i++;
        books[j] = books[i];
    }

    books[i] = key;
    qs(left, j - 1);
    qs(i + 1, right);

}

int main(int argc, char const *argv[]) {
    int i = 0;
    FILE *fp = fopen("books.txt", "r");
    FILE *fp1 = fopen("ordered.txt", "w");
    while (!feof(fp)) {
        fscanf(fp, "%s%s%s%d", books[i].name, books[i].author, books[i].pubhouse, &books[i].year);
        books[i].isDelete = 0;
        i++;
    }

    int max = i;

    qs(0, i - 1);

    int choice=0;

    while (1) {
        scanf("%d", &choice);
        if (choice == 0){
            qs(0, i-1);
            int j;
            for (j = 1; j < i; ++j) {
                if (books[j].isDelete == 0)
                {
                    fprintf(fp1, "%-50s%-20s%-30s%-10d\n", books[j].name, books[j].author, books[j].pubhouse,  books[j].year);
                }
            }

            break;
        } 
        else if (choice == 1){
            scanf("%s%s%s%d", books[i].name, books[i].author, books[i].pubhouse, &books[i].year);
            books[i].isDelete = 0;
            i++;
            qs(0, i-1);
            max = i;
        } 
        else if (choice == 2){
            char tmp[20];
            int j;
            scanf("%s", tmp);
            for (j = 0; j < max; ++j) {
                if (strstr(books[j].name, tmp) != NULL && books[j].isDelete == 0){
                    printf("%-50s%-20s%-30s%-10d\n", books[j].name, books[j].author, books[j].pubhouse, books[j].year);
                }
            }
        } 
        else if (choice == 3){
            char tmp[20];
            int j;
            scanf("%s", tmp);
            for (j = 0; j < max; ++j) {
                if (strstr(books[j].name, tmp) != NULL){
                    books[j].isDelete = 1;
                }
            }
        }
    }

    fclose(fp);
    fclose(fp1);

    return 0;
}