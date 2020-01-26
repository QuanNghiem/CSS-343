Team—
Team member: Cuong Vo, Jessela Budiman, Quan Nguuyen

 
HOW TO COMPILE AND RUN THE PROGRAM

1.	Use cd "folder name" on the linux cmd to get to the folder that contains the lab 4 files. 

2.	Once in that folder, type “g++ *.cpp” to compile all cpp files within that folder. Now there will be an a.out file

3.	To run the program, type ./a.out to print to the console. To print to a text file, type ./a.out > output.txt 2>&1. The running process is recorded into the output.txt.

4.	You can change the input files name in main.cpp:
•	InfileCustomer is the data input for the customer.
•	infileMovies is the data for movies.
•	infileTransaction is the data for transactions.


For using valgrind check:
Type chmod 700 "file-name".cpp to provide permission to the file.
Type valgrind --leak-check=full -v ./"file-name".cpp > valgrind.txt 2>&1 to record the valgrind results and running process into the valgrind.txt.

Team—
Cuong Vo
Jessela Budiman
Quan Nghiem

Cuong Vo: Customer, HashTable, Store, Putting everything together, fixing errors and debug all files, help with readme.
Jessela Budiman: Customer, Transaction, and children of Transaction, Borrow, Return, History, Commenting and documenting, help with debug.
Quan Nghiem: Product, Movie, and children of Movie, Readme, help with debug
