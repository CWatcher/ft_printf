make && aa > ft.txt
rm aa
make DEFS=LIBC && aa > libc.txt
diff ft.txt libc.txt
rm ft.txt libc.txt
