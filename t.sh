make
./aa > libft.txt
make re DEF=LIBC
./aa > libc.txt
diff libft.txt libc.txt
#rm libft.txt libc.txt
