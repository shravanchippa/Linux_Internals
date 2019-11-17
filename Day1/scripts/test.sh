 echo "Enter the name of the file"
 read file_name
 	if [ ! -f $file_name ]
        then
		echo "$file_name dose not exist"
	elif [ ! -r $file_name ]
	then
		echo "The file dose not have read permission"
	elif [ ! -w $file_name ]
	then
		echo "The file dose not have write permission"
	elif [ -f $file_name -a -r $file_name ] # -a is logical AND
	then
		echo "The file is OK"
fi

