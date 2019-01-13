#include<stdio.h>
#include<string.h>

#define FOUND 1
#define NOT_FOUND -1

struct raffeldb{
char name[10];
int start;
int end;
};

void db_display(struct raffeldb *db);
//struct raffeldb * db_read(struct raffeldb *d, int tot_count, int in_value);
int db_read(struct raffeldb *d, int tot_count, int in_value);

int main()
{

	struct raffeldb db[10];
	FILE *fp;
	int i=0, ret=0;
	int in_value;
	int tot_count = 0;
	//struct raffeldb *retdb;
	int retdb;
	fp = fopen("db.txt","r");
	
	if(fp == NULL)
	{
		printf("Can't open the data file db.txt\n");
	}

	while( fscanf(fp, "%s %d %d", db[i].name, &db[i].start, &db[i].end) != EOF){
	i++;
	tot_count++;
	}
	
	printf("\nEnter the ticket number in the counter foil \n");
	scanf("%d",&in_value);
	printf("\nCounter foil number enterd is %d\n\n", in_value);
	db_read(db, tot_count, in_value);	
	//retdb = db_read(db, tot_count, in_value);	
	//db_display(retdb);
	fclose(fp);	
return 0;
}

void db_display(struct raffeldb *db)
{
	int i;

	printf("***********RESULT***********\n");	
	printf("Name = %s ", db->name);
	printf("Start = %d ", db->start);
	printf("End = %d ", db->end);
	printf("\n");
	printf("****************************\n");	
}

//struct raffeldb * db_read(struct raffeldb *d, int tot_count, int in_value)
int db_read(struct raffeldb *d, int tot_count, int in_value)
{
	int i;
	for(i = 0; i < tot_count; i++)
	{
		//if((in_value >= d[i].start) && (in_value <= d[i].end))  
		if((in_value >= d -> start) && (in_value <= d -> end))  
		{
			db_display(d);
			return FOUND;
			//return &d[i];
		}
		*d++;
	}

	printf("Counter foil number not in database\n");
	return NOT_FOUND;
}
