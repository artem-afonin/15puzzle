# bin/bash

mkdir -p test thirdparty
cd thirdparty
wget https://github.com/google/googletest/archive/release-1.8.1.tar.gz
tar -xf release-1.8.1.tar.gz
mv googletest-release-1.8.1/googletest/ googletest
rm -rf googletest-release-1.8.1/
rm -rf release-1.8.1.tar.gz
make test
