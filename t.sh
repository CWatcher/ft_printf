make
./aa > ft.txt
make re DEF=LIBC
./aa > libc.txt
diff ft.txt libc.txt
#rm ft.txt libc.txt
