# PowerPoint
## How to run
```
    mkdir build
    cd build
    cmake ..
    make
    ./powerPoint
```
## Commands
### create -name Slide
>create new slide

### change -slide -id [itemn]
>change current slide

### add -name [item type] [-argument] [value]
>add item to current slide <br />

### remove -id [itemId]
>remove selected item from current slide

### change -item -id [n] [-argument] [value] ...
>change selected item arguments

### list
>display all slides <br />

### display -id [itemId]
>all information about selected item

### save -file [filename].txt
>save document as a .txt file

### load -file [filename].txt
>import .txt file

### quit 
