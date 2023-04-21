//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[] = {0,1,2,3,4,5,6,7,8,9};
//	int  a = sizeof(arr) / sizeof(arr[0]);//元素个数
//	int left = 0;
//	int right =9;
//	int k = 7;//要查找的数字
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid+1;
//		}
//		else if (arr[mid] >k)
//		{
//			right = mid-1;
//		}
//		else 
//		{
//			printf("找到%d",mid);
//			break; 
//		}
//	}
//	if (left>right)
//		printf("无");
//	
//	return 0;
//}