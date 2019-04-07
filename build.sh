# bin/bash

wget https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-linux-gcc-64-bit.tar.gz 
tar -xf SFML-2.5.1-linux-gcc-64-bit.tar.gz SFML-2.5.1/include SFML-2.5.1/lib 
rm -rf SFML-2.5.1-linux-gcc-64-bit.tar.gz
mv SFML-2.5.1/include include/
mv SFML-2.5.1/lib lib/
rm -rf SFML-2.5.1/
make