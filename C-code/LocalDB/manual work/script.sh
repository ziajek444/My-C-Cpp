echo Building objects...
gcc -c manual_work.c
echo done :D

echo Create executable with dynamic lib
gcc -o manual_work manual_work.o -lLocalDB 
echo done :D

