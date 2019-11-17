IFS=:
var=`cat /etc/passwd`
for i in $var
do 
echo $i
done
