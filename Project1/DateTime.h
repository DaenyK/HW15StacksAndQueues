#pragma once
#include "Headers.h"

class DateTime {
public:
	static void getCurrentDateTime() {
		SYSTEMTIME st;
		GetLocalTime(&st);
		printf("%d-%02d-%02d %02d:%02d:%02d",
			st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
	}
};