echo Building objects...
gcc -c ism.c
echo done :D

echo Create executable with dynamic lib
gcc -o ism ism.o -lLocalDB -lrt -lpthread
echo done :D

