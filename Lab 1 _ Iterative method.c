// Title : iterative algorithm implementation 
// Objective :
//     - to implement GCD using iteration 
//     - to implement fibonacci series using iteration 
//     - to implement factorial using iteration 
//     - to implement Linear searching using iteration

// Date : 24th dec | 09 / 09

// Theory :
//     1) name , algotithm and pseudocode
//     2) trace
//     3) complexity analysis
//     4) code in handwritten form 
//     5) output
//     6) conclusion


#include<stdio.h>
#include<stdbool.h>
#define SIZE 10
int array[SIZE];

int GCD(int a, int b ){
    int r; 
    if(b==0)
        return a;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Fact(int n){
	int i = n, factorial = 1;
	while(i!=0){
		factorial *= i;
		i--;
	}
	return factorial;
}

int fibo(int n){
	int a = 0, b = 1, c, i;
	printf("The fibonacci series upto %d index is: ", n);
	printf("%d, %d, ", a, b);
	for(i = 2; i <= n; i++){
		c = a + b;
		printf("%d, ", c);
		a = b;
		b = c;		
	}
}

int Linear_search(int array[], int element){
    bool key_found = false;
    for(int i = 0; i < sizeof(array); i++ ){
        if(array[i] == element){
            key_found = true;
            printf("Element found at index %d", i);
        }
    }
    if(!key_found)
        printf("Element not found!");
}

int main(){
    int a , b, r, n, i, option;
    char proceed = 'y';
    array[SIZE];
    printf("***** Iterative Algorithms *****");

    do{
        printf("\n\n1. Calculate GCD\n");
        printf("2. Calculate Factorial\n");
        printf("3. Calculate Nth fibonacci number\n");
        printf("4. Perform linear searching\n");
        printf("Choose any one operation from above:\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Please enter two numbers for GCD calculation:\t");
                scanf("%d%d", &a, &b);
                if(a>b){
                    a = a+b;
                    b = a-b;
                    a = a-b;
                }
                int gcd = GCD(a, b);
                printf("The Value of GCD(%d, %d) is : %d", a, b, gcd);
                break;
                
            case 2:
                printf("Enter the number whose factorial is required:\t");
                scanf("%d", &n);
                
                int factorial = Fact(n);
                printf("The factorial of %d is %d", n, factorial);
                break;
            
            case 3:
                printf("Upto what term is fibonacci series required?:\t");
                scanf("%d" ,&n);
                fibo(n);
                break;

            case 4: 
                printf("Please enter the size of the array: \t");
                scanf("%d", &n);
                printf("please enter  %d elements:     ", n);
                for(i = 0; i<n; i++){
                    scanf("%d", &array[i]);
                } 

                printf("What is the element to be searched?\n");
                scanf("%d", &a);
                
                Linear_search(array, a);
                break;

            default:
                printf("Invalid input");
        }

        printf("\nDo you want to continue?(y/n)");
        scanf("%d", &proceed);
    }while (proceed == 'y');
}



