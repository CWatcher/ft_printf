make re
aa > ft.txt
make re DEFS=LIBC
aa > libc.txt
make fclean
diff ft.txt libc.txt
rm ft.txt libc.txt
