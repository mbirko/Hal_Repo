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

## Birks Notes 1.2

Open a terminal and write down which commands you use to:
- Display the full path of the current folder
  - The cmd pwd will display the full path of the current folder
    - path working dirctorty 
- What does the “∼” mean in relation to a path in Unix?
  - THis indicates the root of the folder
- Get a list of all ﬁles and folders in the current folder?
  - LS or dir command 
- Change directory to /home/stud?
  - cd /home/stud
- Create a directory /home/stud/hal
  - being in /home/stud, use command
    - mkdir hal
- Change directory to the subdirectory /home/stud/hal
  - cd /home/stud/hal
- Create a directory exercise1
  - mkdir exercise1
- Change directory to the subdirectory exercise1
  - cd <tap> chose exersice1
- Create a ﬁle text1 containing "hello nano" using nano?
  - nano <filename>
    - the you need to fill in the text with the editor
- Create a ﬁle text2 containing "hello echo" using echo?
  - echo repeats something to an output, standard it will be the terminal. You pipe the output to a file with > 
  - echo hello echo > text2
- Append 1234567890 to file text1 using echo?
  - appind con be done with >> on a multitude of diffrent commads
- Dump the contents of text1 to the terminal window?
  - echo $(<filename)
    - dumps the file name 
- Create a directory temp
- Copy text1 to the directory temp
- Remove the subfolder temp and its content
  - rm -rf dirname 
    - -rf recursive force 
- Delete text1 and text2 in one go?
- Install Visual Studio Code Install_vscode
- Create a small c program, hello_linux.c that prints out the text "Hello Linux!"
- Compile the program using gcc (tips here)
- Run the program, change file permissions with chmod if required (tips here)
- - RWX RWX RWX 
  - User
  - gruoup 
  - others

#### Program control
Write down which commands you use to:

Run the program nano in the background
- any command will do, followed by & 
- jobs list all current jobs 
- fg brings a job to the foreground 
- 
Now kill the program Kate you just started
- kill -9 id 
  - the kill command sends a signal, the 9 is what signal to send. 
  - 9 is rip everything apart, tell the job nothing before killing

### shell scripts 
- Write down which commands you use to:
  
- Get a list of the currently running processes (programs)
- Display the current date and time in the terminal
- Find the IP address of the network adapter ens33xxx
- Explain what the ﬁle /var/log/syslog does
- Try using running less /var/log/syslog and read the manual for less. What is it good for?
- What happens when you run dmesg?
- Extending the above like this: dmesg|less, what does it do?
- Determine the CPU type by looking the directory /proc


