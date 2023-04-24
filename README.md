README.md

"Simple Shell" is a Unix shell written in C language that can execute commands, including those with arguments, and can be used with or without a full path name. 
It also includes built-in commands such as cd, exit, alias, setenv, unsetenv, env, and supports logical operators (&&, ||), semicolon separator, and limited variable expansion.

To use the "Simple Shell" program, you need to compile it first by running the following command:

gcc -Wall -Werror -Wextra -pedantic *.c -o <shell_name_here>
Replace <shell_name_here> with the name you want to give to the shell program.

After compiling, you can invoke the shell by running the executable file:

./<shell_name_here>
Once you're in the shell, you can execute commands, including built-in commands, by typing them in and pressing Enter.

For example:

$ ls
This command lists the files and directories in the current directory.

$ cd /home
This command changes the current directory to /home.

$ setenv HELLO world
This command sets an environmental variable named HELLO with the value world.

$ unsetenv HELLO
This command unsets the environmental variable named HELLO.

You can exit the shell by typing exit.

