#include <stdio.h>
#include "LinkedList.h"

struct Character
{
	char chr;
	int index;
};

void t1()
{
	printf("[T1]\n");

	LinkedList list;
	Character chr;

	for (int i = 0; i < 10; i++)
	{
		memset(&chr, 0, sizeof(Character));
		chr.chr = i + 'A';
		chr.index = i;

		list.AddBack(&chr, sizeof(Character));
	}
	printf("Size: %d\n", list.Size());

	printf("List: ");
	while (list.Size() != 0)
	{
		list.Front(&chr, sizeof(Character));
		printf("{%c, %d} ", chr.chr, chr.index);

		list.RemoveFront();
	}

	printf("\nSize: %d\n", list.Size());
}

void t2()
{
	printf("[T2]\n");

	LinkedList list;
	Character chr;

	for (int i = 0; i < 10; i++)
	{
		memset(&chr, 0, sizeof(Character));
		chr.chr = i + 'A';
		chr.index = i;

		list.AddFront(&chr, sizeof(Character));
	}
	printf("Size: %d\n", list.Size());

	printf("List: ");
	while (list.Size() != 0)
	{
		list.Front(&chr, sizeof(Character));
		printf("{%c, %d} ", chr.chr, chr.index);

		list.RemoveFront();
	}

	printf("\nSize: %d\n", list.Size());
}

void t3()
{
	printf("[T3]\n");

	LinkedList list;
	Character chr;

	for (int i = 0; i < 10; i++)
	{
		memset(&chr, 0, sizeof(Character));
		chr.chr = i + 'A';
		chr.index = i;

		list.AddBack(&chr, sizeof(Character));
	}
	printf("Size: %d\n", list.Size());

	printf("List: ");
	while (list.Size() != 0)
	{
		list.Front(&chr, sizeof(Character));
		printf("{%c, %d} ", chr.chr, chr.index);

		list.RemoveFront();
	}

	printf("\nSize: %d\n", list.Size());
}

void t4()
{
	printf("[T4]\n");

	LinkedList list;
	Character chr;

	for (int i = 0; i < 10; i++)
	{
		memset(&chr, 0, sizeof(Character));
		chr.chr = i + 'A';
		chr.index = i;

		list.AddBack(&chr, sizeof(Character));
	}
	printf("Size: %d\n", list.Size());

	printf("List: ");
	list.BeginInterate();
	while (list.Next(&chr, sizeof(Character)))
	{
		printf("{%c, %d} ", chr.chr, chr.index);
	}
	printf("\n");
}

int main()
{
	t1();
	t2();
	t3();
	t4();

	return 0;
}