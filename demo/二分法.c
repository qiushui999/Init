//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int arr[] = {0,1,2,3,4,5,6,7,8,9};
//	int  a = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
//	int left = 0;
//	int right =9;
//	int k = 7;//Ҫ���ҵ�����
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
//			printf("�ҵ�%d",mid);
//			break; 
//		}
//	}
//	if (left>right)
//		printf("��");
//	
//	return 0;
//}