#include <stdio.h>

extern int asm_int_svc(int svc_no);
int main(void)
{
	int rst=0;

	printf("Arm  SVC Interrupt Test Start(pid:%d, ppid:%d, uid:%d, gid:%d)!!\n", getpid(), getppid(), getuid(), getgid());

	//svc no -> /usr/include/arm-linux-gnueabihf/asm/unistd.h
	rst = asm_int_svc(20);	//20 : __NR_getpid
	printf("getpid_SVC_Interrurpt Return Value -> %d\n", rst);

	rst = asm_int_svc(64);	//64 : __NR_getppid
	printf("getppid_SVC_Interrurpt Return Value -> %d\n", rst);

	rst = asm_int_svc(24);	//24 : __NR_getuid
	printf("getuid_SVC_Interrurpt Return Value -> %d\n", rst);

	rst = asm_int_svc(47);	//47 : __NR_getgid
	printf("getgid_SVC_Interrurpt Return Value -> %d\n", rst);

#if 0
	__asm__ __volatile__ (
		"mov	r0, #60;"
		"svc	2;"
	);
#endif

	printf("Arm  SVC Interrupt Test End!!\n");
	return 0;
}

