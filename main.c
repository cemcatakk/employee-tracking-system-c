#include <stdio.h>
#include <stdlib.h>
#define COURSENAMELENGTH 50 // DERS ADI UZUNLUGU
#define COURSECODELENGTH 10 // DERS KODU UZUNLUGU
#define COURSESMAX 5 // Maximüm des yükü
#define DIPLOMAMAX 5 // Maximüm Diploma saysi
typedef struct fullName{ //tam adi
char *name; //adi
char *surname; //soyadi
}name_t;
typedef struct dates{ //tarih
int day; //gün
 char* month; //ay
 short year; //yil
}date_t;
typedef struct diploma{ //diploma
char *facName; //fakülte adi
 char *deptName; //bölüm adi
char *level; //lisans, Yüksek Lisans veya Doktora
date_t dateAwarded; //diploma tarihi
}diploma_t;
typedef struct courseOffered{ //kayitli Dersler
char courseName[COURSENAMELENGTH]; //ders adi
char courseCode[COURSECODELENGTH]; //ders kodu
 date_t startDate; //dersin baslangiç tarihi
 date_t endDate; //dersin bitis tarihi
}course_t;
typedef struct employeeInfo{ //ögretmen bilgisi
name_t employeeName; //ögretmen adi
diploma_t dip[DIPLOMAMAX]; //diploma bilgisi
course_t noCourses[COURSESMAX]; //verdigi derslerin listesi
int age; //yas
double salary; //maas
 date_t startDate; //ise Baslangiç Tarihi
 date_t dateOfBirth; //dogüm Tarihi
}employee_t;
//addDiplome method adds new diploma to employee at given index to given diploma index
void addDiploma(employee_t* allEmployees,int nextIndex,int diplomaIndex){
	//Allocate memory for each char pointer 
	allEmployees[nextIndex].dip[diplomaIndex].deptName=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].dip[diplomaIndex].facName=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].dip[diplomaIndex].level=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].dip[diplomaIndex].dateAwarded.month=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	//Then ask for;
	//Dep name
	printf("Enter Department name:");
	scanf("%s",allEmployees[nextIndex].dip[diplomaIndex].deptName);
	//Faculty name
	printf("Enter Faculty name:");
	scanf("%s",allEmployees[nextIndex].dip[diplomaIndex].facName);
	//Level
	printf("Enter Level:");
	scanf("%s",allEmployees[nextIndex].dip[diplomaIndex].level);
	//Date information
	printf("Enter day given:");
	scanf("%d",&allEmployees[nextIndex].dip[diplomaIndex].dateAwarded.day);
	printf("Enter month given:");
	scanf("%s",allEmployees[nextIndex].dip[diplomaIndex].dateAwarded.month);
	printf("Enter year given:");
	scanf("%d",&allEmployees[nextIndex].dip[diplomaIndex].dateAwarded.year);
	printf("Diploma successfully added.\n");
}
//addCourse method adds new course to employee's course array. 
//Employee given by index and new course is going to be added to given course index
void addCourse(employee_t* allEmployees,int nextIndex,int courseIndex){
	//First, allocate memory for char pointers
	allEmployees[nextIndex].noCourses[courseIndex].startDate.month=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].noCourses[courseIndex].endDate.month=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	//Then ask for Course info
	//Name
	printf("Enter Course Name:");
	scanf("%s",allEmployees[nextIndex].noCourses[courseIndex].courseName);
	//Code
	printf("Enter Course Code:");
	scanf("%s",allEmployees[nextIndex].noCourses[courseIndex].courseCode);
	//Get date info for start
	printf("Enter start day:");
	scanf("%d",&allEmployees[nextIndex].noCourses[courseIndex].startDate.day);
	printf("Enter start month:");
	scanf("%s",allEmployees[nextIndex].noCourses[courseIndex].startDate.month);
	printf("Enter start year:");
	scanf("%d",&allEmployees[nextIndex].noCourses[courseIndex].startDate.year);
	//Get date info for end 
	printf("Enter end day:");
	scanf("%d",&allEmployees[nextIndex].noCourses[courseIndex].endDate.day);
	printf("Enter end month:");
	scanf("%s",allEmployees[nextIndex].noCourses[courseIndex].endDate.month);
	printf("Enter end year:");
	scanf("%d",&allEmployees[nextIndex].noCourses[courseIndex].endDate.year);
}

//addEmployee method adds new employee to employee pointer to given index
void addEmployee(employee_t* allEmployees,int nextIndex){
	//Allocate memory for each char pointer of employee
	allEmployees[nextIndex].employeeName.name=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].employeeName.surname=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].startDate.month=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	allEmployees[nextIndex].dateOfBirth.month=(char*)malloc(sizeof(char)*COURSENAMELENGTH);
	//Get employee info from user
	//Name
	printf("Employee Name:");
	scanf("%s",allEmployees[nextIndex].employeeName.name);
	//Surname
	printf("Employee Surname:");
	scanf("%s",allEmployees[nextIndex].employeeName.surname);
	int choice,diplomaCount=0,courseCount=0;
	//Loop while user doesn't input 2
	while(1){
		printf("1-Add diploma\n2-Done\n>");
		scanf("%d",&choice);
		if(choice==1){
			if(diplomaCount==DIPLOMAMAX){
				printf("You cant add more diplomas.\n");
				break;
			}
			//If choice is 1 and diploma count is not equal to max amount of diploma
			addDiploma(allEmployees,nextIndex,diplomaCount);
			diplomaCount++;
		}
		else if(choice==2){
			break; //Break loop
		}
	}
	//Loop while user doesn't input 2
	while(1){
		printf("1-Add course\n2-Done\n>");
		scanf("%d",&choice);
		if(choice==1){
			if(courseCount==COURSESMAX){
				printf("You cant add more courses.\n");
				break;
			}
			//If choice is 1 and course count is not equal to max amount of course
			addCourse(allEmployees,nextIndex,courseCount);
			courseCount++;
		}
		else if(choice==2){
			break;
		}
	}
	//Get start date information
	printf("Enter start day:");
	scanf("%d",&allEmployees[nextIndex].startDate.day);
	printf("Enter start month:");
	scanf("%s",allEmployees[nextIndex].startDate.month);
	printf("Enter start year:");
	scanf("%d",&allEmployees[nextIndex].startDate.year);
	//Get birth date information
	printf("Enter birth day:");
	scanf("%d",&allEmployees[nextIndex].dateOfBirth.day);
	printf("Enter birth month:");
	scanf("%s",allEmployees[nextIndex].dateOfBirth.month);
	printf("Enter birth year:");
	scanf("%d",&allEmployees[nextIndex].dateOfBirth.year);
	//Calculate employee's age by 2021-birth year
	allEmployees[nextIndex].age = 2021 - allEmployees[nextIndex].dateOfBirth.year;
	//Get salary
	printf("Enter monthly salary:");
	scanf("%lf",&allEmployees[nextIndex].salary);
	printf("Employee successfully added.\n");
}

void displayDate(date_t date){//Displays date in format 'dd mm yyyy'
	printf("%d %s %d",date.day,date.month,date.year);
}

void displayCourseInfo(course_t c){
	//Displays given course info
	printf("-Course Code: %s\tCourse Name: %s\tStart Date: ",c.courseCode,c.courseName);
	displayDate(c.startDate); //Calls displayDate method to display start and end date
	printf("\tEnd Date: ");
	displayDate(c.endDate);
	printf("\n");
}

void displayInstructorInfo(employee_t emp){
	int i;
	//Employee info
	//First, display name, surname information
	printf("Employee Name&Surname: %s %s\n",emp.employeeName.name,emp.employeeName.surname);
	//Then print date of birth and start date by calling displayDate method
	//Also print age and salary
	printf("Date of Birth: "); displayDate(emp.dateOfBirth); printf("\tAge: %d\n",emp.age);
	printf("Start Date: "); displayDate(emp.startDate); printf("\tSalary: %lf TL",emp.salary);
	//For each diploma
	printf("\n---DIPLOMAS---\n");
	for(i=0;i<DIPLOMAMAX;i++){
		if(emp.dip[i].deptName!=NULL){//if deptName is not null, it means there is a record
		//Then it prints diploma information
			printf("\nFaculty: %s\tDepartment: %s\tLevel: %s\tDate Awarded:",emp.dip[i].facName,emp.dip[i].deptName,emp.dip[i].level);
			displayDate(emp.dip[i].dateAwarded);
		}
	}
	//For each course
	printf("\n---COURSES---\n");
	for(i=0;i<COURSESMAX;i++){
		if(emp.noCourses[i].startDate.month!=NULL){//If course start date's month is not null, it means there is a record
		//Then call displayCourseInfo method to display 
			displayCourseInfo(emp.noCourses[i]);
		}
	}
}

void printClass(employee_t* allEmployees,int count){//There is no class or student variable, so i decided to print all employees
	int i;
	//Print all employees in employee pointer
	printf("All employees:");
	for(i=0;i<count;i++){
		//Call displayInstructorInfo method for each employee
		displayInstructorInfo(allEmployees[i]);
	}
}

void calculateCourseAverage(employee_t* allEmployees,int count){//There is no student or course score variable, so i decided to print salary average of teachers
	double avg=0;
	int i;
	//For each employee
	for(i=0;i<count;i++){
		//Add employee's salary to 'avg' variable
		avg+=allEmployees[i].salary;
	}
	avg/=count;//Then divide it by employee count to find salary average
	printf("Employee Count: %d\nSalary Average: %lf\n",count,avg);
}


int main(int argc, char *argv[]) {
	
	employee_t* allEmployees =(employee_t*) malloc(sizeof(employee_t)*10); //Allocate memory for 10 employees
	int choice,empCount=0;
	while(1){
		//While user doesn't enters '0'
		printf("0-Exit\n1-Add Employee\n2-Print Employee List\n3-Calculate Salary Average\n>");
		scanf("%d",&choice);
		if(choice==1){
			//call addEmployee method
			addEmployee(allEmployees,empCount);
			empCount++;//Then increase employee count by 1
		}
		else if(choice==2){
			//call printClass method to print all employees
			printClass(allEmployees,empCount);
		}
		else if(choice==3){
			//call calculateCourseAverage to print salary average
			calculateCourseAverage(allEmployees,empCount);
		}
		else if(choice==0)break;
	}
	printf("Goodbye!");
	return 0;
}
