

/*A Book Management System is required to efficiently organize and manage
information about books. The system should support various operations,
including adding, removing, searching, updating, and displaying book records
based on attributes such as Book ID, Book Name, Author Name, Price, and
Rating. Additionally, the system should provide the capability to show details
of books written by a specific author, display the top 3 books based on price
and rating, and access information about all the books in the database.*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct Book {
    int bookid;
    char bookname[20];
    char authorname[20];
    double price;
    double rating;
} Book;

void storeBooks(Book *,int);
void display(Book *);
void showAuthor(Book *);
int searchBookId(Book*,int );
int searchByName(Book* ,char* );
int searchByAuthorName(Book* ,char* );
void display1(Book );
void removeBook(Book*);
void updateBook(Book *, int);
void top3BooksPrice(Book* );
void top3BooksRating(Book* );

int ctr=0;

void main() {
    int n,choice;
    printf("Enter the number of books you want to store: ");
    scanf("%d", &n);
  // Book books[n];
      Book* b1=(Book*) malloc (sizeof(Book)*n);
    

    do {
    	printf("\n************************Menu*********************\n");
        printf("1. Adding.\n2. Displaying.\n3. Searching.\n4. Removing.\n5. Updating.\n6. Display top 3 books price. \n7. display top 3 books rating \n8.showauthor\n0. To exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
        case 1:
            storeBooks(b1,n);
            ctr++;
            break;
        case 2:
            display(b1);
            break;
        case 3:
            {
		  	int select;
		  	printf("1.search by id\n2.search by name\n3.search by author name\n");
		  	printf("you select :");
		  	scanf("%d",&select);
		  	//------------SEARCH 1-------------------
		  	if(select==1)
		   {
				  		printf("\nyou select search by id: ");
				  		int bid;
				  	printf("\nSearch by id\nPlease Enter book id:");
				  	scanf("%d",&bid);
				  	int	f=searchBookId(b1,bid);
				  		if(f==-1)
						  {
							printf("\nNot Found!!!\n");
						  }	
						else
						{
							printf("\npresent\n");
							display1(b1[f]);
						}
		   }
			  
			  //------------SEARCH 2------------------- 
			else if(select==2)
		{
			printf("\nyou select search by name: ");
		  	char bn[20];	
		  	printf("\nSearch by book name\nPlease Enter book name:");
		  	scanf("%s",bn);
		  	int	m=searchByName(b1,bn);
		  		if(m==-1)
				{
					printf("\nNot Found!!!\n");
				}	
				else
				{
					printf("\npresent\n");
					display1(b1[m]);
				}
		}
			
			//--------------SEARCH 3--------------------------- 
			else if(select==3)
		{
			printf("\nyou select search by author name: ");
			  char ban[20];
			  int d;
			  printf("\nSearch by author name\nPlease Enter author name:");
			  fflush(stdin);
		  	scanf("%s",ban);
		  		d=searchByAuthorName(b1,ban);
		  		if(d==-1)
				{
					printf("\n--------Not Found!!!---------\n");
				}	
				else
				{
					printf("\npresent\n");
					display1(b1[d]);
				}
		}
			
			else
		{
			printf("\n-----------WRONG CHOICE-----------\n");	
		}
    }
            break;
        case 4:
        	
            removeBook(b1);
            break;
        case 5:
        	{
	        	int bid;
	            printf("Enter book id for updating: ");
	            scanf("%d", &bid);
	            updateBook(b1, bid);
          }
            break;
        case 6:
            //  sorting logic and display top 3 books
             top3BooksPrice(b1);
            break;
        case 7:
            	top3BooksRating(b1);
            	break;
        case 8:
            	 showAuthor(b1);
            	break; 
        case 0:
            printf("Thank You!!\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } 
	while (choice != 0);
    free(b1);   
}

/*Add Book: The system should allow users to add new books with their
attributes, including Book ID, Book Name, Author Name, Price, and
Rating.*/

void storeBooks(Book* b1,int n) {
    
    
	if (ctr == n )
	{
		printf("You've reached the maximum capacity.\n");
	} 
	else
	{
        printf("\tEnter book id: ");
        scanf("%d", &b1[ctr].bookid);
        printf("\tEnter book name: ");
       fflush(stdin);
       gets(b1[ctr].bookname);
          
          
        printf("\tEnter book author name: ");
        gets(b1[ctr].authorname);
        printf("\tEnter book price: ");
        scanf("%lf", &b1[ctr].price);
        printf("\tEnter book rating: ");
        scanf("%lf", &b1[ctr].rating);
        
    }   
         
       
}

/*Display All Books: The system should offer the option to display
details of all the books in the database, enabling users to access the
complete list of books.*/
void display(Book *b1) 
{
	int i;
	if(ctr == 0)
	{
		printf("\nNo book to display.");
	}
	else
	{
	    for (int i = 0; i < ctr; i++) 
		{
	        printf("-----------------Display book %d details---------------------\n",i+1);
	        printf("\tBook id: %d\n", b1[i].bookid);
	        printf("\tBook name: %s\n", b1[i].bookname);
	        printf("\tBook author name: %s\n", b1[i].authorname);
	        printf("\tPrice of book: %lf\n", b1[i].price);
	        printf("\tBook rating: %.2lf\n", b1[i].rating);
       }
   }
}

/*• Show Author's Books: Users should be able to retrieve a list of books
written by a specific author, helping readers explore an author's works.*/
 void showAuthor(Book *b1) {
    char author[100];
    printf("Enter author name to display their books: ");
    scanf("%s", author);

    for (int i = 0; i < ctr; i++) 
	{
        if (strcmp(b1[i].authorname, author) == 0) 
		{
            display1(b1[i]);
        }
    }
}

/*Search Book: The system should facilitate book retrieval by both Book
ID and Book Name, enabling users to quickly access book details.*/
int searchBookId(Book *b1,int bid)
{
		int i;
		for(i=0;i<ctr;i++)
		{
			if(b1[i].bookid==bid)
			{
				return i;
			}
		}
		return -1;
}

int searchByName(Book* b1,char* bn)
{
	  	int i;
	  	for(i=0;i<ctr;i++)
		  {
	  		if(strcmp(b1[i].bookname,bn)==0)
			  {
	  			return i;
			  }
		  }
		  return -1;
}	 
	  

int searchByAuthorName(Book* b1,char* ban)
{

  	for(int i=0;i<ctr;i++)
	  {
		  if(strcmp(b1[i].authorname,ban)==0)
		  {
  			display1(b1[i]);
  			return i;
		  }
	  }
	  return -1;
}	
//book display
void display1(Book b)
{
   	        printf("\n--------------Display  details----------------\n");
			printf("\nBook id:%d\n",b.bookid);
			printf("\nBook name:%s\n",b.bookname);
			printf("\nBook author name:%s\n",b.authorname);
			printf("\nPrice of book:%lf\n",b.price);
			printf("\nBook rating:%lf\n",b.rating);	
			printf("\n");
}
			

  


/*Remove Book: Users should be able to remove books from the system,
ensuring that associated data is deleted while preserving data integrity.*/
void removeBook(Book* b1)
{
			int bid;
			printf("\nEnter book id:");
			scanf("%d",&bid);
			int i=searchBookId(b1,bid);                         
			if(i==-1)
		     {
				printf("\nBook id not found");
			 }	
				else
				{
					while(i<ctr-1)
					{
						b1[i]=b1[i+1];
						i++;
					}
						ctr--;
						printf("\nBook removed successfully\n");
				}
				display(b1);		
}

/*Update Book Data: Users must have the ability to update a book's Price
and Rating, providing a means for keeping book information accurate
and up-to-date.*/
void updateBook(Book *b1, int bid) 
{
			int i = searchBookId( b1,bid);
			
			if (i == -1) 
			{
			    printf("\nBook id not found\n");
			} 
			else 
			{    
			    int select;
				printf("\nEnter you want to select:");
				scanf("%d",&select);
				if(select==1)
				   {
					    printf("\tEnter new book price: ");
					    scanf("%lf", &b1[i].price);
			       }
			    else if(select==2)
			       {
					    printf("\tEnter new book rating: ");
					    scanf("%lf", &b1[i].rating);
			       }
			    else
					{
						printf("wrong choice...");
					}
				 printf("\nBook updated successfully\n");
			}
			display(b1);
}
/*Display Top 3 Books: The system should provide a feature to display
the top 3 books based on price and rating, allowing users to see the
highest-priced and highest-rated books in the collection.*/
void top3BooksPrice(Book* b1)
{
    printf("Displaying top 3 books by price :\n");

    // Sort the books by price in descending order
    for (int i = 0; i < ctr - 1; i++) 
	{
        for (int j = i + 1; j < ctr; j++) 
		{
            if (b1[i].price < b1[j].price) 
			{
                  Book temp = b1[i];
                 b1[i] = b1[j];
                 b1[j] = temp;
            }
        }
    }

    // Display the top 3 books by price 
    for (int i = 0; i < 3 && i < ctr; i++) 
	{
       printf("Book ID: %d\n", b1[i].bookid);
        printf("Book Name: %s\n", b1[i].bookname);
        printf("Price: %.2lf\n", b1[i].price);
        printf("Rating: %.2lf\n\n", b1[i].rating);
    }
}

void top3BooksRating(Book* b1)
{
    printf("Displaying top 3 books by  their ratings:\n");

    // Sort the books by price in descending order
    for (int i = 0; i < ctr - 1; i++) 
	{
        for (int j = i + 1; j < ctr; j++) 
		{
            if (b1[i].rating < b1[j].rating) 
			{
                 Book temp = b1[i];
                 b1[i] = b1[j];
                 b1[j] = temp;
            }
        }
    }

    // Display the top 3 books by  ratings
    for (int i = 0; i < 3 && i < ctr; i++) 
	{
       printf("Book ID: %d\n", b1[i].bookid);
        printf("Book Name: %s\n", b1[i].bookname);
        printf("Price: %.2lf\n", b1[i].price);
        printf("Rating: %.2lf\n\n", b1[i].rating);
    }
}
