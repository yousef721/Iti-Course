#include <stdio.h>

typedef struct 
{
    int id;
    int math;
    int language;
    int physics;
    int chemistry;

} Student;



#include <stdio.h>


int main(void){
	int idToSearch;
	Student students[10]={ {1,40,50,60,70},{2,44,55,66,77},{3,98,87,65,54},{4,45,56,78,89},{5,69,58,47,36},
						   {6,74,85,96,63},{7,35,68,57,24},{8,48,59,26,78},{9,55,87,64,94},{10,91,84,61,35}};
			
    printf("Please Enter student ID : ");
    scanf("%d",&idToSearch);

    int found = 0;

    for (int i = 0; i < 10; i++)
    {
        if (idToSearch == students[i].id)
        {
            printf("\nStudent ID Is %d \n", students[i].id);
            printf("Math Grade Is %d \n", students[i].math);
            printf("Language Grade Is %d \n", students[i].language);
            printf("Physics Grade Is %d \n", students[i].physics);
            printf("Chemistry Grade Is %d \n", students[i].chemistry);
            found = 1;
            break; // خلاص لقيته
        }
    }

    if (!found)
    {
        printf("\nStudent ID Is Not Correct \n");
    }
		
	return 0 ;
}

