dialog --inputbox "Enter String1" 20 30 2>file
read string1
dialog --inputbox "Enter String2" 20 30  2>file
read string2
	if [ $string1 = $string2 ] ; then
dialog --inputbox "The string entered is: $string1" 20 30 2>file
else
dialog --inputbox "The string entered is :$string2" 20 30 2>file
fi 
