#include <Windows.h>
#include <stdio.h>
#include "헤더.h"

int main()
{
	NTSTATUS ret = 0;
	HMODULE Ntdll = GetModuleHandleA("ntdll.dll"); // ntdll.dll의 모듈 핸들을 얻음
	_NtQuerySystemInformation NtQuerySystemInformation = (_NtQuerySystemInformation)GetProcAddress(Ntdll, "NtQuerySystemInformation"); //함수를 이용해서 ntdll에서 함수를 가져옴 
	//그리고 형변환함

	ULONG size = 0;

	ret = NtQuerySystemInformation(5, nullptr, 0,&size); //이렇게 하면 size변수에 필요한 사이즈값을 대입함
	SYSTEM_PROCESS_INFORMATION* hinfo = (SYSTEM_PROCESS_INFORMATION*)malloc(size); //동적할당

	memset(hinfo, 0, size); //0으로 세팅

	ret = NtQuerySystemInformation(5, hinfo, size, nullptr); // 구조체 hinfo랑 할당받은 size를 넣음.


	while (true)
	{
		printf("%d\n", hinfo->Pid); //hinfo 멤버에 pid 출력
		printf("%wZ\n", &hinfo->ImageName); //hinfo 멤버에 프로세스 이름 출력 %wZ는 unicode_string구조체의 주소를 넘겨야한다

		printf("\n");
		if (hinfo->NextEntryOffset == 0)
		{
			break;
		}
		
		hinfo = (SYSTEM_PROCESS_INFORMATION*)((PBYTE)hinfo + (hinfo->NextEntryOffset)); //포인터의 주소 재지정 hinfo를 pbyte 형변환하여서 NextEntryOffset값을 더함 

	}
	return 0;
}