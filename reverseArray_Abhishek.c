#include<stdio.h>
main()
{
	int index,size,temp;
	printf("enter array size");
	int arr[size];
	printf("enter elements for array");
	for (index = 0; index < size; i++)
		scanf("%d", &arr[index]);
	for (index = 0; index < size; index++)
	{
		temp=arr[index];
		arr[index]=arr[size-1-index];
		arr[size-1-index]=temp;
	}
	printf("the reversed array is:\n");
	for (index = 0; index < size; index++)
		printf("%d", arr[index]);
}
