<h1>0x16.C - Simple Shell</h1>
This is a collaborative project with **Heba Omar** for ALX Software Engineering program, Cohort 13.

<h1>Tasks</h1>

<h2>0. Betty would be proud</h2>
Write a beautiful code that passes the Betty checks.

<h2>1. Simple shell 0.1</h2>
Write a UNIX command line interpreter.
Usage:  `simple_shell`
Your Shell should:

-   Display a prompt and wait for the user to type a command. A command line always ends with a new line.
-   The prompt is displayed again each time a command has been executed.
-   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-   The command lines are made only of one word. No arguments will be passed to programs.
-   If an executable cannot be found, print an error message and display the prompt again.
-   Handle errors.
-   You have to handle the “end of file” condition (`Ctrl+D`)

You don’t have to:

-   use the  `PATH`
-   implement built-ins
-   handle special characters :  `"`,  `'`,  `` ` ``,  `\`,  `*`,  `&`,  `#`
-   be able to move the cursor
-   handle commands with arguments

_`execve`  will be the core part of your Shell, don’t forget to pass the environ to it…_

<h2>2. Simple shell 0.2</h2>
Simple shell 0.1 +

-   Handle command lines with arguments

<h2>3. Simple shell 0.3</h2>
Simple shell 0.2 +

-   Handle the  `PATH`
-   `fork`  must not be called if the command doesn’t exist

<h2>4. Simple shell 0.4</h2>
Simple shell 0.3 +

-   Implement the  `exit`  built-in, that exits the shell
-   Usage:  `exit`
-   You don’t have to handle any argument to the built-in  `exit`

<h2>5. Simple shell 1.0</h2>
Simple shell 0.4 +

-   Implement the  `env`  **built-in**, that prints the current environment

<h2>7. Simple shell 0.2.1</h2>
Simple shell 0.2 +

-    You are not allowed to use strtok

<h2>10. cd</h2>
Simple shell 1.0 +

Implement the builtin command cd:

-    Changes the current directory of the process.
-    Command syntax: cd [DIRECTORY]
-    If no argument is given to cd the command must be interpreted like cd $HOME
-    You have to handle the command cd -
-    You have to update the environment variable PWD when you change directory
man chdir, man getcwd

<h2>15. Comments</h2>
Simple shell 1.0 +

-    Handle comments (#)
