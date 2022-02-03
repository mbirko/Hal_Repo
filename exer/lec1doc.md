# Lets get started with Linux! 
the purpuce of this exersize is to get familiarised with the linux enviroment. 
## 1.1
open a terminal and write down which commands you use to:
- Display the full path of the current folder?
  - pwd prints working directory
- What does the “∼” mean in relation to a path in Unix?
  - ~ is the icon for home directory (/ is for root)
- Get a list of all ﬁles and folders in the current folder?
  - ls is the command to list information about the current folder - followed by -a to show all files or a -all to show eerything about the files
- Change directory to /home/stud?
  - cd is the command used to **c**hange **d**irectory  
- Create a directory /home/stud/hal
  - mkdir creates a directory with the name equal to the argument of the command
- Change directory to the subdirectory /home/stud/hal
  - cd to change directory
- Create a directory exercise1
  - mkdir creates a new directory as described earlier
- Change directory to the subdirectory exercise1
  - cd to change directory and go a path even further down
- Create a ﬁle text1 containing "hello nano" using nano?
  - nano text1 creates a file and opens a window from which you can edit the file
- Create a ﬁle text2 containing "hello echo" using echo?
  - using the following command will create a text file with "Hello echo" using echo: echo hello echo > text2
- Append 1234567890 to file text1 using echo?
  - using the command >> appends data to an already existing file. The format is therefore echo 1234567890 >> text1
- Dump the contents of text1 to the terminal window?
  - Using the command echo $(\<text1) will print the contents of text 1 to the terminal.
- Create a directory temp
  - mkdir temp creates a file in directory currently in 
- Copy text1 to the directory temp
  - using this format will copy contents from one file to another file cp file_name new_file_name 
- Remove the subfolder temp and its content
  - rm -r temp removes the directory and all its contents including subfolders and files
- Delete text1 and text2 in one go?
  - rm text1 text2
- Install Visual Studio Code Install_vscode
  - snap install code --classic
- Create a small c program, hello_linux.c that prints out the text "Hello Linux!"
  - using visual stuid code create a file and add the .c extension and write the c program to print hello world. Afterwards use the command gcc -o [filename] [filename.c] to create a file that can be run
- Compile the program using gcc (tips here)
  - using command ./[filename] will run the program 
- Run the program, change file permissions with chmod if required (tips here)


Explain how ﬁle permissions work - check the chmod and read its man page.
-   it is either possible to have the permission to read, write or execute files. The permissions of all files in the directory can be read using ls -all were the r is read permission, w is write permission, x is execute permission and - is the lack of permission.

Write down which commands you use to:
-   Run the program nano in the background
    -   By the use of & after a command (e.g nano &) lets a command run things in the background as well as give you the ID of the program running in the background 
-   Now kill the program Kate you just started
    -   using the kill command followed by an ID lets you kill a program. The kill command has a bunch of different ways to stop a program hereunder are signals used to define the way to close the program in question. Kill -9 immediatly kills a program. 

Now, write a small shell script that echos "hello world" every second. Search for bash-scripts, while-do, sleep and echo. Remember to make your shell script executable using the program chmod.

Note down your script and the apropriate commands to make it executable and how to terminate it.

## 1.2

Open a terminal and write down which commands you use to:
- Display the full path of the current folder?
  - d
- What does the “∼” mean in relation to a path in Unix?
- Get a list of all ﬁles and folders in the current folder?
- Change directory to /home/stud?
- Create a directory /home/stud/hal
- Change directory to the subdirectory /home/stud/hal
- Create a directory exercise1
- Change directory to the subdirectory exercise1
- Create a ﬁle text1 containing "hello nano" using nano?
- Create a ﬁle text2 containing "hello echo" using echo?
- Append 1234567890 to file text1 using echo?
- Dump the contents of text1 to the terminal window?
- Create a directory temp
- Copy text1 to the directory temp
- Remove the subfolder temp and its content
- Delete text1 and text2 in one go?
- Install Visual Studio Code Install_vscode
- Create a small c program, hello_linux.c that prints out the text "Hello Linux!"
- Compile the program using gcc (tips here)
- Run the program, change file permissions with chmod if required (tips here)
