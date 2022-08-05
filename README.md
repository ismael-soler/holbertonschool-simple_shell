<h1 align = "center"> C - Simple Shell </h1>

<h2> Description </h2>
<p>This project consist of the development of a command interpreter for Linux. The program tries to replicate the basic functionalities of sh shell. It was developed in C language.</p>

<h2> Flowchart </h2>
<p align = "center"> <img src="https://i.imgur.com/T47ttDM.png" /> </p>
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

<h2> Built-ins </h2>
<p> We have implemented two built-ins intrinsics functions to our "hsh" Shell:<br>
  -<b>ENV</b> - which print the environment variables<br>
  -<b>EXIT</b> - which end the program<br>
  </p>
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
  <td>Check if the command has a path and return an array with the arguments with the corresponding path</td>
  </tr>
  
<tr>
  <td>check_input.c</td>
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


<h2> Examples </h2>
<h3> -ls command </h3>
<p> Interactive mode </p>
 
<pre><code>root# ./hsh
$ls
buff_to_array.c  check_input.c   fix_dir.c   _getenv.c  main.h  shell.c  string_functions.c  check_command.c <br>
check_status.c  free_array.c  hsh  print_error.c  README.md  _start.c</br>
$</code></pre>

<p> Non interactive mode </p>
 
<pre><code>root# echo "ls" | ./hsh
buff_to_array.c  check_input.c   fix_dir.c   _getenv.c  main.h  shell.c  string_functions.c  check_command.c <br>
check_status.c  free_array.c  hsh  print_error.c  README.md  _start.c</br>
</code></pre>

<h3> Built in - env </h3>
<pre><code>root# echo "env" | ./hsh
HOSTNAME=aba1ef7f7e57
LANGUAGE=en_US:en
PWD=/holbertonschool-simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
</code></pre>

<h2> Authors </h2>

<p>Ismael Soler - <a href="https://github.com/ismael-soler"> ismael-soler </a></p>
<p>Ignacio Martino - <a href="https://github.com/Imartino4"> Imartino4 </a></p>

