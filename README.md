<h1 align = "center"> C - Simple Shell </h1>

<h2> Description </h2>
<p>This project consist of the development of a command interpreter for Linux. The program tries to replicate the basic functionalities of sh shell.</p>

<h2> General information </h2>
<p>- All files will be compiled on Ubuntu 20.04 LTS using <pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89</code></pre></p>
<p>- The program must have the exact same output as sh (/bin/sh) as well as the exact same error output, the only difference is when an error is printed:</p>
  <p>The error in sh:</p>
<pre><code>$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$</code></pre>
<p> And the error in our shell  must be:</p>
<pre><code>$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$</code></pre>

<h2> File contents </h2>
<table>
<tr>
  <td><strong>Name of file</strong></td>
  <td><strong>Description</strong></td>
</tr>
<tr>
  <td>README.md</td>
  <td>Description of program</td>
</tr>
<tr>
  <td>_getenv.c</td>
  <td>Gets and environment variable</td>   
</tr>
  
<tr>
  <td>_start.c</td>
  <td>Check mode, generate the prompt, read the user input and evaluate different input cases</td>   
</tr>

<tr>
  <td>buff_to_array.c</td>
  <td>Receives a string, tokenize it and return an array with the generated tokens</td>   
</tr>
  
<tr>
  <td>check_command.c</td>
  <td>Check if the command has a path and return an array with the arguments with the corresponding path path</td>
  </tr>
  
<tr>
  <td>check_input.c.c</td>
  <td>Implement built-ins</td>   
</tr>
  
<tr>
  <td>fix_dir.c</td>
  <td>Adds corresponding path to the command</td>   
</tr>
  
<tr>
  <td>free_array.c</td>
  <td>Auxiliar function to free allocated memory of arrays of strings</td>   
</tr>
 
<tr>
  <td>print_error.c</td>
  <td>Auxiliar function to print errors</td>   
</tr>
  
<tr>
  <td>shell.c</td>
  <td>Main function of the shell</td>   
</tr>
  
<tr>
  <td>main.h</td>
  <td>Header file for the hsh program</td>   
</tr>
  
<tr>
  <td>hsh</td>
  <td>Simple shell program</td>   
</tr>
</table>

<h2> Authors </h2>
<p>Ismael Soler</p>
<p>Ignacio Martino</p>
