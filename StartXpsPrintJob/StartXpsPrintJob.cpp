// StartXpsPrintJob.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <xpsprint.h>
#pragma comment(lib, "XpsPrint.lib")

int main()
{

	CoInitialize(nullptr);
	IXpsOMObjectFactory *xpsFactory = NULL;
	CoCreateInstance(__uuidof(XpsOMObjectFactory), NULL, CLSCTX_INPROC_SERVER, __uuidof(IXpsOMObjectFactory), reinterpret_cast<LPVOID*>(&xpsFactory));
	HANDLE completionEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	IXpsPrintJob *job = NULL;
	IXpsPrintJobStream *jobStream = NULL;
	StartXpsPrintJob(L"Microsoft XPS Document Writer", L"Print Job 1", NULL, NULL, completionEvent, NULL, 0, &job, &jobStream, NULL);
	jobStream->Close();
	CoUninitialize();

    return 0;
}

