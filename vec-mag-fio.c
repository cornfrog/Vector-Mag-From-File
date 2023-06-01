#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define VECTOR_LENGTH 5

void createVectorFile();
void readVectorFile();
void printVector();
void calculateVector();


FILE *vectorFile;
char vectorFileName[] = "Vector-File";
int vector[VECTOR_LENGTH];

int main(){
	createVectorFile();
	readVectorFile();
	printVector();
	calculateVector();
	return 0;
}

void createVectorFile(){
	int count = 0;
	//seeding random 
	srand(time(NULL));
	vectorFile = fopen(vectorFileName, "w");
	if(vectorFile == NULL){
		printf("Error opening/creating %s\n", vectorFileName);
	}
	else{
		while(count < VECTOR_LENGTH){
			fprintf(vectorFile, "%d\n", ((rand()%10)+1));
			count++;
		}
		fclose(vectorFile);
	}
}

void readVectorFile(){
	char buffer[100];
	vectorFile = fopen(vectorFileName, "r");
	if(vectorFile == NULL){
		printf("Error opening %s for reading\n", vectorFileName);
	}
	else{
		int index = 0;
		while(fgets(buffer, sizeof(buffer), vectorFile) != NULL){
			int vectorElement = atoi(buffer);
			vector[index] = vectorElement;
			index++;
		}
	}
}

void printVector(){
	printf("Vector: ");
	printf("< ");
	for(int i = 0; i < VECTOR_LENGTH; i++){
		printf("%d ", vector[i]);
	}
	printf(">\n");
}

void calculateVector(){
	double magnitude;
	int total = 0;
	for(int i = 0; i < VECTOR_LENGTH; i++){
		total += total + vector[i];
	}
	magnitude = sqrt(total);
	printf("Vector Magnitude = %.2f\n", magnitude);
}
