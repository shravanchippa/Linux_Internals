cat file|
while read line
do
    echo "{$line}"
 #   last=$line
done
printf "\nAll done, last:$last\n"

exit 0  # End of code.
~

