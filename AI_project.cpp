#include <stdio.h>
#define MAX 100
//��B
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
	//�Ƿ��_��Ŀ���D�B
	if(	t.right_c == start_c && t.right_y == start_y)
	{
		numpass++;
		// printf("\n�ҵ���%d�l·����\n",numpass);
		// printf("���\t��Ұ\t�҂�\t��Ұ\t��\n");
		// for(int i = 0; i <= index ; i++)
		// {
		// 	printf("%2d\t",ztarr[i].left_c);
		// 	printf("%2d\t",ztarr[i].left_y);
		// 	printf("%2d\t",ztarr[i].right_c);
		// 	printf("%2d\t",ztarr[i].right_y);
		// 	printf("%2d\t",ztarr[i].boat_location);
		// 	printf("\n");
		// }
		//�ҵ����l·�����P�Iһ
		return 0;
	}
	//�Ƿ����}����
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
	//�˔��Ƿ�����
	if(t.left_c < 0 || t.left_y < 0 || t.right_c < 0 || t.right_y < 0  )
	{
		return 0;
	}
	//����ʿ�Ƿ񱻳�
	if((t.left_c < t.left_y && t.left_c != 0) || (t.right_c < t.right_y && t.right_c != 0) )
	{
		return 0;
	}

	//���xһ���R�r���c
	struct zt tt;

	//�ɂ�����ʿ�^��
	tt.left_c = t.left_c - 2 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 2 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index - 1;
	
	//�ɂ�Ұ���^��
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 2 * t.boat_location;
	tt.right_c = t.right_c ;
	tt.right_y = t.right_y + 2 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;	

	//һ��Ұ�ˣ�һ������ʿ�^��
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;

	//һ������ʿ�^��
	tt.left_c = t.left_c - 1 * t.boat_location;
	tt.left_y = t.left_y;
	tt.right_c = t.right_c + 1 * t.boat_location;
	tt.right_y = t.right_y;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;

	//һ��Ұ���^��
	tt.left_c = t.left_c;
	tt.left_y = t.left_y - 1 * t.boat_location;
	tt.right_c = t.right_c;
	tt.right_y = t.right_y + 1 * t.boat_location;
	tt.boat_location = ( -t.boat_location);
	index = index + 1;
	ztarr[index] = tt;
	handle(ztarr[index]);
	index = index-1;
	//�ҵ����l·�����P�I��
	return 0;
}


int main()
{
	while(1){
	printf("Ոݔ���ʼ����ʿ�˔���");
	scanf("%d",&start_c);
	printf("Ոݔ���ʼ����ʿ�˔���");
	scanf("%d",&start_y);
	ztarr[index].left_c = start_c;
	ztarr[index].left_y = start_y;
	ztarr[index].right_c = 0;
	ztarr[index].right_y = 0;
	ztarr[index].boat_location = 1;
	handle(ztarr[index]);
	printf("�ў����ҵ�%d�l�^��·�����K����ȫ���d���ꮅ��\n",numpass);
	}
}