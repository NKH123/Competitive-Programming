ct=0
for i in `ls`; 
do 
	#echo $i;
	ct=`echo $ct + 1 | bc`
	#echo "ct = $ct"

done; 
echo "The number of files is $ct"
