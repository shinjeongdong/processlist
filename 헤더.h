

typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWCH   Buffer;
} UNICODE_STRING, * PUNICODE_STRING;

typedef struct _SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;
    ULONG NumberOfThreads;
    LARGE_INTEGER Reserved[3];
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER KernelTime;
    UNICODE_STRING ImageName;
    ULONG BasePriority;
    HANDLE Pid;
    HANDLE InheritedFromProcessId;
} SYSTEM_PROCESS_INFORMATION, * PSYSTEM_PROCESS_INFORMATION;


// 함수 포인터 선언 getprocaddress 함수를 이용해 얻은 함수의 주소를 _NtQuerySystemInformation형으로 변환함 
typedef NTSTATUS(* _NtQuerySystemInformation)(
    ULONG SystemInformationClass, 
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength
    );