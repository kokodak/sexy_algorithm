#include <stdio.h>
#define MAX 8
#pragma warning (disable: 4996)

int sorted[MAX]; //메모리의 비효율성을 막기 위해 전역 변수 선언

void merge(int arr[], int L, int M, int R) {
	int i = L; //왼쪽 부분 배열의 인덱스를 가르키는 i
	int j = M + 1; //오른쪽 부분 배열의 인덱스를 가르키는 j
	int k = L; //sorted 배열의 인덱스를 가르키는 k

	while (i <= M && j <= R) {
        //두 개의 부분 배열중 하나라도 먼저 정렬이 끝날 때까지,
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > M) {
    //왼쪽 부분 배열의 정렬이 먼저 끝났을 경우
		for (int l = j; l <= R; l++) {
			sorted[k] = arr[l];
			k++;
		}
	}
	else {
    //오른쪽 부분 배열의 정렬이 먼저 끝났을 경우
		for (int l = i; l <= M; l++) {
			sorted[k] = arr[l];
			k++;
		}
	}

	for (int l = L; l <= R; l++) {
    //복사
		arr[l] = sorted[l];
	}
}

void merge_sort(int arr[], int L, int R) {
    //재귀적으로 함수를 호출하면서 인덱스 값을 조정하여 간접적으로 부분 배열 구현
	if (L < R) {
		int M = (L + R) / 2;
		merge_sort(arr, L, M);
		merge_sort(arr, M + 1, R);
		merge(arr, L, M, R);
	}
}

void main() {
	int arr[MAX] = { 3, 7, 2, 4, 11, 9, 15, 1 };

	merge_sort(arr, 0, MAX - 1);

	for (int i = 0; i < MAX; i++) printf("%d ", arr[i]);
    //merge_sort를 마친 arr는 { 1, 2, 3, 4, 7, 9, 11, 15 }
}
