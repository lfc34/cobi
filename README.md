# cobi
Convert units of digital information in CLI

# Installation
Compile program:
```bash
make
```
or:
```bash
cc -O2 cobi.c -o cobi
```
Move it into any location you want, preferably one from the $PATH, like:
```bash
mv cobi /usr/bin/
```

# Usage
```bash
cobi 1024   bit             byte
     ^value ^type of value  ^unit to convert to
cobi 8 gib byte
```
Supported units:
valid CLI argument / full name
bit                  bit
byte                 byte
kb                   kilobyte
kib                  kebibyte
mb                   megabyte
mib                  mebibyte
gb                   gigabyte
gib                  gebibyte
tb                   terabyte
tib                  tebibyte
