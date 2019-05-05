#include<stdio.h>
main()
{
	int i,size;
	printf("enter array size");
	int arr[size],rev[size];
	printf("enter elements for array");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < size; i++)
		rev[i] = arr[size - 1];
	for (i = 0; i < size; i++)
		printf("%d", arr[i]);
}