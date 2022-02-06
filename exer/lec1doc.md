# Lets get started with Linux! 
the purpuce of this exersize is to get familiarised with the linux enviroment. 
## 1.1





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


