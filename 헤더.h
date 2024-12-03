

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


// �Լ� ������ ���� getprocaddress �Լ��� �̿��� ���� �Լ��� �ּҸ� _NtQuerySystemInformation������ ��ȯ�� 
typedef NTSTATUS(* _NtQuerySystemInformation)(
    ULONG SystemInformationClass, 
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength
    );