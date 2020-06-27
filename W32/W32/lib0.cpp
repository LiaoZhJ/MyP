#include"stdafx.h"
#include"lib0.h"

char* pchar()
{
	return "从静态库内取得的字符串";
}

int F::GetA() {
	return a + 1;
}