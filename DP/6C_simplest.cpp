#include <stdio.h>
int main() 
{ 
    int n;
	long long a=2,b=0;  
    scanf("%d", &n);  
    while(--n)  a = a + b , b = a - b;  
	printf("%lld\n", a); 
    return 0;
}
