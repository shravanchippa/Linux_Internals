#include <stdio.h>

struct employee
{
	char name[8];
	int serial_num;
};

void print_employee_rec(struct employee rec)
{
	printf ("Name: %s\n",rec.name);
	printf ("Number: %d\n",rec.serial_num);
	return ;
}

void update_employee_name( struct employee *rec,char *name )
{
	strcpy ( rec -> name,name );
	return ;
}

void add_employee (struct employee *rec,char *name,int num)
{
	strcpy (rec->name,name);
	rec->serial_num = num;
	return;
}

int main ()
{
	struct employee rec;
	add_employee(&rec,"Fred",25);
	print_employee_rec(rec);
	printf ("UPdating employee's name......\n\n");
	update_employee_name (&rec,"Fred Smith" );
	print_employee_rec(rec);
	return 0;
}
