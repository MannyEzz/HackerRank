#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:\n",t.name);
    for(int i=0;i<t.offices_count;i++)
    {
        printf("\t%d:\n",i);
        
        for(int j=0; j<t.offices[i].packages_count;j++)
        {
            printf("\t\t%s\n",t.offices[i].packages[j].id);
        }
        
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int n = 0;
    for(int i=0;i<source->offices[source_office_index].packages_count;i++)
    {
        if(source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight && source->offices[source_office_index].packages[i].weight >=target->offices[target_office_index].min_weight)
        {
            n++;
            
        }
    }
    package* new_target_package = malloc((target->offices[target_office_index].packages_count+n) *sizeof(package));
    package* new_source_package = malloc((source->offices[source_office_index].packages_count-n ) *sizeof(package));
    // copy the target package to the new target package
    for(int i=0;i< target->offices[target_office_index].packages_count;i++)
    {
        new_target_package[i] = target->offices[target_office_index].packages[i];
    }
    //update the packages
    n = target->offices[target_office_index].packages_count;
    int m = 0;
    for(int i=0;i<source->offices[source_office_index].packages_count;i++)
    {
        if(source->offices[source_office_index].packages[i].weight <= target->offices[target_office_index].max_weight && source->offices[source_office_index].packages[i].weight >=target->offices[target_office_index].min_weight)
        {
            //update the new target package
            new_target_package[n] = source->offices[source_office_index].packages[i];
            n++;
        }
        else{
            //update the new soyrce package
            new_source_package[m] = source->offices[source_office_index].packages[i];
            m++;
        }
    }
    //update the target package
    target->offices[target_office_index].packages_count = n;
    free(target->offices[target_office_index].packages);
    target->offices[target_office_index].packages = new_target_package;
    //update the source package
    source->offices[source_office_index].packages_count = m;
    free(source->offices[source_office_index].packages);
    source->offices[source_office_index].packages = new_source_package;
}

town town_with_most_packages(town* towns, int towns_count) {
    int most_packages = -1;
    int index = 0;
    for(int i=0;i<towns_count;i++)
    {
        int sum_packages = 0;
        for(int j=0; j<towns[i].offices_count;j++)
        {
            sum_packages += towns[i].offices[j].packages_count;
        }
        
        if(sum_packages > most_packages)
        {
            most_packages = sum_packages;
            index = i;
        }
    }
    
    return towns[index];
}

town* find_town(town* towns, int towns_count, char* name) {
    int indx=0;
    for(int i=0;i<towns_count;i++)
    {
        if (!strcmp(towns[i].name, name))
        {
            indx = i;
        }
    }   
    return &towns[indx];
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
