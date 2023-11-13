#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myObject {
    char title[50];
    char author[50];
};
// create structure object
struct myObject* m = NULL;

void getMain() {
    // assigning memory to struct variable m
    // m = (struct myObject*)malloc(sizeof(struct myObject));
    struct myObject book;
    char placeholder[50];
    printf("Title: \n");
    fgets(placeholder, 50, stdin);
    printf("%s",placeholder);
    // fgets(m.title, sizeof(m.title), stdin);
    // printf("%s", m.title);
    // m->title
    // printf("Title: \n");
    // fgets(m.title, sizeof(m.title), stdin);
    // printf("Author: \n");
    // fgets(m.author, sizeof(m.author), stdin);
    // return m;
    // struct Main m;
    // printf("Title: ");
    // fflush(stdout); // flush the output buffer
    // fgets(m.title, sizeof(m.title), stdin);
    // m.title[strcspn(m.title, "\n")] = '\0';
    // printf("%s", m.title);
    
    // // Consume the newline character from the input buffer
    // int ch;
    // while ((ch = getchar()) != '\n' && ch != EOF);

    // printf("Author: ");
    // fflush(stdout);
    // fgets(m.author, sizeof(m.author), stdin);
    // m.author[strcspn(m.author, "\n")] = '\0';
    // printf("%s", m.author);
    // return m;
}

void fileWriter(char title[], char author[]) {
    // open file
    FILE *file = fopen("filename.txt","a");
    printf("%s %s", title, author);
    fprintf(file, "\nTitle: %s, Author: %s\n", title, author);

    fclose(file);
}

void checkout(char title[], char author[]) {
    // first take out the book from filename.txt by copying all in filename
    // except book into new list, then copy that file into filename
    FILE *file = fopen("filename.txt","r");
    FILE *newFile = fopen("BooksCheckedOut.txt","a");
    char ch;
    if (file == NULL) {
        printf("File cannot be opened.\n");
        exit(0);
    }

    do {
        ch = fgetc(file);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(file);
    
    // add the book to checkout.txt
    fprintf(newFile, "\nTitle: %s, Author: %s\n", title, author);
    fclose(newFile);

}

char *fileReader(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Failed to open file.");
        return NULL;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate the necessary memory for the content
    char *content = (char *)malloc(file_size +1);

    if (content == NULL) {
        fprintf(stderr, "Something failed!\n");
        fclose(file);
        return NULL;
    }

    // read the file into the content buffer
    size_t bytesRead = fread(content, 1, file_size, file);
    content[bytesRead] = '\0';

    // close file 
    fclose(file);

    return content;
}

// use strcmp for the user to select an option, or switch case?
int main() {
    char choice[6];
    int numberChoice;
    // struct Main m = getMain();
    // printf("Title: %s\n", m.title);
    // printf("Author: %s\n", m.author);
    printf("Welcome to the library.");
    printf("Add a book, see whats listed, checkout a book, return a book, or remove a book altogether.");
    printf("Enter add, list, or delete.\n");
    scanf("%s",choice); // strcmp string compare
    // printf("%s", choice);
    if (strcmp(choice, "add") == 0) {
        fflush(stdin);
        struct myObject book;
        printf("Enter title: \n");
        scanf("%[^\n]%*c", book.title);
        printf("Enter author: \n");
        scanf("%[^\n]%*c", book.author);
        fileWriter(book.title, book.author);
        printf("Added.");
    } else if (strcmp(choice, "list") == 0) {
        printf("%s", fileReader("filename.txt"));
    } else if (strcmp(choice, "checkout") == 0) {
        // struct Main m = getMain();
        // checkout(m.title, m.author);
    } else if (strcmp(choice, "return")) {

    } else if (strcmp(choice, "remove")) {

    } else {
        exit(0);
    }
    
    return 0;
}