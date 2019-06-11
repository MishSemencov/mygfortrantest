#!bin/bash

echo "Enter key O0 = 0, O1 = 1; O2 = 2; O3 = 3; Os = s"
read n

if ( echo $n | grep -E -v -q "^([0-3s])$" )
then
	echo "Wrong parameters"
	exit
fi

case $n in
	0) g++ -c Main.cpp -O0;;
	1) g++ -c Main.cpp -O1;;
	2) g++ -c Main.cpp -O2;;
	3) g++ -c Main.cpp -O3;;
        s) g++ -c Main.cpp -Os;;
esac
g++ Main.o
time ./a.out
du -b  Main.o
