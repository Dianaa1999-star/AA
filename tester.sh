#!/bin/bash

touch file

echo ".....SparseTable....."

g++ SparseTable.cpp -o SparseTable
x=1 
while [ $x -le 10 ]
do
	./SparseTable './in/test'$x.in file
	DIFF=$(diff file "./out/test"$x.out)
	if [ "$DIFF" != "" ]; then
		echo "Test$x FAILED!"
	else
		echo "Test$x PASSED!"
	fi
	x=$(( $x + 1 ))
done
rm file
rm SparseTable

touch file

echo "...SqrtDecomposition..."

g++ SqrtDecomposition.cpp -o SqrtDecomposition
x=1 
while [ $x -le 10 ]
do
	./SqrtDecomposition './in/test'$x.in file
	DIFF=$(diff file "./out/test"$x.out)
	if [ "$DIFF" != "" ]; then
		echo "Test$x FAILED!"
	else
		echo "Test$x PASSED!"
	x=$(( $x + 1 ))
	fi
done
rm file
rm SqrtDecomposition

touch file
touch file

echo "......Segments......."

g++ Segments.cpp -o Segments

x=1 
while [ $x -le 10 ]
do
	./Segments './in/test'$x.in file
	DIFF=$(diff file "./out/test"$x.out)
	if [ "$DIFF" != "" ]; then
		echo "Test$x FAILED!"
	else
		echo "Test$x PASSED!"
	fi
	x=$(( $x + 1 ))
done
rm file
rm Segments
touch file

echo "......Algo......."


g++ main.cpp algo.cpp -o main

x=1 
while [ $x -le 10 ]
do
	./main "./in/test"$x.in file
	DIFF=$(diff file "./out/test"$x.out)
	if [ "$DIFF" != "" ]; then
		echo "Test$x FAILED!"
	else
		echo "Test$x PASSED!"
	fi
	x=$(( $x + 1 ))
done
rm file
rm main
