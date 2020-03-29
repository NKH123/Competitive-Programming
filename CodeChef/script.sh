for i in {1..1000}
do
	echo $i
	./gen >a.in; ./a.out <a.in

done
