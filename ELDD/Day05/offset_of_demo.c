#include <stdio.h>

struct student{
	int rollno;
	char name[20];
	int std;
};

#define offset_of(type, member) ((long)&(((type *)0)->member))
#define container_of(ptr, type, member) \
	((type *)((char *)(ptr) - offset_of(type, member)))

int main(void)
{
	struct student st = {12, "abc", 4};

	printf("offset_of(rollno) : %ld\n", offset_of(struct student, rollno));
	printf("offset_of(name) : %ld\n", offset_of(struct student, name));
	printf("offset_of(std) : %ld\n", offset_of(struct student, std));
	
	printf("&st : %u\n", &st);
	printf("&st.rollno : %u\n", &st.rollno);
	printf("&st.name : %u\n", &st.name);
	printf("&st.std : %u\n", &st.std);

	int *ptr = &st.std;

	printf("base address of st : %u\n", container_of(ptr, struct student, std));

	return 0;
}











