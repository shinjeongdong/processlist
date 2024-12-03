#include <Windows.h>
#include <stdio.h>
#include "���.h"

int main()
{
	NTSTATUS ret = 0;
	HMODULE Ntdll = GetModuleHandleA("ntdll.dll"); // ntdll.dll�� ��� �ڵ��� ����
	_NtQuerySystemInformation NtQuerySystemInformation = (_NtQuerySystemInformation)GetProcAddress(Ntdll, "NtQuerySystemInformation"); //�Լ��� �̿��ؼ� ntdll���� �Լ��� ������ 
	//�׸��� ����ȯ��

	ULONG size = 0;

	ret = NtQuerySystemInformation(5, nullptr, 0,&size); //�̷��� �ϸ� size������ �ʿ��� ������� ������
	SYSTEM_PROCESS_INFORMATION* hinfo = (SYSTEM_PROCESS_INFORMATION*)malloc(size); //�����Ҵ�

	memset(hinfo, 0, size); //0���� ����

	ret = NtQuerySystemInformation(5, hinfo, size, nullptr); // ����ü hinfo�� �Ҵ���� size�� ����.


	while (true)
	{
		printf("%d\n", hinfo->Pid); //hinfo ����� pid ���
		printf("%wZ\n", &hinfo->ImageName); //hinfo ����� ���μ��� �̸� ��� %wZ�� unicode_string����ü�� �ּҸ� �Ѱܾ��Ѵ�

		printf("\n");
		if (hinfo->NextEntryOffset == 0)
		{
			break;
		}
		
		hinfo = (SYSTEM_PROCESS_INFORMATION*)((PBYTE)hinfo + (hinfo->NextEntryOffset)); //�������� �ּ� ������ hinfo�� pbyte ����ȯ�Ͽ��� NextEntryOffset���� ���� 

	}
	return 0;
}