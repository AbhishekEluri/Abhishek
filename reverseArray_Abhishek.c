#include<stdio.h>
main()
{
	int i,size;
	printf("enter array size");
	int arr[size];
	printf("enter elements for array");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < size; i++)
	{
		arr[i] = arr[i]+arr[size-1-i];
		arr[size-1-i] = arr[i]-arr[size-1-i];
		arr[i] = arr[i]-arr[size-1-i];
	}
	for (i = 0; i < size; i++)
	printf("%d", arr[i]);
}
