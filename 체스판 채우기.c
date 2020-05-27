#pragma warning(disable:4996)
#include <stdio.h>
#define chnum 8
char chess[100][100];
int check(int N, int M);
int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {/*기본 사각형에 B인지 W인지 넣는 작업*/
		for (int j = 0; j < M; j++) {
			scanf(" %c", &chess[i][j]);
		}
	}
	printf("%d", check(N, M));
	return 0;
}

int check(int N, int M) {/*사각형 내에서 모든 8*8사각형을 검사*/
	int min = 64;
  int tmp;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for(int num=0;num<2;num++){/*w와B둘중 더 작은값을 선택해야하므로 둘 다 해보아야한다.*/
			if(num==0)
				tmp = 0;/*체스판에 검은색이 칠해져있을때*/
      else
      tmp=1;
			int count = 0;
			for (int k = i; k < i + 8; k++) {
				for (int z = j; z < j + 8; z++) {
					if (tmp == 1) {
						tmp = 0;
						if (chess[k][z] != 'W')
							count++;
					}
					else {
						tmp = 1;
						if (chess[k][z] != 'B')
							count++;
					}
				}
				if (tmp == 1)
					tmp = 0;
				else
					tmp = 1;
			}
			if (min > count)
				min = count;
		}

    }
	}
	return min;
}
