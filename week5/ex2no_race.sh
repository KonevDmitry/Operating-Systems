#!/bin/bash
if test ! -f ex2.txt
then
	echo 0>ex2.txt
fi
if ln ex2.txt ex2.txt.lock
then
	for((i=0;i<100;i++))
	do
		number=`tail -1 ex2.txt`
		number=$((number+1))
		echo $number >> ex2.txt
	done
	rm ex2.txt
fi
