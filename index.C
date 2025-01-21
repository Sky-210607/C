#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_USERS 100
#define MAX_BOOKS 1000

typedef struct{
char username[50];
char password[50]
int isAdmin;
} User;

typedef struct {
int id;
char title[MAX_TITLE_LENGTH];
char author[50];
int isIssued;
} Book;

Book_books[MAX_BOOKS];
int bookCount=0;

void clearInputBuffer (){
  int c;
while((c=getchar())!='\n' && c!=EOF);
}

void saveBooksToFile () {
  FILE*file=fopen("books.dat","wb");
if(!file) {
printf("error saving books data!"):
return;
}
fwrite (&bookCount, sizeof(bookCount), 1, file);
fwrite(books,sizeof(Book),bookCount, file):
fclose(file);
}

void loadBooksFromFile() {
  FILE*file=fopen("books.dat", "rb");
if(file) {
fread(&bookCount, sizeof(bookCount),1, file);
fread(books, sizeof(Book) bookCount, file);
fclose(file);
}else {
printf("No book data found, starting fresh")
  }
}

void addUser(User users[], int*userCount) {
  if(*userCount>=MAX_USERS) {
printf("user limit reached");
return;
  }
char
int
printf(
scanf(

