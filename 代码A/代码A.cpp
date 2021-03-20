define _CRT_SECURE_NO_WARNINGS
# include<stdio.h>
void find(int s1s, int* sns, int sn) {
	int light = 0, right = sn - 1;
	int mid, falg = 1;
	while (light <= right) {
		mid = (light + right) / 2;
		if (sns[mid] == s1s) {
			falg = 2;
			break;
		}
		else if (sns[mid] < s1s) {
			light = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (falg == 1) {
		printf("NO\n");
	}
	if (falg == 2) {
		printf("YES\n");
	}
}

void QuickSort(int sns[], int low, int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int k = sns[low];
		while (i < j)
		{
			while (i < j && sns[j] >= k)     // 从右向左找第一个小于k的数
			{
				j--;
			}
			if (i < j)
			{
				sns[i++] = sns[j];
			}
			while (i < j && sns[i] < k)      // 从左向右找第一个大于等于k的数
			{
				i++;
			}
			if (i < j)
			{
				sns[j--] = sns[i];
			}
		}
		sns[i] = k;
		// 递归调用
		QuickSort(sns, low, i - 1);     // 排序k左边
		QuickSort(sns, i + 1, high);    // 排序k右边
	}
}
int main()
{
	int sn, sm;//数组长度和查询次数
	scanf("%d %d", &sn, &sm);
	int s1s;//要查询的数 
	int sns[100020] = { 0 };
	for (int i = 0; i < sn; i++) {
		scanf("%d", &sns[i]);
	}
	QuickSort(sns, 0, sn - 1);
	while (sm--) {
		scanf("%d", &s1s);
		find(s1s, sns, sn);
	}
	return 0;
}
