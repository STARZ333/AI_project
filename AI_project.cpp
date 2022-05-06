#include <stdio.h>
#define MAX 100
//狀態
struct zt
{
	int left_c;
	int right_c;
	int left_y;
	int right_y;
	int boat_location;
};
struct zt ztarr[MAX];
long int index=0;
long int numpass=0;
long int start_c,start_y;


int handle(zt t)
{
	//是否達到目標轉態
	if(	t.right_c == start_c && t.right_y == start_y)
	{
		numpass++;
		// printf("\n找到第%d條路徑！\n",numpass);
		// printf("左傳\t左野\t右傳\t右野\t船\n");
		// for(int i = 0; i <= index ; i++)
		// {
		// 	printf("%2d\t",ztarr[i].left_c);
		// 	printf("%2d\t",ztarr[i].left_y);
		// 	printf("%2d\t",ztarr[i].right_c);
		// 	printf("%2d\t",ztarr[i].right_y);
		// 	printf("%2d\t",ztarr[i].boat_location);
		// 	printf("\n");
		// }
		//找到多條路徑的關鍵一
		return 0;
	}
	//是否重複操作
	for(int i = 0; i < index; i++)
	{
		if(t.left_c == ztarr[i].left_c && t.left_y == ztarr[i].left_y)
		{
			if(t.boat_location == ztarr[i].boat_location)
			{
				return 0;
			}
			
		}
	}
	//人數是否合理嗎
	if(t.left_c < 0 || t.left_y < 0 || t.right_c < 0 || t.right_y < 0  )
	{
		return 0;
	}
	//傳教士是否被吃
	if((t.left_c < t.left_y && t.left_c != 0) || (t.right_c < t.right_y && t.right_c != 0) )
	{
		return 0;
	}

	//定義一個臨時節點
	struct zt tt;

	//兩個傳教士過河
	tt.left_c = t.left_c - 2 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 2 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index - 1;
	
	//兩個野人過河
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 2 * t.boat_location;
	tt.right_c = t.right_c ;
	tt.right_y = t.right_y + 2 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;	

	//一個野人，一個傳教士過河
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;

	//一個傳教士過河
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;

	//一個野人過河
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;
	//找到多條路徑的關鍵二
	return 0;
}


int main()
{
	while(1){
	printf("請輸入初始傳教士人數：");
	scanf("%d",&start_c);
	printf("請輸入初始傳教士人數：");
	scanf("%d",&start_y);
	ztarr[index].left_c = start_c;
	ztarr[index].left_y = start_y;
	ztarr[index].right_c = 0;
	ztarr[index].right_y = 0;
	ztarr[index].boat_location = 1;
	handle(ztarr[index]);
	printf("已為您找到%d條過河路徑！並且已全部載入完畢！\n",numpass);
	}
}