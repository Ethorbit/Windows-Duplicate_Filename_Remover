# Windows-Duplicate_Filename_Remover
### A Windows command line program developed in C++ that helps you find, move and remove duplicate filenames.
It does this by checking for files that have - Copy or (number) at the end of their names.

### Download the executable:
https://github.com/Ethorbit/Windows-Duplicate_Filename_Remover/releases/latest

### Instructions:
Drag & drop the folder you want to check on the executable or run the program in a command-line.

Arguments: 
* First argument: the directory you want it to search _(C:/Desktop/bob/CheckThis)_

* Second argument: safe 
Passing the word safe as the second argument will ensure that a file will only be marked as duplicate if there is another file with the same name (The default mode will mark files as duplicate for simply having (number) or - Copy at the end because it's much faster)
