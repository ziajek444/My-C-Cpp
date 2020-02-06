echo Building objects...
gcc -fPIC -c sensor_r.c
gcc -fPIC -c sensor_w.c
gcc -fPIC -c sensor_l.c
gcc -fPIC -c sensor_i.c
echo done :D
echo Create dynamic library...
gcc -shared -o libLocalDB.so sensor_r.o sensor_w.o sensor_l.o sensor_i.o 
echo done :D
echo Copy library to /usr/lib ...
sudo cp libLocalDB.so /usr/lib
echo Configurating
sudo ldconfig
echo Well done :DD
