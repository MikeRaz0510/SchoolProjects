/*
Mike Rasmussen
z1696323
466-PE1
3/22/23"
*/

\!echo "Connect to henrybooks database"
USE henrybooks;

-- 1
Select authorFirst, AuthorLast      -- Select the Authors first and last names
FROM Author                         -- From the Author Table
ORDER BY AuthorFirst Asc;           -- In Alphabetical order

-- 2
SELECT UNIQUE City 
FROM Publisher;

SELECT Count(Title) FROM Book;
SELECT Branch.BranchName, Sum(OnHand) FROM Inventory, Branch WHERE Branch.BranchNum = Inventory.BranchNum GROUP BY Inventory.BranchNum;
SELECT Sum(NumEmployees) FROM Branch;
SELECT Title FROM Book, Author, Wrote WHERE Wrote.BookCode = Book.BookCode AND Wrote.AuthorNum = Author.AuthorNum AND AuthorLast = 'King';
SELECT Title, Type, Price FROM Book WHERE Paperback = 'Y';
SELECT BranchName FROM Branch, Inventory WHERE Branch.BranchNum = Inventory.BranchNum AND OnHand >= 10;
SELECT Title, AuthorFirst, AuthorLast FROM Book, Author, Wrote WHERE Wrote.BookCode = Book.BookCode AND Wrote.AuthorNum = Author.AuthorNum ORDER BY Title DESC;
SELECT PublisherName, Count(*) FROM Publisher, Book WHERE Publisher.PublisherCode = Book.PublisherCode GROUP BY Publisher.PublisherCode;
SELECT Count(*) FROM Book WHERE Price < 10;
SELECT AuthorLast FROM Author, Wrote, Book, Publisher WHERE Author.AuthorNum = Wrote.AuthorNum AND Wrote.BookCode = Book.BookCode AND Book.PublisherCode = Publisher.PublisherCode AND PublisherName = 'Simon and Schuster';
SELECT Type, Count(Type) FROM Book GROUP BY Type;
SELECT Sum(OnHand), BranchLocation FROM Branch.BranchNum = Inventory.BranchNum AND BranchLocation = 'Brentwood Mall';
SELECT BranchLocation, NumEmployees, Sum(OnHand) FROM Branch, Inventory WHERE Branch.BranchNum = Inventory.BranchNum GROUP BY Inventory.BranchNum;
SELECT Title FROM Book WHERE BookCode IN (SELECT BookCode FROM Wrote WHERE Sequence = 1);
SELECT PublisherName FROM Publisher WHERE PublisherName  LIKE 'T%';
SELECT * FROM Author WHERE AuthorLast LIKE '%ll%' OR AuthorFirst LIKE '%ll%';
SELECT Title FROM Book WHERE BookCode = '079x' OR BookCode = '138x' OR BookCode = '669x';
SELECT Title, AuthorLast, PublisherName FROM Book, Author, Wrote, Publisher WHERE Author.AuthorNum = Wrote.AuthorNum AND Wrote.BookCode = Book.BookCode AND Book.PublisherCode = Publisher.PublisherCode ORDER BY PublisherName ASC;
SELECT Title FROM Book, Wrote WHERE Wrote.BookCode = Book.BookCode AND Wrote.Sequence = 1;
SELECT Title FROM Book WHERE BookCode LIKE '%x';
SELECT AuthorFirst, AuthorLast, Count(Title) FROM Author, Book, Wrote, Publisher WHERE Author.AuthorNum = Wrote.AuthorNum AND Wrote.BookCode = Book.BookCode AND Book.PublisherCode = Publisher.PublisherCode GROUP BY Author.AuthorNum;