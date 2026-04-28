#include<stdio.h>
#include<dirent.h>
#include<string.h>
int List();
int main()
{
	char command[100] , name[100];
	printf("Enter Your Name\n");
	fgets(name,sizeof(name),stdin);
	for(int i = 0 ; name[i] != '\0'; i++){
		if(name[i] == '\n'){
			name[i] = '\0';
			break;
		}
	}
	printf("%s$ ",name);
	fgets(command,sizeof(command),stdin);
	for(int i = 0 ; command[i] != '\0'; i++){
		if(command[i] == '\n'){
			command[i] = '\0';
			break;
		}
	}
	if((strcmp(command,"ls") == 0) || (strcmp(command,"ls -a") == 0)){
		List(command);
	}	
}

int List(char command[100]){
	DIR *dir = opendir(".");
	if(dir == NULL){
		printf("File Don't open or Gives Error\n");
		return 1;
	}
	printf("File Read Success FUlly\n");
	struct dirent *inf;
	while((inf = readdir(dir)) != NULL){
		if(strcmp(command,"ls") == 0){
			if(inf -> d_name[0] == '.'){
				continue;
			}
		}
		printf("%s\n",inf -> d_name);
	}
	
	
	closedir(dir);
	return 0;
}
