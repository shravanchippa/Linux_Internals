IFS=:
while read name passwd uid gid fullname homedir shell
do
echo -e " $name \t $uid \t $fullname"
done < /etc/passwd
