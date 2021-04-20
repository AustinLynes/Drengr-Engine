#pragma once

#include <iostream>
#include <string>
#include <comdef.h>

//// THE ASSERT HEADER HANDLES ALL EXCEPTION AND ASSERTION RELATION DEFINES AND GLOBAL USE HELPER FUNCTIONS



inline std::wstring GetCOMError(HRESULT hr) {

	_com_error err(hr);
	return err.ErrorMessage();
}

// Throws a basic exception
#define THROW(str) throw new std::exception(str)
//hr --> HRESULT
#define THROW_IF_FAILED(hr) if (FAILED(hr)) { std::wstring str = L"Exception Thrown: \nline: " + std::to_wstring(__LINE__) + L"\n"+ L"What Drengr think: \n" + GetCOMError(hr); OutputDebugString(str.c_str()); THROW("COM Exception"); }
